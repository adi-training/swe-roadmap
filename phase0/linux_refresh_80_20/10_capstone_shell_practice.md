# Chapter 10 — Linux & Bash Capstone Practice Set

**Time:** ~60 minutes  
**Goal:** Combine commands and shell scripting without being told which individual feature to use.

Before each problem, decide whether the simplest solution is:

- one command
- a pipeline
- a small shell loop
- a reusable function
- a complete script

---

# Level 1 — Command-line drills

## E1. Largest files

Find the five largest regular files below `~/linux-lab` and display their sizes.

## E2. Error lines

Find all `.log` files below `~/linux-lab` and print only lines containing `ERROR`, including filenames.

## E3. Country frequency

For a CSV file `people.csv`, print countries ordered by frequency.

## E4. Disk summary

Print filesystem usage and the size of each immediate subdirectory in `~/linux-lab`.

# Level 2 — Small scripts

## E5. File extension counter

Write a script that counts file extensions below a given directory.

## E6. Duplicate lines

Write a script that prints duplicate lines from a text file, along with counts.

## E7. Rename `.txt` to `.bak`

Write a script that renames `.txt` files in a chosen directory to `.bak`, with a dry-run option.

## E8. Recent files

Print regular files modified within the last 24 hours below a directory.

# Level 3 — Robust shell scripting

## E9. Backup utility

Accept `-s SOURCE -d DEST` and create a timestamped `.tar.gz` archive. Validate both directories and use cleanup/error handling.

## E10. Log summary utility

Accept a log file and print line count, INFO/WARNING/ERROR counts, and the top five words. Return useful non-zero status on bad input.

## E11. Process watchdog

Accept a process name and check whether it is running. Print a useful message and return success when it exists, failure otherwise.

## E12. Batch processor

Accept a directory. For every `.txt` file, create a `.wordcount` file containing the number of words. Handle filenames safely.

# Level 4 — Final mini-project

## E13. Project health checker

Create `healthcheck.sh` that reports:

- current user and hostname
- current time
- filesystem usage for `/`
- available memory
- whether a chosen service/process exists
- number of `.log` files below a directory
- top five largest files below that directory

Requirements:

- Bash
- functions
- `set -euo pipefail`
- argument validation
- clean output
- meaningful exit status
- no parsing `ls`
- quoted variable expansions

---

# Final shell-scripting checklist

You should now be comfortable with:

```text
command execution
exit status
stdin/stdout/stderr
pipes and redirection
quoting
variables
arguments
if / case
for / while / until
functions
arrays
associative arrays
command substitution
find / grep / sed / awk
sort / uniq / cut / xargs
getopts
mktemp
trap
set -euo pipefail
bash -n / bash -x
ShellCheck
```

The biggest next step is not more Bash syntax. It is writing small scripts repeatedly and learning to debug them from the shell's actual behavior.

