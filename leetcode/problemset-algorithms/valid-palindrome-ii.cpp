class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            } else {
                int sl = l+1, sr = r;
                bool firstTry = true, secondTry = true;
                while(sl < sr) {
                    if(s[sl] == s[sr]) {
                        sl++;
                        sr--;
                    } else {
                        firstTry = false;
                        break;
                    }
                }
                sl = l, sr = r-1;
                while(sl < sr) {
                    if(s[sl] == s[sr]) {
                        sl++;
                        sr--;
                    } else {
                        secondTry = false;
                        break;
                    }
                }
                if(firstTry == false && secondTry == false) {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};
