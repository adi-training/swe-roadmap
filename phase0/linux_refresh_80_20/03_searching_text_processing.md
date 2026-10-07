# Chapter 3 — Searching and Text Processing

**Time:** ~60 minutes  
**Goal:** Learn the command-line tools that make Linux powerful: `grep`, `find`, `head`, `tail`, `sort`, `uniq`, `cut`, `sed`, and `awk`.

---

## 1. Create predictable test data

```bash
cat > people.txt <<'EOF'
Maya,India,85
John,UK,72
Asha,India,91
Ravi,India,85
Lena,Germany,78
EOF
```

A here-document starts after `<<EOF` and ends at a line containing `EOF`.

## 2. Inspecting files

```bash
cat people.txt
less people.txt
head people.txt
head -n 2 people.txt
tail -n 2 people.txt
wc people.txt
wc -l people.txt
```

## 3. `grep`

```bash
grep 'India' people.txt
grep -i 'india' people.txt
grep -n 'India' people.txt
grep -v 'India' people.txt
```

Useful options:

```text
-i ignore case
-n show line number
-v invert match
-c count matching lines
-r recursive search
```

## 4. `find`

```bash
find . -name '*.txt'
find . -type f
find . -type d
find . -type f -size +1M
```

Run another command carefully with `-exec`:

```bash
find . -type f -name '*.log' -exec wc -l {} +
```

## 5. Pipes

The pipe sends standard output of one command to standard input of another:

```bash
cat people.txt | grep India
```

Often the first `cat` is unnecessary:

```bash
grep India people.txt
```

A more useful pipeline:

```bash
cut -d, -f2 people.txt | sort | uniq -c
```

## 6. `cut`

```bash
cut -d, -f1 people.txt
cut -d, -f1,3 people.txt
```

## 7. `sort` and `uniq`

`uniq` works on adjacent duplicates, so sorting is commonly paired with it:

```bash
cut -d, -f2 people.txt | sort | uniq -c
```

## 8. `sed`

Replace text:

```bash
sed 's/India/IN/g' people.txt
```

Delete blank lines:

```bash
sed '/^$/d' file.txt
```

By default `sed` prints transformed output without changing the original file.

## 9. `awk`

`awk` is excellent for field-based text processing:

```bash
awk -F, '{print $1, $3}' people.txt
awk -F, '$2 == "India" {print $1}' people.txt
```

`$1`, `$2`, etc. refer to fields; `$0` is the whole line.

## 10. Redirection

```bash
command > output.txt
command >> output.txt
command < input.txt
command 2> errors.txt
command >out.txt 2>err.txt
command >all.txt 2>&1
```

`>` replaces; `>>` appends.

---

# Hands-on Exercises

## E1. Search for a name

Use `grep` to find lines containing `Ravi` in `people.txt`.

## E2. Ignore case

Search for `india` regardless of case and show line numbers.

## E3. Count lines

Use `wc` to print the number of lines in `people.txt`.

## E4. List source files

Use `find` to list all `.sh` files under the current directory.

## E5. Count countries

Use `cut`, `sort`, and `uniq -c` to count each country.

## E6. Extract names

Use `cut` to print only names.

## E7. Filter and transform

Use `awk` to print names of people from India with their score.

## E8. Replace text without changing the file

Use `sed` to display `India` as `IN` without editing `people.txt`.

## E9. Pipeline practice

Build a pipeline that extracts the third CSV field, sorts it numerically, and shows the smallest five values.

## E10. Error redirection

Run a command that fails and redirect its error output to `errors.txt`.

## E11. Recursive search

Find all `.log` files below `~/linux-lab` that contain the word `ERROR`.

## E12. Word-frequency pipeline

Starting with a text file, build a pipeline that produces the most frequent words, one per line with counts.

