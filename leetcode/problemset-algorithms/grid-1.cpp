#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    const int MOD = 1000000007;
    cin>>h>>w;
    vector<vector<char> > v(h+1, vector<char>(w+1));
    for(int i = 1; i<=h; i++) {
        for(int j = 1; j<=w; j++) {
            cin>>v[i][j];
        }
    }
    vector<vector<int> > dp(h+1, vector<int>(w+1, 0));
    for(int i = 2; i<=h; i++) {
        if(v[i][1] == '.') {
            dp[i][1] = 1;
        } else {
            break;
        }
    }
    for(int j = 2; j<=w; j++) {
        if(v[1][j] == '.') {
            dp[1][j] = 1;
        } else {
            break;
        }
    }
    for(int i = 2; i<=h; i++) {
        for(int j = 2; j<=w; j++) {
            if(v[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout<<dp[h][w]<<"\n";
}
