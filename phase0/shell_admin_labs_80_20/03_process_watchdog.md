# Lab 03 — Process Watchdog & Resource Reporter

## Scenario

An administrator wants a lightweight script that checks whether a named service/process is running and reports suspicious resource usage. The script should be usable from cron or a monitoring system.

You are not building a full monitoring platform. Build a focused command-line tool that produces a reliable snapshot.

## Learning goals

- `ps`, process selection, PID handling
- exit codes as monitoring signals
- thresholds
- sorting and reporting
- command-line parsing
- defensive scripting
- avoiding false positives

## Requirements

Implement:

```text
procwatch.sh --name NAME --cpu-limit PERCENT --mem-limit PERCENT
```

The script should:

1. find matching processes;
2. avoid accidentally matching the watchdog itself where possible;
3. report PID, command, CPU%, MEM%, elapsed time;
4. return:
   - `0` when the process exists and is within limits;
   - `1` when the process exists but exceeds a limit;
   - `2` when no matching process exists;
   - `3` for usage/configuration errors;
5. support `--json FILE` or another clearly documented machine-readable report format as an improvement.

## Lab setup

Use harmless local processes. Examples include `sleep`, a Python loop, or a small CPU-intensive test program/script. Do not kill system processes during the lab.

## Questions to reason about

- Is process name matching exact or substring based?
- What if there are multiple matching PIDs?
- Do you alert if one process exceeds a limit while another is normal?
- What does “service is running” mean when there are multiple workers?

## Hints

Start with `ps -eo pid=,comm=,pcpu=,pmem=,etime=`.

Normalize whitespace before feeding rows into other tools.

Keep the monitoring decision separate from the display formatting.

## Test plan

Test:

- process absent
- process present
- multiple matching processes
- CPU threshold exceeded
- memory threshold exceeded
- invalid numeric threshold
- process ending while being inspected

## Improvement challenge

Add a `--history FILE` option that stores one CSV snapshot per run and a second mode that summarizes the last N runs.

## Explain

Explain why shell monitoring based on snapshots can have race conditions and why exit status is useful for cron/alerting integrations.
