# Answer — Lab 06: User/Home Directory Audit

## Reference approach

The lab uses a simulated passwd file so the script is safe to run as an ordinary user.

```bash
#!/usr/bin/env bash
set -u
passwd_file=${1:-passwd.sample}
homes_root=${2:-homes}
size_limit_mb=${SIZE_LIMIT_MB:-500}

while IFS=: read -r user _ uid gid gecos home shell; do
  [[ -n $user ]] || continue
  [[ $user == \#* ]] && continue

  if [[ ! -d $home ]]; then
    printf 'CRITICAL missing_home user=%s home=%s
' "$user" "$home"
    continue
  fi

  size_mb=$(du -sm -- "$home" | awk '{print $1}')
  if (( size_mb > size_limit_mb )); then
    printf 'WARN large_home user=%s size_mb=%s
' "$user" "$size_mb"
  fi

  case $shell in
    /bin/bash|/bin/sh|/bin/zsh) ;;
    *) printf 'WARN unusual_shell user=%s shell=%s
' "$user" "$shell" ;;
  esac

  while IFS= read -r -d '' f; do
    if [[ -w $f && -n $(find "$f" -maxdepth 0 -perm -0002 -print -quit) ]]; then
      printf 'CRITICAL world_writable user=%s file=%s
' "$user" "$f"
    fi
  done < <(find "$home" -type f -print0)
done < "$passwd_file"
```

For ownership checks in the simulated lab, compare recorded expected UID/GID metadata with a fixture or sidecar rather than changing real ownership.

## Production improvements

For a real system, use `getent passwd` instead of opening `/etc/passwd` directly when appropriate, exclude pseudo-users according to policy, and avoid expensive recursive scans on every run without caching.
