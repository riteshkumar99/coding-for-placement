class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int count = 0, countOn = 0, countBlue = 0, n = light.size();
        vector<bool> on(n, false), blue(n, false);
        for(auto e: light) {
            on[e-1] = true;
            countOn++;
            if(e == 1 || blue[e-2]) {
                blue[e-1] = true;
                countBlue++;
                for(int j = e; j<n; j++) {
                    if(!blue[j] && on[j]) {
                        blue[j] = true;
                        countBlue++;
                    } else {
                        break;
                    }
                }
            }
            if(countOn == countBlue) {
                count++;
            }
        }
        return count;
    }
};
