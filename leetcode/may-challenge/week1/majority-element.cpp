class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, elem;
        for(int i = 0, n = nums.size(); i<n; i++) {
            if(count == 0) {
                count = 1;
                elem = nums[i];
            } else {
                if(elem == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return elem;
    }
};

