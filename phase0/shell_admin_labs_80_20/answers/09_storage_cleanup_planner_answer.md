# Answer — Lab 09: Storage Capacity & Cleanup Planner

## Reference implementation sketch

Filesystem status:

```bash
df -P "$root" | awk 'NR==2 {print "capacity=" $5, "available_kb=" $4}'
```

Largest directories:

```bash
du -x -h "$root" 2>/dev/null | sort -h | tail -20
```

Largest files:

```bash
find "$root" -xdev -type f -printf '%s %p
' 2>/dev/null | sort -n | tail -20
```

Old candidates:

```bash
find "$root" -xdev -type f -mtime +30 \
  \( -name '*.tmp' -o -name '*.bak' -o -name '*.log.gz' \) -print
```

The crucial design rule is that this script **does not delete**. It reports candidates and estimates reclaimable space.

## Production improvements

Add protected-path configuration, owner/group columns, deterministic CSV, filesystem-device filtering, and a policy explanation for every candidate class.
