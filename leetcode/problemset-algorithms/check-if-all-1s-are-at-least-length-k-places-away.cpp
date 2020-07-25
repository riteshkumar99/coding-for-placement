class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = k;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                dist++;
            } else {
                if(dist < k) {
                    return false;
                }
                dist = 0;
            }
        }
        return true;
    }
};
