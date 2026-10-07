# Answer — Lab 10: Daily Operations Control Center

## Reference architecture

The control center should treat each check as a small command with a contract:

```bash
run_check() {
  local name=$1
  shift
  local started ended rc
  started=$(date +%s)
  "$@"
  rc=$?
  ended=$(date +%s)
  printf '%s|%s|%s|%s
' "$name" "$rc" "$((ended-started))" "$(date -Is)"
  return "$rc"
}
```

Then collect results without stopping after one failure:

```bash
overall=0
run_check disk check_disk || overall=1
run_check process check_process || overall=1
run_check backup check_backup || overall=1
run_check drift check_drift || overall=1
```

For machine-readable output, prefer a deliberately defined schema. Simple newline-delimited records are often easier in Bash than trying to build complex JSON by hand. For JSON, use `jq` when it is an approved dependency.

## Important shell lesson

Be careful with pipelines when you need the exit status of the main check. Depending on the shell/options, a formatting command may hide the failure. Capture the status before formatting or use `PIPESTATUS`/`pipefail` appropriately.

## Production improvements

Add config validation, dependency checks, locking, timeout handling, a version string, structured logs, and a small automated regression suite.
