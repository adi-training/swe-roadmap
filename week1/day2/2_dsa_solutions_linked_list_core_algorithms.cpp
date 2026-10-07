#include <iostream>
#include <utility>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// ============================================================================
// Problem 1: Reverse Singly Linked List (Iterative & In-Place)
// Time Complexity: O(N), Auxiliary Space: O(1)
// ============================================================================
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// ============================================================================
// Problem 2: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(N), Auxiliary Space: O(1)
// ============================================================================
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// ============================================================================
// Problem 3: Merge Two Sorted Lists (Using Dummy Node)
// Time Complexity: O(N + M), Auxiliary Space: O(1)
// ============================================================================
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
}

// ============================================================================
// Problem 4: Remove N-th Node From End of List (One-Pass)
// Time Complexity: O(N), Auxiliary Space: O(1)
// ============================================================================
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    
    for (int i = 0; i <= n; ++i) {
        if (!fast) return head;
        fast = fast->next;
    }
    
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;
    
    return dummy.next;
}

// Helper utility to print lists
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

int main() {
    std::cout << "=== Testing Day 2 DSA Solutions ===\n\n";

    // Test Reverse
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    std::cout << "Original List: ";
    printList(l1);
    l1 = reverseList(l1);
    std::cout << "Reversed List: ";
    printList(l1);

    // Test Merge
    ListNode* a = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* b = new ListNode(2, new ListNode(4, new ListNode(6)));
    ListNode* merged = mergeTwoLists(a, b);
    std::cout << "Merged Sorted List: ";
    printList(merged);

    // Clean memory
    while (l1) { ListNode* temp = l1; l1 = l1->next; delete temp; }
    while (merged) { ListNode* temp = merged; merged = merged->next; delete temp; }

    return 0;
}