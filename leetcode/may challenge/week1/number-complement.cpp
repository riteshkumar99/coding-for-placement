class Solution {
public:
    int findComplement(int num) {
        int ans = 0, k = 0;
        while(num) {
            ans += (((num % 2) ^ 1) << k);
            k++;
            num /= 2;
        }
        return ans;
    }
};

