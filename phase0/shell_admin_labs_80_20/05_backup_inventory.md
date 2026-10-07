# Lab 05 — Backup Inventory & Verification

## Scenario

An administrator receives backup files from several systems. They need a daily inventory showing what exists, what is stale, whether checksums match a manifest, and which expected backups are missing.

You will simulate the repository locally.

## Learning goals

- manifests and checksums
- comparing expected vs actual state
- file metadata
- robust iteration
- report generation
- exit codes for operational checks

## Input model

Create:

```text
repository/
  app1/backup-YYYY-MM-DD.tar.gz
  app2/backup-YYYY-MM-DD.tar.gz
  db1/backup-YYYY-MM-DD.tar.gz
manifest.sha256
expected.csv
```

Example expected CSV:

```text
system,latest_allowed_date,required
app1,2026-10-05,yes
app2,2026-10-05,yes
db1,2026-10-05,yes
legacy,2026-10-01,no
```

## Requirements

Build `backupcheck.sh` to report:

- latest backup per system;
- missing required systems;
- stale backups;
- checksum mismatches;
- unexpected backup files;
- total bytes represented by current backups.

Return non-zero when required backups are missing, stale, or corrupted.

## Hints

Separate these stages:

1. discover files;
2. normalize names into fields;
3. compare against expected inventory;
4. verify checksums;
5. generate report;
6. determine final exit status.

Do not assume filesystem ordering.

## Testing

Deliberately:

- remove one required backup;
- modify a file after creating its checksum;
- introduce an unexpected file;
- create an old backup;
- add a malformed filename.

## Improvement challenge

Add a `--repair-report` mode that generates a prioritized action list without changing any files.

## Explain

Explain the difference between “file exists”, “backup is current”, and “backup is trustworthy”.
