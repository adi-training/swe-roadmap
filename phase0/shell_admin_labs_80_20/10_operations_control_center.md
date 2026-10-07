# Lab 10 — Daily Operations Control Center

## Scenario

You are asked to build a single daily operations command that runs several independent checks and produces one status summary for an operations dashboard.

This is the capstone: combine ideas from the previous labs without copy-pasting them blindly.

## Components

Your control center should invoke or embed checks for:

1. filesystem capacity;
2. process availability;
3. log retention compliance;
4. backup freshness;
5. configuration drift;
6. a CSV job-success KPI;
7. incident-worthy findings.

## Requirements

Implement:

```text
opsctl.sh [--config FILE] [--verbose] [--json FILE]
```

The config can define thresholds and lab paths.

The script must:

- validate configuration;
- run checks independently;
- capture each check's exit status;
- continue after a non-fatal check failure;
- generate a concise human report;
- generate optional machine-readable output;
- return an overall status according to a documented policy;
- log start/end time and duration of each check.

## Architecture expectation

Do not create one 800-line function. Treat each check as a component with a small contract:

```text
run_check_name
  -> produces result + evidence
  -> returns status
```

## Hints

Start with two checks only. Make the orchestration generic before adding more checks.

Bash does not have rich structured data types, so keep your internal contract simple. Arrays or temporary files are acceptable.

Be careful not to lose a command's exit status when you pipe it through formatting commands.

## Testing

Create a test matrix where each component can independently be healthy/unhealthy. Verify that:

- one failure does not stop unrelated checks;
- overall status matches policy;
- human and machine outputs agree;
- repeated runs do not leave stale temporary files.

## Improvement challenge

Add a final `--explain` section that maps each failed check to a recommended administrator action.

## Final explanation

Present the tool as though you were handing it to another administrator. Cover assumptions, dependencies, failure modes, extension points, and why the code is safe to operate.
