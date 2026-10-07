# Lab 09 — Storage Capacity & Cleanup Planner

## Scenario

A server is approaching a storage threshold. An administrator needs a report that identifies where space is going and proposes cleanup candidates without automatically deleting anything.

## Learning goals

- `du`, `find`, `sort`, `awk`
- thresholds and percentages
- ranking directories/files
- safe recommendations
- report generation
- distinguishing planning from execution

## Requirements

Build `storageplan.sh` with:

```text
storageplan.sh --root DIR --warn 70 --critical 85
```

The report should include:

- total/used/free space for the filesystem containing the root;
- largest directories;
- largest files;
- files older than a configurable age;
- candidate temporary files;
- a “do not delete automatically” section for protected patterns;
- estimated reclaimable bytes by candidate class;
- overall status: OK/WARN/CRITICAL.

## Safety rule

This project is a **planner**, not a deleter. Do not implement automatic deletion in the core solution.

## Hints

Use `df` for filesystem capacity and `du` for directory consumption.

Keep “candidate” separate from “safe to delete”.

Be explicit about whether symbolic links are followed.

## Improvement challenge

Produce both human-readable text and CSV output. Add a top-N parameter.

## Explain

Explain why filesystem free space and directory-reported usage are not always identical and why cleanup scripts must be conservative.
