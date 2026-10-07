# Linux Commands & Shell Scripting 80:20 Refresh — Hands-On Roadmap

## Goal

This is an **8–10 hour beginner-friendly Linux and Bash refresher** aimed at practical development, debugging, DevOps foundations, and DSA/Linux training environments.

The command-line portion concentrates on the commands you will use constantly. The shell-scripting portion goes deeper because scripting becomes much easier once you understand how the shell actually handles commands, variables, quoting, exit codes, pipes, redirection, functions, and arguments.

### Command-line 80:20

- navigation and filesystem commands
- files, directories, permissions and ownership
- searching and text processing
- processes and jobs
- disk, memory, environment, and system information
- archives, compression, SSH, and common networking checks

### Bash scripting — deeper coverage

- shell execution model
- quoting and expansion
- variables and environment variables
- positional parameters and `getopts`
- exit status and `set -euo pipefail`
- `if`, `case`, `for`, `while`, `until`
- functions and return status
- arrays and associative arrays
- command substitution
- pipes, redirection, `tee`, here-documents
- `grep`, `sed`, `awk`, `sort`, `uniq`, `cut`, `xargs`
- traps, temporary files, cleanup, and defensive scripting
- debugging and maintainable script structure

This is not a full Linux administration course. Topics such as kernel internals, systemd unit authoring, advanced networking, SELinux/AppArmor administration, kernel modules, and complex shell metaprogramming are intentionally postponed.

## How to use these files

For commands:

1. type the command yourself
2. run it on a safe directory such as `~/linux-lab`
3. inspect the output rather than memorizing it
4. combine two commands with a pipe

For shell scripting:

1. type each script instead of copy/paste-only learning
2. intentionally break it and read the error
3. inspect `$?` after commands
4. test empty input, spaces in filenames, and failure cases
5. quote variables by default unless you have a specific reason not to

Create a safe lab:

```bash
mkdir -p ~/linux-lab/{data,work,backup}
cd ~/linux-lab
```

## Suggested schedule

| Chapter | Topic | Time |
|---|---|---:|
| 1 | Navigation and filesystem | 40 min |
| 2 | Files, permissions and links | 45 min |
| 3 | Searching and text processing | 60 min |
| 4 | Processes, jobs and system information | 45 min |
| 5 | Archives, networking and SSH | 40 min |
| 6 | Bash fundamentals and execution model | 60 min |
| 7 | Bash variables, arguments, conditions, loops | 70 min |
| 8 | Bash functions, arrays, text tools and pipelines | 75 min |
| 9 | Defensive and maintainable shell scripting | 65 min |
| 10 | Shell capstone practice | 60 min |
| | **Total** | **~9.5 hours** |

## Safe practice rule

Do not experiment with destructive commands in `/`, `/etc`, `/usr`, `/var`, or another shared/project directory. Use `~/linux-lab` unless you explicitly know what a command will change.

---

# Command cheat sheet

```text
pwd                    current directory
ls -la                 detailed listing
cd DIR                 change directory
mkdir -p DIR           create directories
cp SRC DST             copy
mv SRC DST             move/rename
rm FILE                remove file
rm -r DIR              remove directory tree — use carefully
cat FILE               print a file
less FILE              inspect a file interactively
head / tail            first / last lines
wc                     line/word/byte counts
grep PATTERN FILE      search text
find PATH ...          search filesystem
sort                   sort lines
uniq -c                count adjacent duplicates
cut                    select columns/characters
sed                    stream editing
awk                    field-oriented text processing
ps                     process snapshot
top                    live process view
grep in ps output      quick process filtering
kill PID               request process termination
df -h                  filesystem space
du -sh DIR             directory size
chmod                   permissions
chown                   owner/group (usually admin task)
ssh user@host          remote shell
scp SRC user@host:     copy over SSH
tar                    archive/compress
```

