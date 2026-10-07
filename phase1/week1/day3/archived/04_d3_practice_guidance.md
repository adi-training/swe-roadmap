## Problem 1: Build Prefix Sum Array

```text
Input:  [3, 1, 4, 1, 5]
Output: [0, 3, 4, 8, 9, 14]
```

### What does the output mean?

Each result value is the sum of all input values before that position.

```text
Input:        [3, 1, 4, 1, 5]
Prefix sum: [0, 3, 4, 8, 9, 14]
```

```text
prefix[0] = 0
prefix[1] = 3
prefix[2] = 3 + 1 = 4
prefix[3] = 3 + 1 + 4 = 8
prefix[4] = 3 + 1 + 4 + 1 = 9
prefix[5] = 3 + 1 + 4 + 1 + 5 = 14
```

The output has one extra value: the initial `0`.

### Why add the initial zero?

It makes later range-sum calculations easier.

For example, sum from index `1` through `3`:

```text
prefix[4] - prefix[1]
9 - 3
= 6
```

That corresponds to:

```text
1 + 4 + 1 = 6
```

### Step-by-step algorithm

```text
1. Create an empty result vector.
2. Add 0 as the first prefix value.
3. Visit every input value.
4. Add the current input value to the most recent prefix sum.
5. Append this new total to the result.
6. Return the result.
```

### Pseudocode

```text
prefixSums = [0]

For each value in values:
    nextSum = last value in prefixSums + value
    append nextSum to prefixSums

Return prefixSums
```

### Try this skeleton first

```cpp
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& values) {
    std::cout << '[';

    for (std::size_t index = 0; index < values.size(); ++index) {
        std::cout << values[index];

        if (index + 1 < values.size()) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

std::vector<int> buildPrefixSums(const std::vector<int>& values) {
    std::vector<int> prefixSums;

    prefixSums.push_back(0);

    for (int value : values) {
        // 1. Get the most recent prefix sum.
        // 2. Add value to it.
        // 3. Add the result to prefixSums.
    }

    return prefixSums;
}

int main() {
    std::vector<int> values = {3, 1, 4, 1, 5};

    std::vector<int> prefixSums = buildPrefixSums(values);

    printVector(prefixSums);
}
```

### Reference solution

```cpp
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& values) {
    std::cout << '[';

    for (std::size_t index = 0; index < values.size(); ++index) {
        std::cout << values[index];

        if (index + 1 < values.size()) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

std::vector<int> buildPrefixSums(const std::vector<int>& values) {
    std::vector<int> prefixSums;

    prefixSums.push_back(0);

    for (int value : values) {
        int nextSum = prefixSums.back() + value;
        prefixSums.push_back(nextSum);
    }

    return prefixSums;
}

int main() {
    std::vector<int> values = {3, 1, 4, 1, 5};

    std::vector<int> prefixSums = buildPrefixSums(values);

    printVector(prefixSums);
}
```

Expected output:

```text
[0, 3, 4, 8, 9, 14]
```

### Test cases

```cpp
{}              // [0]
{5}             // [0, 5]
{1, 1, 1}       // [0, 1, 2, 3]
{-2, 5, -1}     // [0, -2, 3, 2]
```

### Interview explanation

> I create a prefix-sum vector with an initial zero. As I traverse the input, I add each value to the last cumulative sum and append that new total. This takes O(n) time and O(n) extra space because the prefix array stores one additional value for each input value.

## Problem 2: Range Sum Query

You already have a prefix-sum array. Now use it to answer range sums efficiently.

```text
Values:      [3, 1, 4, 1, 5]
Prefix sums: [0, 3, 4, 8, 9, 14]
```

Find the sum from index `left` through index `right`, inclusive.

Examples:

```text
Range [1, 3] → 1 + 4 + 1 = 6
Range [0, 2] → 3 + 1 + 4 = 8
Range [2, 4] → 4 + 1 + 5 = 10
```

## Key formula

```text
rangeSum = prefixSums[right + 1] - prefixSums[left]
```

Why?

For `[1, 3]`:

```text
prefixSums[4] = 9  → sum of values from index 0 through 3
prefixSums[1] = 3  → sum of values before index 1

9 - 3 = 6
```

## Think before coding

- Why is it `right + 1`?
  - The prefix array has a leading zero, so `prefixSums[i]` represents the sum of the first `i` original values.

- Why subtract `prefixSums[left]`?
  - It removes all values before the left boundary.

- Complexity?
  - O(1) time per query after building prefix sums.

## Try this skeleton

```cpp
#include <iostream>
#include <vector>

int rangeSum(
    const std::vector<int>& prefixSums,
    int left,
    int right
) {
    // Return the inclusive sum from left through right.
}

int main() {
    std::vector<int> prefixSums = {0, 3, 4, 8, 9, 14};

    std::cout << rangeSum(prefixSums, 1, 3) << '\n';
    std::cout << rangeSum(prefixSums, 0, 2) << '\n';
    std::cout << rangeSum(prefixSums, 2, 4) << '\n';
}
```

## Reference solution

```cpp
#include <iostream>
#include <vector>

int rangeSum(
    const std::vector<int>& prefixSums,
    int left,
    int right
) {
    return prefixSums[right + 1] - prefixSums[left];
}

int main() {
    std::vector<int> prefixSums = {0, 3, 4, 8, 9, 14};

    std::cout << rangeSum(prefixSums, 1, 3) << '\n';
    std::cout << rangeSum(prefixSums, 0, 2) << '\n';
    std::cout << rangeSum(prefixSums, 2, 4) << '\n';
}
```

Expected output:

```text
6
8
10
```

## Dry run

For:

```text
Range [2, 4]
```

```text
prefixSums[right + 1] - prefixSums[left]
prefixSums[5] - prefixSums[2]
14 - 4
= 10
```

## Test cases

```cpp
rangeSum(prefixSums, 0, 0);  // 3
rangeSum(prefixSums, 4, 4);  // 5
rangeSum(prefixSums, 0, 4);  // 14
rangeSum(prefixSums, 2, 2);  // 4
```

## Important limitation

This basic version assumes the range is valid:

```text
0 <= left <= right < original array size
```

Do not call:

```text
rangeSum(prefixSums, -1, 2)
rangeSum(prefixSums, 3, 8)
rangeSum(prefixSums, 4, 2)
```

We can add validation later.

## Interview explanation

> I use a prefix-sum array where each position stores the total of all values before that index. To get an inclusive range sum, I subtract the sum before the left boundary from the sum after the right boundary. Each query is O(1), after O(n) preprocessing time and O(n) storage.

## Problem 3: Pivot Index

Find an index where the sum of all values to its left equals the sum of all values to its right.

```text
Input:  [1, 7, 3, 6, 5, 6]
Output: 3
```

At index `3`:

```text
Value at pivot: 6

Left side:  1 + 7 + 3 = 11
Right side: 5 + 6 = 11
```

So index `3` is the pivot.

## Key idea

Instead of calculating the left and right sums from scratch at every index:

1. Calculate the total sum once.
2. Keep a running `leftSum`.
3. Derive the right sum:

```text
rightSum = totalSum - leftSum - currentValue
```

Why subtract `currentValue` too?

```text
totalSum = left side + current value + right side
```

So:

```text
right side = totalSum - left side - current value
```

## Dry run

```text
numbers = [1, 7, 3, 6, 5, 6]
totalSum = 28
leftSum = 0
```

| Index | Value | Left sum | Right sum | Pivot? |
|---:|---:|---:|---:|---|
| 0 | 1 | 0 | 27 | No |
| 1 | 7 | 1 | 20 | No |
| 2 | 3 | 8 | 17 | No |
| 3 | 6 | 11 | 11 | Yes |

## Pseudocode

```text
Calculate totalSum
Set leftSum to 0

For every index:
    rightSum = totalSum - leftSum - current value

    If leftSum equals rightSum:
        return current index

    Add current value to leftSum

Return -1
```

## Try this skeleton

```cpp
#include <iostream>
#include <vector>

int findPivotIndex(const std::vector<int>& numbers) {
    int totalSum = 0;

    for (int number : numbers) {
        totalSum += number;
    }

    int leftSum = 0;

    for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
        int rightSum = 0;

        // Calculate rightSum.

        if (leftSum == rightSum) {
            return index;
        }

        // Add the current number to leftSum.
    }

    return -1;
}

int main() {
    std::vector<int> numbers = {1, 7, 3, 6, 5, 6};

    std::cout << "Pivot index: "
              << findPivotIndex(numbers)
              << '\n';
}
```

## Reference solution

```cpp
#include <iostream>
#include <vector>

int findPivotIndex(const std::vector<int>& numbers) {
    int totalSum = 0;

    for (int number : numbers) {
        totalSum += number;
    }

    int leftSum = 0;

    for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
        int rightSum = totalSum - leftSum - numbers[index];

        if (leftSum == rightSum) {
            return index;
        }

        leftSum += numbers[index];
    }

    return -1;
}

int main() {
    std::vector<int> numbers = {1, 7, 3, 6, 5, 6};

    std::cout << "Pivot index: "
              << findPivotIndex(numbers)
              << '\n';
}
```

Expected output:

```text
Pivot index: 3
```

## Test cases

```cpp
{1, 7, 3, 6, 5, 6}  // 3
{1, 2, 3}           // -1
{2, 1, -1}          // 0
{0, 0, 0, 0}        // 0
{5}                 // 0
{}                  // -1
```

## Complexity

```text
Time: O(n)
Extra space: O(1)
```

You make one pass to calculate the total, then one pass to find the pivot. Two consecutive O(n) passes are still O(n).

## Interview explanation

> I first compute the total sum. Then I scan the array while maintaining the sum of values to the left. At each index, the right sum is total sum minus left sum minus the current value. If left and right sums match, I return that index. This takes O(n) time and O(1) extra space.

## Problem 4: Left-and-Right Sum Difference

For every index, calculate:

```text
absolute value of (left sum - right sum)
```

```text
Input:  [10, 4, 8, 3]
Output: [15, 1, 11, 22]
```

## Understand one position first

At index `1`, the value is `4`.

```text
Left side:  10
Right side: 8 + 3 = 11

Difference: |10 - 11| = 1
```

So the second result value is `1`.

## Key idea

Use the same running-sum idea as Pivot Index.

1. Calculate the total sum once.
2. Start `leftSum = 0`.
3. At every index:

```text
rightSum = totalSum - leftSum - currentValue
difference = absolute(leftSum - rightSum)
```

4. Store the difference.
5. Add the current value to `leftSum`.

## Dry run

```text
numbers = [10, 4, 8, 3]
totalSum = 25
leftSum = 0
```

| Index | Value | Left sum | Right sum | Difference |
|---:|---:|---:|---:|---:|
| 0 | 10 | 0 | 15 | 15 |
| 1 | 4 | 10 | 11 | 1 |
| 2 | 8 | 14 | 3 | 11 |
| 3 | 3 | 22 | 0 | 22 |

Final result:

```text
[15, 1, 11, 22]
```

## Pseudocode

```text
Calculate totalSum
leftSum = 0
Create empty result array

For every number:
    rightSum = totalSum - leftSum - current number
    append absolute(leftSum - rightSum) to result
    add current number to leftSum

Return result
```

## Try this skeleton

```cpp
#include <iostream>
#include <vector>

std::vector<int> leftRightDifference(
    const std::vector<int>& numbers
) {
    int totalSum = 0;

    for (int number : numbers) {
        totalSum += number;
    }

    int leftSum = 0;
    std::vector<int> result;

    for (int number : numbers) {
        int rightSum = 0;

        // Calculate rightSum.
        // Add absolute(leftSum - rightSum) to result.
        // Update leftSum.
    }

    return result;
}

void printVector(const std::vector<int>& values) {
    std::cout << '[';

    for (std::size_t index = 0; index < values.size(); ++index) {
        std::cout << values[index];

        if (index + 1 < values.size()) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

int main() {
    std::vector<int> numbers = {10, 4, 8, 3};

    printVector(leftRightDifference(numbers));
}
```

## Reference solution

```cpp
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> leftRightDifference(
    const std::vector<int>& numbers
) {
    int totalSum = 0;

    for (int number : numbers) {
        totalSum += number;
    }

    int leftSum = 0;
    std::vector<int> result;

    for (int number : numbers) {
        int rightSum = totalSum - leftSum - number;

        result.push_back(std::abs(leftSum - rightSum));

        leftSum += number;
    }

    return result;
}

void printVector(const std::vector<int>& values) {
    std::cout << '[';

    for (std::size_t index = 0; index < values.size(); ++index) {
        std::cout << values[index];

        if (index + 1 < values.size()) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

int main() {
    std::vector<int> numbers = {10, 4, 8, 3};

    printVector(leftRightDifference(numbers));
}
```

Expected output:

```text
[15, 1, 11, 22]
```

## Test cases

```cpp
{10, 4, 8, 3}  // [15, 1, 11, 22]
{1}            // [0]
{}             // []
{1, 2, 3}      // [5, 3, 3]
{5, 5, 5}      // [10, 0, 10]
```

## Complexity

```text
Time: O(n)
Output space: O(n)
Extra working space: O(1)
```

The result vector must contain one answer for every input value, so it naturally uses O(n) space.

## Interview explanation

> I first calculate the total sum. Then I traverse the array while maintaining the sum to the left. The right sum is total minus left sum minus the current value. I append the absolute difference to the result and then update the left sum. The algorithm is O(n) time, uses O(1) extra working space, and O(n) space for the required output vector.

Now we move to the first C++ practice question.

## Problem 5: Multi-file Calculator

Goal: practice headers, source files, namespaces, and function declarations/definitions.

Your program will calculate:

```text
7 + 3 = 10
7 - 3 = 4
```

## Project structure

```text
calculator/
├── include/
│   └── calculator.hpp
└── src/
    ├── calculator.cpp
    └── main.cpp
```

## Step 1: Create folders

```bash
cd /home/guru/Documents/ChatGPT/Roadmap2028/day1-practice
mkdir -p calculator/include calculator/src
cd calculator
```

## Step 2: Create the header

```bash
nano include/calculator.hpp
```

Paste:

```cpp
#pragma once

namespace calculator {
    int add(int firstNumber, int secondNumber);

    int subtract(int firstNumber, int secondNumber);
}
```

This header declares what the calculator can do.

```text
calculator::add
calculator::subtract
```

It does not contain the actual calculation code yet.

## Step 3: Create the implementation

```bash
nano src/calculator.cpp
```

Paste:

```cpp
#include "calculator.hpp"

namespace calculator {
    int add(int firstNumber, int secondNumber) {
        return firstNumber + secondNumber;
    }

    int subtract(int firstNumber, int secondNumber) {
        return firstNumber - secondNumber;
    }
}
```

This file defines how the two functions work.

## Step 4: Create `main.cpp`

```bash
nano src/main.cpp
```

Paste:

```cpp
#include <iostream>

#include "calculator.hpp"

int main() {
    int firstNumber = 7;
    int secondNumber = 3;

    std::cout << firstNumber << " + " << secondNumber
              << " = "
              << calculator::add(firstNumber, secondNumber)
              << '\n';

    std::cout << firstNumber << " - " << secondNumber
              << " = "
              << calculator::subtract(firstNumber, secondNumber)
              << '\n';

    return 0;
}
```

## Step 5: Compile all source files

```bash
g++ -std=c++20 -Wall -Wextra -Iinclude src/main.cpp src/calculator.cpp -o calculator_app
```

Then run:

```bash
./calculator_app
```

Expected output:

```text
7 + 3 = 10
7 - 3 = 4
```

## Step 6: Understand the compile command

```bash
g++ -std=c++20 -Wall -Wextra -Iinclude src/main.cpp src/calculator.cpp -o calculator_app
```

| Part | Meaning |
|---|---|
| `-Iinclude` | Look inside `include/` when a source file uses `#include "calculator.hpp"` |
| `src/main.cpp` | Compile the program entry point |
| `src/calculator.cpp` | Compile calculator function definitions |
| `-o calculator_app` | Create an executable named `calculator_app` |

## Step 7: Your modifications

After it works:

1. Add a `multiply` function.
2. Add a `divide` function.
3. For division, handle a second number of `0` safely.

Suggested declaration:

```cpp
int multiply(int firstNumber, int secondNumber);
```

For division, use a boolean success result:

```cpp
bool divide(
    int firstNumber,
    int secondNumber,
    double& result
);
```

Expected behavior:

```text
10 / 2 = 5
Cannot divide by zero.
```

## Interview explanation

> I separated the calculator interface from its implementation. The header declares the functions so other source files know they exist. The source file contains the function definitions, and `main.cpp` calls them through the `calculator` namespace. This makes the code easier to organize, test, and extend.

## Problem 6: Parse One CSV Log Line

Goal: take one text line, split it into three fields, store it in a `LogEntry` struct, and print the result.

```text
Input:
2026-09-20 10:00:01,INFO,Sensor started
```

Expected output:

```text
Timestamp: 2026-09-20 10:00:01
Level: INFO
Message: Sensor started
```

## Step 1: Understand the CSV format

CSV means comma-separated values.

```text
timestamp,level,message
```

For this line:

```text
2026-09-20 10:00:01,INFO,Sensor started
```

```text
timestamp = 2026-09-20 10:00:01
level     = INFO
message   = Sensor started
```

## Step 2: Create a struct

A struct groups fields belonging to one log entry.

```cpp
struct LogEntry {
    std::string timestamp;
    std::string level;
    std::string message;
};
```

## Step 3: Use `std::stringstream`

A `stringstream` lets you read from a string as if it were a file.

```cpp
std::stringstream lineStream(line);
```

Then read until each comma:

```cpp
std::getline(lineStream, timestamp, ',');
std::getline(lineStream, level, ',');
std::getline(lineStream, message);
```

The final call has no comma delimiter because it should read everything remaining as the message.

## Step 4: Try this skeleton

Create:

```bash
cd /home/guru/Documents/ChatGPT/Roadmap2028/day1-practice
nano parse_csv_line.cpp
```

Paste and complete the missing section:

```cpp
#include <iostream>
#include <sstream>
#include <string>

struct LogEntry {
    std::string timestamp;
    std::string level;
    std::string message;
};

bool parseLogLine(const std::string& line, LogEntry& entry) {
    std::stringstream lineStream(line);

    std::string timestamp;
    std::string level;
    std::string message;

    // Read timestamp until the first comma.
    // Read level until the second comma.
    // Read the remaining text as message.

    // If any field is missing or empty, return false.

    // Copy parsed values into entry.
    // Return true.
}

void printEntry(const LogEntry& entry) {
    std::cout << "Timestamp: " << entry.timestamp << '\n';
    std::cout << "Level: " << entry.level << '\n';
    std::cout << "Message: " << entry.message << '\n';
}

int main() {
    std::string line =
        "2026-09-20 10:00:01,INFO,Sensor started";

    LogEntry entry;

    if (parseLogLine(line, entry)) {
        printEntry(entry);
    } else {
        std::cout << "Invalid log line.\n";
    }
}
```

## Step 5: Reference solution

```cpp
#include <iostream>
#include <sstream>
#include <string>

struct LogEntry {
    std::string timestamp;
    std::string level;
    std::string message;
};

bool parseLogLine(const std::string& line, LogEntry& entry) {
    std::stringstream lineStream(line);

    std::string timestamp;
    std::string level;
    std::string message;

    if (!std::getline(lineStream, timestamp, ',') ||
        !std::getline(lineStream, level, ',') ||
        !std::getline(lineStream, message)) {
        return false;
    }

    if (timestamp.empty() || level.empty() || message.empty()) {
        return false;
    }

    entry.timestamp = timestamp;
    entry.level = level;
    entry.message = message;

    return true;
}

void printEntry(const LogEntry& entry) {
    std::cout << "Timestamp: " << entry.timestamp << '\n';
    std::cout << "Level: " << entry.level << '\n';
    std::cout << "Message: " << entry.message << '\n';
}

int main() {
    std::string line =
        "2026-09-20 10:00:01,INFO,Sensor started";

    LogEntry entry;

    if (parseLogLine(line, entry)) {
        printEntry(entry);
    } else {
        std::cout << "Invalid log line.\n";
    }
}
```

## Step 6: Compile and run

```bash
g++ -std=c++20 -Wall -Wextra parse_csv_line.cpp -o parse_csv_line
./parse_csv_line
```

Expected output:

```text
Timestamp: 2026-09-20 10:00:01
Level: INFO
Message: Sensor started
```

## Step 7: Test invalid input

Replace `line` in `main()` with each value:

```cpp
"2026-09-20,INFO,Started"  // valid
"2026-09-20,INFO,"         // invalid
"2026-09-20,,Started"      // invalid
",INFO,Started"            // invalid
"only one field"           // invalid
```

## Interview explanation

> I represent one log record using a struct with timestamp, level, and message fields. I use a string stream to read the line field by field, stopping at commas for the first two fields. If a field is missing or empty, the parser returns false; otherwise, it fills the output `LogEntry` and returns true.

