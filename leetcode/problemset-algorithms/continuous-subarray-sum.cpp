class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> m;
        m[0] = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            int mod = k ? sum % k : sum;
            if(m.find(mod) == m.end()) {
                m[mod] = i+1;
            } else if(i + 1 - m[mod] >= 2) {
                return true;
            }
        }
        return false;
    }
};
