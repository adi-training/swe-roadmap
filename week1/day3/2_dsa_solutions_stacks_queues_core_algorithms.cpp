#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <cassert>

// ============================================================================
// Problem 1: Valid Parentheses
// Time Complexity: O(N), Auxiliary Space: O(N)
// ============================================================================
bool isValidParentheses(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

// ============================================================================
// Problem 2: Min Stack (O(1) Auxiliary Minimum Retrieval)
// Time Complexity: O(1) for all ops, Auxiliary Space: O(N)
// ============================================================================
class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() const {
        return mainStack.top();
    }

    int getMin() const {
        return minStack.top();
    }
};

// ============================================================================
// Problem 3: Evaluate Reverse Polish Notation (RPN)
// Time Complexity: O(N), Auxiliary Space: O(N)
// ============================================================================
int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> st;
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            if (token == "+") st.push(op1 + op2);
            else if (token == "-") st.push(op1 - op2);
            else if (token == "*") st.push(op1 * op2);
            else if (token == "/") st.push(op1 / op2);
        } else {
            st.push(std::stoi(token));
        }
    }
    return st.top();
}

// ============================================================================
// Problem 4: Sliding Window Maximum (Monotonic Queue / Deque)
// Time Complexity: O(N), Auxiliary Space: O(K)
// ============================================================================
std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> dq; // Stores indices of elements in decreasing order of value

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        // Remove indices out of the current window boundary [i - k + 1, i]
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Maintain monotonic decreasing invariant in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Record max element for windows starting at index k - 1
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    std::cout << "=== Testing Day 3 DSA Solutions ===\n\n";

    // Test Parentheses
    assert(isValidParentheses("()[]{}") == true);
    assert(isValidParentheses("(]") == false);
    std::cout << "[PASS] Valid Parentheses\n";

    // Test MinStack
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);
    std::cout << "[PASS] MinStack\n";

    // Test RPN
    std::vector<std::string> rpn = {"2", "1", "+", "3", "*"}; // (2 + 1) * 3 = 9
    assert(evalRPN(rpn) == 9);
    std::cout << "[PASS] Evaluate RPN\n";

    // Test Sliding Window Maximum
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> res = maxSlidingWindow(nums, 3);
    std::vector<int> expected = {3, 3, 5, 5, 6, 7};
    assert(res == expected);
    std::cout << "[PASS] Sliding Window Maximum\n";

    return 0;
}