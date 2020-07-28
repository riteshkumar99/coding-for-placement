**Problem**

```
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1
```

**Solution**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<long long> v(n);
        for(long long &i: v) cin>>i;
        vector<long long> dp(n, 0);
        dp[0] = v[0];
        for(int i = 1; i<n; i++) {
            dp[i] = v[i];
            if(dp[i-1] > 0) dp[i] += dp[i-1];
        }
        cout<<*max_element(dp.begin(), dp.end())<<"\n";
    }
}

```
