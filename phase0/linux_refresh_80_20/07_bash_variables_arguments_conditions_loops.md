# Chapter 7 — Bash Variables, Arguments, Conditions and Loops

**Time:** ~70 minutes  
**Goal:** Build real shell scripts using branching, iteration, input parameters, and robust tests.

---

## 1. Arithmetic

For arithmetic, use `$((...))`:

```bash
a=10
b=3
sum=$((a + b))
echo "$sum"
```

Do not write spaces into assignment:

```bash
sum=$((a + b))
```

## 2. Test expressions

Use `[[ ... ]]` for modern Bash scripts:

```bash
if [[ "$count" -gt 10 ]]; then
    echo "large"
fi
```

String comparisons:

```bash
[[ "$a" == "$b" ]]
[[ -z "$a" ]]
[[ -n "$a" ]]
```

File tests:

```bash
[[ -f "$path" ]]
[[ -d "$path" ]]
[[ -r "$path" ]]
[[ -w "$path" ]]
[[ -x "$path" ]]
```

For numeric tests:

```text
-eq -ne -lt -le -gt -ge
```

## 3. `if`

```bash
if [[ -f "$file" ]]; then
    echo "file exists"
elif [[ -d "$file" ]]; then
    echo "directory exists"
else
    echo "not found"
fi
```

## 4. `case`

Great for command choices:

```bash
case "$1" in
    start) echo "starting" ;;
    stop)  echo "stopping" ;;
    *)     echo "usage: $0 {start|stop}"; exit 2 ;;
esac
```

## 5. `for`

List values:

```bash
for name in Maya Ravi Asha; do
    echo "$name"
done
```

C-style loop:

```bash
for ((i = 1; i <= 5; i++)); do
    echo "$i"
done
```

Files:

```bash
for file in ./*.txt; do
    [[ -e "$file" ]] || continue
    echo "$file"
done
```

The existence check handles the case where no matching file exists.

## 6. `while`

```bash
n=1
while (( n <= 5 )); do
    echo "$n"
    ((n++))
done
```

Read lines safely:

```bash
while IFS= read -r line; do
    printf '%s\n' "$line"
done < file.txt
```

## 7. `until`

Runs until a condition becomes true:

```bash
count=1
until (( count > 3 )); do
    echo "$count"
    ((count++))
done
```

## 8. `break` and `continue`

```bash
for ((i=1; i<=10; i++)); do
    ((i == 3)) && continue
    ((i == 8)) && break
    echo "$i"
done
```

## 9. Reading input

```bash
read -r -p "Name: " name
printf 'Hello, %s\n' "$name"
```

For passwords:

```bash
read -r -s -p "Password: " password
printf '\n'
```

## 10. Positional arguments and `$@`

Always quote `"$@"` when forwarding arguments:

```bash
for arg in "$@"; do
    printf '<%s>\n' "$arg"
done
```

`"$@"` preserves each argument as a separate argument.

## 11. Optional arguments with `getopts`

```bash
while getopts ':n:v' opt; do
    case "$opt" in
        n) name=$OPTARG ;;
        v) verbose=1 ;;
        *) exit 2 ;;
    esac
done
```

This is preferable to manually parsing every flag in a larger script.

---

# Hands-on Exercises

## E1. Even numbers

Write a loop that prints even numbers from 1 to 20 using Bash arithmetic.

## E2. Positive/negative/zero

Accept one number and classify it using `if`.

## E3. File checker

Accept a path and report whether it is a regular file, directory, or missing.

## E4. Menu with `case`

Accept `start`, `stop`, `status`, or anything else and print an appropriate response.

## E5. Count files

Count regular files in the current directory using a loop.

## E6. Read file line by line

Read a file with `while IFS= read -r` and prefix every line with its line number.

## E7. Sum command-line integers

Write a script that sums all integer arguments.

## E8. Validate argument count

Require exactly one argument and print a usage message with exit code 2 if it is missing or extra.

## E9. Directory batch operation

Accept a directory and print the names of all `.log` files in it.

## E10. `getopts` script

Create a script supporting `-n NAME` and `-v` and print the parsed values.

## E11. Countdown

Read `n` and count down to 1 using `while`.

## E12. Search loop

Read a filename and a search pattern, then repeatedly ask for another pattern until the user types `quit`.

