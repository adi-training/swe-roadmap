# Chapter 2 — Files, Permissions, Ownership and Links

**Time:** ~45 minutes  
**Goal:** Read permission strings, change permissions safely, and understand links.

---

## 1. Permission string

A listing may look like:

```text
-rwxr-xr-- 1 user group 1234 Oct 7 10:10 script.sh
```

The first character indicates the type:

```text
- regular file
d directory
l symbolic link
```

Then permissions appear in three groups:

```text
owner   group   others
rwx     r-x     r--
```

Meaning:

```text
r = read
w = write
x = execute
```

## 2. Numeric permissions

```text
r = 4
w = 2
x = 1
```

Therefore:

```text
7 = rwx
6 = rw-
5 = r-x
4 = r--
```

Example:

```bash
chmod 755 script.sh
```

means owner has `rwx`, group has `r-x`, others have `r-x`.

## 3. Symbolic permissions

```bash
chmod u+x script.sh
chmod g-w file.txt
chmod o-r secret.txt
```

## 4. Executable scripts

A text file becomes executable when it has the execute permission. A shebang tells the system which interpreter to use:

```bash
#!/usr/bin/env bash
```

Then:

```bash
chmod +x hello.sh
./hello.sh
```

## 5. Ownership

```bash
ls -l
```

shows owner and group. `chown` and `chgrp` change them and often require elevated privileges.

```bash
sudo chown user:group file
```

Use `sudo` deliberately. Do not make `sudo` the default answer to permission problems without understanding the problem.

## 6. Hard and symbolic links

Symbolic link:

```bash
ln -s original.txt shortcut.txt
```

It points to a pathname.

Hard link:

```bash
ln original.txt second-name.txt
```

For beginner practice, focus on symbolic links and understand that deleting the original pathname does not make a symbolic link meaningful anymore.

---

# Hands-on Exercises

## E1. Read permissions

Use `ls -l` and describe the owner/group/other permissions of one file.

## E2. Make a script executable

Create `hello.sh`, add a Bash shebang and a `echo` command, then run it using `./hello.sh`.

## E3. Numeric permissions

Set `hello.sh` to `rwxr-xr-x` using `chmod`.

## E4. Symbolic permissions

Remove write permission for group and others from a test file using symbolic `chmod` syntax.

## E5. Inspect ownership

Use `stat` to display owner and group information for a file.

## E6. Symbolic link

Create a symlink to a text file and prove that reading the link reads the original content.

## E7. Link behavior

Change the original file and verify that the symlink sees the updated content.

## E8. Executable search

Use `which` and `command -v` to locate a common command such as `bash`.

