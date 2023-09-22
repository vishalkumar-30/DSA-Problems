class Solution {
private:
    void reversePart(vector<int>&nums, int start, int end){
        while(start<end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++; end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reversePart(nums, 0, n-1);
        reversePart(nums, 0, k-1);
        reversePart(nums, k, n-1);

        return ;
    }
};