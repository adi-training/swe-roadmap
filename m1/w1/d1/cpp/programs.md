Start with these 8 C++ programs. They cover Day 1: input/output, variables, conditions, loops, functions, and Big-O intuition.

| # | Program | Expected outcome | Example |
|---:|---|---|---|
| 1 | Hello + profile printer | Read a name, year, and branch; print a readable introduction. | Input: `Guru`, `3`, `Robotics and AI` → Output: `Hello Guru. You are a 3rd-year Robotics and AI student.` |
| 2 | Two-number calculator | Use functions to add, subtract, multiply, and safely divide two numbers. | Input: `12 4` → Output: `Sum: 16, Difference: 8, Product: 48, Quotient: 3` |
| 3 | Temperature converter | Convert Celsius to Fahrenheit using a dedicated function. | Input: `25` → Output: `25 C = 77 F` |
| 4 | Even/odd and sign checker | Use `if/else` and modulo to classify an integer. | Input: `-14` → Output: `Negative even number` |
| 5 | Maximum of three numbers | Find the largest of three values without using `std::max`. | Input: `14 81 42` → Output: `Largest number: 81` |
| 6 | Sum from 1 to N | Use a loop to calculate the sum of integers from 1 through `n`. State its complexity. | Input: `5` → Output: `Sum: 15` and `Time complexity: O(n), Space complexity: O(1)` |
| 7 | Multiplication table | Print a table from 1 to 10 for a user-provided number. | Input: `7` → Output includes `7 x 1 = 7` through `7 x 10 = 70` |
| 8 | Operation counter | Demonstrate linear vs quadratic growth by counting loop iterations. | Input: `n = 4` → Output: `Single loop operations: 4`, `Nested loop operations: 16` |

## Stretch programs

Do these only after completing the eight above.

| Program | Expected outcome | Example |
|---|---|---|
| Factorial calculator | Calculate factorial with a function; handle invalid negative input. | Input: `5` → Output: `Factorial: 120` |
| Number classifier | Report whether a number is positive/negative, even/odd, and divisible by 3 or 5. | Input: `15` → Output: `Positive, odd, divisible by 3 and 5` |
| Simple login simulation | Check a hard-coded username and PIN with conditions. | Input: `guru`, `1234` → Output: `Login successful` |
| Binary-search iteration simulator | Given a sorted-range size, estimate how many “halve the range” steps are needed. | Input: `16` → Output: roughly `4 iterations`, illustrating `O(log n)` |

## What you should learn from the set

After these programs, you should be able to:

- Write a complete C++ program with `main()`.
- Read input and print formatted output.
- Create and call functions.
- Use `if/else`, loops, arithmetic, and modulo.
- Distinguish linear work from nested-loop/quadratic work.
- Explain why Program 6 is `O(n)` and Program 8’s nested loop is `O(n²)`.
- Handle simple invalid cases, especially division by zero and negative factorial input.

For each program, create a separate file such as:

```text
day-01/
  01_profile.cpp
  02_calculator.cpp
  03_temperature.cpp
  ...
```

Commit only after you can explain every line you wrote.