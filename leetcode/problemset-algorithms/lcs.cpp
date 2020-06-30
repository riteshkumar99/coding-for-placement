#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1));
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }
    string ans = "";
    int i = n, j = m;
    while(i && j) {
        if(s[i-1] == t[j-1]) {
            ans = s[i-1] + ans;
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout<<ans<<"\n";
}
