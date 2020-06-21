class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n % W) {
            return false;
        }
        map<int, int> m;
        for(auto i: hand) {
            m[i]++;
        }
        for(int i = 0; i<n/W; i++) {
            int start = m.begin()->first;
            if(--m[start] == 0) {
                m.erase(start);
            }
            for(int j = W-1; j>0; j--) {
                if(!m.count(++start)) {
                    return false;
                }
                if(--m[start] == 0) {
                    m.erase(start);
                }
            }
        }
        return true;
    }
};
