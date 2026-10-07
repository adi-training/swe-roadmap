# Chapter 6 — Bash Fundamentals and the Shell Execution Model

**Time:** ~60 minutes  
**Goal:** Understand what Bash is doing when it reads and executes a command. This mental model prevents many beginner shell bugs.

---

## 1. Shell vs terminal

The terminal is the interface. Bash is a shell program running inside it.

When you type:

```bash
ls -l *.txt
```

Bash parses the command, performs expansions such as wildcard expansion, then runs the resulting command.

## 2. Shebang and execution

Create:

```bash
#!/usr/bin/env bash

echo "Hello"
```

Save as `hello.sh` and run either:

```bash
bash hello.sh
```

or, after making it executable:

```bash
chmod +x hello.sh
./hello.sh
```

These are not identical. `bash hello.sh` explicitly asks Bash to interpret the file. `./hello.sh` asks the OS to execute the file and relies on its shebang and execute permission.

## 3. Commands, arguments, and whitespace

```bash
echo hello world
```

The command is `echo`; arguments are `hello` and `world`.

Newlines often separate commands. A semicolon can also separate commands:

```bash
echo one; echo two
```

## 4. Quoting — one of the most important shell skills

Double quotes allow variable expansion:

```bash
name="Maya"
echo "Hello $name"
```

Single quotes prevent parameter expansion:

```bash
echo '$name'
```

Command substitution happens inside double quotes:

```bash
today="$(date)"
echo "$today"
```

As a beginner rule: **quote variable expansions unless you specifically need word splitting or wildcard expansion.**

## 5. Variables

Assignment has no spaces around `=`:

```bash
name="Maya"
count=10
```

Read it with `$`:

```bash
echo "$name"
```

Useful special variables:

```text
$0       script name
$1..$9   positional arguments
$#       number of positional arguments
$@       all positional arguments
$?       previous command's exit status
$$       current shell PID
```

## 6. Exit status

Every command produces an exit status. Conventionally, `0` means success and non-zero means failure.

```bash
true
echo "$?"
false
echo "$?"
```

You can combine commands based on success/failure:

```bash
mkdir output && echo "created"
```

or:

```bash
mkdir output || echo "could not create"
```

## 7. Redirection

```bash
command > file.txt
command >> file.txt
command < input.txt
command 2> errors.txt
```

Standard streams:

```text
stdin  = 0
stdout = 1
stderr = 2
```

## 8. Pipes

```bash
ps aux | grep '[p]ython'
```

A pipe connects stdout of the left command to stdin of the right command.

## 9. Command substitution

Use `$()` to capture command output:

```bash
files="$(find . -type f | wc -l)"
echo "Files: $files"
```

Do not use old backtick syntax in new scripts unless you are reading legacy code.

## 10. `printf` vs `echo`

For predictable formatted output in scripts, prefer `printf`:

```bash
printf 'Name: %s\n' "$name"
```

---

# Hands-on Exercises

## E1. Hello script

Write a Bash script that prints three lines and run it both with `bash file.sh` and `./file.sh`.

## E2. Variable assignment

Create variables `name` and `city` and print a sentence using double quotes.

## E3. Quoting experiment

Print `$name` once with double quotes and once with single quotes. Observe the difference.

## E4. Exit status

Run a successful command and a failing command and print `$?` after each.

## E5. `&&` and `||`

Write commands that print `success` only when a directory is created successfully and `failed` otherwise.

## E6. Redirection

Send normal output to `out.txt` and error output to `errors.txt`.

## E7. Command substitution

Store today's date in a variable and print it.

## E8. Count files

Use command substitution to store the number of regular files below the current directory.

## E9. Positional arguments

Write a script that prints its script name, argument count, and each argument.

## E10. Preserve spaces

Write a script that prints the exact value of a variable containing spaces without accidental word splitting.

