# Answer — Lab 01: Folder Housekeeper

## Reference approach

The key design is to separate **classification** from **action**. The script first discovers files and decides `DELETE`, `ARCHIVE`, or `KEEP`. Only in `--apply` mode does it perform the selected action.

Reference implementation:

```bash
#!/usr/bin/env bash
set -u

usage() {
  cat <<'EOF'
Usage: housekeeper.sh --root DIR (--dry-run|--apply) [--archive DIR] [--tmp-age N] [--report FILE]
EOF
}

root=""
mode=""
archive_dir=""
tmp_age=7
report=""

while [[ $# -gt 0 ]]; do
  case $1 in
    --root) root=${2-}; shift 2 ;;
    --dry-run) mode=dry; shift ;;
    --apply) mode=apply; shift ;;
    --archive) archive_dir=${2-}; shift 2 ;;
    --tmp-age) tmp_age=${2-}; shift 2 ;;
    --report) report=${2-}; shift 2 ;;
    -h|--help) usage; exit 0 ;;
    *) echo "Unknown option: $1" >&2; usage; exit 3 ;;
  esac
done

[[ -d $root ]] || { echo "Invalid root directory" >&2; exit 3; }
[[ $mode ]] || { echo "Choose --dry-run or --apply" >&2; exit 3; }
[[ $tmp_age =~ ^[0-9]+$ ]] || { echo "Bad age" >&2; exit 3; }

[[ -n $archive_dir ]] || archive_dir="$root/archive"
mkdir -p "$archive_dir" 2>/dev/null || true

if [[ -n $report ]]; then
  printf 'path,category,size_bytes,mtime,action
' > "$report"
fi

classify() {
  local f=$1 base
  base=${f##*/}
  case $base in
    *.tmp|*.bak|*.swp) echo DELETE ;;
    *)
      if [[ $f == "$root/reports/"* && $f == *.report && $(find "$f" -mtime +30 -print) ]]; then
        echo ARCHIVE
      else
        echo KEEP
      fi
      ;;
  esac
}

count_keep=0; count_archive=0; count_delete=0
while IFS= read -r -d '' f; do
  [[ -L $f ]] && continue
  [[ -f $f ]] || continue
  category=$(classify "$f")
  size=$(stat -c '%s' "$f")
  mtime=$(stat -c '%y' "$f")
  action=NONE

  case $category in
    DELETE)
      ((count_delete++))
      if [[ $mode == apply ]]; then rm -- "$f" && action=DELETED || action=ERROR; else action=WOULD_DELETE; fi
      ;;
    ARCHIVE)
      ((count_archive++))
      dest="$archive_dir/${f#"$root/"}"
      mkdir -p "$(dirname "$dest")"
      if [[ $mode == apply ]]; then mv -- "$f" "$dest" && action=ARCHIVED || action=ERROR; else action=WOULD_ARCHIVE; fi
      ;;
    KEEP) ((count_keep++)); action=KEPT ;;
  esac

  [[ -n $report ]] && printf '%q,%s,%s,%q,%s
' "$f" "$category" "$size" "$mtime" "$action" >> "$report"
done < <(find "$root" -path "$archive_dir" -prune -o -type f -print0)

printf 'KEEP=%d ARCHIVE=%d DELETE=%d MODE=%s
' "$count_keep" "$count_archive" "$count_delete" "$mode"
```

## What to notice

- `find ... -print0` plus `read -d ''` avoids ordinary whitespace-splitting problems.
- symlinks are skipped explicitly.
- the archive directory is pruned from discovery.
- destructive operations occur only in apply mode.
- classification is centralized instead of duplicated in multiple branches.

## Production improvements

A production version should use a cleaner CSV encoder, stronger error aggregation, a lock to prevent concurrent runs, configurable policies, and explicit handling for cross-filesystem moves.
