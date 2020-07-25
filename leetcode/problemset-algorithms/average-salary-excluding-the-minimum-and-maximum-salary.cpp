class Solution {
public:
    double average(vector<int>& salary) {
        int maxValue = INT_MIN, minValue = INT_MAX, sum = 0, n = salary.size();
        for(int i = 0; i<n; i++) {
            sum += salary[i];
            if(maxValue < salary[i]) maxValue = salary[i];
            if(minValue > salary[i]) minValue = salary[i];
        }
        double den = 1.0/(n-2);
        return (sum - maxValue - minValue) * den;
    }
};
