# Lab 01 — Folder Housekeeper

## Scenario

A development team drops temporary artifacts into a shared workspace every day. The folder contains build outputs, old reports, editor backups, zero-byte leftovers, and files that should be archived rather than deleted.

You need to build a **safe housekeeping tool** that can scan the workspace, classify files, show what it intends to do, and optionally perform the cleanup.

## Learning goals

- advanced `find` usage
- filename safety
- timestamps and file sizes
- Bash functions and arrays
- dry-run design
- archive/move workflows
- structured logging
- safe deletion

## Lab data

Create a directory such as:

```text
lab01/
  workspace/
    build/
    reports/
    tmp/
    source/
```

Create files with different ages, sizes, and names containing spaces.

Suggested categories:

- `*.tmp`, `*.bak`, `*.swp` → temporary candidates
- reports older than a configurable number of days → archive candidates
- zero-byte files → inspect candidates
- source files → never touch automatically

## Requirements

Build `housekeeper.sh` with these modes:

```text
housekeeper.sh --root DIR --dry-run
housekeeper.sh --root DIR --apply
housekeeper.sh --root DIR --apply --archive DIR
```

The script should:

1. validate the root directory;
2. print a summary before making changes;
3. support configurable age thresholds;
4. move archive candidates to an archive directory;
5. delete only files explicitly classified as safe-to-delete;
6. never follow symlinks unexpectedly;
7. handle spaces/newlines in ordinary filenames as safely as practical;
8. write a log of every action;
9. return a non-zero status on invalid arguments or operational errors;
10. make a dry run produce no filesystem changes.

## Think before coding

Decide:

- What makes a file “safe to delete”?
- What makes a file “archive” rather than “delete”?
- Should classification use extension, age, directory, or a combination?
- How will you avoid treating a filename as multiple shell words?
- What should happen if one file fails while others succeed?

## Hints

**Hint 1:** Start with classification only. Print `DELETE`, `ARCHIVE`, or `KEEP` for every file.

**Hint 2:** Use `find` expressions carefully and consider `-print0` when filenames can contain whitespace.

**Hint 3:** A dry run should share the same decision logic as apply mode; only the final action changes.

**Hint 4:** Separate functions such as `validate_args`, `classify_file`, `archive_file`, `delete_file`, `write_log` make the script easier to test.

## Test plan

Test at least:

- empty directory
- old and new files
- files with spaces
- files beginning with `-`
- zero-byte files
- symlink to a file
- missing archive directory
- read-only file
- dry-run followed by a directory listing
- second `--apply` run to test idempotence

## Improvement challenge

Add a `--report FILE` option that writes a machine-readable CSV containing:

```text
path,category,size_bytes,mtime,action
```

Then add summary totals by category.

## Explain your solution

Be prepared to explain why your solution is safe, how it behaves on partial failure, and which assumptions are specific to the lab rather than a production environment.
