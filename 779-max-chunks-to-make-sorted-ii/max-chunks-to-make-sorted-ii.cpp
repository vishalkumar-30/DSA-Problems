#include <vector>
#include <stack>
using namespace std;

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
/* 
The stack in this code is used to keep track of the largest number seen so far in the array. The idea is to iterate through the array and for each number, pop all numbers from the stack that are smaller than the current number, and then push the current number into the stack. This way, the stack always contains a sequence of numbers in decreasing order from bottom to top.

Here’s a step-by-step breakdown of how the stack works in this code:

Initialize an empty stack: A stack is a data structure that follows the Last-In-First-Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed.

Iterate through the array: For each number in the array, do the following:

Find the largest number: If the current number is larger than the top of the stack (i.e., the last number added to the stack), update the largest number.

Pop smaller numbers from the stack: While the top of the stack is smaller than the current number, pop the top of the stack. This is because these smaller numbers cannot form a valid chunk with the current number.

Push the largest number into the stack: After popping all smaller numbers, push the largest number into the stack. This ensures that the stack always contains a sequence of numbers in decreasing order from bottom to top.

Return the size of the stack: After iterating through the entire array, the size of the stack represents the maximum number of chunks that the array can be divided into.

In summary, the stack in this code is used to divide the array into a maximum number of chunks that can be sorted individually to sort the entire array. Each chunk corresponds to a sequence of numbers in the stack. The stack ensures that each chunk is a sequence of numbers in increasing order, and all numbers in a chunk are smaller than any number in the next chunk.
*/