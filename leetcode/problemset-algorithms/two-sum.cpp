class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0, n = nums.size(); i<n; i++) {
            if(m.find(target-nums[i]) != m.end()) {
                return vector<int>{m[target-nums[i]], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return vector<int>{0, 1};
    }
};
