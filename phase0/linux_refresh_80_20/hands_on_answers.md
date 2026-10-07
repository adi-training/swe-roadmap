# Linux Commands & Shell Scripting 80:20 Refresh — Hands-On Answers

This is the answer key for Chapters 1–10.

The command examples are intended to be run in the safe lab directory created by the refresher:

```bash
mkdir -p ~/linux-lab/{data,work,backup}
cd ~/linux-lab
```

For Bash scripts, save the code to a `.sh` file, then check it with:

```bash
bash -n script.sh
```

Make it executable when needed:

```bash
chmod +x script.sh
```

Run with:

```bash
./script.sh
```

Where a command depends on a file or directory created in the exercise, adapt the path to your own lab.

---

# Chapter 1 — Navigation and Filesystem

## E1. Create a lab tree

```bash
mkdir -p ~/linux-lab/demo/{src,docs,logs}
```

## E2. Navigate

```bash
cd ~
cd ~/linux-lab/demo
pwd
cd -
pwd
cd -
pwd
```

## E3. Create files

```bash
touch ~/linux-lab/demo/src/main.sh
touch ~/linux-lab/demo/docs/readme.txt
touch ~/linux-lab/demo/logs/app.log
```

The accidental leading space before the second `touch` would be a typo when typing manually; use:

```bash
touch ~/linux-lab/demo/src/main.sh

touch ~/linux-lab/demo/docs/readme.txt

touch ~/linux-lab/demo/logs/app.log
```

## E4. Copy and rename

```bash
cd ~/linux-lab/demo
cp docs/readme.txt docs/readme.bak
mv src/main.sh src/run.sh
```

## E5. List hidden files

```bash
touch ~/linux-lab/demo/.config
ls -la ~/linux-lab/demo
```

## E6. Inspect file metadata

```bash
file ~/linux-lab/demo/docs/readme.txt
stat ~/linux-lab/demo/docs/readme.txt
```

## E7. Safe cleanup

```bash
rm ~/linux-lab/demo/logs/app.log
rmdir ~/linux-lab/demo/logs
```

`rmdir` is useful here because it refuses to delete a non-empty directory.

## E8. Find your home path

```bash
echo "$HOME"
pwd
```

---

# Chapter 2 — Permissions, Ownership and Links

## E1. Read permissions

```bash
ls -l ~/linux-lab/demo/src/run.sh
```

Read the first ten characters. For example:

```text
-rwxr-xr-x
```

means regular file; owner `rwx`; group `r-x`; others `r-x`.

## E2. Make a script executable

```bash
cat > ~/linux-lab/hello.sh <<'EOF'
#!/usr/bin/env bash
echo "Hello from Bash"
EOF

chmod +x ~/linux-lab/hello.sh
~/linux-lab/hello.sh
```

## E3. Numeric permissions

```bash
chmod 755 ~/linux-lab/hello.sh
ls -l ~/linux-lab/hello.sh
```

## E4. Symbolic permissions

```bash
touch ~/linux-lab/test.txt
chmod go-w ~/linux-lab/test.txt
ls -l ~/linux-lab/test.txt
```

## E5. Inspect ownership

```bash
stat ~/linux-lab/test.txt
```

## E6. Symbolic link

```bash
echo "original content" > ~/linux-lab/original.txt
ln -s ~/linux-lab/original.txt ~/linux-lab/link.txt
cat ~/linux-lab/link.txt
```

## E7. Link behavior

```bash
echo "updated content" > ~/linux-lab/original.txt
cat ~/linux-lab/link.txt
```

The link still points to the same original pathname, so it reads the updated data.

## E8. Executable search

```bash
which bash
command -v bash
```

`command -v` is generally a good shell-friendly choice because it also handles shell builtins and aliases/functions in appropriate shells.

---

# Chapter 3 — Searching and Text Processing

First create the sample CSV:

```bash
cd ~/linux-lab
cat > people.txt <<'EOF'
Maya,India,85
John,UK,72
Asha,India,91
Ravi,India,85
Lena,Germany,78
EOF
```

## E1. Search for a name

```bash
grep 'Ravi' people.txt
```

## E2. Ignore case

```bash
grep -in 'india' people.txt
```

## E3. Count lines

```bash
wc -l people.txt
```

## E4. List source files

```bash
find . -type f -name '*.sh'
```

## E5. Count countries

```bash
cut -d, -f2 people.txt | sort | uniq -c
```

## E6. Extract names

```bash
cut -d, -f1 people.txt
```

## E7. Filter and transform

```bash
awk -F, '$2 == "India" {print $1, $3}' people.txt
```

## E8. Replace text without changing the file

```bash
sed 's/India/IN/g' people.txt
```

## E9. Smallest five scores

```bash
cut -d, -f3 people.txt | sort -n | head -n 5
```

## E10. Error redirection

```bash
ls /definitely/not/a/real/path 2> errors.txt
cat errors.txt
```

## E11. Recursive search

```bash
find ~/linux-lab -type f -name '*.log' -exec grep -nH 'ERROR' {} +
```

`-H` keeps the filename in the output.

## E12. Word-frequency pipeline

For ordinary whitespace-separated text:

```bash
tr -cs '[:alnum:]' '\n' < input.txt | tr '[:upper:]' '[:lower:]' | sort | uniq -c | sort -nr
```

This treats sequences of non-alphanumeric characters as separators and then counts adjacent identical words after sorting.

---

# Chapter 4 — Processes, Jobs and System Information

## E1. Find your shell

```bash
printf 'SHELL=%s\n' "${SHELL-}"
printf '0=%s\n' "$0"
ps -p $$ -o pid,ppid,comm,args
```

## E2. Identify yourself

```bash
whoami
id
```

`whoami` focuses on the effective username; `id` shows UID, primary group, and supplementary groups.

## E3. Inspect current shell process

```bash
ps -p $$ -o pid,ppid,comm,args
```

The current shell's PID is available as `$$`.

## E4. Background job

```bash
sleep 60 &
jobs
```

## E5. Bring a job to foreground

```bash
fg
```

Then press `Ctrl-C` to terminate the foreground `sleep`.

## E6. Disk usage

```bash
df -h
du -sh ~/linux-lab
```

## E7. Memory

```bash
free -h
```

Look especially at the `total`, `used`, and `available` values.

## E8. Process search

```bash
pgrep -af bash
```

## E9. Exit status

```bash
true
echo "$?"
false
echo "$?"
```

Expected statuses are typically `0` and `1`.

## E10. Parent PID

```bash
ps -p $$ -o pid,ppid,comm,args
```

The `PPID` column is the parent process ID.

---

# Chapter 5 — Archives, Networking and SSH

## E1. Create an archive

```bash
tar -czf ~/linux-lab/demo.tar.gz -C ~/linux-lab demo
```

Using `-C` avoids storing a long absolute path in the archive.

## E2. Inspect an archive

```bash
tar -tzf ~/linux-lab/demo.tar.gz
```

## E3. Extract elsewhere

```bash
mkdir -p ~/linux-lab/restore
tar -xzf ~/linux-lab/demo.tar.gz -C ~/linux-lab/restore
```

## E4. HTTP headers

```bash
curl -I https://example.com
```

## E5. DNS

```bash
getent hosts example.com
```

## E6. Local SSH configuration

```bash
ssh -G localhost | head
```

This prints effective configuration after SSH processes its configuration files; it does not open the connection.

## E7. PATH lookup

```bash
command -v bash
command -v ls
command -v python3
```

## E8. Dated backup command

A practical simple form is:

```bash
tar -czf "$HOME/linux-lab/data-$(date +%Y%m%d-%H%M%S).tar.gz" -C "$HOME/linux-lab" data
```

---

# Chapter 6 — Bash Fundamentals and Execution Model

## E1. Hello script

`hello.sh`:

```bash
#!/usr/bin/env bash
printf '%s\n' 'line one'
printf '%s\n' 'line two'
printf '%s\n' 'line three'
```

Run:

```bash
bash hello.sh
chmod +x hello.sh
./hello.sh
```

## E2. Variable assignment

```bash
name='Maya'
city='Bengaluru'
printf 'My name is %s and I live in %s.\n' "$name" "$city"
```

## E3. Quoting experiment

```bash
name='Maya Rao'
printf 'double quotes: %s\n' "$name"
printf 'single quotes: %s\n' '$name'
```

The first expands `name`; the second prints the literal characters `$name`.

## E4. Exit status

```bash
true
echo "status=$?"
false
echo "status=$?"
```

## E5. `&&` and `||`

For a simple safe example:

```bash
mkdir -p output && echo 'success' || echo 'failed'
```

Note that `mkdir -p` succeeds if the directory already exists, so this is idempotent.

## E6. Redirection

```bash
printf 'normal output\n' > out.txt
ls /no/such/path 2> errors.txt
```

## E7. Command substitution

```bash
today="$(date)"
printf 'Today is %s\n' "$today"
```

## E8. Count files

```bash
file_count="$(find . -type f | wc -l)"
printf 'Regular files: %s\n' "$file_count"
```

## E9. Positional arguments

```bash
#!/usr/bin/env bash
printf 'script=%s\n' "$0"
printf 'count=%s\n' "$#"

for arg in "$@"; do
    printf 'arg=<%s>\n' "$arg"
done
```

## E10. Preserve spaces

```bash
#!/usr/bin/env bash
value='hello world from bash'
printf '<%s>\n' "$value"
```

The quotes around `"$value"` preserve it as one argument.

---

# Chapter 7 — Variables, Arguments, Conditions and Loops

## E1. Even numbers

```bash
for ((i = 1; i <= 20; i++)); do
    if (( i % 2 == 0 )); then
        printf '%d\n' "$i"
    fi
done
```

## E2. Positive/negative/zero

```bash
#!/usr/bin/env bash

if (( $# != 1 )); then
    printf 'Usage: %s NUMBER\n' "$0" >&2
    exit 2
fi

n=$1
if (( n > 0 )); then
    echo 'positive'
elif (( n < 0 )); then
    echo 'negative'
else
    echo 'zero'
fi
```

## E3. File checker

```bash
path=$1

if [[ -f "$path" ]]; then
    echo 'regular file'
elif [[ -d "$path" ]]; then
    echo 'directory'
elif [[ -e "$path" ]]; then
    echo 'other filesystem object'
else
    echo 'missing'
fi
```

## E4. Menu with `case`

```bash
case "${1-}" in
    start)  echo 'starting' ;;
    stop)   echo 'stopping' ;;
    status) echo 'status: demo' ;;
    *)
        echo "Usage: $0 {start|stop|status}" >&2
        exit 2
        ;;
esac
```

## E5. Count files

```bash
count=0
for file in ./*; do
    [[ -f "$file" ]] || continue
    ((count++))
done
printf '%d\n' "$count"
```

The existence/type checks also avoid treating directories as regular files.

## E6. Read file line by line

```bash
line_no=0
while IFS= read -r line || [[ -n "$line" ]]; do
    ((line_no++))
    printf '%d: %s\n' "$line_no" "$line"
done < input.txt
```

The `|| [[ -n "$line" ]]` handles a final line that does not end with a newline.

## E7. Sum command-line integers

```bash
sum=0
for arg in "$@"; do
    if ! [[ "$arg" =~ ^-?[0-9]+$ ]]; then
        printf 'Not an integer: %s\n' "$arg" >&2
        exit 2
    fi
    ((sum += arg))
done
printf '%d\n' "$sum"
```

## E8. Validate argument count

```bash
if (( $# != 1 )); then
    printf 'Usage: %s ARG\n' "$0" >&2
    exit 2
fi
printf 'argument=%s\n' "$1"
```

## E9. Directory batch operation

```bash
#!/usr/bin/env bash

if (( $# != 1 )) || [[ ! -d "$1" ]]; then
    printf 'Usage: %s DIRECTORY\n' "$0" >&2
    exit 2
fi

for file in "$1"/*.log; do
    [[ -f "$file" ]] || continue
    printf '%s\n' "$file"
done
```

## E10. `getopts` script

```bash
#!/usr/bin/env bash

name=''
verbose=0

while getopts ':n:v' opt; do
    case "$opt" in
        n) name=$OPTARG ;;
        v) verbose=1 ;;
        *)
            printf 'Usage: %s [-v] -n NAME\n' "$0" >&2
            exit 2
            ;;
    esac
done

printf 'name=%s\n' "$name"
printf 'verbose=%d\n' "$verbose"
```

## E11. Countdown

```bash
read -r -p 'n: ' n
while (( n >= 1 )); do
    printf '%d\n' "$n"
    ((n--))
done
```

## E12. Search loop

```bash
read -r -p 'Filename: ' file

if [[ ! -f "$file" ]]; then
    printf 'Not a file: %s\n' "$file" >&2
    exit 1
fi

while true; do
    read -r -p 'Pattern (quit to stop): ' pattern
    [[ "$pattern" == 'quit' ]] && break
    grep -n -- "$pattern" "$file" || true
done
```

---

# Chapter 8 — Functions, Arrays, Associative Arrays and Text Tools

## E1. Greeting function

```bash
greet() {
    local name=$1
    printf 'Hello, %s!\n' "$name"
}

greet 'Maya Rao'
```

## E2. Function return status

```bash
is_file() {
    [[ -f "$1" ]]
}

if is_file 'data.txt'; then
    echo 'regular file'
else
    echo 'not a regular file'
fi
```

## E3. Sum function

```bash
sum_numbers() {
    local total=0
    local x
    for x in "$@"; do
        ((total += x))
    done
    printf '%d\n' "$total"
}

sum_numbers 10 20 30
```

## E4. Indexed array

```bash
fruits=(apple banana mango orange grape)
printf 'length=%d\n' "${#fruits[@]}"

for fruit in "${fruits[@]}"; do
    printf '%s\n' "$fruit"
done
```

## E5. Reverse array

```bash
fruits=(apple banana mango orange grape)

for ((i = ${#fruits[@]} - 1; i >= 0; i--)); do
    printf '%s\n' "${fruits[i]}"
done
```

## E6. Associative frequency map

```bash
#!/usr/bin/env bash

declare -A freq

for word in "$@"; do
    ((freq["$word"]++))
done

for key in "${!freq[@]}"; do
    printf '%s %d\n' "$key" "${freq[$key]}"
done
```

Associative arrays require Bash; they are not POSIX `sh` features.

## E7. CSV average with `awk`

```bash
awk -F, 'NR > 1 {sum += $3; count++} END {if (count) printf "%.2f\n", sum / count}' people.csv
```

If the file has no header, remove `NR > 1`.

## E8. CSV filtering

```bash
awk -F, 'NR > 1 && $3 >= 80 {print $1}' people.csv
```

## E9. Pipeline frequency

For one word per line:

```bash
sort words.txt | uniq -c | sort -nr | head -n 10
```

## E10. `tee` practice

```bash
ps aux | tee processes.txt | grep '[p]ython'
```

The full `ps` output is saved while the filtered output is shown.

## E11. Here-document

```bash
cat > config.txt <<'EOF'
name=demo
mode=test
port=8080
EOF
```

## E12. Safe line processing

```bash
print_nonempty() {
    local file=$1
    local line

    while IFS= read -r line || [[ -n "$line" ]]; do
        [[ -n "$line" ]] || continue
        printf 'LINE: %s\n' "$line"
    done < "$file"
}

print_nonempty input.txt
```

---

# Chapter 9 — Defensive and Maintainable Shell Scripting

## E1. Safe file display

```bash
#!/usr/bin/env bash

if (( $# != 1 )); then
    printf 'Usage: %s FILE\n' "$0" >&2
    exit 2
fi

if [[ ! -f "$1" ]]; then
    printf 'Not a regular file: %s\n' "$1" >&2
    exit 1
fi

cat -- "$1"
```

## E2. Strict mode

```bash
#!/usr/bin/env bash
set -euo pipefail

printf 'before\n'
printf '%s\n' "$UNSET_VARIABLE"
printf 'after\n'
```

With `-u`, referencing the unset variable causes the script to fail before `after` is printed.

## E3. Pipefail demonstration

Without `pipefail`:

```bash
set +o pipefail
false | true
echo "$?"
```

The pipeline status is typically that of `true`, so it succeeds.

With `pipefail`:

```bash
set -o pipefail
false | true
echo "$?"
```

Now the failing `false` makes the pipeline fail.

## E4. Safe glob loop

```bash
for file in ./*.log; do
    [[ -e "$file" ]] || continue
    printf 'Processing: %s\n' "$file"
done
```

## E5. Temporary directory

```bash
tmpdir=$(mktemp -d)
cleanup() {
    rm -rf -- "$tmpdir"
}
trap cleanup EXIT

echo 'temporary data' > "$tmpdir/data.txt"
cat "$tmpdir/data.txt"
```

## E6. Cleanup on interruption

```bash
#!/usr/bin/env bash

set -euo pipefail

tmp=$(mktemp)
cleanup() {
    rm -f -- "$tmp"
    printf 'cleaned: %s\n' "$tmp"
}
trap cleanup EXIT INT TERM

echo 'temporary content' > "$tmp"
printf 'Temp file: %s\nPress Ctrl-C to interrupt.\n' "$tmp"
sleep 30
```

## E7. Argument validation

```bash
#!/usr/bin/env bash

if (( $# != 2 )); then
    printf 'Usage: %s ARG1 ARG2\n' "$0" >&2
    exit 2
fi

printf 'arg1=%s\narg2=%s\n' "$1" "$2"
```

## E8. Debug a script

Deliberately buggy:

```bash
#!/usr/bin/env bash
name='Maya'
if [[ "$name" == Maya ]; then
    echo "Hello $name"
# missing fi
```

Check syntax:

```bash
bash -n buggy.sh
```

Then trace:

```bash
bash -x buggy.sh
```

Add the missing `fi`, then run again.

## E9. Log analyzer

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# != 1 )); then
    printf 'Usage: %s LOGFILE\n' "$0" >&2
    exit 2
fi

file=$1
[[ -f "$file" ]] || {
    printf 'Not a regular file: %s\n' "$file" >&2
    exit 1
}

printf 'Lines: '
wc -l < "$file"
printf 'INFO: '
grep -c 'INFO' "$file" || true
printf 'WARNING: '
grep -c 'WARNING' "$file" || true
printf 'ERROR: '
grep -c 'ERROR' "$file" || true
```

## E10. Backup script

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# != 2 )); then
    printf 'Usage: %s SOURCE_DIR DEST_DIR\n' "$0" >&2
    exit 2
fi

source_dir=$1
dest_dir=$2

[[ -d "$source_dir" ]] || { printf 'Missing source: %s\n' "$source_dir" >&2; exit 1; }
mkdir -p -- "$dest_dir"

timestamp=$(date +%Y%m%d-%H%M%S)
base=$(basename -- "$source_dir")
archive="$dest_dir/$base-$timestamp.tar.gz"

parent=$(dirname -- "$source_dir")
tar -czf "$archive" -C "$parent" "$base"
printf 'Created: %s\n' "$archive"
```

## E11. ShellCheck cleanup

Unsafe example:

```bash
#!/usr/bin/env bash
file=$1
for x in $(cat $file); do
    echo $x
done
```

Problems include unquoted variables, unnecessary command substitution, and word splitting.

Safer rewrite:

```bash
#!/usr/bin/env bash
file=$1

while IFS= read -r x || [[ -n "$x" ]]; do
    printf '%s\n' "$x"
done < "$file"
```

Run:

```bash
shellcheck script.sh
```

## E12. Reusable script structure

```bash
#!/usr/bin/env bash
set -euo pipefail

usage() {
    printf 'Usage: %s DIRECTORY\n' "$0" >&2
}

log() {
    printf '[INFO] %s\n' "$*"
}

die() {
    printf '[ERROR] %s\n' "$*" >&2
    exit 1
}

main() {
    if (( $# != 1 )); then
        usage
        return 2
    fi

    local dir=$1
    [[ -d "$dir" ]] || die "not a directory: $dir"

    local count
    count=$(find "$dir" -type f | wc -l)
    log "regular files: $count"
}

main "$@"
```

This structure separates usage, logging, error handling, and the main task.

---

# Chapter 10 — Capstone Practice Set

## E1. Largest files

A compact solution:

```bash
find ~/linux-lab -type f -printf '%s\t%p\n' | sort -nr | head -n 5
```

`%s` prints size in bytes and `%p` prints the path. This form depends on GNU `find`, common on Linux.

## E2. Error lines

```bash
find ~/linux-lab -type f -name '*.log' -exec grep -nH 'ERROR' {} +
```

## E3. Country frequency

```bash
cut -d, -f2 people.csv | tail -n +2 | sort | uniq -c | sort -nr
```

The `tail -n +2` skips a header. Remove it if there is no header.

## E4. Disk summary

Filesystem usage:

```bash
df -h
```

Immediate child directories:

```bash
du -sh ~/linux-lab/*/ 2>/dev/null
```

## E5. File extension counter

For simple filenames with one extension:

```bash
#!/usr/bin/env bash
set -euo pipefail

dir=${1:?Usage: $0 DIRECTORY}

find "$dir" -type f -printf '%f\n' |
awk '
function ext(name, base,n,a) {
    n = split(name, a, ".")
    if (n == 1 || a[n] == "") return "[no extension]"
    return a[n]
}
{
    print ext($0)
}' |
sort | uniq -c | sort -nr
```

For production-grade extension parsing, think carefully about hidden files such as `.bashrc` and names with multiple dots.

## E6. Duplicate lines

```bash
sort input.txt | uniq -c | awk '$1 > 1'
```

For preserving exact original ordering, a Bash or Python solution may be more appropriate.

## E7. Rename `.txt` to `.bak` with dry run

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# < 1 || $# > 2 )); then
    printf 'Usage: %s DIRECTORY [--dry-run]\n' "$0" >&2
    exit 2
fi

dir=$1
dry_run=0
[[ ${2-} == --dry-run ]] && dry_run=1

for file in "$dir"/*.txt; do
    [[ -f "$file" ]] || continue
    new=${file%.txt}.bak

    if (( dry_run )); then
        printf 'would rename: %s -> %s\n' "$file" "$new"
    else
        mv -- "$file" "$new"
        printf 'renamed: %s -> %s\n' "$file" "$new"
    fi
done
```

## E8. Recent files

```bash
find "$1" -type f -mmin -1440 -print
```

This uses 1,440 minutes = 24 hours.

## E9. Backup utility with `getopts`

```bash
#!/usr/bin/env bash
set -euo pipefail

source=''
dest=''

usage() {
    printf 'Usage: %s -s SOURCE -d DEST\n' "$0" >&2
}

die() {
    printf 'Error: %s\n' "$*" >&2
    exit 1
}

while getopts ':s:d:' opt; do
    case "$opt" in
        s) source=$OPTARG ;;
        d) dest=$OPTARG ;;
        *) usage; exit 2 ;;
    esac
done

[[ -n "$source" && -n "$dest" ]] || { usage; exit 2; }
[[ -d "$source" ]] || die "source directory does not exist: $source"
mkdir -p -- "$dest"

timestamp=$(date +%Y%m%d-%H%M%S)
base=$(basename -- "$source")
parent=$(dirname -- "$source")
archive="$dest/$base-$timestamp.tar.gz"

tar -czf "$archive" -C "$parent" "$base"
printf 'Backup created: %s\n' "$archive"
```

## E10. Log summary utility

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# != 1 )); then
    printf 'Usage: %s LOGFILE\n' "$0" >&2
    exit 2
fi

file=$1
[[ -f "$file" ]] || { printf 'Not a file: %s\n' "$file" >&2; exit 1; }

printf 'Lines: '
wc -l < "$file"
printf 'INFO: '
grep -c 'INFO' "$file" || true
printf 'WARNING: '
grep -c 'WARNING' "$file" || true
printf 'ERROR: '
grep -c 'ERROR' "$file" || true

printf '\nTop words:\n'
tr -cs '[:alnum:]' '\n' < "$file" |
tr '[:upper:]' '[:lower:]' |
sort |
uniq -c |
sort -nr |
head -n 5
```

## E11. Process watchdog

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# != 1 )); then
    printf 'Usage: %s PROCESS_NAME\n' "$0" >&2
    exit 2
fi

if pgrep -x -- "$1" >/dev/null; then
    printf 'running: %s\n' "$1"
    exit 0
else
    printf 'not running: %s\n' "$1"
    exit 1
fi
```

Be aware that `pgrep -x` compares the process name, not the full command line. Use `pgrep -af` for broader matching when appropriate.

## E12. Batch word-count processor

```bash
#!/usr/bin/env bash
set -euo pipefail

if (( $# != 1 )) || [[ ! -d "$1" ]]; then
    printf 'Usage: %s DIRECTORY\n' "$0" >&2
    exit 2
fi

dir=$1

for file in "$dir"/*.txt; do
    [[ -f "$file" ]] || continue
    wc -w < "$file" > "$file.wordcount"
done
```

This uses a safe glob rather than parsing `ls`.

## E13. Project health checker

One complete beginner-friendly implementation:

```bash
#!/usr/bin/env bash
set -euo pipefail

usage() {
    printf 'Usage: %s DIRECTORY PROCESS_NAME\n' "$0" >&2
}

section() {
    printf '\n=== %s ===\n' "$1"
}

main() {
    if (( $# != 2 )); then
        usage
        return 2
    fi

    local dir=$1
    local process_name=$2

    [[ -d "$dir" ]] || {
        printf 'Not a directory: %s\n' "$dir" >&2
        return 1
    }

    section 'Identity'
    printf 'User: %s\n' "$(whoami)"
    printf 'Host: %s\n' "$(hostname)"
    printf 'Time: %s\n' "$(date)"

    section 'Filesystem'
    df -h /

    section 'Memory'
    free -h

    section 'Process'
    if pgrep -x -- "$process_name" >/dev/null; then
        printf 'Running: %s\n' "$process_name"
    else
        printf 'Not running: %s\n' "$process_name"
    fi

    section 'Log files'
    local log_count
    log_count=$(find "$dir" -type f -name '*.log' | wc -l)
    printf 'Log files: %s\n' "$log_count"

    section 'Largest files'
    find "$dir" -type f -printf '%s\t%p\n' |
        sort -nr |
        head -n 5
}

main "$@"
```

Run it, for example:

```bash
chmod +x healthcheck.sh
./healthcheck.sh ~/linux-lab bash
```

Notice the script uses functions, strict mode, quoted variables, validation, no `ls` parsing, and meaningful return statuses.

---

# What to retain after the refresher

The high-value Linux knowledge is the combination of a small command set with a correct shell mental model:

```text
pwd / cd / ls
cp / mv / rm / mkdir
cat / less / head / tail / wc
grep / find / sort / uniq / cut / sed / awk
ps / pgrep / kill / jobs / fg / bg
df / du / free
ssh / scp / curl / tar

Bash:
variables
quoting
exit status
stdin/stdout/stderr
pipes
redirection
command substitution
arguments
if / case
for / while
functions
arrays
getopts
mktemp / trap
set -euo pipefail
bash -n / bash -x
ShellCheck
```

The most important shell habit is simple: **slow down when you are writing a script, quote your data, check assumptions, and inspect exit statuses.**

