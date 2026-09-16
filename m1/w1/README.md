# Week 1 — C++ Setup, Arrays, Hashing, and CLI Project Foundation

**Total time:** 15–16 hours  
- Monday–Friday: 2 hours/day  
- Saturday: 3 hours  
- Sunday: 2–3 hours  

## Week 1 outcomes

By the end of this week, I will have:

- Set up a working C++ development environment.
- Created a GitHub repository for a C++ CLI log/sensor-data analyzer.
- Learned and practiced Big-O analysis for common array and hash-map operations.
- Solved 6 new DSA problems and re-solved 2 problems.
- Built a CLI tool that reads a text/CSV file and prints basic summary information.
- Written unit tests, documentation, and meaningful Git commits.

## Daily rule

For every DSA problem:

1. Restate the problem in my own words.
2. Identify edge cases.
3. Explain brute force first.
4. Explain the optimized approach.
5. Write time and space complexity.
6. Test the solution manually.
7. Commit or record the solution and learning.

---

# Day 1 — Environment Setup, C++ Basics, and Big-O

**Duration:** 2 hours

## DSA and interview preparation

- Learn Big-O notation.
- Understand constant, linear, logarithmic, linearithmic, quadratic, and exponential complexity.
- Practice identifying time complexity for:
  - Array traversal.
  - Nested loops.
  - Binary search.
  - Hash-map lookup.
  - Sorting.

## C++ learning

- Verify compiler installation.
- Learn the compile/run workflow.
- Revise:
  - `main()`
  - Variables and primitive types.
  - Functions.
  - Input/output with `std::cin` and `std::cout`.
  - Basic control flow.

## Hands-on work

- Create a GitHub repository named something similar to:
  - `cpp-log-analyzer`
  - `sensor-log-analyzer`
- Add:
  - `README.md`
  - `.gitignore`
  - `CMakeLists.txt`
  - `src/main.cpp`
- Build and run a “Hello, Analyzer!” program.

## Deliverable

- First Git commit.
- CMake project builds successfully.
- README includes the project goal.

## End-of-day check

- [ ] I can compile and run a C++ program.
- [ ] I can explain Big-O for a single loop and nested loops.
- [ ] My repository is pushed to GitHub.
- [ ] I made at least one meaningful commit.

---

# Day 2 — Arrays, Vectors, References, and File Input

**Duration:** 2 hours

## DSA and interview preparation

- Learn array traversal patterns.
- Practice:
  - Finding minimum and maximum.
  - Computing sum and average.
  - Updating values in-place.
  - Identifying duplicates.
- Solve 2 array-focused DSA problems.

## C++ learning

- Learn:
  - `std::vector`
  - Pass-by-value versus pass-by-reference.
  - `const` correctness.
  - Range-based loops.
  - Basic file input using `std::ifstream`.

## Hands-on work

- Add command-line argument support for an input file.
- Read a text or CSV file.
- Print:
  - File name.
  - Number of lines.
  - First few lines.

## Deliverable

- CLI accepts an input-file path.
- Program reads and prints file content safely.

## End-of-day check

- [ ] I solved 2 DSA problems.
- [ ] I can explain why vectors are often preferred over raw arrays.
- [ ] I understand pass-by-reference.
- [ ] My CLI reads an input file.

---

# Day 3 — Functions, Code Organization, and Prefix Sums

**Duration:** 2 hours

## DSA and interview preparation

- Learn:
  - Prefix sums.
  - Range-sum queries.
  - Subarray intuition.
- Solve 1 prefix-sum or array problem.
- Re-solve the Day 1 DSA problem without looking at the previous code.

## C++ learning

- Learn:
  - Header files versus source files.
  - Function declarations and definitions.
  - Namespaces.
  - Basic error handling.
  - Separating logic from `main()`.

## Hands-on work

- Create a data model for one log/sensor-data row.
- Parse rows from the input file.
- Store parsed data in a vector.
- Create separate functions for:
  - Reading the file.
  - Parsing a row.
  - Printing a summary.

## Deliverable

- Application code is split into meaningful functions/files.
- Parsed data is stored in a C++ vector.

## End-of-day check

- [ ] I understand prefix sums conceptually.
- [ ] I can explain the purpose of header files.
- [ ] My application has functions beyond `main()`.
- [ ] I re-solved one earlier DSA problem.

---

# Day 4 — Hash Maps and Frequency Counting

**Duration:** 2 hours

## DSA and interview preparation

- Learn:
  - Hashing.
  - Frequency maps.
  - Duplicate detection.
  - `unordered_map` lookup complexity.
- Solve 2 hash-map-focused DSA problems.

## C++ learning

- Learn:
  - `std::unordered_map`
  - `std::map`
  - Iterators.
  - Key-value insertion and lookup.
  - When to prefer ordered maps versus hash maps.

## Hands-on work

- Add frequency counting to the log analyzer.
- For example, count:
  - Event types.
  - Sensor IDs.
  - Error categories.
  - Status values.
- Print the frequency summary.

## Deliverable

- CLI produces an event/sensor/error frequency report.
- Code handles unknown or malformed categories safely.

## End-of-day check

- [ ] I solved 2 DSA problems.
- [ ] I can explain average lookup complexity in a hash map.
- [ ] I can explain when an ordered map is useful.
- [ ] My CLI calculates frequencies.

---

# Day 5 — Sorting, Lambdas, and Weekly DSA Review

**Duration:** 2 hours

## DSA and interview preparation

- Solve 1 mixed array/hash-map problem.
- Re-solve the hardest problem from Day 2.
- Practice verbally explaining:
  - Brute-force solution.
  - Optimized solution.
  - Complexity.
  - Edge cases.

## C++ learning

- Learn:
  - `std::sort`
  - Custom comparators.
  - Lambda functions.
  - Basic exception handling.
  - Common STL algorithms such as `find` and `count`.

## Hands-on work

- Sort analyzer output by frequency or timestamp.
- Add a `top N` output option.
- Improve user-facing error messages.

## Deliverable

- CLI shows sorted output.
- CLI can print top frequent events or sensor IDs.

## End-of-day check

- [ ] I solved 1 new DSA problem.
- [ ] I re-solved 1 older problem.
- [ ] I can use `std::sort` with a custom comparator.
- [ ] My CLI has one useful sorted report.

---

# Day 6 — Timed Practice, Debugging, and Refactoring

**Duration:** 3 hours

## DSA and interview preparation

- Complete a 75-minute timed practice session.
- Solve 3 problems:
  - One easy array/hash-map problem.
  - One medium array/hash-map problem.
  - One review problem.
- Spend 30 minutes reviewing mistakes and recording them.

## C++ learning

- Learn debugger basics:
  - Breakpoints.
  - Stepping through code.
  - Inspecting variables.
  - Reading compiler errors.
- Review Git commits and branch workflow.

## Hands-on work

- Refactor code for readability.
- Add handling for:
  - Missing files.
  - Empty files.
  - Invalid input rows.
  - Unknown event types.
- Improve function names and variable names.

## Deliverable

- Timed-practice notes.
- Error log with mistakes and corrections.
- Refactored analyzer with error handling.

## End-of-day check

- [ ] I completed a timed coding session.
- [ ] I wrote down my DSA mistakes.
- [ ] I used a debugger or stepping workflow.
- [ ] My CLI handles invalid input gracefully.

---

# Day 7 — Testing, Documentation, and Weekly Review

**Duration:** 2–3 hours

## DSA and interview preparation

- Complete a 45-minute mock interview simulation.
- Explain aloud:
  - One easy problem.
  - One medium-style problem.
- Focus on communication, not only correct code.

## C++ learning

- Learn the basics of unit testing.
- Review:
  - CMake.
  - Git.
  - STL containers.
  - Big-O.
  - Arrays and hashing.

## Hands-on work

- Add 3–5 tests.
- Update README with:
  - Project purpose.
  - Features.
  - Build instructions.
  - Usage examples.
  - Sample input/output.
  - Future improvements.
- Record a short demo video or GIF.
- Push final Week 1 code to GitHub.

## Deliverable

- Complete Week 1 project checkpoint.
- Tests, README, and demo committed to GitHub.
- Weekly retrospective notes.

## End-of-day check

- [ ] I completed one mock coding explanation.
- [ ] My project has tests.
- [ ] My README explains setup and usage.
- [ ] My GitHub repository is clean and updated.
- [ ] I know what to revise next week.

---

# Week 1 DSA tracker

| Category | Target | Completed |
|---|---:|---:|
| New DSA problems | 6 | [ ] |
| Re-solved problems | 2 | [ ] |
| Timed coding sessions | 1 | [ ] |
| Mock interview simulations | 1 | [ ] |
| Big-O explanations practiced | 8+ | [ ] |

# Week 1 project tracker

| Task | Completed |
|---|---|
| GitHub repository created | [ ] |
| CMake project created | [ ] |
| CLI reads an input file | [ ] |
| Log/CSV rows parsed | [ ] |
| Frequency report added | [ ] |
| Sorted/top-N output added | [ ] |
| Error handling added | [ ] |
| Unit tests added | [ ] |
| README completed | [ ] |
| Demo recorded | [ ] |
| Week 1 retrospective written | [ ] |

# Week 1 retrospective

## What I learned

- 

## Problems I could not solve independently

- 

## Bugs or implementation challenges

- 

## Concepts to revise next week

- 

## Improvements for the project

- 