# C++ 80:20 Refresh — Hands-On Answers

This file is the **answer key for the hands-on exercises** in Chapters 1–9 of the refresher.

## How to use this answer key

Try each exercise yourself first. Then compare your solution with the answer here.

The examples favor:

- clear beginner-friendly C++17
- `std::vector`, `std::string`, and STL containers where they are appropriate
- functions for reusable logic
- simple solutions before optimized solutions
- DSA-oriented habits such as stating complexity

Most snippets are complete programs. Where several exercises are closely related, one snippet may demonstrate the core solution and a nearby variation.

Compile with:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic program.cpp -o program
./program
```

---

# Chapter 1 — Basics, Input/Output, Variables and Types

## 1. Hello profile

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    std::cin >> name >> age;

    std::cout << "Hello " << name << "\n";
    std::cout << "You are " << age << " years old.\n";
}
```

> If the name may contain spaces, use `std::getline` instead of `operator>>` for the name.

## 2. Rectangle calculator

```cpp
#include <iostream>

int main() {
    double length, width;
    std::cin >> length >> width;

    double area = length * width;
    double perimeter = 2 * (length + width);

    std::cout << "Area: " << area << "\n";
    std::cout << "Perimeter: " << perimeter << "\n";
}
```

## 3. Temperature converter

```cpp
#include <iostream>

int main() {
    double celsius;
    std::cin >> celsius;

    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    std::cout << fahrenheit << '\n';
}
```

Using `9.0 / 5.0` avoids accidental integer division.

## 4. Simple interest

```cpp
#include <iostream>

int main() {
    double principal, rate, time;
    std::cin >> principal >> rate >> time;

    double interest = principal * rate * time / 100.0;
    std::cout << interest << '\n';
}
```

## 5. Average of three numbers

```cpp
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    double average = (a + b + c) / 3.0;
    std::cout << average << '\n';
}
```

## 6. Last digit

```cpp
#include <iostream>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;

    std::cout << std::abs(n % 10) << '\n';
}
```

For a positive integer, the simpler `n % 10` is enough.

## 7. Sum of digits — two digit number

```cpp
#include <iostream>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;
    n = std::abs(n);

    int tens = n / 10;
    int ones = n % 10;
    std::cout << tens + ones << '\n';
}
```

## 8. Seconds converter

```cpp
#include <iostream>

int main() {
    long long total;
    std::cin >> total;

    long long hours = total / 3600;
    total %= 3600;
    long long minutes = total / 60;
    long long seconds = total % 60;

    std::cout << hours << ' ' << minutes << ' ' << seconds << '\n';
}
```

## 9. Swap two values

```cpp
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;

    std::cout << a << ' ' << b << '\n';
}
```

## 10. Swap without a third variable

In real code, prefer `std::swap` because it is clearer:

```cpp
#include <iostream>
#include <utility>

int main() {
    int a, b;
    std::cin >> a >> b;

    std::swap(a, b);

    std::cout << a << ' ' << b << '\n';
}
```

The classic arithmetic version is educational but less robust for integer overflow:

```cpp
a = a + b;
b = a - b;
a = a - b;
```

## Challenge A — Salary breakdown

Assuming the three additions are percentages of the **base salary**:

```cpp
#include <iostream>

int main() {
    double base, p1, p2, p3;
    std::cin >> base >> p1 >> p2 >> p3;

    double finalSalary = base * (1.0 + (p1 + p2 + p3) / 100.0);
    std::cout << finalSalary << '\n';
}
```

If the intended meaning is that each percentage compounds on the previous result, apply them one at a time instead.

## Challenge B — Digit extraction

```cpp
#include <iostream>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;
    n = std::abs(n);

    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int ones = n % 10;

    std::cout << hundreds << ' ' << tens << ' ' << ones << '\n';
}
```

## Challenge C — Expression prediction

Output:

```text
2
1
2.5
```

Reason: `5 / 2` is integer division, `5 % 2` is `1`, and casting `5` to `double` makes the final division floating-point.

## Challenge D — Type awareness

One reasonable set of choices:

```cpp
long long population = 1400000000LL;
double productPrice = 2499.50;
char firstLetter = 'B';
bool loggedIn = true;
std::string fullName = "Asha Rao";
```

---

# Chapter 2 — Operators, Conditions and Loops

## 1. Even or odd

```cpp
#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    std::cout << (n % 2 == 0 ? "Even" : "Odd") << '\n';
}
```

## 2. Positive, negative, or zero

```cpp
#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    if (n > 0) std::cout << "Positive\n";
    else if (n < 0) std::cout << "Negative\n";
    else std::cout << "Zero\n";
}
```

## 3. Largest of three

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::max({a, b, c}) << '\n';
}
```

## 4. Leap year

A year is a leap year when it is divisible by 400, or divisible by 4 but not by 100.

```cpp
#include <iostream>

int main() {
    int year;
    std::cin >> year;

    bool leap = (year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0);

    std::cout << (leap ? "Leap year" : "Not a leap year") << '\n';
}
```

## 5. Grade calculator

One reasonable policy is A/B/C/D/F; the exact cutoffs were not specified.

```cpp
#include <iostream>

int main() {
    int score;
    std::cin >> score;

    if (score >= 90) std::cout << 'A';
    else if (score >= 80) std::cout << 'B';
    else if (score >= 70) std::cout << 'C';
    else if (score >= 60) std::cout << 'D';
    else std::cout << 'F';

    std::cout << '\n';
}
```

## 6. Triangle validity

The three side lengths form a triangle exactly when all are positive and the sum of any two is greater than the third.

```cpp
#include <iostream>

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    bool valid = a > 0 && b > 0 && c > 0 &&
                 a + b > c && a + c > b && b + c > a;

    std::cout << (valid ? "Valid" : "Invalid") << '\n';
}
```

## 7. Calculator with `switch`

```cpp
#include <iostream>

int main() {
    double a, b;
    char op;
    std::cin >> a >> op >> b;

    switch (op) {
        case '+': std::cout << a + b; break;
        case '-': std::cout << a - b; break;
        case '*': std::cout << a * b; break;
        case '/':
            if (b == 0) std::cout << "Cannot divide by zero";
            else std::cout << a / b;
            break;
        default:
            std::cout << "Invalid operator";
    }
    std::cout << '\n';
}
```

## 8. Print 1 to N

```cpp
int n;
std::cin >> n;
for (int i = 1; i <= n; ++i) {
    std::cout << i << ' ';
}
```

## 9. Print N to 1

```cpp
int n;
std::cin >> n;
for (int i = n; i >= 1; --i) {
    std::cout << i << ' ';
}
```

## 10. Sum 1 to N

Loop version:

```cpp
long long n;
std::cin >> n;
long long sum = 0;
for (long long i = 1; i <= n; ++i) {
    sum += i;
}
std::cout << sum << '\n';
```

Formula version:

```cpp
long long sum = n * (n + 1) / 2;
```

The loop is `O(n)`. The formula is `O(1)`.

## 11. Count digits

```cpp
#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 1 << '\n';
        return 0;
    }

    n = n < 0 ? -n : n;
    int count = 0;
    while (n > 0) {
        n /= 10;
        ++count;
    }
    std::cout << count << '\n';
}
```

## 12. Reverse a number

```cpp
#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    long long x = n < 0 ? -n : n;
    long long rev = 0;

    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    if (n < 0) rev = -rev;
    std::cout << rev << '\n';
}
```

## 13. Palindrome number

```cpp
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n < 0) {
        std::cout << "Not palindrome\n";
        return 0;
    }

    int original = n;
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    std::cout << (original == rev ? "Palindrome" : "Not palindrome") << '\n';
}
```

## 14. Count even and odd digits

```cpp
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    n = n < 0 ? -n : n;

    int even = 0, odd = 0;
    if (n == 0) ++even;

    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) ++even;
        else ++odd;
        n /= 10;
    }

    std::cout << "Even digits: " << even << '\n';
    std::cout << "Odd digits: " << odd << '\n';
}
```

## 15. Sum of digits

```cpp
int n;
std::cin >> n;
n = n < 0 ? -n : n;
int sum = 0;
while (n > 0) {
    sum += n % 10;
    n /= 10;
}
```

For `0`, the sum remains `0`.

## 16. Multiplication table

```cpp
int n;
std::cin >> n;
for (int i = 1; i <= 10; ++i) {
    std::cout << n << " x " << i << " = " << n * i << '\n';
}
```

## 17. Prime check

Simple version:

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int d = 2; d < n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}
```

Better version:

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int d = 2; 1LL * d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}
```

## 18. Print primes in a range

```cpp
#include <iostream>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int d = 2; 1LL * d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int L, R;
    std::cin >> L >> R;

    for (int n = L; n <= R; ++n) {
        if (isPrime(n)) std::cout << n << ' ';
    }
    std::cout << '\n';
}
```

## 19. Greatest common divisor

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a < 0 ? -a : a;
}
```

## 20. Pattern printing

Increasing triangle:

```cpp
for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= i; ++j) {
        std::cout << '*';
    }
    std::cout << '\n';
}
```

Decreasing triangle:

```cpp
for (int i = 5; i >= 1; --i) {
    for (int j = 1; j <= i; ++j) {
        std::cout << '*';
    }
    std::cout << '\n';
}
```

## Mini Debugging Drill

First program:

```cpp
for (int i = 0; i <= n; ++i)
```

is not automatically wrong. It prints `0` through `n`. If the intended range is `0` through `n - 1`, use:

```cpp
for (int i = 0; i < n; ++i)
```

Second program:

```cpp
if (x = 10)
```

assigns `10` to `x`. It should be:

```cpp
if (x == 10)
```

---

# Chapter 3 — Functions, Scope and Recursion

## 1. `maxOfTwo`

```cpp
int maxOfTwo(int a, int b) {
    return a > b ? a : b;
}
```

## 2. `isEven`

```cpp
bool isEven(int n) {
    return n % 2 == 0;
}
```

## 3. `isPrime`

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int d = 2; 1LL * d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}
```

## 4. `gcd`

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a < 0 ? -a : a;
}
```

## 5. `power`

```cpp
long long power(long long base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
```

Assumes `exponent >= 0`.

## 6. `countDigits`

```cpp
int countDigits(long long n) {
    if (n == 0) return 1;
    if (n < 0) n = -n;

    int count = 0;
    while (n > 0) {
        n /= 10;
        ++count;
    }
    return count;
}
```

## 7. `reverseNumber`

```cpp
long long reverseNumber(long long n) {
    bool negative = n < 0;
    if (negative) n = -n;

    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return negative ? -rev : rev;
}
```

## 8. `swap`

```cpp
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## 9. Array sum

```cpp
#include <vector>

int sum(const std::vector<int>& a) {
    int total = 0;
    for (int x : a) total += x;
    return total;
}
```

## 10. Count occurrences

```cpp
#include <vector>

int countOccurrences(const std::vector<int>& a, int x) {
    int count = 0;
    for (int value : a) {
        if (value == x) ++count;
    }
    return count;
}
```

## 11. Factorial recursively

```cpp
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

The base case stops the recursion.

## 12. Sum from 1 to N recursively

```cpp
long long sumToN(int n) {
    if (n <= 0) return 0;
    return n + sumToN(n - 1);
}
```

## 13. Print 1 to N recursively

```cpp
void print1ToN(int n) {
    if (n <= 0) return;
    print1ToN(n - 1);
    std::cout << n << ' ';
}
```

## 14. Print N to 1 recursively

```cpp
void printNTo1(int n) {
    if (n <= 0) return;
    std::cout << n << ' ';
    printNTo1(n - 1);
}
```

## 15. Sum of digits recursively

```cpp
int digitSum(int n) {
    if (n < 0) n = -n;
    if (n < 10) return n;
    return n % 10 + digitSum(n / 10);
}
```

## 16. Reverse a string recursively

```cpp
void printReverse(const std::string& s, int index) {
    if (index < 0) return;
    std::cout << s[index];
    printReverse(s, index - 1);
}
```

Call with:

```cpp
printReverse(s, static_cast<int>(s.size()) - 1);
```

## 17. Fibonacci — naive recursion

```cpp
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

The naive version is slow because the same subproblems are recomputed many times. Its time grows exponentially, commonly described as `O(2^n)`.

## Tiny Refactoring Exercise

A clean decomposition is:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> readInput() {
    std::vector<int> a(5);
    for (int& x : a) std::cin >> x;
    return a;
}

int findMax(const std::vector<int>& a) {
    return *std::max_element(a.begin(), a.end());
}

int countEvens(const std::vector<int>& a) {
    int count = 0;
    for (int x : a) {
        if (x % 2 == 0) ++count;
    }
    return count;
}

int main() {
    std::vector<int> a = readInput();
    std::cout << "Max: " << findMax(a) << '\n';
    std::cout << "Evens: " << countEvens(a) << '\n';
}
```

---

# Chapter 4 — Arrays, Strings and Vectors

For the raw-array examples below, assume a fixed array such as:

```cpp
int a[] = {4, 2, 7, 2, 9};
int n = 5;
```

## 1. Print an array

```cpp
for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
}
```

## 2. Sum all elements

```cpp
int total = 0;
for (int i = 0; i < n; ++i) {
    total += a[i];
}
```

## 3. Find minimum and maximum

```cpp
int mn = a[0];
int mx = a[0];
for (int i = 1; i < n; ++i) {
    mn = std::min(mn, a[i]);
    mx = std::max(mx, a[i]);
}
```

## 4. Count positive, negative, and zero values

```cpp
int positive = 0, negative = 0, zero = 0;
for (int i = 0; i < n; ++i) {
    if (a[i] > 0) ++positive;
    else if (a[i] < 0) ++negative;
    else ++zero;
}
```

## 5. Count even numbers

```cpp
int count = 0;
for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) ++count;
}
```

## 6. Find the first occurrence of X

```cpp
int firstOccurrence(const int a[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}
```

## 7. Find the last occurrence of X

```cpp
int lastOccurrence(const int a[], int n, int x) {
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == x) return i;
    }
    return -1;
}
```

## 8. Reverse an array in place

```cpp
void reverseArray(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        std::swap(a[left], a[right]);
        ++left;
        --right;
    }
}
```

## 9. Check whether an array is sorted

```cpp
bool isSorted(const int a[], int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}
```

This checks non-decreasing order.

## 10. Second largest distinct value

```cpp
#include <vector>
#include <optional>
#include <limits>

std::optional<int> secondLargestDistinct(const std::vector<int>& a) {
    std::optional<int> largest;
    std::optional<int> second;

    for (int x : a) {
        if (!largest || x > *largest) {
            if (largest && x != *largest) second = largest;
            largest = x;
        } else if (x != *largest && (!second || x > *second)) {
            second = x;
        }
    }
    return second;
}
```

Example use:

```cpp
std::vector<int> a = {5, 1, 5, 4, 2};
auto answer = secondLargestDistinct(a);
if (answer) std::cout << *answer << '\n';
else std::cout << "No second distinct value\n";
```

## 11. Read N numbers into a vector

```cpp
int n;
std::cin >> n;
std::vector<int> a(n);
for (int& x : a) std::cin >> x;
```

## 12. Sum and average

```cpp
long long sum = 0;
for (int x : a) sum += x;

double average = a.empty() ? 0.0
                           : static_cast<double>(sum) / a.size();
```

## 13. Remove all occurrences of X

New-vector version:

```cpp
std::vector<int> removeX(const std::vector<int>& a, int x) {
    std::vector<int> result;
    for (int value : a) {
        if (value != x) result.push_back(value);
    }
    return result;
}
```

In-place STL version:

```cpp
a.erase(std::remove(a.begin(), a.end(), x), a.end());
```

## 14. Rotate right by one

```cpp
void rotateRightByOne(std::vector<int>& a) {
    if (a.empty()) return;
    int last = a.back();
    for (int i = static_cast<int>(a.size()) - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = last;
}
```

## 15. Move all zeros to the end

Stable in-place solution:

```cpp
void moveZeros(std::vector<int>& a) {
    int write = 0;

    for (int x : a) {
        if (x != 0) {
            a[write++] = x;
        }
    }

    while (write < static_cast<int>(a.size())) {
        a[write++] = 0;
    }
}
```

Time: `O(n)`, extra space: `O(1)`.

## 16. Merge two sorted vectors

```cpp
std::vector<int> mergeSorted(const std::vector<int>& a,
                             const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());

    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}
```

Time: `O(n + m)`.

## 17. Count vowels

```cpp
int countVowels(const std::string& s) {
    int count = 0;
    for (char c : s) {
        char x = static_cast<char>(std::tolower(
            static_cast<unsigned char>(c)));
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            ++count;
        }
    }
    return count;
}
```

## 18. Count uppercase/lowercase letters

```cpp
int upper = 0, lower = 0;
for (char c : s) {
    unsigned char u = static_cast<unsigned char>(c);
    if (std::isupper(u)) ++upper;
    else if (std::islower(u)) ++lower;
}
```

Include `<cctype>`.

## 19. Reverse a string

```cpp
std::reverse(s.begin(), s.end());
```

Manual version:

```cpp
for (int l = 0, r = static_cast<int>(s.size()) - 1; l < r; ++l, --r) {
    std::swap(s[l], s[r]);
}
```

## 20. Check palindrome string

```cpp
bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}
```

## 21. Count words

Count a word whenever you move from a space to a non-space character.

```cpp
int countWords(const std::string& s) {
    int count = 0;
    bool inWord = false;

    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            if (!inWord) {
                ++count;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}
```

## 22. Remove spaces

```cpp
std::string removeSpaces(const std::string& s) {
    std::string result;
    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            result += c;
        }
    }
    return result;
}
```

## 23. Toggle case

```cpp
std::string toggleCase(std::string s) {
    for (char& c : s) {
        unsigned char u = static_cast<unsigned char>(c);
        if (std::islower(u)) c = static_cast<char>(std::toupper(u));
        else if (std::isupper(u)) c = static_cast<char>(std::tolower(u));
    }
    return s;
}
```

## 24. Character frequency

Frequency array version:

```cpp
int freq[26] = {};
for (char c : s) {
    if (c >= 'a' && c <= 'z') {
        ++freq[c - 'a'];
    }
}
```

`unordered_map` version:

```cpp
std::unordered_map<char, int> freq;
for (char c : s) ++freq[c];
```

## DSA Thinking Drill — model answers

| Problem | Input | Simple algorithm | Time | Extra space |
|---|---|---|---|---|
| Find maximum | array | scan and keep best | `O(n)` | `O(1)` |
| Check palindrome | string | compare ends moving inward | `O(n)` | `O(1)` |
| Count frequencies | sequence/string | update count table | `O(n)` average | `O(k)` |
| Move zeros | array | write non-zeros, fill zeros | `O(n)` | `O(1)` |
| Merge sorted arrays | two sorted arrays | two pointers | `O(n+m)` | `O(n+m)` for result |

The important habit is to write this down **before** coding.

---

# Chapter 5 — References, Pointers and Memory

## 1. Change through reference

```cpp
void setToZero(int& x) {
    x = 0;
}
```

## 2. Change through pointer

```cpp
void setToZero(int* x) {
    if (x != nullptr) {
        *x = 0;
    }
}
```

Call it as:

```cpp
int x = 42;
setToZero(&x);
```

## 3. Swap through references

```cpp
void swapValues(int& a, int& b) {
    std::swap(a, b);
}
```

## 4. Swap through pointers

```cpp
void swapValues(int* a, int* b) {
    if (!a || !b) return;
    std::swap(*a, *b);
}
```

## 5. Find maximum using a pointer

```cpp
int maxValue(const int* a, int n) {
    if (n <= 0) return 0; // define your preferred empty-input behavior

    int mx = a[0];
    for (int i = 1; i < n; ++i) {
        mx = std::max(mx, a[i]);
    }
    return mx;
}
```

## 6. Traverse an array with pointer arithmetic

```cpp
void printArray(const int* a, int n) {
    const int* p = a;
    for (int i = 0; i < n; ++i) {
        std::cout << *(p + i) << ' ';
    }
}
```

## 7. Sum through pointers

```cpp
int sum(const int* a, int n) {
    int total = 0;
    for (const int* p = a; p != a + n; ++p) {
        total += *p;
    }
    return total;
}
```

## 8. Reverse array using two pointers

```cpp
void reverseArray(int* a, int n) {
    if (n <= 1) return;

    int* left = a;
    int* right = a + n - 1;

    while (left < right) {
        std::swap(*left, *right);
        ++left;
        --right;
    }
}
```

This is the pointer form of the same two-pointer idea used constantly in DSA.

## 9. Pointer safety test

```cpp
int main() {
    int x = 42;
    int* p = &x;
    int* q = nullptr;

    if (p != nullptr) std::cout << *p << '\n';
    if (q != nullptr) std::cout << *q << '\n';
}
```

Never dereference a null pointer.

## 10. Dynamic array exercise

Manual allocation:

```cpp
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        a[i] = i * 10;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    delete[] a;
}
```

Modern version:

```cpp
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i * 10;

    for (int x : a) std::cout << x << ' ';
    std::cout << '\n';
}
```

The vector version automatically manages memory and is normally preferable.

## DSA Bridge Exercise

Given:

```cpp
struct Node {
    int value;
    Node* next;
};
```

- `value` is the data stored in the node.
- `next` is a pointer to another `Node`.
- `Node*` means “pointer to a `Node`”.
- `next == nullptr` means this node is not pointing to another node.

This is the basic shape behind a singly linked list.

---

# Chapter 6 — Structs, Classes and Constructors

## 1. `Point`

```cpp
#include <cstdlib>

struct Point {
    int x;
    int y;
};

int manhattanDistance(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}
```

## 2. `Student`

```cpp
struct Student {
    std::string name;
    int score;
};

const Student* highestScorer(const std::vector<Student>& students) {
    if (students.empty()) return nullptr;

    const Student* best = &students[0];
    for (const Student& s : students) {
        if (s.score > best->score) best = &s;
    }
    return best;
}
```

## 3. `Product`

```cpp
struct Product {
    std::string name;
    double price;
    int quantity;
};

double inventoryValue(const Product& p) {
    return p.price * p.quantity;
}
```

## 4. `Book`

```cpp
struct Book {
    std::string title;
    std::string author;
    int year;
};

void printNewerThan(const std::vector<Book>& books, int year) {
    for (const Book& b : books) {
        if (b.year > year) {
            std::cout << b.title << " by " << b.author << '\n';
        }
    }
}
```

## 5. `Rectangle`

```cpp
struct Rectangle {
    double width;
    double height;

    double area() const {
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }
};
```

## 6. Constructor practice

```cpp
class Point {
private:
    int x;
    int y;

public:
    Point(int xValue, int yValue) : x(xValue), y(yValue) {}

    int getX() const { return x; }
    int getY() const { return y; }
};
```

## 7. `Counter`

```cpp
class Counter {
private:
    int value = 0;

public:
    void increment() { ++value; }
    void decrement() { --value; }
    int get() const { return value; }
};
```

## 8. Simple node

```cpp
#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main() {
    Node first{10, nullptr};
    Node second{20, nullptr};

    first.next = &second;

    std::cout << first.value << '\n';
    std::cout << first.next->value << '\n';
}
```

## 9. Array of structs

```cpp
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int score;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (Student& s : students) {
        std::cin >> s.name >> s.score;
    }

    if (students.empty()) return 0;

    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (students[i].score > students[best].score) best = i;
    }

    std::cout << students[best].name << ' ' << students[best].score << '\n';
}
```

## 10. Sort-ready record

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

struct Item {
    int id;
    int value;
};

int main() {
    std::vector<Item> items = {{1, 50}, {2, 10}, {3, 30}};

    std::sort(items.begin(), items.end(),
              [](const Item& a, const Item& b) {
                  return a.value < b.value;
              });

    for (const Item& item : items) {
        std::cout << item.id << ' ' << item.value << '\n';
    }
}
```

The lambda is the pattern you will use frequently for custom STL sorting.

---

# Chapter 7 — Essential STL for DSA

## 1. Sort ascending

```cpp
std::sort(a.begin(), a.end());
```

## 2. Sort descending

```cpp
std::sort(a.begin(), a.end(), std::greater<int>());
```

Include `<functional>` if needed.

## 3. Reverse a vector

```cpp
std::reverse(a.begin(), a.end());
```

## 4. Find minimum and maximum

Manual:

```cpp
int mn = a[0], mx = a[0];
for (int x : a) {
    mn = std::min(mn, x);
    mx = std::max(mx, x);
}
```

STL:

```cpp
int mn = *std::min_element(a.begin(), a.end());
int mx = *std::max_element(a.begin(), a.end());
```

For an empty vector, check `a.empty()` before dereferencing the iterator.

## 5. Remove duplicates

```cpp
std::sort(a.begin(), a.end());
a.erase(std::unique(a.begin(), a.end()), a.end());
```

Important: `std::unique` does **not** change the vector's size by itself. It moves unique values toward the front and returns the new logical end. `erase` removes the remaining tail.

## 6. Merge and sort

```cpp
std::vector<int> result = a;
result.insert(result.end(), b.begin(), b.end());
std::sort(result.begin(), result.end());
```

This is easy and costs `O((n+m) log(n+m))` after concatenation.

For already sorted inputs, the earlier two-pointer merge is better: `O(n+m)`.

## 7. Character frequency

```cpp
std::unordered_map<char, int> freq;
for (char c : s) ++freq[c];

for (const auto& [ch, count] : freq) {
    std::cout << ch << " -> " << count << '\n';
}
```

The iteration order of `unordered_map` is not sorted.

## 8. Most frequent value

```cpp
int mostFrequent(const std::vector<int>& a) {
    std::unordered_map<int, int> freq;
    for (int x : a) ++freq[x];

    int bestValue = 0;
    int bestCount = 0;

    for (const auto& [value, count] : freq) {
        if (count > bestCount) {
            bestCount = count;
            bestValue = value;
        }
    }
    return bestValue;
}
```

When ties matter, define a tie-breaking rule explicitly.

## 9. First unique character

```cpp
int firstUniqueIndex(const std::string& s) {
    std::unordered_map<char, int> freq;
    for (char c : s) ++freq[c];

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (freq[s[i]] == 1) return i;
    }
    return -1;
}
```

## 10. Duplicate detector

```cpp
bool hasDuplicate(const std::vector<int>& a) {
    std::unordered_set<int> seen;
    for (int x : a) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}
```

Average time: `O(n)`, extra space: `O(n)`.

## 11. Common elements

`set` version gives sorted distinct results:

```cpp
std::set<int> common;
std::set<int> seenA(a.begin(), a.end());

for (int x : b) {
    if (seenA.count(x)) common.insert(x);
}

for (int x : common) std::cout << x << ' ';
```

`unordered_set` version:

```cpp
std::unordered_set<int> seenA(a.begin(), a.end());
std::unordered_set<int> result;

for (int x : b) {
    if (seenA.count(x)) result.insert(x);
}
```

The second version does not guarantee sorted output.

## 12. Balanced parentheses

```cpp
bool balanced(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            char open = st.top();
            st.pop();

            bool match = (open == '(' && c == ')') ||
                         (open == '[' && c == ']') ||
                         (open == '{' && c == '}');
            if (!match) return false;
        }
    }

    return st.empty();
}
```

## 13. Reverse using a stack

```cpp
std::string reverseWithStack(const std::string& s) {
    std::stack<char> st;
    for (char c : s) st.push(c);

    std::string result;
    result.reserve(s.size());
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
```

## 14. Queue simulation

```cpp
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<int> q;
    std::string command;

    while (std::cin >> command && command != "exit") {
        if (command == "push") {
            int x;
            std::cin >> x;
            q.push(x);
        } else if (command == "pop") {
            if (q.empty()) std::cout << "empty\n";
            else {
                q.pop();
            }
        } else if (command == "front") {
            if (q.empty()) std::cout << "empty\n";
            else std::cout << q.front() << '\n';
        }
    }
}
```

## 15. First non-repeating character

```cpp
int firstNonRepeating(const std::string& s) {
    std::unordered_map<char, int> freq;
    for (char c : s) ++freq[c];

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (freq[s[i]] == 1) return i;
    }
    return -1;
}
```

## 16. Find the K largest elements

Simple max-heap approach:

```cpp
std::vector<int> kLargest(const std::vector<int>& a, int k) {
    std::priority_queue<int> pq(a.begin(), a.end());
    std::vector<int> result;

    for (int i = 0; i < k && !pq.empty(); ++i) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
```

For small `k`, the more memory-efficient min-heap keeps only `k` elements:

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

for (int x : a) {
    pq.push(x);
    if (static_cast<int>(pq.size()) > k) pq.pop();
}
```

## 17. K smallest elements

Max-heap of size `k`:

```cpp
std::priority_queue<int> pq;

for (int x : a) {
    pq.push(x);
    if (static_cast<int>(pq.size()) > k) pq.pop();
}
```

At the end, the heap contains the `k` smallest values.

## 18. Running maximum

If the goal is specifically to practice a priority queue:

```cpp
std::priority_queue<int> pq;

for (int x : stream) {
    pq.push(x);
    std::cout << pq.top() << ' ';
}
```

A plain variable would be simpler for a running maximum, but the exercise is to practice the heap interface.

## STL Speed-Memory Exercise — model cheat sheet

```text
vector: dynamic sequence
set: unique + sorted
map: key -> value + sorted keys
unordered_map: key -> value, average fast lookup
stack: LIFO
queue: FIFO
priority_queue: highest priority on top
sort: reorder sequence
```

---

# Chapter 8 — DSA-Ready Patterns and Complexity

## 1. Linear search

```cpp
int linearSearch(const std::vector<int>& a, int target) {
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (a[i] == target) return i;
    }
    return -1;
}
```

Time: `O(n)`, extra space: `O(1)`.

## 2. Two-sum brute force

```cpp
std::pair<int, int> twoSumBrute(const std::vector<int>& a, int target) {
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(a.size()); ++j) {
            if (a[i] + a[j] == target) return {i, j};
        }
    }
    return {-1, -1};
}
```

Time: `O(n^2)`, extra space: `O(1)`.

## 3. Two-sum with a hash set/map

Map version returns indexes:

```cpp
std::pair<int, int> twoSumHash(const std::vector<int>& a, int target) {
    std::unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        int need = target - a[i];
        auto it = seen.find(need);
        if (it != seen.end()) return {it->second, i};
        seen[a[i]] = i;
    }

    return {-1, -1};
}
```

Average time: `O(n)`, extra space: `O(n)`.

## 4. Two-pointer palindrome

```cpp
bool palindromeTwoPointer(const std::string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}
```

## 5. Two-pointer pair sum

The array must be sorted.

```cpp
bool pairSumSorted(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;

    while (left < right) {
        long long sum = static_cast<long long>(a[left]) + a[right];
        if (sum == target) return true;
        if (sum < target) ++left;
        else --right;
    }
    return false;
}
```

Time: `O(n)` after sorting. If you must sort first, total time is `O(n log n)`.

## 6. Prefix sum array

Using a prefix array where `prefix[i]` is the sum of the first `i` elements:

```cpp
std::vector<long long> buildPrefix(const std::vector<int>& a) {
    std::vector<long long> prefix(a.size() + 1, 0);
    for (size_t i = 0; i < a.size(); ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    return prefix;
}
```

## 7. Range sum queries

For an inclusive query `[L, R]`:

```cpp
long long rangeSum(const std::vector<long long>& prefix, int L, int R) {
    return prefix[R + 1] - prefix[L];
}
```

Preprocessing: `O(n)`. Each query: `O(1)`.

## 8. Maximum subarray — brute force

```cpp
long long maxSubarrayBrute(const std::vector<int>& a) {
    long long best = a[0];

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        long long sum = 0;
        for (int j = i; j < static_cast<int>(a.size()); ++j) {
            sum += a[j];
            best = std::max(best, sum);
        }
    }
    return best;
}
```

Time: `O(n^2)`, extra space: `O(1)`.

## 9. Maximum subarray — Kadane's idea

```cpp
long long maxSubarrayKadane(const std::vector<int>& a) {
    long long current = a[0];
    long long best = a[0];

    for (int i = 1; i < static_cast<int>(a.size()); ++i) {
        current = std::max<long long>(a[i], current + a[i]);
        best = std::max(best, current);
    }

    return best;
}
```

Time: `O(n)`, extra space: `O(1)`.

The key idea is: at position `i`, the best subarray ending at `i` either starts at `i`, or extends the best subarray ending at `i-1`.

## 10. Binary search

```cpp
int binarySearch(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

Time: `O(log n)`, extra space: `O(1)`.

## 11. First occurrence

```cpp
int firstOccurrence(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            answer = mid;
            right = mid - 1; // continue looking left
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}
```

## 12. Complexity labeling

### Snippet A

```cpp
for (int i = 0; i < n; ++i) {
    std::cout << a[i];
}
```

Answer: `O(n)` time, `O(1)` extra space.

### Snippet B

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        // constant work
    }
}
```

Answer: `O(n^2)` time, `O(1)` extra space.

### Snippet C

```cpp
while (n > 1) {
    n /= 2;
}
```

Answer: `O(log n)` time, `O(1)` extra space.

### Snippet D

```cpp
std::sort(a.begin(), a.end());
```

Answer: `O(n log n)` time in the standard complexity model for `std::sort`.

---

# Chapter 9 — Capstone Practice Set

## 1. Digit statistics

```cpp
#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    n = n < 0 ? -n : n;

    if (n == 0) {
        std::cout << "Digits: 1\n";
        std::cout << "Sum: 0\n";
        std::cout << "Max: 0\n";
        std::cout << "Min: 0\n";
        return 0;
    }

    int digits = 0;
    int sum = 0;
    int mx = 0;
    int mn = 9;

    while (n > 0) {
        int d = static_cast<int>(n % 10);
        ++digits;
        sum += d;
        mx = std::max(mx, d);
        mn = std::min(mn, d);
        n /= 10;
    }

    std::cout << "Digits: " << digits << '\n';
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Max: " << mx << '\n';
    std::cout << "Min: " << mn << '\n';
}
```

## 2. Second largest distinct value

```cpp
#include <iostream>
#include <optional>
#include <vector>

std::optional<int> secondLargest(const std::vector<int>& a) {
    std::optional<int> largest;
    std::optional<int> second;

    for (int x : a) {
        if (!largest || x > *largest) {
            if (largest) second = largest;
            largest = x;
        } else if (x != *largest && (!second || x > *second)) {
            second = x;
        }
    }
    return second;
}
```

This handles duplicates because equal values do not become the second distinct value.

## 3. Rotate array right by K

Simple repeated-shift version:

```cpp
void rotateRightSimple(std::vector<int>& a, int k) {
    if (a.empty()) return;
    k %= static_cast<int>(a.size());

    for (int step = 0; step < k; ++step) {
        int last = a.back();
        for (int i = static_cast<int>(a.size()) - 1; i >= 1; --i) {
            a[i] = a[i - 1];
        }
        a[0] = last;
    }
}
```

Better reversal solution:

```cpp
void rotateRight(std::vector<int>& a, int k) {
    if (a.empty()) return;
    k %= static_cast<int>(a.size());

    std::reverse(a.begin(), a.end());
    std::reverse(a.begin(), a.begin() + k);
    std::reverse(a.begin() + k, a.end());
}
```

Simple version: `O(nk)`.

Reversal version: `O(n)`.

## 4. Anagram check

Frequency-array version for lowercase English letters:

```cpp
bool areAnagrams(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;

    int freq[26] = {};
    for (char c : a) ++freq[c - 'a'];
    for (char c : b) {
        if (--freq[c - 'a'] < 0) return false;
    }
    return true;
}
```

Sorting alternative:

```cpp
bool areAnagramsSorted(std::string a, std::string b) {
    if (a.size() != b.size()) return false;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}
```

Hash-map alternative:

```cpp
bool areAnagramsMap(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;

    std::unordered_map<char, int> freq;
    for (char c : a) ++freq[c];
    for (char c : b) --freq[c];

    for (const auto& [ch, count] : freq) {
        if (count != 0) return false;
    }
    return true;
}
```

## 5. First non-repeating character

```cpp
int firstUnique(const std::string& s) {
    int freq[256] = {};
    for (unsigned char c : s) ++freq[c];

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (freq[static_cast<unsigned char>(s[i])] == 1) return i;
    }
    return -1;
}
```

The reason a count pass plus a second scan is natural is that a character is unique only after we know its total frequency.

## 6. Longest run of the same character

```cpp
int longestRun(const std::string& s) {
    if (s.empty()) return 0;

    int best = 1;
    int current = 1;

    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == s[i - 1]) ++current;
        else current = 1;
        best = std::max(best, current);
    }
    return best;
}
```

## 7. Move zeros to the end

```cpp
void moveZeros(std::vector<int>& a) {
    int write = 0;
    for (int x : a) {
        if (x != 0) a[write++] = x;
    }
    while (write < static_cast<int>(a.size())) {
        a[write++] = 0;
    }
}
```

Time `O(n)`, extra space `O(1)`.

## 8. Missing number

Sorting solution:

```cpp
int missingBySort(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (a[i] != i) return i;
    }
    return static_cast<int>(a.size());
}
```

Arithmetic-sum solution:

```cpp
int missingBySum(const std::vector<int>& a) {
    long long n = a.size();
    long long expected = n * (n + 1) / 2;
    long long actual = 0;
    for (int x : a) actual += x;
    return static_cast<int>(expected - actual);
}
```

XOR solution:

```cpp
int missingByXor(const std::vector<int>& a) {
    int answer = static_cast<int>(a.size());
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        answer ^= i;
        answer ^= a[i];
    }
    return answer;
}
```

The XOR trick avoids overflow from the sum formula, while the sum formula is easier to explain. The sorting method uses more time and changes/copies the data.

## 9. Majority element

Frequency-map solution:

```cpp
int majorityElement(const std::vector<int>& a) {
    std::unordered_map<int, int> freq;
    for (int x : a) {
        ++freq[x];
        if (freq[x] > static_cast<int>(a.size()) / 2) return x;
    }
    return -1; // problem guarantee says this should not happen
}
```

Boyer–Moore stretch solution:

```cpp
int majorityElementBoyerMoore(const std::vector<int>& a) {
    int candidate = 0;
    int count = 0;

    for (int x : a) {
        if (count == 0) candidate = x;
        count += (x == candidate ? 1 : -1);
    }

    return candidate;
}
```

The stretch solution is `O(n)` time and `O(1)` extra space.

## 10. Merge intervals — simple version

```cpp
std::vector<std::pair<int, int>> mergeIntervals(
    std::vector<std::pair<int, int>> intervals) {

    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end());
    std::vector<std::pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        auto& last = merged.back();
        auto current = intervals[i];

        if (current.first <= last.second) {
            last.second = std::max(last.second, current.second);
        } else {
            merged.push_back(current);
        }
    }

    return merged;
}
```

The pattern is **sort first, then linear scan**. Overall time: `O(n log n)`.

## 11. Valid parentheses

```cpp
bool validParentheses(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
            continue;
        }

        if (st.empty()) return false;
        char open = st.top();
        st.pop();

        if ((open == '(' && c != ')') ||
            (open == '[' && c != ']') ||
            (open == '{' && c != '}')) {
            return false;
        }
    }

    return st.empty();
}
```

## 12. Next greater element — brute force

```cpp
std::vector<int> nextGreaterBrute(const std::vector<int>& a) {
    std::vector<int> result(a.size(), -1);

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(a.size()); ++j) {
            if (a[j] > a[i]) {
                result[i] = a[j];
                break;
            }
        }
    }
    return result;
}
```

Monotonic-stack version:

```cpp
std::vector<int> nextGreater(const std::vector<int>& a) {
    std::vector<int> result(a.size(), -1);
    std::stack<int> st; // indexes

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        while (!st.empty() && a[i] > a[st.top()]) {
            result[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

Brute force: `O(n^2)`.

Monotonic stack: `O(n)` because each index is pushed and popped at most once.

## 13. Queue using two stacks

```cpp
class MyQueue {
private:
    std::stack<int> in;
    std::stack<int> out;

    void moveIfNeeded() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    void push(int x) {
        in.push(x);
    }

    void pop() {
        moveIfNeeded();
        if (!out.empty()) out.pop();
    }

    int front() {
        moveIfNeeded();
        return out.top();
    }

    bool empty() const {
        return in.empty() && out.empty();
    }
};
```

The key insight is that the two stack reversals turn LIFO behavior into FIFO behavior. Individual operations are amortized `O(1)`.

## 14. Binary search variations

Target search:

```cpp
int binarySearch(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

First occurrence:

```cpp
int firstOccurrence(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] >= target) {
            if (a[mid] == target) ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
```

Last occurrence:

```cpp
int lastOccurrence(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= target) {
            if (a[mid] == target) ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}
```

Count occurrences:

```cpp
int countOccurrences(const std::vector<int>& a, int target) {
    int first = firstOccurrence(a, target);
    if (first == -1) return 0;

    int last = lastOccurrence(a, target);
    return last - first + 1;
}
```

## 15. Prefix sum queries

```cpp
#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long x;
        std::cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }

    while (q--) {
        int L, R;
        std::cin >> L >> R;
        std::cout << prefix[R + 1] - prefix[L] << '\n';
    }
}
```

Assumes zero-based inclusive query indexes.

## 16. Top K frequent values

Frequency map plus sorting:

```cpp
std::vector<int> topKFrequent(const std::vector<int>& a, int k) {
    std::unordered_map<int, int> freq;
    for (int x : a) ++freq[x];

    std::vector<std::pair<int, int>> items;
    for (const auto& [value, count] : freq) {
        items.push_back({value, count});
    }

    std::sort(items.begin(), items.end(),
              [](const auto& x, const auto& y) {
                  if (x.second != y.second) return x.second > y.second;
                  return x.first < y.first;
              });

    std::vector<int> result;
    for (int i = 0; i < k && i < static_cast<int>(items.size()); ++i) {
        result.push_back(items[i].first);
    }
    return result;
}
```

For large input and small `k`, a min-heap of size `k` can reduce the sorting work.

---

# Final Capstone — Mini DSA Console Program

A complete implementation can look like this:

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void printValues(const std::vector<int>& a) {
    if (a.empty()) {
        std::cout << "[empty]\n";
        return;
    }
    for (int x : a) std::cout << x << ' ';
    std::cout << '\n';
}

void addValue(std::vector<int>& a) {
    int x;
    std::cin >> x;
    a.push_back(x);
}

void removeLast(std::vector<int>& a) {
    if (!a.empty()) a.pop_back();
    else std::cout << "Vector is empty\n";
}

void findMin(const std::vector<int>& a) {
    if (a.empty()) {
        std::cout << "Vector is empty\n";
        return;
    }
    std::cout << *std::min_element(a.begin(), a.end()) << '\n';
}

void findMax(const std::vector<int>& a) {
    if (a.empty()) {
        std::cout << "Vector is empty\n";
        return;
    }
    std::cout << *std::max_element(a.begin(), a.end()) << '\n';
}

void searchValue(const std::vector<int>& a) {
    int target;
    std::cin >> target;

    auto it = std::find(a.begin(), a.end(), target);
    if (it == a.end()) std::cout << -1 << '\n';
    else std::cout << std::distance(a.begin(), it) << '\n';
}

void countFrequency(const std::vector<int>& a) {
    int target;
    std::cin >> target;

    int count = 0;
    for (int x : a) {
        if (x == target) ++count;
    }
    std::cout << count << '\n';
}

void printUniqueValues(const std::vector<int>& a) {
    std::unordered_set<int> seen;
    for (int x : a) {
        if (seen.insert(x).second) std::cout << x << ' ';
    }
    std::cout << '\n';
}

void showSumAverage(const std::vector<int>& a) {
    if (a.empty()) {
        std::cout << "Sum: 0\nAverage: 0\n";
        return;
    }

    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    double average = static_cast<double>(sum) / a.size();

    std::cout << "Sum: " << sum << '\n';
    std::cout << "Average: " << average << '\n';
}

void showMenu() {
    std::cout << "\n"
              << "1. Add value\n"
              << "2. Remove last value\n"
              << "3. Print values\n"
              << "4. Find minimum\n"
              << "5. Find maximum\n"
              << "6. Search for value\n"
              << "7. Sort ascending\n"
              << "8. Reverse\n"
              << "9. Count frequency of a value\n"
              << "10. Print unique values\n"
              << "11. Show sum and average\n"
              << "0. Exit\n";
}

int main() {
    std::vector<int> a;

    while (true) {
        showMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addValue(a);
                break;
            case 2:
                removeLast(a);
                break;
            case 3:
                printValues(a);
                break;
            case 4:
                findMin(a);
                break;
            case 5:
                findMax(a);
                break;
            case 6:
                searchValue(a);
                break;
            case 7:
                std::sort(a.begin(), a.end());
                break;
            case 8:
                std::reverse(a.begin(), a.end());
                break;
            case 9:
                countFrequency(a);
                break;
            case 10:
                printUniqueValues(a);
                break;
            case 11:
                showSumAverage(a);
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}
```

This project revises a large portion of the refresher: functions, references, vectors, loops, conditions, STL algorithms, hashing, and edge-case handling.

---

# Final Self-Test — Suggested solutions / checks

These are deliberately short because the goal is to test whether you can write them yourself.

## Syntax

Two integers in / formatted output:

```cpp
int a, b;
std::cin >> a >> b;
std::cout << "sum=" << a + b << '\n';
```

Reference parameter:

```cpp
void increment(int& x) {
    ++x;
}
```

## Control flow

Prime check:

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int d = 2; 1LL * d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}
```

Digit sum:

```cpp
int digitSum(int n) {
    n = n < 0 ? -n : n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
```

Nested loop:

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        // constant work
    }
}
```

## Sequences

Vector traversal:

```cpp
for (int x : a) std::cout << x << ' ';
```

Reverse in place:

```cpp
std::reverse(a.begin(), a.end());
```

Maximum:

```cpp
int mx = *std::max_element(a.begin(), a.end());
```

Frequency count:

```cpp
std::unordered_map<int, int> freq;
for (int x : a) ++freq[x];
```

## STL

Sort:

```cpp
std::sort(a.begin(), a.end());
```

Set:

```cpp
std::set<int> s(a.begin(), a.end());
```

Unordered map:

```cpp
std::unordered_map<int, int> m;
m[key]++;
```

Stack:

```cpp
std::stack<int> st;
st.push(10);
int x = st.top();
st.pop();
```

Queue:

```cpp
std::queue<int> q;
q.push(10);
int x = q.front();
q.pop();
```

Priority queue:

```cpp
std::priority_queue<int> pq;
pq.push(10);
int largest = pq.top();
```

## DSA patterns

Two pointers:

```cpp
int left = 0;
int right = static_cast<int>(a.size()) - 1;
while (left < right) {
    // use a[left] and a[right]
    ++left;
    --right;
}
```

Prefix sum:

```cpp
std::vector<long long> prefix(a.size() + 1, 0);
for (size_t i = 0; i < a.size(); ++i) {
    prefix[i + 1] = prefix[i] + a[i];
}
```

Binary search:

```cpp
int lo = 0, hi = static_cast<int>(a.size()) - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;
```

Hash-based lookup:

```cpp
std::unordered_map<int, int> seen;
for (int i = 0; i < static_cast<int>(a.size()); ++i) {
    if (seen.count(target - a[i])) {
        // found a pair
    }
    seen[a[i]] = i;
}
```

---

# Suggested practice order

For maximum benefit from the 80:20 approach, do **not** simply read this answer file from top to bottom. Use it after attempting the corresponding chapter exercises.

A strong final test is to close this file and implement these without notes:

1. `isPrime`
2. reverse an array in place
3. frequency map
4. move zeros to the end
5. two-sum with hashing
6. prefix sums + range query
7. binary search
8. valid parentheses
9. merge intervals
10. top K frequent values

If those feel reasonably natural, you are ready to put most of your energy into DSA concepts rather than C++ syntax.
