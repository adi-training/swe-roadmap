#include <iostream>
#include <vector>
#include <cassert>

// ============================================================================
// Problem 1: LeetCode 27 - Remove Element
// ============================================================================
class SolutionRemoveElement {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int write_ptr = 0;
        for (int read_ptr = 0; read_ptr < static_cast<int>(nums.size()); ++read_ptr) {
            if (nums[read_ptr] != val) {
                nums[write_ptr] = nums[read_ptr];
                write_ptr++;
            }
        }
        return write_ptr;
    }
};

void test_remove_element() {
    SolutionRemoveElement sol;
    std::vector<int> nums = {3, 2, 2, 3};
    int k = sol.removeElement(nums, 3);
    assert(k == 2);
    assert(nums[0] == 2 && nums[1] == 2);
    std::cout << "  [LeetCode 27] Remove Element: PASSED" << std::endl;
}

// ============================================================================
// Problem 2: LeetCode 26 - Remove Duplicates from Sorted Array
// ============================================================================
class SolutionRemoveDuplicates {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slow = 0;
        for (size_t fast = 1; fast < nums.size(); ++fast) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

void test_remove_duplicates() {
    SolutionRemoveDuplicates sol;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = sol.removeDuplicates(nums);
    assert(k == 5);
    
    int expected[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < k; ++i) {
        assert(nums[i] == expected[i]);
    }
    std::cout << "  [LeetCode 26] Remove Duplicates: PASSED" << std::endl;
}

int main() {
    std::cout << "=== Running Day 1 DSA Solution Verification ===" << std::endl;
    test_remove_element();
    test_remove_duplicates();
    std::cout << "All DSA tests completed successfully!\n" << std::endl;
    return 0;
}