class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int currPos = 1, repPos = 1;
        for(; currPos < nums.size(); currPos++) {
            if(nums[currPos] != nums[currPos-1]) {
                nums[repPos] = nums[currPos];
                repPos++;
            }
        }
        return repPos;
    }
};
