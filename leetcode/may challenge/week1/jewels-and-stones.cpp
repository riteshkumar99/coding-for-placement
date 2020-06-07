class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char> s;
        for(int i = 0, n = J.size(); i<n; i++) {
            s.insert(J[i]);
        }
        for(auto e: S) {
            if(s.find(e) != s.end()) {
                count++;
            }
        }
        return count;
    }
};
