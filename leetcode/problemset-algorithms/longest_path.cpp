#include<bits/stdc++.h>
using namespace std;

int dfs(int i, vector<vector<int> > &edges, vector<int> &maxDistance) {
    if(maxDistance[i] != -1) {
        return maxDistance[i];
    }
    maxDistance[i] = 0;
    for(auto e: edges[i]) {
        maxDistance[i] = max(maxDistance[i], 1 + dfs(e, edges, maxDistance));
    }
    return maxDistance[i];
}

int main() {
    int n, m, u, v;
    cin>>n>>m;
    vector<vector<int> > edges(n+1, vector<int>(0));
    for(int i = 0; i<m; i++) {
        cin>>u>>v;
        edges[u].push_back(v);
    }
    vector<int> maxDistance(n+1, -1);
    for(int i = 1; i<=n; i++) {
        if(maxDistance[i] == -1) {
            maxDistance[i] = dfs(i, edges, maxDistance);
        }
    }
    cout<<*max_element(maxDistance.begin(), maxDistance.end())<<endl;
}
