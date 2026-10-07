# Tricky Interview & Coding Questions: Linked Lists

## Part 1: Conceptual & System Design Questions

### Q1: Why are Linked Lists significantly slower for sequential access compared to `std::vector` on modern CPUs?

**Answer:**
CPU speed depends heavily on spatial locality and hardware prefetching in L1/L2/L3 caches. 

* **`std::vector`:** Stores elements in contiguous memory. When element `A[0]` is read, the CPU cache line (64 bytes) automatically prefetches adjacent elements (`A[1]...A[15]`), resulting in minimal cache misses.
* **`std::list`:** Memory nodes are allocated individually on the heap. Pointers wander across non-contiguous physical addresses. Traversing a linked list causes constant L1/L2 cache misses ("pointer chasing"), slowing down processing by up to 10x-50x.

---

### Q2: How do Sentinel (Dummy) nodes prevent memory crashes and edge-case bugs?

**Answer:**
Sentinel nodes eliminate special conditional checks for empty states (`head == nullptr`) or operations involving edge boundaries (e.g., removing the absolute first or last node). By ensuring every active node always has valid non-null `prev` and `next` pointers, standard insertion/deletion code can run uniformly without branches.

---

## Part 2: Advanced Coding Challenges

### Challenge 1: Reverse Linked List in $K$-Groups

**Problem:** Given a linked list, reverse the nodes of a linked list $k$ at a time and return its modified list.

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    
    // Check if there are at least k nodes left
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    
    if (count == k) {
        ListNode* prev = nullptr;
        ListNode* nextTemp = nullptr;
        curr = head;
        
        for (int i = 0; i < k; ++i) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Recursively reverse remaining sublist
        if (nextTemp) {
            head->next = reverseKGroup(nextTemp, k);
        }
        return prev; // New head for this group
    }
    return head;
}
```