#include <iostream>
#include <cassert>
#include <string>
#include "4_custom_stack_queue_implementation.cpp"

void testPushPopBothEnds() {
    CustomDeque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5); // Deque: [5, 10, 20]

    assert(dq.getSize() == 3);
    assert(dq.front() == 5);
    assert(dq.back() == 20);

    dq.pop_front(); // Deque: [10, 20]
    assert(dq.front() == 10);

    dq.pop_back(); // Deque: [10]
    assert(dq.back() == 10);
    assert(dq.getSize() == 1);
    std::cout << "[PASS] Push/Pop Both Ends Test\n";
}

void testCircularWrappingAndResize() {
    CustomDeque<int> dq(4); // Capacity = 4
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.pop_front(); // Head wraps: elements [2, 3]
    dq.pop_front(); // Elements [3]

    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6); // Triggers circular wrap and eventual resize!

    assert(dq[0] == 3);
    assert(dq[1] == 4);
    assert(dq[2] == 5);
    assert(dq[3] == 6);
    std::cout << "[PASS] Circular Wrapping & Resizing Test\n";
}

void testCopyAndMove() {
    CustomDeque<std::string> dq1 = {"A", "B", "C"};
    CustomDeque<std::string> dq2 = dq1; // Copy

    assert(dq2.getSize() == 3);
    assert(dq2.front() == "A");

    CustomDeque<std::string> dq3 = std::move(dq1); // Move
    assert(dq3.back() == "C");
    assert(dq1.getSize() == 0);
    std::cout << "[PASS] Copy and Move Semantics Test\n";
}

int main() {
    std::cout << "=== Running CustomDeque Unit Tests ===\n";
    testPushPopBothEnds();
    testCircularWrappingAndResize();
    testCopyAndMove();
    std::cout << "All unit tests passed successfully!\n";
    return 0;
}