class Solution {
public:    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), minSum, currSum = 0, l = 0, r = n - k - 1;
        for(int i = l; i<=r; i++) {
            currSum += cardPoints[i];
        }
        minSum = currSum;
        l++;
        r++;
        while(r < n) {
            currSum += cardPoints[r] - cardPoints[l-1];
            minSum = min(minSum, currSum);
            l++;
            r++;
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};
