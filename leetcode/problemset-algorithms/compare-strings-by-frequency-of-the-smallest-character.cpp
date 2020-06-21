#include<bits/stdc++.h>
using namespace std;

vector<int> findF(vector<string> &v) {
    int n = v.size();
    vector<int> ans(n, 0);
    for(int i = 0; i<n; i++) {
        vector<int> arr(26, 0);
        for(auto e: v[i]) {
            arr[e-'a']++;
        }
        for(int j = 0; j<26; j++) {
            if(arr[j]) {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> q = findF(queries);
    vector<int> w = findF(words);
    int n = queries.size();
    vector<int> ans(n, 0);
    for(int i =0; i<n; i++) {
        for(auto e: w) {
            ans[i] += (q[i] < e);
        }
    }
    return ans;
}

int main() {
    vector<string> queries = {"bbb", "cc"}, words = {"a", "aa", "aaa", "aaaa"};
    vector<int> ans = numSmallerByFrequency(queries, words);
    for(auto e: ans) {
        cout<<e<<" ";
    }
    cout<<endl;
}
