#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, w, total_values = 0;
    cin>>n>>w;
    vector<int> weights(n), values(n);
    for(int i = 0; i<n; i++) {
        cin>>weights[i]>>values[i];
        total_values += values[i];
    }
    vector<vector<long long> > dp(n+1, vector<long long>(total_values+1, 0));
    for(int i = 1; i<=total_values; i++) {
        dp[0][i] = INT_MAX;
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=total_values; j++) {
            if(values[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = min(dp[i-1][j], weights[i-1] + dp[i-1][j-values[i-1]]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<=total_values; i++) {
        if(dp[n][i] <= w) {
            ans = i;
        }
    }
    cout<<ans<<"\n";
}
