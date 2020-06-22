class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int len = 0, flag = 0;
        for(int i = 0; i<(n-1); i++) {
            if(nums[i] == nums[i+1] && !flag) {
                nums[len++] = nums[i];
                flag = 1;
            } else if(nums[i] == nums[i+1]) {
                continue;
            } else {
                nums[len++] = nums[i];
                flag = 0;
            }
        }
        nums[len++] = nums[n-1];
        return len;
    }
};
