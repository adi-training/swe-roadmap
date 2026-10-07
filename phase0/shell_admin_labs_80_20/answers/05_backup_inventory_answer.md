# Answer — Lab 05: Backup Inventory & Verification

## Reference approach

A useful decomposition is:

1. parse valid backup filenames into `(system,date,path)`;
2. keep the latest date per system in an associative array;
3. load expected inventory;
4. compare expected to discovered state;
5. run `sha256sum -c` against the checksum manifest;
6. aggregate findings and choose the final exit code.

Example discovery pattern:

```bash
while IFS= read -r -d '' f; do
  base=${f##*/}
  if [[ $base =~ ^backup-([0-9]{4}-[0-9]{2}-[0-9]{2})\.tar\.gz$ ]]; then
    system=$(basename "$(dirname "$f")")
    date=${BASH_REMATCH[1]}
    # compare date with latest[$system]
  fi
done < <(find "$repo" -type f -print0)
```

Checksum verification:

```bash
if sha256sum -c "$manifest"; then
  checksum_status=0
else
  checksum_status=1
fi
```

When the manifest contains relative paths, run the check from the directory for which the manifest was created.

## Key point

Existence, freshness, and integrity are different checks. A backup can exist and be recent but still be corrupted.

## Production improvements

Validate that backup dates are real calendar dates, use deterministic report ordering, validate manifest paths, and avoid accepting unexpected absolute paths from an untrusted manifest.
