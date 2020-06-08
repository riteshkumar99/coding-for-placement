#include<bits/stdc++.h>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<int> rowMax(n, 0), colMax(m, 0);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            rowMax[i] = max(rowMax[i], grid[i][j]);
            colMax[j] = max(colMax[j], grid[i][j]);
        }
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            count += min(rowMax[i], colMax[j]) - grid[i][j];
        }
    }
    return count;
}

int main() {
    vector<vector<int> > v = {
        {3,0,8,4},
        {2,4,5,7},
        {9,2,6,3},
        {0,3,1,0}
    };
    cout<<maxIncreaseKeepingSkyline(v)<<endl;
}
