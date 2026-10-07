# Lab 08 — Configuration Drift Detector

## Scenario

Several servers should share a known-good configuration for a small application. Someone changed one server manually. Operations wants a script that compares the current configuration against a baseline and clearly identifies drift.

## Learning goals

- canonicalization
- checksums and diffs
- associative arrays
- comparison logic
- ignored/secret fields
- machine-readable output

## Lab structure

```text
baseline/
  app.conf
  limits.conf
server-a/
  app.conf
  limits.conf
server-b/
  app.conf
  limits.conf
server-c/
  app.conf
  limits.conf
ignore.patterns
```

## Requirements

Build `driftcheck.sh` that:

- compares every expected file against every server directory;
- reports missing files;
- reports unexpected files;
- reports content drift;
- reports line-level differences for text configs;
- ignores configured volatile lines/patterns;
- computes a summary per server;
- exits non-zero when drift exists.

## Design questions

Should you compare raw checksums, normalized checksums, or both?

How will you avoid hiding meaningful differences when ignoring timestamps or generated IDs?

## Hints

First prove a simple checksum comparison. Then introduce normalization as an explicit function.

Use `diff -u` for diagnostics even if checksums are used for the initial fast comparison.

## Improvement challenge

Add a `--fix-plan` mode that lists the exact baseline files that would need to be replaced, without replacing anything.

## Explain

Explain why configuration drift tools should report evidence rather than simply saying “different”.
