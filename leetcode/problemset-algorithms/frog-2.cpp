#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> h(n), dp(n, 0);
    for(auto &e: h) cin>>e;
    for(int i = 1; i<n; i++) {
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        for(int j = 2; j<=k && (i-j) >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout<<dp[n-1]<<"\n";
}
