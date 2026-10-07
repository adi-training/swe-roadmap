# Chapter 7 — Essential STL for DSA

**Time:** ~90 minutes  
**Goal:** Learn the small set of standard-library tools that gives you most of the practical power needed for DSA practice.

The Standard Template Library is large. Do **not** try to learn all of it in this refresher.

Focus on:

```text
vector
string
pair
sort / reverse
set
map / unordered_map
stack
queue
priority_queue
```

Also know a few algorithms such as `find`, `count`, and `min/max`.

---

## 1. `vector`

You should already know the basics.

```cpp
std::vector<int> a;
a.push_back(10);
a.push_back(20);
```

Useful operations:

```cpp
a.size()
a.empty()
a.front()
a.back()
a.pop_back()
a.clear()
```

Create with a size:

```cpp
std::vector<int> a(10); // 10 zeros
```

Create with repeated value:

```cpp
std::vector<int> a(10, -1);
```

---

## 2. `pair`

A pair stores two values together.

```cpp
std::pair<int, std::string> p = {1, "apple"};
```

Access:

```cpp
p.first
p.second
```

Nested pairs are possible but often become hard to read. Prefer a struct when the meaning matters.

---

## 3. Sorting

```cpp
std::sort(a.begin(), a.end());
```

Descending:

```cpp
std::sort(a.begin(), a.end(), std::greater<int>());
```

Or:

```cpp
std::sort(a.rbegin(), a.rend());
```

Custom comparator:

```cpp
std::sort(a.begin(), a.end(), [](int x, int y) {
    return x > y;
});
```

For a struct:

```cpp
std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
    return a.value < b.value;
});
```

The comparator answers:

> Should `a` come before `b`?

---

## 4. `reverse`

```cpp
std::reverse(a.begin(), a.end());
```

Remember the iterator pattern:

```cpp
a.begin()
a.end()
```

`end()` points **one past** the last element.

---

## 5. `set`

A `set` stores unique values in sorted order.

```cpp
std::set<int> s;
s.insert(10);
s.insert(5);
s.insert(10);
```

The value `10` appears only once.

Operations:

```cpp
s.insert(x)
s.erase(x)
s.count(x)
s.find(x)
s.size()
```

A `set` is useful when you need uniqueness plus ordered operations.

---

## 6. `map`

A `map` stores key/value pairs in sorted key order.

```cpp
std::map<std::string, int> freq;
freq["apple"]++;
```

Now `freq["apple"]` is `1`.

Iterate:

```cpp
for (const auto& [key, value] : freq) {
    std::cout << key << " " << value << '\n';
}
```

Structured bindings are a C++17 feature.

---

## 7. `unordered_map`

```cpp
std::unordered_map<int, int> freq;
freq[7]++;
```

This is often used for fast average-case key lookup.

Conceptual difference:

| Container | Typical behavior |
|---|---|
| `map` | keys ordered, O(log n) operations |
| `unordered_map` | no sorted order, average O(1) lookup/insert |

For DSA practice, the decision is often:

- Need sorted keys / ordered traversal? → `map`
- Need frequency/count lookup and order does not matter? → `unordered_map`

Worst-case hash-table behavior is more subtle; do not treat O(1) as an absolute guarantee.

---

## 8. `stack`

Last in, first out.

```cpp
std::stack<int> st;
st.push(10);
st.push(20);
std::cout << st.top();
st.pop();
```

Important operations:

```text
push
pop
top
empty
size
```

Typical problems:

- matching brackets
- undo-like behavior
- monotonic-stack patterns
- DFS variants

---

## 9. `queue`

First in, first out.

```cpp
std::queue<int> q;
q.push(10);
q.push(20);
std::cout << q.front();
q.pop();
```

Useful for BFS later.

---

## 10. `priority_queue`

A priority queue gives access to the largest element by default.

```cpp
std::priority_queue<int> pq;
pq.push(5);
pq.push(10);
pq.push(3);

std::cout << pq.top(); // 10
```

Min-heap style:

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

Priority queues become very useful in greedy algorithms, shortest paths, scheduling, and top-K problems.

---

## 11. Common algorithms

Include `<algorithm>`.

Examples:

```cpp
std::min(a, b)
std::max(a, b)
std::swap(a, b)
std::reverse(begin, end)
std::sort(begin, end)
```

Search:

```cpp
std::find(a.begin(), a.end(), x)
```

Count occurrences:

```cpp
std::count(a.begin(), a.end(), x)
```

Do not memorize every algorithm now. Learn to recognize when a standard algorithm probably exists.

---

# Hands-On Practice

## Vector + algorithms

### 1. Sort ascending

### 2. Sort descending

### 3. Reverse a vector

### 4. Find minimum and maximum

Use both a manual loop and `std::min_element` / `std::max_element`.

### 5. Remove duplicates

Start with:

```text
sort + unique + erase
```

Understand what `std::unique` actually does before using it.

### 6. Merge and sort

Combine two vectors and sort the result.

Then compare against your earlier linear merge algorithm for two sorted vectors.

---

## Frequency problems

### 7. Character frequency

Given a string, print the frequency of every character.

### 8. Most frequent value

Return the value with highest frequency.

### 9. First unique character

Return the first character whose frequency is 1.

### 10. Duplicate detector

Return whether an array contains duplicates.

### 11. Common elements

Given two arrays, print distinct common elements.

Try both `set` and `unordered_set`.

---

## Stack and queue

### 12. Balanced parentheses

Given a string containing `()[]{}`, determine whether brackets are balanced.

### 13. Reverse using a stack

Push all characters, then pop them to create the reverse.

### 14. Queue simulation

Read commands such as:

```text
push 10
push 20
pop
front
```

Implement the operations using `std::queue`.

### 15. First non-repeating character

Use a frequency structure followed by a scan.

---

## Priority queue

### 16. Find the K largest elements

Use a max heap first. Then try the more memory-efficient min-heap approach when `k` is small compared with `n`.

### 17. K smallest elements

Try the analogous approach.

### 18. Running maximum

Process a stream of numbers and print the maximum seen after each insertion using a priority queue.

---

# STL Speed-Memory Exercise

Create a one-page personal cheat sheet with exactly this information:

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

Then close your notes and reproduce it from memory.

---

# Chapter Checkpoint

You should know what to reach for when a problem says:

- “store N numbers” → `vector`
- “count frequency” → often `unordered_map`
- “unique values in sorted order” → `set`
- “key/value association” → `map` / `unordered_map`
- “last added comes out first” → `stack`
- “first added comes out first” → `queue`
- “always need the current largest/smallest priority” → `priority_queue`
- “sort these items” → `sort`
