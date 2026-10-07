# Day 2 Master Guide: Linked Lists & Memory Node Management

Welcome to Day 2! Today we shift from contiguous dynamic arrays to node-based heap structures: **Singly and Doubly Linked Lists**. 

---

## 1. Memory Architecture: Contiguous Arrays vs. Fragmented Nodes

Understanding how linked lists reside in physical hardware memory is critical for low-level system engineering and technical interviews.

```
Array (Contiguous Memory):
+-------+-------+-------+-------+
|  10   |  20   |  30   |  40   |  [0x1000 - 0x100F]
+-------+-------+-------+-------+

Linked List (Non-Contiguous Heap Allocation):
Node A [0x1040]: [ Val: 10 | Next: 0x2080 ] ---> Node B [0x2080]: [ Val: 20 | Next: 0x1100 ]
```

### Key Differences
| Attribute | Dynamic Array (`std::vector`) | Linked List (`std::list`) |
| :--- | :--- | :--- |
| **Memory Allocation** | Single contiguous block | Separate dynamic node allocations |
| **Random Access** | $O(1)$ constant time | $O(N)$ linear traversal |
| **Insertion/Deletion at Head** | $O(N)$ (requires shifting) | $O(1)$ constant time |
| **Insertion/Deletion (Given Node)**| $O(N)$ | $O(1)$ constant time pointer swap |
| **Cache Locality** | **High** (Spatial prefetching) | **Low** (Cache miss overhead) |
| **Memory Overhead** | Unused capacity buffer | Pointer storage per element |

---

## 2. Pointer Manipulation & Double Pointers (`Node**`)

In C++, modifying head pointers requires passing either a reference to a pointer (`Node*&`) or a pointer to a pointer (`Node**`).

### Modifying Head Pointer with `Node**`

```cpp
void pushFront(Node** headRef, int newValue) {
    Node* newNode = new Node();
    newNode->val = newValue;
    newNode->next = *headRef;
    *headRef = newNode; // Mutates original head pointer in caller frame
}
```

---

## 3. Sentinel Nodes (Dummy Heads & Tails)

Sentinel nodes are dummy objects that hold no domain data but eliminate conditional `nullptr` checks for empty list edge cases.

### Without Sentinel Nodes (Messy):
```cpp
void insertFront(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
```

### With Dummy Head & Tail (Clean & Bug-Free):
```cpp
void insertFront(int val) {
    Node* newNode = new Node(val);
    Node* firstRealNode = dummyHead->next;

    newNode->next = firstRealNode;
    newNode->prev = dummyHead;
    dummyHead->next = newNode;
    firstRealNode->prev = newNode;
}
```

---

## 4. Time & Space Complexity Summary

* **Access / Search:** $O(N)$ time, $O(1)$ space.
* **Prepend (`push_front`):** $O(1)$ time, $O(1)$ space.
* **Append (`push_back`):** $O(1)$ time with tail pointer/sentinel, $O(1)$ space.
* **In-Place Reversal:** $O(N)$ time, $O(1)$ space.
* **Cycle Detection (Floyd's Algorithm):** $O(N)$ time, $O(1)$ space.