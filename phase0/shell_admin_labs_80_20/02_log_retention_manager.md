# Lab 02 — Log Retention & Compression Manager

## Scenario

A small service writes daily application logs. Disk usage is growing because historical logs are kept forever. Operations wants a retention policy:

- recent logs remain as plain text;
- older logs are compressed;
- very old logs are removed;
- actions are auditable.

## Learning goals

- retention policies
- `find` with timestamps
- `gzip`/`gunzip` and archives
- rotation logic
- safe deletion
- dry-run and audit logging
- handling partially processed data

## Sample layout

```text
logs/
  app-2026-09-20.log
  app-2026-09-21.log
  app-2026-09-22.log
  app-2026-09-23.log
  app-2026-09-24.log.gz
```

Populate a lab directory with dates spanning at least 30 days. Include malformed names and an unrelated file.

## Requirements

Implement:

```text
logretention.sh --log-dir DIR --compress-after N --delete-after N --dry-run
logretention.sh --log-dir DIR --compress-after N --delete-after N --apply
```

Rules:

- files younger than `compress-after` days remain plain;
- eligible plain logs are compressed;
- compressed logs older than `delete-after` days are removed;
- unrelated files are ignored;
- already compressed logs must not be compressed again;
- malformed filenames must not be deleted accidentally;
- all changes must be logged;
- dry-run must have no side effects.

## Design questions

Should age be determined from filesystem modification time or the date encoded in the filename? What are the operational pros and cons of each?

Use one consistent policy for the lab and document your choice.

## Hints

- First build a parser that recognizes valid log filenames.
- Treat “recognition” and “action” as separate steps.
- You may use Bash regex matching for the filename format.
- Test compression separately from deletion.

## Testing

Include:

- logs exactly on the threshold
- logs just below/above the threshold
- already compressed logs
- malformed log names
- empty logs
- permission failure
- repeated execution

## Improvement challenge

Add a `--summary` mode reporting:

- count/size of plain logs
- count/size of compressed logs
- count/size eligible for deletion
- estimated space to be reclaimed

## Explain

Explain why the retention rule is safer when it is narrow and explicit instead of “delete everything older than X”.
