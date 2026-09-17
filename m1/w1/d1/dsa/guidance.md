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