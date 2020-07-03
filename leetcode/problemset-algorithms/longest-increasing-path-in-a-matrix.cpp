#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool inside(int i, int j, int n, int m) {
        return (i >= 0 && i<n && j >= 0 && j<m);
    }
    
    int solveDP(vector<vector<int> > &v, vector<vector<int> > &dp, int n, int m, int i, int j) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        if(inside(i+1, j, n, m) && v[i][j] < v[i+1][j]) {
            dp[i][j] = max(dp[i][j], 1 + solveDP(v, dp, n, m, i+1, j));
        }
        if(inside(i, j+1, n, m) && v[i][j] < v[i][j+1]) {
            dp[i][j] = max(dp[i][j], 1 + solveDP(v, dp, n, m, i, j+1));
        }
        if(inside(i-1, j, n, m) && v[i][j] < v[i-1][j]) {
            dp[i][j] = max(dp[i][j], 1 + solveDP(v, dp, n, m, i-1, j));
        }
        if(inside(i, j-1, n, m) && v[i][j] < v[i][j-1]) {
            dp[i][j] = max(dp[i][j], 1 + solveDP(v, dp, n, m, i, j-1));
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        vector<vector<int> > dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans = max(ans, solveDP(matrix, dp, n, m, i, j));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int> > matrix = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    Solution *soln = new Solution();
    cout<<soln->longestIncreasingPath(matrix)<<endl;
}
