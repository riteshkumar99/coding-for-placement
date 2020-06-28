#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 3, 4};
    map<pair<int, int>, int> m;
    for(int i = 0; i<3; i++) {
        m[{a[i], b[i]}] = a[i]*b[i];
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        cout<<"["<<it->first.first<<", "<<it->first.second<<"]"<<"=>"<<it->second<<endl;
    }
}
