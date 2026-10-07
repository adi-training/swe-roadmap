# Answer — Lab 07: Service Health Check & Incident Bundle

## Reference skeleton

```bash
#!/usr/bin/env bash
set -u
service_log=service.log
health_cmd=health-command.sh
config=service.conf
lines=50
stamp=$(date +%Y%m%d-%H%M%S)
tmp=$(mktemp -d "${TMPDIR:-/tmp}/incident.XXXXXX")
out="incident-$stamp"
cleanup(){ rm -rf -- "$tmp"; }
trap cleanup EXIT INT TERM

health_status=0
if "$health_cmd" >"$tmp/health.txt" 2>&1; then
  health_status=0
else
  health_status=$?
fi

ps -ef >"$tmp/process.txt" 2>&1 || true
{
  printf 'timestamp=%s
' "$(date -Is)"
  printf 'hostname=%s
' "$(hostname)"
  printf 'health_exit=%s
' "$health_status"
} >"$tmp/summary.txt"

tail -n "$lines" "$service_log" >"$tmp/relevant.log" 2>/dev/null || :

# Redact common secret-looking values instead of copying raw configuration.
sed -E 's/^(.*(password|token|secret|api[_-]?key)[[:space:]]*=[[:space:]]*).*/<REDACTED>/I'   "$config" >"$tmp/metadata.txt" 2>/dev/null || :

mkdir -p "$out"
cp "$tmp"/* "$out"/
tar -czf "$out.tar.gz" "$out"
rm -rf -- "$out"
exit "$health_status"
```

## Key ideas

`trap` guarantees cleanup for normal exit and common signals. The health result is saved immediately so later evidence-collection failures do not accidentally replace it.

A more robust implementation should decide exactly which evidence failures are warnings, include a bundle manifest, and use a stronger secret-redaction policy than a few regular expressions.
