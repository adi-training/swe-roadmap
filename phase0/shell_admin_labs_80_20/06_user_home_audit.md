# Lab 06 — User/Home Directory Audit

## Scenario

A systems team wants a recurring audit of local user accounts and their home directories. You need to detect stale accounts, unusual home-directory ownership/permissions, oversized homes, and missing homes.

The lab must be runnable without root by auditing a **simulated passwd file and lab directory tree** rather than changing real accounts.

## Learning goals

- parsing colon-delimited records
- `getent`/`/etc/passwd` concepts
- `awk` and `stat`
- permissions and ownership reasoning
- size aggregation
- producing an actionable audit

## Lab files

Create:

```text
lab06/
  passwd.sample
  homes/
    alice/
    bob/
    service-account/
  config/thresholds.conf
```

Use a sample passwd-like format:

```text
alice:x:1001:1001:Alice:/lab06/homes/alice:/bin/bash
```

## Requirements

Build `homeaudit.sh` that reports:

- users with missing home directories;
- users whose home owner does not match the expected UID/GID metadata in the sample;
- home directories above a configurable size threshold;
- accounts using shells outside an approved list;
- service-like accounts with interactive shells;
- world-writable files inside user homes.

Output should distinguish severity such as `INFO`, `WARN`, `CRITICAL`.

## Hints

Use the simulated UID/GID values as metadata instead of requiring `chown`.

For real Linux systems, the equivalent concepts come from `/etc/passwd`, `getent passwd`, `stat`, and `find`.

Design your script so the source of account data can later be swapped from the sample file to `getent`.

## Improvement challenge

Add a suppression file for approved exceptions and include “suppressed findings” in the report count.

## Explain

Explain why parsing account metadata and verifying actual filesystem state should be treated as two separate concerns.
