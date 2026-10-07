# Chapter 5 — Strings and File Handling

**Time:** ~55 minutes  
**Goal:** Get comfortable with string manipulation and the file operations commonly used in scripts and data-processing tasks.

---

## 1. Strings are sequences

```python
s = "hello"
print(s[0])
print(s[-1])
print(s[1:4])
```

Strings are immutable. Operations create new strings rather than modifying the original character-by-character.

## 2. Useful string methods

```python
s.lower()
s.upper()
s.strip()
s.split()
s.replace("old", "new")
s.startswith("pre")
s.endswith(".txt")
```

Join pieces with:

```python
"-".join(["2026", "10", "07"])
```

## 3. Character classification

```python
ch.isdigit()
ch.isalpha()
ch.isspace()
```

## 4. File reading

Prefer `with`, which closes the file automatically:

```python
with open("data.txt", "r", encoding="utf-8") as f:
    text = f.read()
```

Read line-by-line when appropriate:

```python
with open("data.txt", encoding="utf-8") as f:
    for line in f:
        print(line.strip())
```

## 5. Writing

```python
with open("out.txt", "w", encoding="utf-8") as f:
    f.write("hello\n")
```

Append with mode `"a"`.

## 6. Paths

For scripts that manipulate files, `pathlib` is usually easier than manually joining path strings:

```python
from pathlib import Path

path = Path("data") / "input.txt"
print(path.exists())
```

---

# Hands-on Exercises

## E1. Count vowels and consonants

Given a sentence, count alphabetic vowels and consonants.

## E2. Normalize spaces

Turn a sentence containing repeated spaces into one with single spaces between words.

## E3. Palindrome

Check whether a string is a palindrome ignoring case and spaces.

## E4. Word count

Count the number of words in a sentence.

## E5. Longest word

Find the longest word in a sentence.

## E6. Character frequency

Build a frequency dictionary for characters, ignoring spaces.

## E7. Write numbers to a file

Write integers 1 through 100 to `numbers.txt`, one per line.

## E8. Sum numbers from a file

Read `numbers.txt` and print the sum.

## E9. Count log levels

Given a text file where each line contains a log message, count how many lines contain `INFO`, `WARNING`, and `ERROR`.

## E10. Copy non-empty lines

Read one text file and write only non-empty, stripped lines to another file.

