class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int lo = 0, hi = nums.size()-1;
        if(nums[lo] < nums[hi]) {
            return nums[lo];
        }
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(nums[mid+1] < nums[mid]) {
                return nums[mid+1];
            }
            if(nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if(nums[lo] < nums[mid]) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return -1;
    }
};
