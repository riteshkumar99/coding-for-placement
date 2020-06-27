#include<bits/stdc++.h>
using namespace std;

int solve(vector<array<int, 3> > &v, vector<array<int, 3> > &dp, int pos, int i) {
    if(pos == v.size()) return 0;
    if(dp[pos][i] != -1) return dp[pos][i];
    switch(i) {
        case 0: dp[pos][i] = max(v[pos][1] + solve(v, dp, pos+1, 1), v[pos][2] + solve(v, dp, pos+1, 2));
                break;
        case 1: dp[pos][i] = max(v[pos][0] + solve(v, dp, pos+1, 0), v[pos][2] + solve(v, dp, pos+1, 2));
                break;
        case 2: dp[pos][i] = max(v[pos][0] + solve(v, dp, pos+1, 0), v[pos][1] + solve(v, dp, pos+1, 1));
                break;
    }
    return dp[pos][i];
}

int main() {
    int n;
    cin>>n;
    vector<array<int, 3> > v(n);
    vector<array<int, 3> > dp(n, {-1, -1, -1});
    for(auto &e: v) cin>>e[0]>>e[1]>>e[2];
    dp[0][0] = v[0][0] + solve(v, dp, 1, 0);
    dp[0][1] = v[0][1] + solve(v, dp, 1, 1);
    dp[0][2] = v[0][2] + solve(v, dp, 1, 2);
    cout<<max(dp[0][0], max(dp[0][1], dp[0][2]))<<endl;
}
