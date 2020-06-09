#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &a, int s) {
    int count = 0, currSum, n = a.size(), j = 1;
    for(int i = 0; i<n; i++) {
        currSum = a[i];
        if(currSum == s) {
            count++;
        }
        for(int j = i+1; j<n; j++) {
            currSum += a[j];
            if(currSum == s) {
                count++;
            } else if(currSum > s) {
                break;
            }
        }
    }
    return count;
}

int main() {
    vector<int> v = {0, 0, 0, 0, 0};
    cout<<numSubarraysWithSum(v, 0)<<"\n";
}
