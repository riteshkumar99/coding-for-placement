#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int> > &grid, vector<vector<bool> > &visited, int &currAns) {
    if(i < (n-1) && grid[i+1][j] && !visited[i+1][j]) {
        currAns++;
        visited[i+1][j] = true;
        dfs(i+1, j, n, m, grid, visited, currAns);
    }
    if(j < (m-1) && grid[i][j+1] && !visited[i][j+1]) {
        currAns++;
        visited[i][j+1] = true;
        dfs(i, j+1, n, m, grid, visited, currAns);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0, currAns;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] && !visited[i][j]) {
                currAns = 1;
                visited[i][j] = true;
                dfs(i, j, n, m, grid, visited, currAns);
                ans = max(ans, currAns);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > v = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout<<maxAreaOfIsland(v)<<endl;
}
