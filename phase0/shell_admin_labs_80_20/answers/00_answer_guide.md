# Answer Guide — Administrative Mini-Projects

This directory contains the reference implementations. They are intentionally **reference solutions, not the only correct solutions**.

Recommended workflow:

1. Attempt the lab without opening the answer.
2. Compare architecture before comparing individual commands.
3. Read the explanation after reading the code.
4. Reimplement the solution from memory in a clean directory.
5. Modify one requirement and make the script pass your new tests.

## What to compare

For every solution, inspect:

- quoting;
- input validation;
- exit status;
- handling of empty input;
- handling of malformed input;
- filesystem race considerations;
- dry-run or read-only behavior;
- cleanup with `trap`;
- predictable output;
- whether data processing is delegated to the right tool (`awk`, `find`, `sort`, etc.).

## Suggested mastery challenge

After completing all ten labs, choose any two and rewrite them without looking at the answers. Then add one feature neither version had before.

The point of this track is operational problem-solving: **discover → validate → transform → decide → act → report → test**.
