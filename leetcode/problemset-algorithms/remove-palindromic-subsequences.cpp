class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        int l = 0, r = n-1;
        while(l < r) {
            if(s[l++] != s[r--]) {
                return 2;
            }
        }
        return 1;
    }
};
