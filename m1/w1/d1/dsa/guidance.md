## Guided problem: find the largest element

Problem:

```text
Input:  [8, 12, 3, 19, 5]
Output: 19
```

### Step 1: Decide what you must remember

As you scan the array, you only need one piece of information:

```text
The largest number seen so far.
```

For `[8, 12, 3, 19, 5]`:

```text
Start: largest = 8

See 12 → largest = 12
See 3  → largest remains 12
See 19 → largest = 19
See 5  → largest remains 19
```

### Step 2: Answer these before coding

- What should `largest` be initialized to?
  - The first array element.

- Why not initialize it to `0`?
  - An array such as `[-8, -3, -12]` would incorrectly return `0`.

- How many times do you scan the array?
  - Once.

- Complexity?
  - O(n) time and O(1) extra space.

### Step 3: Write pseudocode

```text
If the array is empty:
    report that there is no largest value

Set largest to the first element

For every remaining element:
    if current element is greater than largest:
        update largest

Return largest
```

### Step 4: Convert it to C++

Try completing the missing parts yourself first:

```cpp
#include <iostream>
#include <vector>

int findLargest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        // What should happen here?
    }

    int largest = numbers[0];

    for (int index = 1; index < numbers.size(); ++index) {
        // Compare numbers[index] with largest
        // Update largest if needed
    }

    return largest;
}

int main() {
    std::vector<int> numbers = {8, 12, 3, 19, 5};

    std::cout << "Largest: " << findLargest(numbers) << '\n';
    return 0;
}
```

### Step 5: Reference solution

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

int findLargest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Cannot find largest value in an empty array.");
    }

    int largest = numbers[0];

    for (int index = 1; index < static_cast<int>(numbers.size()); ++index) {
        if (numbers[index] > largest) {
            largest = numbers[index];
        }
    }

    return largest;
}

int main() {
    std::vector<int> numbers = {8, 12, 3, 19, 5};

    std::cout << "Largest: " << findLargest(numbers) << '\n';
    return 0;
}
```

Expected output:

```text
Largest: 19
```

### Step 6: Test cases

Run these before considering it complete:

```cpp
{8, 12, 3, 19, 5}      // 19
{-8, -3, -12}          // -3
{42}                   // 42
{5, 5, 5}              // 5
{-1, 0, 1}             // 1
```

For an empty vector, the reference solution throws an exception. In an interview, clearly state that you are handling empty input explicitly; if the problem guarantees a non-empty array, you can omit that check.

### Interview answer

> I initialize `largest` with the first value so the solution works even when every value is negative. I then scan the remaining elements once and update `largest` whenever I find a larger number. The algorithm visits each value once, so it runs in O(n) time and uses O(1) extra space.


Next: **Two Sum** — the key Day 1 hash-map problem.

## Problem

Given an array and a target, return indices of two different numbers whose sum equals the target.

```text
Input:  numbers = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

Because:

```text
numbers[0] + numbers[1] = 2 + 7 = 9
```

## Step 1: Brute force idea

Compare every pair:

```text
2 + 7
2 + 11
2 + 15
7 + 11
...
```

This works, but it can take **O(n²)** time.

## Step 2: Better observation

For every current number, calculate what number you need:

```text
needed = target - currentNumber
```

Example:

```text
Target: 9
Current number: 7
Needed number: 9 - 7 = 2
```

If you have already seen `2`, you have found the answer.

## Step 3: Walkthrough

```text
numbers = [2, 7, 11, 15]
target = 9

seenNumbers = {}

Index 0, number = 2
Needed = 9 - 2 = 7
Has 7 appeared before? No
Store: 2 → index 0

seenNumbers = {2: 0}

Index 1, number = 7
Needed = 9 - 7 = 2
Has 2 appeared before? Yes

Answer: [0, 1]
```

## Step 4: Pseudocode

```text
Create an empty hash map: number → index

For every index and number:
    needed = target - number

    If needed exists in the hash map:
        return [stored index of needed, current index]

    Store current number and current index in the hash map
```

Important: **check first, then store**. This prevents accidentally using the same element twice.

## Step 5: Reference C++ solution

```cpp
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::pair<int, int> twoSum(
    const std::vector<int>& numbers,
    int target
) {
    std::unordered_map<int, int> indexByNumber;

    for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
        int currentNumber = numbers[index];
        int neededNumber = target - currentNumber;

        if (indexByNumber.contains(neededNumber)) {
            return {indexByNumber[neededNumber], index};
        }

        indexByNumber[currentNumber] = index;
    }

    return {-1, -1};
}

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    auto [firstIndex, secondIndex] = twoSum(numbers, target);

    std::cout << '[' << firstIndex << ", " << secondIndex << "]\n";
}
```

Expected output:

```text
[0, 1]
```

## Test cases

```cpp
{2, 7, 11, 15}, 9      // [0, 1]
{3, 2, 4}, 6           // [1, 2]
{3, 3}, 6              // [0, 1]
{-1, -2, -3, -4}, -6   // [1, 3]
{1, 2, 3}, 10          // [-1, -1]
```

## Interview explanation

> I use a hash map to store every number I have seen along with its index. For each current number, I calculate its complement, which is `target - currentNumber`. If that complement is already in the map, I return the stored index and current index. Each value is processed once, giving O(n) average time complexity and O(n) extra space.

Add this to your notes:

```md
## Two Sum pattern

When asked to find two values satisfying a target condition:

1. Iterate through the array.
2. Compute the complement needed.
3. Check whether the complement was seen before.
4. Store the current value after checking.

Time: O(n) average
Space: O(n)
```

