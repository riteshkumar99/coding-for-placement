#include<bits/stdc++.h>
using namespace std;

int dfs(int node, int c_road, vector<vector<int> > &edges, vector<bool> &visited) {
    int cost = 0;
    for(auto it = edges[node].begin(); it != edges[node].end(); it++) {
        if(!visited[*it]) {
            visited[*it] = true;
            cost += c_road;
            cost += dfs(*it, c_road, edges, visited);
        }
    }
    return cost;
}

int main() {
    int n, m, c_lib, c_road, q, u, v, cost;
    cin>>q;
    while(q--) {
        cin>>n>>m>>c_lib>>c_road;
        vector<vector<int> > edges(n+1, vector<int>(0));
        vector<bool> visited(n+1, false);
        cost = 0;
        for(int i = 0; i<m; i++) {
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 1; i<=n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                cost += c_lib;
                cost += dfs(i, (c_road < c_lib) ? c_road : c_lib, edges, visited);
            }
        }
        cout<<cost<<"\n";
    }
}
