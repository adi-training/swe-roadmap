# Answer — Lab 02: Log Retention & Compression Manager

## Reference implementation

```bash
#!/usr/bin/env bash
set -u
log_dir=""; compress_after=7; delete_after=30; mode=""; audit=""
usage(){ echo "Usage: $0 --log-dir DIR --compress-after N --delete-after N (--dry-run|--apply) [--audit FILE]"; }
while [[ $# -gt 0 ]]; do
  case $1 in
    --log-dir) log_dir=${2-}; shift 2;;
    --compress-after) compress_after=${2-}; shift 2;;
    --delete-after) delete_after=${2-}; shift 2;;
    --dry-run) mode=dry; shift;;
    --apply) mode=apply; shift;;
    --audit) audit=${2-}; shift 2;;
    -h|--help) usage; exit 0;;
    *) echo "Unknown option: $1" >&2; exit 3;;
  esac
done
[[ -d $log_dir && $mode ]] || { usage >&2; exit 3; }
[[ $compress_after =~ ^[0-9]+$ && $delete_after =~ ^[0-9]+$ && $delete_after -gt $compress_after ]] || { echo "Bad retention values" >&2; exit 3; }
[[ -n $audit ]] && : > "$audit"

log(){ printf '%s %s\n' "$(date '+%F %T')" "$*"; [[ -n $audit ]] && printf '%s,%s\n' "$(date '+%FT%T')" "$*" >> "$audit"; }

while IFS= read -r -d '' f; do
  base=${f##*/}
  case $base in
    app-????-??-??.log)
      age=$(( ( $(date +%s) - $(stat -c %Y "$f") ) / 86400 ))
      if (( age >= compress_after )); then
        if [[ $mode == apply ]]; then gzip -- "$f" && log "COMPRESS $f" || log "ERROR_COMPRESS $f"; else log "WOULD_COMPRESS $f"; fi
      fi
      ;;
    app-????-??-??.log.gz)
      age=$(( ( $(date +%s) - $(stat -c %Y "$f") ) / 86400 ))
      if (( age >= delete_after )); then
        if [[ $mode == apply ]]; then rm -- "$f" && log "DELETE $f" || log "ERROR_DELETE $f"; else log "WOULD_DELETE $f"; fi
      fi
      ;;
    *) : ;;
  esac
done < <(find "$log_dir" -maxdepth 1 -type f -print0)
```

## Important design choice

This implementation uses filesystem modification time as the retention clock. That means copying a file may change the apparent age. A production policy might instead use the date embedded in a trusted filename or metadata store. The policy must be explicit.

## Improvement directions

Add size summaries, compression-ratio reporting, stronger filename/date validation, and a lock file so two retention runs cannot overlap.
