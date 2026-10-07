# Python 80:20 Refresh — Hands-On Answers

This is the answer key for the hands-on exercises in Chapters 1–9.

Try every exercise first. The solutions are intentionally beginner-friendly and generally use only Python features introduced in the refresher. When a more compact standard-library solution is useful for DSA, it is shown explicitly.

Run a file with:

```bash
python3 program.py
```

---

# Chapter 1 — Basics, Input/Output, Variables and Types

## E1. Personal profile

```python
name = input("Name: ")
age = int(input("Age: "))
city = input("City: ")
print(f"{name} is {age} years old and lives in {city}.")
```

## E2. Rectangle calculator

```python
length = float(input())
width = float(input())

area = length * width
perimeter = 2 * (length + width)

print("Area:", area)
print("Perimeter:", perimeter)
```

## E3. Temperature conversion

```python
c = float(input())
f = c * 9 / 5 + 32
print(f)
```

## E4. Seconds converter

```python
seconds = int(input())

hours = seconds // 3600
remaining = seconds % 3600
minutes = remaining // 60
seconds = remaining % 60

print(hours, minutes, seconds)
```

## E5. Swap values

```python
a = int(input())
b = int(input())
a, b = b, a
print(a, b)
```

Python's tuple unpacking makes swapping especially simple.

## E6. Average of three numbers

```python
a = float(input())
b = float(input())
c = float(input())

avg = (a + b + c) / 3
print(f"{avg:.2f}")
```

## E7. Digit extraction

```python
n = int(input())

last_digit = n % 10

digits = 1 if n == 0 else 0
x = n
while x > 0:
    digits += 1
    x //= 10

print(last_digit)
print(digits)
```

## E8. Simple bill

```python
price = float(input())
quantity = int(input())

subtotal = price * quantity
tax = subtotal * 0.10
total = subtotal + tax

print(f"Subtotal: {subtotal:.2f}")
print(f"Tax: {tax:.2f}")
print(f"Total: {total:.2f}")
```

---

# Chapter 2 — Conditions and Loops

## E1. Even or odd

```python
n = int(input())
print("even" if n % 2 == 0 else "odd")
```

## E2. Largest of three

```python
a, b, c = map(int, input().split())

largest = a
if b > largest:
    largest = b
if c > largest:
    largest = c

print(largest)
```

## E3. Grade

```python
score = int(input())

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
elif score >= 60:
    grade = "D"
else:
    grade = "F"

print(grade)
```

## E4. Sum from 1 to n

```python
n = int(input())
total = 0

for x in range(1, n + 1):
    total += x

print(total)
```

## E5. Count digits

```python
n = int(input())

if n == 0:
    print(1)
else:
    count = 0
    while n > 0:
        count += 1
        n //= 10
    print(count)
```

## E6. Reverse an integer

```python
n = int(input())
rev = 0

while n > 0:
    digit = n % 10
    rev = rev * 10 + digit
    n //= 10

print(rev)
```

## E7. Multiplication table

```python
n = int(input())
for i in range(1, 11):
    print(f"{n} x {i} = {n * i}")
```

## E8. Prime check

```python
n = int(input())

if n < 2:
    print("not prime")
else:
    prime = True
    d = 2
    while d * d <= n:
        if n % d == 0:
            prime = False
            break
        d += 1
    print("prime" if prime else "not prime")
```

Why only test up to `sqrt(n)`? If `n = a * b` and both were greater than `sqrt(n)`, their product would be greater than `n`.

## E9. Print primes

```python
n = int(input())

for x in range(2, n + 1):
    prime = True
    d = 2
    while d * d <= x:
        if x % d == 0:
            prime = False
            break
        d += 1
    if prime:
        print(x, end=" ")
```

## E10. FizzBuzz

```python
for i in range(1, 101):
    if i % 15 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)
```

## E11. Fibonacci

```python
n = int(input())

a, b = 0, 1
for _ in range(n):
    print(a, end=" ")
    a, b = b, a + b
```

## E12. GCD

```python
a, b = map(int, input().split())

while b != 0:
    a, b = b, a % b

print(abs(a))
```

---

# Chapter 3 — Functions, Scope, Modules and Errors

## E1. `is_even`

```python
def is_even(n):
    return n % 2 == 0

print(is_even(12))
```

## E2. `factorial`

```python
def factorial(n):
    if n < 0:
        raise ValueError("factorial is undefined for negative integers")

    result = 1
    for x in range(2, n + 1):
        result *= x
    return result
```

## E3. `is_prime`

```python
def is_prime(n):
    if n < 2:
        return False

    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True
```

## E4. `count_vowels`

```python
def count_vowels(text):
    vowels = set("aeiouAEIOU")
    count = 0
    for ch in text:
        if ch in vowels:
            count += 1
    return count
```

## E5. Default greeting

```python
def greet(name="friend"):
    return f"Hello, {name}!"

print(greet())
print(greet("Maya"))
```

## E6. Min/max without built-ins

```python
def min_max(nums):
    if not nums:
        raise ValueError("list must not be empty")

    lo = hi = nums[0]
    for x in nums[1:]:
        if x < lo:
            lo = x
        if x > hi:
            hi = x
    return lo, hi
```

## E7. Safe integer reader

```python
def read_int(prompt="Enter an integer: "):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("That was not an integer. Try again.")

n = read_int()
print(n)
```

## E8. Module exercise

`math_utils.py`:

```python
def square(x):
    return x * x


def cube(x):
    return x * x * x


def is_even(x):
    return x % 2 == 0
```

`main.py`:

```python
import math_utils

print(math_utils.square(5))
print(math_utils.cube(3))
print(math_utils.is_even(8))
```

Keep both files in the same directory for this simple exercise.

## E9. Recursive factorial

```python
def factorial(n):
    if n < 0:
        raise ValueError("negative input")
    if n <= 1:
        return 1
    return n * factorial(n - 1)
```

Base case: `0! = 1` and `1! = 1`.

## E10. Recursive sum

```python
def recursive_sum(n):
    if n <= 0:
        return 0
    return n + recursive_sum(n - 1)
```

---

# Chapter 4 — Lists, Tuples, Dictionaries and Sets

## E1. Sum a list

```python
nums = list(map(int, input().split()))

total = 0
for x in nums:
    total += x

print(total)
```

## E2. Find maximum

```python
def find_max(nums):
    if not nums:
        raise ValueError("empty list")

    result = nums[0]
    for x in nums[1:]:
        if x > result:
            result = x
    return result
```

## E3. Reverse a list

```python
def reverse_list(nums):
    result = []
    for i in range(len(nums) - 1, -1, -1):
        result.append(nums[i])
    return result
```

## E4. Remove duplicates preserving order

```python
def unique_in_order(nums):
    seen = set()
    result = []

    for x in nums:
        if x not in seen:
            seen.add(x)
            result.append(x)

    return result
```

## E5. Frequency map

```python
def frequencies(nums):
    freq = {}
    for x in nums:
        freq[x] = freq.get(x, 0) + 1
    return freq
```

## E6. Most frequent value

```python
def most_frequent(nums):
    if not nums:
        raise ValueError("empty list")

    freq = {}
    for x in nums:
        freq[x] = freq.get(x, 0) + 1

    best = nums[0]
    for x in nums:
        if freq[x] > freq[best]:
            best = x
    return best
```

## E7. Two-sum

```python
def two_sum(nums, target):
    seen = {}

    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return seen[need], i
        seen[x] = i

    return None
```

Average complexity: O(n) time and O(n) extra space.

## E8. Common elements

```python
def common_unique(a, b):
    return set(a) & set(b)
```

If output order matters, preserve it explicitly:

```python
def common_in_a_order(a, b):
    b_set = set(b)
    seen = set()
    result = []
    for x in a:
        if x in b_set and x not in seen:
            seen.add(x)
            result.append(x)
    return result
```

## E9. Anagram check

```python
def are_anagrams(a, b):
    if len(a) != len(b):
        return False

    freq = {}
    for ch in a:
        freq[ch] = freq.get(ch, 0) + 1

    for ch in b:
        if ch not in freq:
            return False
        freq[ch] -= 1
        if freq[ch] < 0:
            return False

    return True
```

## E10. Group words by first letter

```python
def group_by_first(words):
    result = {}
    for word in words:
        if not word:
            continue
        key = word[0]
        result.setdefault(key, []).append(word)
    return result
```

## E11. Stack

```python
stack = []

# push
stack.append(10)
stack.append(20)

# peek
print(stack[-1])

# pop
print(stack.pop())
print(stack.pop())
```

## E12. Queue

```python
from collections import deque

q = deque()
q.append(10)
q.append(20)

print(q[0])
print(q.popleft())
print(q.popleft())
```

---

# Chapter 5 — Strings and File Handling

## E1. Count vowels and consonants

```python
def vowel_consonant_counts(text):
    vowels = set("aeiou")
    v = c = 0

    for ch in text.lower():
        if ch.isalpha():
            if ch in vowels:
                v += 1
            else:
                c += 1
    return v, c
```

## E2. Normalize spaces

```python
def normalize_spaces(text):
    return " ".join(text.split())
```

`split()` without an argument treats runs of whitespace as a separator.

## E3. Palindrome

```python
def is_palindrome(text):
    cleaned = "".join(ch.lower() for ch in text if ch.isalnum())
    return cleaned == cleaned[::-1]
```

## E4. Word count

```python
def word_count(text):
    return len(text.split())
```

## E5. Longest word

```python
def longest_word(text):
    words = text.split()
    return max(words, key=len, default="")
```

## E6. Character frequency

```python
def char_frequency(text):
    freq = {}
    for ch in text:
        if not ch.isspace():
            freq[ch] = freq.get(ch, 0) + 1
    return freq
```

## E7. Write numbers to a file

```python
with open("numbers.txt", "w", encoding="utf-8") as f:
    for i in range(1, 101):
        f.write(f"{i}\n")
```

## E8. Sum numbers from a file

```python
total = 0

with open("numbers.txt", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if line:
            total += int(line)

print(total)
```

## E9. Count log levels

```python
counts = {"INFO": 0, "WARNING": 0, "ERROR": 0}

with open("app.log", encoding="utf-8") as f:
    for line in f:
        for level in counts:
            if level in line:
                counts[level] += 1
                break

print(counts)
```

## E10. Copy non-empty lines

```python
from pathlib import Path

src = Path("input.txt")
dst = Path("clean.txt")

with src.open(encoding="utf-8") as fin, dst.open("w", encoding="utf-8") as fout:
    for line in fin:
        clean = line.strip()
        if clean:
            fout.write(clean + "\n")
```

---

# Chapter 6 — Classes and Practical OOP

## E1. Rectangle class

```python
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)
```

## E2. BankAccount

```python
class BankAccount:
    def __init__(self, balance=0):
        self.balance = balance

    def deposit(self, amount):
        if amount < 0:
            raise ValueError("negative deposit")
        self.balance += amount

    def withdraw(self, amount):
        if amount < 0:
            raise ValueError("negative withdrawal")
        if amount > self.balance:
            return False
        self.balance -= amount
        return True
```

## E3. Student class

```python
class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = list(marks)

    def average(self):
        return sum(self.marks) / len(self.marks)

    def passed(self):
        return self.average() >= 40
```

## E4. Counter

```python
class Counter:
    def __init__(self, start=0):
        self.value = start

    def increment(self):
        self.value += 1

    def decrement(self):
        self.value -= 1
```

## E5. Point

```python
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance_to(self, other):
        dx = self.x - other.x
        dy = self.y - other.y
        return math.sqrt(dx * dx + dy * dy)
```

## E6. Simple inheritance

```python
class Animal:
    def speak(self):
        return "..."


class Dog(Animal):
    def speak(self):
        return "woof"


class Cat(Animal):
    def speak(self):
        return "meow"
```

## E7. DSA node

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


a = Node(10)
b = Node(20)
c = Node(30)

a.next = b
b.next = c

current = a
while current:
    print(current.value)
    current = current.next
```

This simple structure is the starting point for linked-list implementations.

---

# Chapter 7 — Comprehensions, Built-ins and Iterables

## E1. Squares comprehension

```python
squares = [x * x for x in range(1, 21)]
```

## E2. Filter positives

```python
nums = [-3, 0, 4, -1, 8]
positives = [x for x in nums if x > 0]
```

## E3. Enumerate positions

```python
for i, value in enumerate(nums):
    print(i, value)
```

## E4. Zip names and scores

```python
names = ["A", "B", "C"]
scores = [80, 90, 75]

result = dict(zip(names, scores))
print(result)
```

## E5. Longest string

```python
words = ["pear", "watermelon", "kiwi", "apple"]
longest = max(words, key=len)
print(longest)
```

## E6. Sort records

```python
records = [("Maya", 90), ("Asha", 90), ("John", 82)]
result = sorted(records, key=lambda x: (-x[1], x[0]))
print(result)
```

The negative score gives descending score order; the name remains ascending.

## E7. Any/all

```python
nums = [2, 4, 6, 8]
print(any(x < 0 for x in nums))
print(all(x > 0 for x in nums))
```

## E8. Flatten one level

```python
matrix = [[1, 2], [3, 4], [5, 6]]
flat = [x for row in matrix for x in row]
print(flat)
```

## E9. Frequency dictionary comprehension

First build the frequency dictionary:

```python
words = ["a", "b", "a", "c", "b", "a"]

freq = {}
for word in words:
    freq[word] = freq.get(word, 0) + 1

result = {word: count for word, count in freq.items()}
print(result)
```

The second step is intentionally simple; the important point is understanding dictionary-comprehension syntax.

---

# Chapter 8 — Python Patterns You Will Use in DSA

## E1. First duplicate

```python
def first_duplicate(nums):
    seen = set()
    for x in nums:
        if x in seen:
            return x
        seen.add(x)
    return None
```

## E2. Two-sum indices

```python
def two_sum(nums, target):
    seen = {}
    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return seen[need], i
        seen[x] = i
    return None
```

## E3. Valid parentheses

```python
def valid_parentheses(s):
    stack = []
    pairs = {')': '(', ']': '[', '}': '{'}

    for ch in s:
        if ch in "([{":
            stack.append(ch)
        elif ch in pairs:
            if not stack or stack.pop() != pairs[ch]:
                return False

    return not stack
```

## E4. Top-level frequency

```python
def most_frequent(nums):
    freq = {}
    for x in nums:
        freq[x] = freq.get(x, 0) + 1

    best = None
    for x in nums:
        if best is None or freq[x] > freq[best]:
            best = x
    return best
```

## E5. Prefix-sum range queries

```python
def build_prefix(nums):
    prefix = [0]
    for x in nums:
        prefix.append(prefix[-1] + x)
    return prefix


def range_sum(prefix, left, right):
    return prefix[right + 1] - prefix[left]


nums = [2, 4, 1, 7, 3]
prefix = build_prefix(nums)
print(range_sum(prefix, 1, 3))  # 12
```

Building prefix sums costs O(n); each query is O(1).

## E6. Binary search

```python
def binary_search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1
```

## E7. First occurrence

```python
def first_occurrence(nums, target):
    left, right = 0, len(nums) - 1
    answer = -1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            answer = mid
            right = mid - 1
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return answer
```

## E8. Two-pointer pair

```python
def has_pair_sum(nums, target):
    left, right = 0, len(nums) - 1

    while left < right:
        total = nums[left] + nums[right]
        if total == target:
            return True
        if total < target:
            left += 1
        else:
            right -= 1

    return False
```

This assumes `nums` is sorted.

## E9. Move zeros

```python
def move_zeros(nums):
    write = 0

    for read in range(len(nums)):
        if nums[read] != 0:
            nums[write], nums[read] = nums[read], nums[write]
            write += 1
```

The operation is in-place and O(n) time.

## E10. Sliding-window maximum sum

```python
def max_window_sum(nums, k):
    if k <= 0 or k > len(nums):
        raise ValueError("invalid window size")

    current = sum(nums[:k])
    best = current

    for i in range(k, len(nums)):
        current += nums[i]
        current -= nums[i - k]
        best = max(best, current)

    return best
```

## E11. Queue with two stacks

```python
class QueueWithStacks:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def _move(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())

    def enqueue(self, x):
        self.in_stack.append(x)

    def dequeue(self):
        self._move()
        if not self.out_stack:
            raise IndexError("queue is empty")
        return self.out_stack.pop()
```

Each element moves between stacks only a small number of times, giving amortized O(1) queue operations.

## E12. BFS level order idea

```python
from collections import deque


def bfs(graph, start):
    visited = {start}
    q = deque([start])
    order = []

    while q:
        node = q.popleft()
        order.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                q.append(neighbor)

    return order
```

---

# Chapter 9 — Capstone Practice Set

## E1. Digit statistics

```python
def digit_stats(n):
    if n <= 0:
        raise ValueError("positive integer expected")

    x = n
    count = 0
    total = 0
    rev = 0

    while x:
        digit = x % 10
        total += digit
        rev = rev * 10 + digit
        count += 1
        x //= 10

    return count, total, rev
```

## E2. Word statistics

```python
def word_stats(text):
    words = text.split()
    distinct = set(word.lower() for word in words)
    longest = max(words, key=len, default="")
    return len(words), longest, len(distinct)
```

## E3. Rotate list

```python
def rotate_right(nums, k):
    if not nums:
        return nums

    k %= len(nums)
    nums[:] = nums[-k:] + nums[:-k] if k else nums
    return nums
```

## E4. Merge two sorted lists

```python
def merge_sorted(a, b):
    i = j = 0
    result = []

    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1

    result.extend(a[i:])
    result.extend(b[j:])
    return result
```

Time: O(n + m).

## E5. Valid palindrome

```python
def valid_palindrome(text):
    cleaned = [ch.lower() for ch in text if ch.isalnum()]
    return cleaned == cleaned[::-1]
```

## E6. First non-repeating character

```python
def first_unique_char(s):
    freq = {}
    for ch in s:
        freq[ch] = freq.get(ch, 0) + 1

    for i, ch in enumerate(s):
        if freq[ch] == 1:
            return i
    return -1
```

## E7. Intersection with counts

```python
def intersect_with_counts(a, b):
    from collections import Counter

    ca = Counter(a)
    cb = Counter(b)
    result = []

    for value, count in (ca & cb).items():
        result.extend([value] * count)

    return result
```

## E8. Missing number

```python
def missing_number(nums):
    n = len(nums)
    result = n
    for i, x in enumerate(nums):
        result ^= i
        result ^= x
    return result
```

Alternative arithmetic solution:

```python
def missing_number_sum(nums):
    n = len(nums)
    return n * (n + 1) // 2 - sum(nums)
```

## E9. Longest increasing contiguous run

```python
def longest_increasing_run(nums):
    if not nums:
        return 0

    best = current = 1

    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            current += 1
        else:
            current = 1
        best = max(best, current)

    return best
```

## E10. Subarray sum equals target

For arbitrary integers, prefix sums plus a frequency dictionary give O(n) average time.

```python
def has_subarray_sum(nums, target):
    seen_prefix = {0}
    prefix = 0

    for x in nums:
        prefix += x
        if prefix - target in seen_prefix:
            return True
        seen_prefix.add(prefix)

    return False
```

## E11. Group anagrams

```python
def group_anagrams(words):
    groups = {}

    for word in words:
        key = tuple(sorted(word))
        groups.setdefault(key, []).append(word)

    return list(groups.values())
```

A common alternative uses a 26-character frequency tuple for lowercase English letters.

## E12. Minimum window substring

```python
from collections import Counter


def min_window(s, t):
    if not s or not t:
        return ""

    need = Counter(t)
    have = {}
    formed = 0
    required = len(need)

    left = 0
    best_len = float("inf")
    best_start = 0

    for right, ch in enumerate(s):
        have[ch] = have.get(ch, 0) + 1

        if ch in need and have[ch] == need[ch]:
            formed += 1

        while formed == required and left <= right:
            if right - left + 1 < best_len:
                best_len = right - left + 1
                best_start = left

            left_ch = s[left]
            have[left_ch] -= 1
            if left_ch in need and have[left_ch] < need[left_ch]:
                formed -= 1
            left += 1

    return "" if best_len == float("inf") else s[best_start:best_start + best_len]
```

The important pattern is to expand the right side, then shrink the left side while the window remains valid.

## E13. Command-line frequency analyzer

```python
import sys
from collections import Counter
from pathlib import Path


def analyze(path):
    text = path.read_text(encoding="utf-8")
    lines = text.splitlines()
    words = text.split()
    non_space = sum(not ch.isspace() for ch in text)
    counts = Counter(word.strip(".,!?;:\"'()[]{}").lower() for word in words)

    print("Lines:", len(lines))
    print("Words:", len(words))
    print("Non-space characters:", non_space)
    print("Top 5 words:")

    for word, count in counts.most_common(5):
        if word:
            print(f"{word}: {count}")


def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} FILE")
        return 2

    path = Path(sys.argv[1])
    if not path.is_file():
        print(f"File not found: {path}")
        return 1

    analyze(path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
```

Run it with:

```bash
python3 analyzer.py sample.txt
```

---

# What to retain after the refresher

The high-value Python knowledge for DSA is not every language feature. It is the ability to write these naturally:

```python
for i, x in enumerate(nums):
    ...

freq[x] = freq.get(x, 0) + 1

seen = set()

stack.append(x)
stack.pop()

q.append(x)
q.popleft()

nums.sort()

left, right = 0, len(nums) - 1

while left <= right:
    ...
```

Once these patterns feel routine, spend the next study hours on **arrays, strings, hashing, stacks/queues, linked lists, recursion, binary search, trees, heaps, graphs, and dynamic programming** rather than on advanced Python syntax.

