class Solution {
    int findOne(vector<int> &v) {
        if(v[0] == 0) {
            return 0;
        }
        int n = v.size(), l = 0, r = n-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(v[mid] == 1 && v[mid+1] == 0) {
                return mid+1;
            } else if(v[mid] == 1) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(l < n-1 && v[l] == 1 && v[l+1] == 0) {
            return l+1;
        } else {
            return n;
        }
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int> > v(m);
        for(int i = 0; i<m; i++) {
            v[i] = {findOne(mat[i]), i};
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for(int i = 0; i<k; i++) {
            ans[i] = v[i].second;
        }
        return ans;
    }
};
