#include <iostream>
#include <cassert>
#include <string>
#include "4_custom_linked_list_implementation.cpp"

void testPushAndPop() {
    CustomLinkedList<int> list;
    assert(list.isEmpty());
    assert(list.getSize() == 0);

    list.push_back(10);
    list.push_back(20);
    list.push_front(5); // List: [5, 10, 20]

    assert(list.getSize() == 3);
    assert(list.front() == 5);
    assert(list.back() == 20);

    list.pop_front(); // List: [10, 20]
    assert(list.front() == 10);

    list.pop_back(); // List: [10]
    assert(list.back() == 10);
    assert(list.getSize() == 1);

    list.clear();
    assert(list.isEmpty());
    std::cout << "[PASS] Test Push and Pop\n";
}

void testIterators() {
    CustomLinkedList<int> list = {1, 2, 3, 4, 5};
    int expected = 1;
    for (int val : list) {
        assert(val == expected);
        expected++;
    }
    assert(expected == 6);
    std::cout << "[PASS] Test Iterators\n";
}

void testCopyAndMove() {
    CustomLinkedList<std::string> original = {"Alpha", "Beta", "Gamma"};
    CustomLinkedList<std::string> copy = original; // Copy Constructor

    assert(copy.getSize() == 3);
    assert(copy.front() == "Alpha");

    CustomLinkedList<std::string> moved = std::move(original); // Move Constructor
    assert(moved.getSize() == 3);
    assert(moved.back() == "Gamma");

    std::cout << "[PASS] Test Copy and Move Semantics\n";
}

int main() {
    std::cout << "=== Running CustomLinkedList Unit Tests ===\n";
    testPushAndPop();
    testIterators();
    testCopyAndMove();
    std::cout << "All unit tests passed successfully!\n";
    return 0;
}