#include<bits/stdc++.h>
using namespace std;

int partitionDisjoint(vector<int> &v) {
    int n = v.size();
    vector<int> maxv(n, v[0]), minv(n, v[n-1]);
    for(int i = 1; i<n; i++) {
        maxv[i] = max(v[i], maxv[i-1]);
    }
    for(int i = n-2; i>=0; i--) {
        minv[i] = min(v[i], minv[i+1]);
    }
    for(int i = 0; i<(n-1); i++) {
        if(maxv[i] <= minv[i+1]) {
            return i+1;
        }
    }
    return 0;
}

int main() {
    vector<int> v = {29,33,6,4,42,0,10,22,62,16,46,75,100,67,70,74,87,69,73,88};
    cout<<partitionDisjoint(v)<<"\n";
}
