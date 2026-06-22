#include <iostream>
#include <stack>
#include <algorithm>

/* Min Stack, you need to return the minimum value in O(1) time.
 * Create a normal stack to store all values and a second stack
 * called minStack to keep track of the minimum value seen so far.
 *
 * When pushing a value, add it to the normal stack, then compare
 * it with the current minimum and store the smaller value in
 * minStack. This ensures the top of minStack always contains the
 * minimum element currently in the stack.
 *
 * When popping, remove an element from both stacks to keep them
 * synchronized. This allows push(), pop(), top(), and getMin()
 * to all run in O(1) time.
 */

class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    void push(int val) {
        stack.push(val);

        val = std::min(
            val,
            minStack.empty() ? val : minStack.top()
        );

        minStack.push(val);
    }

    void pop() {
        stack.pop();
        minStack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    std::cout << "Pushed 5, Min = "
              << ms.getMin() << '\n';

    ms.push(2);
    std::cout << "Pushed 2, Min = "
              << ms.getMin() << '\n';

    ms.push(8);
    std::cout << "Pushed 8, Min = "
              << ms.getMin() << '\n';

    ms.push(1);
    std::cout << "Pushed 1, Min = "
              << ms.getMin() << '\n';

    ms.push(4);
    std::cout << "Pushed 4, Min = "
              << ms.getMin() << '\n';

    std::cout << "\nTop = "
              << ms.top() << '\n';

    ms.pop();
    std::cout << "Popped 4, Min = "
              << ms.getMin() << '\n';

    ms.pop();
    std::cout << "Popped 1, Min = "
              << ms.getMin() << '\n';

    return 0;
}
