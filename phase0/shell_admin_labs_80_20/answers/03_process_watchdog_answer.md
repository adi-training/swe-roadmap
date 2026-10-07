# Answer — Lab 03: Process Watchdog & Resource Reporter

## Reference implementation

```bash
#!/usr/bin/env bash
set -u
name=""; cpu_limit=100; mem_limit=100; json=""
usage(){ echo "Usage: $0 --name NAME --cpu-limit N --mem-limit N [--json FILE]"; }
while [[ $# -gt 0 ]]; do
  case $1 in
    --name) name=${2-}; shift 2;;
    --cpu-limit) cpu_limit=${2-}; shift 2;;
    --mem-limit) mem_limit=${2-}; shift 2;;
    --json) json=${2-}; shift 2;;
    -h|--help) usage; exit 0;;
    *) echo "Unknown option" >&2; exit 3;;
  esac
done
[[ -n $name && $cpu_limit =~ ^[0-9]+([.][0-9]+)?$ && $mem_limit =~ ^[0-9]+([.][0-9]+)?$ ]] || { usage >&2; exit 3; }

found=0; alert=0
printf '%-8s %-24s %8s %8s %12s
' PID COMMAND CPU MEM ELAPSED

while read -r pid comm pcpu pmem etime; do
  [[ $comm == "$name" ]] || continue
  found=1
  printf '%-8s %-24s %8s %8s %12s
' "$pid" "$comm" "$pcpu" "$pmem" "$etime"
  awk -v c="$pcpu" -v m="$pmem" -v cl="$cpu_limit" -v ml="$mem_limit" 'BEGIN { if (c>cl || m>ml) exit 1 }' && : || alert=1
done < <(ps -eo pid=,comm=,pcpu=,pmem=,etime=)

(( found )) || exit 2
(( alert )) && exit 1
exit 0
```

## Why this is intentionally simple

Monitoring output needs a stable decision point. The key contract is the exit code. Formatting should not change whether the process is healthy.

## Production improvements

Use a stronger process identity than command name alone, define what multiple workers mean, write machine-readable output, and consider PID reuse/races. A watchdog should also have a timeout around slow checks and should avoid depending on non-portable `ps` columns if portability matters.
