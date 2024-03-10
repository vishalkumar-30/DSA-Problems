class Solution {
public:
    int BS(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) end = mid - 1;
            else if(nums[mid] < target) start = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        int p = 0;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] < nums[(m - 1 + n) % n] && nums[m] < nums[(m + 1) % n]){
                p = m;
                break;
            }
            else if(nums[m] <= nums[r]) r = m - 1;
            else if(nums[m] >= nums[l]) l = m + 1;
        }
        l = 0, r = n - 1;
        cout<<p;
        // if(p == -1) p = 0;
        
        if(target >= nums[l] && target <= nums[(p-1+n)%n]) return BS(nums, l, (p - 1 + n) % n, target);
        if(target >= nums[p] && target <= nums[r]) return BS(nums, p, r, target);
        
        return -1;
    }
};
