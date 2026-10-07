# Chapter 5 — Archives, Networking Checks and SSH

**Time:** ~40 minutes  
**Goal:** Know the practical commands used to package files, inspect connectivity, and work on remote Linux systems.

---

## 1. `tar`

Create an archive:

```bash
tar -cf backup.tar demo/
```

Extract:

```bash
tar -xf backup.tar
```

Create gzip-compressed archive:

```bash
tar -czf backup.tar.gz demo/
```

Extract:

```bash
tar -xzf backup.tar.gz
```

List contents without extracting:

```bash
tar -tf backup.tar.gz
```

## 2. `zip` / `unzip`

These may not be installed everywhere:

```bash
zip -r demo.zip demo/
unzip demo.zip
```

## 3. Connectivity checks

```bash
ping -c 3 example.com
```

DNS lookup tools vary by system. Common commands include:

```bash
getent hosts example.com
```

or, when installed:

```bash
nslookup example.com
```

Check an HTTP endpoint:

```bash
curl -I https://example.com
```

## 4. SSH

Typical form:

```bash
ssh user@host
```

Copy a file:

```bash
scp report.txt user@host:/tmp/
```

Copy a directory recursively:

```bash
scp -r demo user@host:/tmp/
```

For repeated work, SSH keys are preferable to repeatedly entering passwords. Do not put passwords directly into shell commands or scripts.

## 5. Environment and `PATH`

When you type a command, the shell searches directories in `PATH`.

```bash
echo "$PATH"
command -v python3
```

---

# Hands-on Exercises

## E1. Create an archive

Create `demo.tar.gz` containing your `~/linux-lab/demo` directory.

## E2. Inspect an archive

List archive contents without extracting them.

## E3. Extract elsewhere

Create `~/linux-lab/restore` and extract the archive there.

## E4. HTTP headers

Use `curl -I` to inspect headers from `https://example.com`.

## E5. DNS

Use `getent hosts example.com` and observe the returned address information.

## E6. Local SSH configuration

Run `ssh -G localhost | head` to see resolved SSH configuration without actually making a connection.

## E7. PATH lookup

Use `command -v` to locate `bash`, `ls`, and `python3`.

## E8. Archive backup script idea

Write down the one `tar` command you would use to create a dated backup of `~/linux-lab/data`.

