# Answer — Lab 08: Configuration Drift Detector

## Reference approach

Start with hashes:

```bash
baseline_hash=$(sha256sum "$baseline/app.conf" | awk '{print $1}')
current_hash=$(sha256sum "$server/app.conf" | awk '{print $1}')
```

If hashes differ, produce evidence:

```bash
diff -u "$baseline/app.conf" "$server/app.conf" || true
```

For ignored volatile lines, normalize both files first:

```bash
normalize() {
  sed -E '/^[[:space:]]*#/d; /generated_at[[:space:]]*=/d' "$1"
}
```

Then compare normalized streams or temporary normalized files.

## Key design point

Do not jump straight to “overwrite current config”. A drift detector should be read-only. Its job is to establish evidence and an actionable plan.

## Production improvements

Define a well-versioned normalization policy, distinguish missing/extra/content-drift states, and use deterministic output. If configs contain secrets, ensure reports do not print secret values.
