# Solutions Key: Practice Problems - Linked Lists

This document provides detailed solutions, mathematical proofs, and standard C++ implementations for all 10 practice problems.

---

## Problem 1: In-Place Singly Linked List Reversal (Recursive)

```cpp
ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
```

---

## Problem 2: Palindrome Linked List Verification ($O(1)$ Space)

```cpp
ListNode* getMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // 1. Find middle
    ListNode* mid = getMiddle(head);

    // 2. Reverse second half
    ListNode* secondHalf = reverseList(mid);
    ListNode* firstHalf = head;

    // 3. Compare both halves
    ListNode* p2 = secondHalf;
    bool result = true;
    while (p2 != nullptr) {
        if (firstHalf->val != p2->val) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        p2 = p2->next;
    }

    // 4. Restore original list structure
    reverseList(secondHalf);
    return result;
}
```

---

## Problem 3: Detect Cycle Entry Point (Mathematical Proof & Solution)

### Mathematical Proof:
Let $L_1$ be distance from head to cycle entrance.
Let $C$ be the loop cycle length.
Let $X$ be the distance from cycle entrance to meeting point.

When slow and fast pointers meet:
* Distance covered by slow: $D_{slow} = L_1 + X$
* Distance covered by fast: $D_{fast} = L_1 + X + n \cdot C$

Since fast travels twice as fast ($D_{fast} = 2 \cdot D_{slow}$):
$$2(L_1 + X) = L_1 + X + n \cdot C \implies L_1 + X = n \cdot C \implies L_1 = n \cdot C - X$$

Thus, moving one pointer to `head` and stepping both pointers by 1 will result in convergence at the cycle entrance after $L_1$ steps!

```cpp
ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr; // Cycle start
        }
    }
    return nullptr;
}
```

---

## Problem 7: Design LRU Cache ($O(1)$ Ops)

```cpp
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node *head, *tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (cache.size() == capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};
```