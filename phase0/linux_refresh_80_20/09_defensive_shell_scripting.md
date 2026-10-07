# Chapter 9 — Defensive and Maintainable Shell Scripting

**Time:** ~65 minutes  
**Goal:** Learn the habits that turn fragile shell snippets into scripts you can trust.

---

## 1. Start with a clear script structure

A useful template:

```bash
#!/usr/bin/env bash
set -euo pipefail

usage() {
    printf 'Usage: %s FILE\n' "$0" >&2
}

main() {
    ...
}

main "$@"
```

## 2. `set -euo pipefail`

These options are common in robust Bash scripts:

```bash
set -euo pipefail
```

- `-e`: exit when a simple command fails, subject to Bash's rules and exceptions.
- `-u`: treat unset variables as errors.
- `pipefail`: make a pipeline fail if an earlier command fails rather than reporting only the final command's status.

These options improve safety, but they do not make a script bug-proof. Understand the commands you run.

## 3. Quote variables

Fragile:

```bash
rm $file
```

Safer:

```bash
rm -- "$file"
```

The `--` tells many commands that following arguments are data rather than options.

## 4. Never parse `ls`

Do not write:

```bash
for file in $(ls)
```

This breaks on spaces, newlines, and special characters.

Prefer shell globbing:

```bash
for file in ./*.txt; do
    [[ -e "$file" ]] || continue
    ...
done
```

Or `find` with a suitable action when recursion is required.

## 5. `read -r`

When reading lines:

```bash
while IFS= read -r line; do
    printf '%s\n' "$line"
done < file.txt
```

`-r` prevents backslashes from being treated as escapes by `read`.

## 6. Traps and cleanup

Temporary files should be cleaned even when a script is interrupted.

```bash
tmp=$(mktemp)
cleanup() {
    rm -f -- "$tmp"
}
trap cleanup EXIT INT TERM
```

`EXIT` runs when the shell exits. `INT` and `TERM` handle common interruption/termination signals.

## 7. Temporary directories

```bash
tmpdir=$(mktemp -d)
trap 'rm -rf -- "$tmpdir"' EXIT
```

This is safer than inventing temporary filenames such as `/tmp/data.$$`.

## 8. Debugging

Run Bash with tracing:

```bash
bash -x script.sh
```

Inside a script, temporarily enable tracing:

```bash
set -x
...
set +x
```

Check shell syntax without running the script:

```bash
bash -n script.sh
```

## 9. ShellCheck

When available, ShellCheck is one of the best beginner tools for finding Bash mistakes:

```bash
shellcheck script.sh
```

Treat warnings as learning opportunities. Do not silence a warning before understanding why it appeared.

## 10. Validate assumptions early

```bash
if [[ $# -ne 1 ]]; then
    printf 'Usage: %s FILE\n' "$0" >&2
    exit 2
fi

file=$1
if [[ ! -f "$file" ]]; then
    printf 'Error: not a regular file: %s\n' "$file" >&2
    exit 1
fi
```

Fail early with a useful message.

## 11. Avoid unnecessary `cat`

Instead of:

```bash
cat file.txt | grep ERROR
```

use:

```bash
grep ERROR file.txt
```

A pipeline is appropriate when the previous command transforms the data.

## 12. Use `printf` for stable output

```bash
printf 'Count: %d\n' "$count"
printf 'File: %s\n' "$file"
```

## 13. Think about exit codes as an API

Scripts can be composed when their exit status has a clear meaning:

```text
0  success
1  expected/general failure
2  usage error is a common convention
```

The exact non-zero values are a design choice unless a tool defines specific semantics.

---

# Hands-on Exercises

## E1. Safe file display

Write a script that accepts a filename, validates it, and prints it with `cat --` or another safe command form.

## E2. Strict mode

Create a script with `set -euo pipefail`, then intentionally reference an unset variable and observe the failure.

## E3. Pipefail demonstration

Construct a pipeline where an early command fails but a later command succeeds. Compare behavior with and without `pipefail`.

## E4. Safe glob loop

Process all `.log` files in the current directory using a glob and an existence check.

## E5. Temporary directory

Create a temporary directory with `mktemp -d`, write a file into it, and clean it with an `EXIT` trap.

## E6. Cleanup on interruption

Create a script that sleeps for a while after creating a temp file, then handle `Ctrl-C` so cleanup happens.

## E7. Argument validation

Write a script requiring exactly two arguments and return exit status 2 for incorrect usage.

## E8. Debug a script

Write a deliberately buggy script, run `bash -n`, then `bash -x`, and fix it.

## E9. Log analyzer

Write a script that accepts a log file and prints counts of `INFO`, `WARNING`, and `ERROR` lines. Validate the input first.

## E10. Backup script

Write a safe script that accepts a source directory and creates a dated `.tar.gz` backup in a destination directory.

## E11. ShellCheck cleanup

Write one unsafe script containing at least three common quoting/word-splitting mistakes, run ShellCheck, and fix them.

## E12. Reusable script structure

Create a script with `usage`, `log`, `die`, `main`, and `main "$@"`, then implement a small real task using that structure.

