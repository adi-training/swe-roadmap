# Chapter 1 — Linux Navigation and Filesystem Basics

**Time:** ~40 minutes  
**Goal:** Move around the filesystem confidently and understand the basic Linux directory model.

---

## 1. Linux paths

An absolute path starts from `/`:

```text
/home/maya/project/app.py
```

A relative path starts from your current directory:

```text
project/app.py
```

Special names:

```text
.    current directory
..   parent directory
~    your home directory in most shells
/    filesystem root
```

## 2. Where am I?

```bash
pwd
```

## 3. Listing files

```bash
ls
ls -l
ls -la
ls -lh
```

Useful idea: `-l` asks for a long listing; `-a` includes hidden files; `-h` makes sizes easier to read.

## 4. Moving around

```bash
cd ~/linux-lab
cd data
cd ..
cd -
cd ~
```

`cd -` usually returns to the previous directory.

## 5. Creating and removing

```bash
mkdir notes
mkdir -p project/src
rmdir empty_dir
```

`rmdir` only removes an empty directory. `rm -r` can remove a directory tree and should be treated as dangerous.

## 6. Copy and move

```bash
cp file.txt backup.txt
cp -r dir1 dir2
mv old.txt new.txt
mv file.txt dir/
```

## 7. Paths with spaces

Quote them:

```bash
cd "my project"
cat "report final.txt"
```

This becomes extremely important in shell scripts.

---

# Hands-on Exercises

## E1. Create a lab tree

Create `~/linux-lab/demo/{src,docs,logs}` using one command.

## E2. Navigate

Start anywhere and use `pwd`, `cd`, and `cd -` to move between your home directory and `~/linux-lab/demo`.

## E3. Create files

Inside `demo`, create `src/main.sh`, `docs/readme.txt`, and `logs/app.log` without opening an editor.

## E4. Copy and rename

Copy `readme.txt` to `readme.bak` and rename `main.sh` to `run.sh`.

## E5. List hidden files

Create a hidden file `.config` and use one `ls` command to see it.

## E6. Inspect file metadata

Use `file` and `stat` on one of your files.

## E7. Safe cleanup

Remove only the `logs/app.log` file and then remove the now-empty `logs` directory.

## E8. Find your home path

Print your home directory using the shell environment and then print the current directory.

