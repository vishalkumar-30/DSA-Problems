class MyStack {
public:
    queue<int> q1, q2;
    int top_element;

    MyStack() {
        top_element = -1;
    }

    void push(int x) {
        q1.push(x);
        top_element = x; // Update top element
    }

    int pop() {
        if (q1.empty())
            return -1;  // Stack is empty

        while (q1.size() > 1) {
            top_element = q1.front(); // Update top element while moving elements
            q2.push(q1.front());
            q1.pop();
        }

        int x = q1.front();
        q1.pop();

        swap(q1, q2); // Swap q1 and q2 to maintain the stack property

        return x;
    }

    int top() {
        return top_element;
    }

    bool empty() {
        return q1.empty();
    }
};
