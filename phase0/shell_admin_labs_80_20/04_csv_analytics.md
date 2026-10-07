# Lab 04 — CSV Server/Job Analytics

## Scenario

Operations receives a daily CSV containing background job executions. Management wants quick answers without opening a spreadsheet.

Sample columns:

```text
job_id,server,status,duration_sec,rows_processed,start_time,owner
```

Possible statuses:

```text
SUCCESS,FAILED,TIMEOUT,CANCELLED
```

## Learning goals

- `awk` as a reporting language
- CSV limitations and assumptions
- grouping and aggregation
- percentages
- sorting
- Bash orchestration
- validating input before analytics

## Requirements

Implement `jobreport.sh` that accepts a CSV file and produces a report containing:

1. total jobs;
2. success/failure/timeout counts;
3. success rate;
4. average duration overall;
5. average duration by server;
6. total rows processed by server;
7. top 5 slowest jobs;
8. top 5 servers by failed-job count;
9. a section listing malformed rows.

Support:

```text
jobreport.sh input.csv
jobreport.sh input.csv --server SERVER
jobreport.sh input.csv --status FAILED
```

## CSV scope

For this lab, assume fields do not contain embedded commas or newlines. Document that limitation explicitly.

## Hints

Use one pass for validation/counting and additional passes only when they make the solution clearer.

In `awk`, associative arrays are ideal for per-server totals.

Keep numeric conversion explicit and decide how to handle zero-row or zero-duration cases.

## Test data

Create at least 50 rows containing:

- multiple servers
- every status
- duplicate job IDs
- blank fields
- invalid numeric fields
- one malformed row
- one very slow job

## Improvement challenge

Add:

- daily/hourly grouping from `start_time`
- SLA breach counts such as duration > 300 seconds
- a CSV output file suitable for another script

## Explain

Be ready to explain where Bash ends and `awk` begins, and why trying to do all numeric aggregation with many nested shell loops would be a poor design.
