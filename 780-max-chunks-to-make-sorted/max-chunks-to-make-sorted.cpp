class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for (int num : arr) {
            int largest = num;
            while (!s.empty() && s.top() > num) {
                largest = max(largest, s.top());
                s.pop();
            }
            s.push(largest);
        }
        return s.size();
    }
};