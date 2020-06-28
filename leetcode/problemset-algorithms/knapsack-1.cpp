#include<bits/stdc++.h>
using namespace std;

long long knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    vector<vector<long long> > dp(n+1, vector<long long>(W+1, 0));
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=W; j++) {
            if(j >= weights[i-1]) {
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, w;
    cin>>n>>w;
    vector<int> weights(n), values(n);
    for(int i = 0; i<n; i++) {
        cin>>weights[i]>>values[i];
    }
    cout<<knapsack(w, weights, values, n)<<"\n";
}
