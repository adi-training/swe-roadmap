# Answer — Lab 04: CSV Server/Job Analytics

## Reference implementation

For the lab's simple CSV format (no embedded commas/newlines), `awk` is an excellent fit:

```bash
#!/usr/bin/env bash
set -u
file=${1-}
[[ -f $file ]] || { echo "CSV file required" >&2; exit 2; }

awk -F, '
NR==1 { next }
NF!=7 { bad++; next }
{
  jobs++
  status[$3]++
  duration_total += $4
  server_duration[$2] += $4
  server_jobs[$2]++
  server_rows[$2] += $5
  if ($3 != "SUCCESS") server_fail[$2]++
  if ($4 > 300) sla[$2]++
  slow[++slow_n] = $0
}
END {
  print "Total jobs:", jobs
  print "SUCCESS:", status["SUCCESS"]+0
  print "FAILED:", status["FAILED"]+0
  print "TIMEOUT:", status["TIMEOUT"]+0
  print "CANCELLED:", status["CANCELLED"]+0
  if (jobs) printf "Success rate: %.2f%%
", 100*status["SUCCESS"]/jobs
  if (jobs) printf "Average duration: %.2f sec
", duration_total/jobs
  print ""
  print "Server summary"
  for (s in server_jobs)
    printf "%s jobs=%d avg_duration=%.2f rows=%d failed_or_timeout=%d sla_breach=%d
", s, server_jobs[s], server_duration[s]/server_jobs[s], server_rows[s], server_fail[s]+0, sla[s]+0
  if (bad) print "Malformed rows:", bad
}' "$file"
```

For top-5 reports, sort numeric columns before printing. A clear solution can use a small number of `awk` pipelines rather than forcing everything into one giant program.

## Important limitation

This intentionally assumes no quoted CSV fields containing commas. A production system should use a real CSV parser when the format permits quoting/escaping.

## Improvement directions

Add `--server` and `--status` filters, emit a machine-readable summary file, and implement deterministic tie-breaking in rankings.
