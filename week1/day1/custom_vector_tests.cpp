#include "custom_vector.hpp"
#include <cassert>
#include <iostream>
#include <string>

void test_vector_initialization() {
    CustomVector<int> vec;
    assert(vec.size() == 0);
    assert(vec.capacity() == 2);
    assert(vec.empty());
    std::cout << "  [Test] Vector Initialization: PASSED" << std::endl;
}

void test_vector_push_and_reallocation() {
    CustomVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    assert(vec.size() == 2);
    assert(vec.capacity() == 2);

    // This push should trigger 2x capacity growth (capacity becomes 4)
    vec.push_back(30);
    assert(vec.size() == 3);
    assert(vec.capacity() == 4);

    assert(vec[0] == 10);
    assert(vec[1] == 20);
    assert(vec[2] == 30);
    std::cout << "  [Test] Push & Dynamic Reallocation: PASSED" << std::endl;
}

void test_vector_pop_and_bounds() {
    CustomVector<std::string> vec;
    vec.push_back("Hello");
    vec.push_back("World");

    assert(vec.at(0) == "Hello");
    assert(vec.at(1) == "World");

    vec.pop_back();
    assert(vec.size() == 1);
    assert(vec[0] == "Hello");

    bool caught_exception = false;
    try {
        vec.at(5);
    } catch (const std::out_of_range&) {
        caught_exception = true;
    }
    assert(caught_exception);
    std::cout << "  [Test] Pop Back & Bounds Checking: PASSED" << std::endl;
}

int main() {
    std::cout << "=== Running CustomVector Unit Tests ===" << std::endl;
    test_vector_initialization();
    test_vector_push_and_reallocation();
    test_vector_pop_and_bounds();
    std::cout << "All CustomVector tests passed cleanly!\n" << std::endl;
    return 0;
}