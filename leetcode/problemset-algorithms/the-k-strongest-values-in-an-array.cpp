class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), median = arr[(n-1)/2], pos = 0, l = 0, r = (n-1);
        vector<int> ans(k);
        while(k--) {
            if((median - arr[l]) > (arr[r] - median)) {
                ans[pos++] = arr[l++];
            } else if((median - arr[l]) < (arr[r] - median)) {
                ans[pos++] = arr[r--];
            } else {
                ans[pos++] = arr[r--];
            }
        }
        return ans;
    }
};
