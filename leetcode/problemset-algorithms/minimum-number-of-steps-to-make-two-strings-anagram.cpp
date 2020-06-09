class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vs(26, 0);
        int count = 0;
        for(auto e: s) {
            vs[e - 'a']++;
        }
        for(auto e: t) {
            if(vs[e - 'a']) {
                vs[e - 'a']--;
            } else {
                count++;
            }
        }
        return count;
    }
};
