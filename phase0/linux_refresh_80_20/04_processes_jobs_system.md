# Chapter 4 — Processes, Jobs and System Information

**Time:** ~45 minutes  
**Goal:** Understand the difference between a shell, a process, a foreground job, and a background job.

---

## 1. Process basics

A process is a running program with a process ID (PID).

```bash
ps
ps aux
ps -ef
```

The exact output differs between systems, but the ideas are the same: PID, parent, CPU, memory, command, etc.

## 2. Live view

```bash
top
```

On many systems `htop` is also available, but it may need installation.

## 3. Finding processes

```bash
pgrep bash
pgrep -af python
```

Or:

```bash
ps aux | grep '[p]ython'
```

The bracket trick avoids matching the `grep` command itself.

## 4. Terminating processes

```bash
kill PID
kill -TERM PID
kill -KILL PID
```

Start with a normal termination request (`TERM`). `KILL` is forceful and should be a last resort because the process cannot catch it to clean up.

## 5. Foreground and background jobs

```bash
sleep 30 &
```

The `&` starts it in the background.

```bash
jobs
fg
bg
```

You can suspend a foreground program with `Ctrl-Z`, then resume it in the background with `bg`.

## 6. System information

```bash
uname -a
whoami
id
date
uptime
hostname
```

## 7. Disk and memory

```bash
df -h
du -sh ~/linux-lab
free -h
```

`df` is about filesystems; `du` is about directory/file usage.

## 8. Environment

```bash
env
printenv
printenv HOME
```

The current shell can also have local variables that are not automatically exported.

---

# Hands-on Exercises

## E1. Find your shell

Print the current shell-related environment variables.

## E2. Identify yourself

Use `whoami` and `id` and compare the information.

## E3. Inspect processes

Find the PID of your current shell.

## E4. Background job

Run `sleep 60` in the background and inspect it with `jobs`.

## E5. Bring a job to foreground

Use `fg` to bring your background `sleep` job to the foreground, then stop it with `Ctrl-C`.

## E6. Disk usage

Use `df -h` to inspect available filesystem space and `du -sh ~/linux-lab` to inspect your lab directory.

## E7. Memory

Run `free -h` and identify total and available memory.

## E8. Process search

Use `pgrep -af` to find a running process such as your shell.

## E9. Exit status

Run `true`, inspect `$?`, then run `false` and inspect `$?` again.

## E10. Process tree idea

Use `ps -ef` and identify the parent PID (`PPID`) of your shell.

