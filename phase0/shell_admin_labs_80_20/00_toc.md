# Linux & Bash Administrative Mini-Projects — 80:20 Lab Track

## Purpose

This track is a practical extension of the Linux/Bash refresher. It is designed for someone who knows basic Linux commands and Bash syntax and now wants to become comfortable solving **real administrative problems with shell scripts**.

The projects deliberately use medium-to-high complexity. The goal is not to memorize commands; it is to learn how to turn an operational requirement into a reliable script.

## How to use each lab

Each project is designed for about **2 hours**:

| Stage | Time | What you do |
|---|---:|---|
| Development | 30 min | Read the scenario, design the script, implement a first version |
| Testing | 30 min | Build test data, run happy-path and failure-path tests, inspect output |
| Improvement | 30 min | Add validation, logging, safety, edge-case handling, better interfaces |
| Explanation | 30 min | Explain your design, decisions, failure handling, and trade-offs |

**Do not open the answer key until you have attempted the lab.** The lab documents intentionally provide requirements, hints, checkpoints, and test ideas without giving away the implementation.

## Recommended order

1. [01 — Folder Housekeeper](01_folder_housekeeper.md)
2. [02 — Log Retention & Compression Manager](02_log_retention_manager.md)
3. [03 — Process Watchdog & Resource Reporter](03_process_watchdog.md)
4. [04 — CSV Server/Job Analytics](04_csv_analytics.md)
5. [05 — Backup Inventory & Verification](05_backup_inventory.md)
6. [06 — User/Home Directory Audit](06_user_home_audit.md)
7. [07 — Service Health & Incident Bundle](07_service_health_incident_bundle.md)
8. [08 — Configuration Drift Detector](08_config_drift_detector.md)
9. [09 — Storage Capacity & Cleanup Planner](09_storage_cleanup_planner.md)
10. [10 — Daily Operations Control Center](10_operations_control_center.md)

## Prerequisites

You should be comfortable with:

- `find`, `xargs`, `sort`, `uniq`, `cut`, `tr`, `grep`, `sed`, `awk`
- pipes and redirection
- variables, command substitution, `if`, `case`, loops, functions
- exit status and `&&` / `||`
- Bash arrays and associative arrays
- `getopts`
- `date`, `stat`, `du`, `ps`
- `trap`, temporary directories, quoting

You do **not** need root privileges for these labs.

## Safety rule

Use a dedicated lab tree such as `/tmp/bash-admin-lab` or a directory under your home directory. The reference solutions are designed to work on simulated data wherever possible. Do not point destructive commands at real `/`, `/home`, `/var/log`, production process tables, or live backup repositories while learning.

## Lab conventions

Most projects use this pattern:

```text
project/
  input/        # simulated operational data
  output/       # generated reports
  archive/      # files moved or compressed by the lab
  bin/          # your script
  tests/        # test fixtures and expected behavior
```

## What “production-minded” means here

A good solution should think about:

- quoting and spaces in file names
- empty input and malformed input
- predictable exit codes
- logs that explain what happened
- dry-run support for destructive operations
- configuration instead of hard-coded values
- safe temporary-file handling
- race conditions where relevant
- idempotency where practical
- clear stdout vs stderr behavior
- input validation
- easy-to-read functions
- testability without requiring root access

## Scoring yourself

For each lab, score 0–3 in each area:

| Area | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| Correctness | broken | happy path only | most cases | robust |
| Safety | unsafe | basic care | guarded | production-minded |
| Testing | none | a few manual tests | organized | repeatable test suite |
| Design | tangled | workable | modular | reusable/clear |
| Diagnostics | unclear | some output | useful logs | operationally excellent |

A score of **12+/15** is a strong result.
