class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);
        for(auto e: magazine) {
            m[e - 'a']++;
        }
        for(auto e: ransomNote) {
            if(m[e - 'a']) {
                m[e - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};
