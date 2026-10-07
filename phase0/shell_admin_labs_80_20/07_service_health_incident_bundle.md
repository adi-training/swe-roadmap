# Lab 07 — Service Health Check & Incident Bundle

## Scenario

A service has intermittent failures. When an administrator is paged, they need one command that performs a health check and creates a compact incident bundle containing relevant evidence.

The service itself is simulated with files and harmless local commands.

## Learning goals

- orchestration scripts
- functions and exit codes
- collecting evidence
- timestamped incident directories
- log filtering
- cleanup with traps
- operationally useful reports

## Lab input

Create:

```text
service.log
service.conf
health-command.sh
```

The health command should exit 0 for healthy and non-zero for unhealthy states.

## Requirements

Build `incident.sh` that:

1. runs the health check;
2. captures system/process information;
3. captures the last N relevant log lines;
4. records configuration metadata without exposing secrets;
5. records the script version and timestamp;
6. creates a compressed incident bundle;
7. preserves the original exit status of the health check;
8. never leaves a partially assembled temporary directory behind after interruption.

Use a structure such as:

```text
incident-YYYYmmdd-HHMMSS/
  summary.txt
  process.txt
  health.txt
  relevant.log
  metadata.txt
```

## Security requirement

Your bundle must not blindly copy a configuration file if it may contain passwords or tokens. Demonstrate a safe redaction strategy using the simulated config.

## Hints

Use `mktemp -d` and `trap`.

Collect evidence first; package it after collection succeeds or fails.

Do not make the script itself fail merely because one optional evidence command is unavailable. Decide which failures are fatal and which are warnings.

## Improvement challenge

Add:

- a `--lines N` argument;
- severity detection based on the health result;
- a manifest containing file names and SHA-256 checksums.

## Explain

Explain the difference between the **incident result** and the **evidence collection process**. They should not accidentally overwrite each other.
