#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;

    MyStack() {
        
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty())
            return -1;  // Stack is empty

        int size = q1.size();
        for (int i = 0; i < size - 1; ++i) {
            int x = q1.front();
            q1.pop();
            q1.push(x);
        }

        int x = q1.front();
        q1.pop();

        return x;
    }

    int top() {
        if (q1.empty())
            return -1;  // Stack is empty

        int size = q1.size();
        for (int i = 0; i < size - 1; ++i) {
            int x = q1.front();
            q1.pop();
            q1.push(x);
        }

        int x = q1.front();
        q1.pop();
        q1.push(x); // Push the top element back to maintain the order

        return x;
    }

    bool empty() {
        return q1.empty();
    }
};
