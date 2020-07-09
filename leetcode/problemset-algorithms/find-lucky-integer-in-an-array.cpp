class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto e: arr) {
            m[e]++;
        }
        int ans = -1;
        for(auto e: arr) {
            if(e == m[e]) {
                ans = max(ans, e);
            }
        }
        return ans;
    }
};

