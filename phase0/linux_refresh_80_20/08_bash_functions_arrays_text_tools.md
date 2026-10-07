# Chapter 8 — Bash Functions, Arrays, Associative Arrays, Pipelines and Text Tools

**Time:** ~75 minutes  
**Goal:** Move from one-off scripts to reusable shell programs.

---

## 1. Functions

Basic syntax:

```bash
greet() {
    local name=$1
    printf 'Hello, %s\n' "$name"
}

greet "Maya"
```

Use `local` for function-local variables to avoid accidental changes to globals.

## 2. Return status from functions

A function's exit status is the status of its last command unless you use `return`.

```bash
is_even() {
    (( $1 % 2 == 0 ))
}

if is_even 8; then
    echo "even"
fi
```

The function communicates success/failure through its exit status.

## 3. Arrays

Indexed array:

```bash
nums=(10 20 30)
printf '%s\n' "${nums[0]}"
printf '%s\n' "${#nums[@]}"
```

Append:

```bash
nums+=(40)
```

Loop safely:

```bash
for x in "${nums[@]}"; do
    echo "$x"
done
```

## 4. Associative arrays

Useful for dictionaries/maps:

```bash
declare -A freq
freq[apple]=2
freq[banana]=5

echo "${freq[banana]}"
```

Keys:

```bash
for key in "${!freq[@]}"; do
    printf '%s %s\n' "$key" "${freq[$key]}"
done
```

## 5. Pipeline composition

A typical analysis pipeline:

```bash
cut -d, -f2 data.csv | sort | uniq -c | sort -nr
```

Each command does one job.

## 6. `awk`

Examples:

```bash
awk -F, '{sum += $3} END {print sum}' people.csv
awk -F, '$3 >= 80 {print $1, $3}' people.csv
```

## 7. `sed`

Examples:

```bash
sed 's/[[:space:]]\+/ /g' file.txt
sed -n '1,5p' file.txt
```

## 8. `xargs`

`xargs` turns input into command arguments.

```bash
printf '%s\n' a b c | xargs -n1 echo item:
```

For filenames containing newlines or unusual characters, prefer null-delimited workflows where supported:

```bash
find . -type f -print0 | xargs -0 ...
```

## 9. `tee`

See output and save it at the same time:

```bash
command | tee output.txt
```

Append with:

```bash
command | tee -a output.txt
```

## 10. Here-documents

Useful for generating multi-line text:

```bash
cat > config.txt <<'EOF'
name=demo
mode=test
EOF
```

Quote the delimiter (`'EOF'`) when you do not want parameter/command expansion inside the document.

---

# Hands-on Exercises

## E1. Greeting function

Write a function accepting a name and printing a greeting.

## E2. Function return status

Write `is_file` that succeeds when its argument is a regular file.

## E3. Sum function

Write a function that adds all numeric arguments and prints the result.

## E4. Indexed array

Create an array of five fruits, print its length, then print every element.

## E5. Reverse array

Print an indexed array in reverse order without modifying it.

## E6. Associative frequency map

Read words from command-line arguments and build a Bash associative-array frequency map.

## E7. CSV summary with `awk`

Given `people.csv` with `name,country,score`, print the average score.

## E8. CSV filtering

Print names of rows where score is at least 80.

## E9. Pipeline frequency

Given a file of one word per line, print the 10 most frequent words.

## E10. `tee` practice

Run a pipeline whose output is both displayed and written to a file.

## E11. Generate a file with a here-document

Create a small configuration file with three key/value lines.

## E12. Safe line processing

Write a function that receives a filename and prints every non-empty line prefixed with `LINE:` while preserving spaces.

