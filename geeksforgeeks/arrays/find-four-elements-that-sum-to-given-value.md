**Problem**

Given an array of integers, find all combination of four elements in the array whose sum is equal to a given value X.
For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and X = 23, then your function should print “3 5 7 8” (3 + 5 + 7 + 8 = 23).

**Solution**

_Approach 1_

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> v(n);
        for(int &i: v) cin>>i;
        sort(v.begin(), v.end());
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int l = j+1, h = n-1;
                while(l < h) {
                    int sum = v[i] + v[j] + v[l] + v[h];
                    if(sum == k) {
                        printf("%d %d %d %d\n", v[i], v[j], v[l], v[h]);
                        l++;
                        h--;
                    } else if(sum > k) {
                        h--;
                    } else {
                        l++;
                    }
                }
            }
        }
    }
}

```

_Approach 2_

```cpp
#include<bits/stdc++.h>
using namespace std;

struct PairSum {
    int first, second, sum;
};

bool compare(PairSum p1, PairSum p2) {
    return p1.sum < p2.sum;
}

bool noCommon(PairSum a, PairSum b) {
    if(a.first == b.first or a.second == b.second or a.first == b.second or a.second == b.first) return false;
    return true;
}

int main() {
    int t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> v(n);
        for(int &i: v) cin>>i;
        long twoSumSize = (1L*n*(n-1))/2, pos = 0;
        vector<PairSum> arr(twoSumSize);
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                arr[pos].first = i;
                arr[pos].second = j;
                arr[pos].sum = v[i] + v[j];
                pos++;
            }
        }
        sort(arr.begin(), arr.end(), compare);
        int l = 0, h = twoSumSize - 1;
        while(l < h) {
            if(arr[l].sum + arr[h].sum == k) {
                if(noCommon(arr[l], arr[h])) {
                    printf("%d %d %d %d\n", v[arr[l].first], v[arr[l].second], v[arr[h].first], v[arr[h].second]);
                    break;
                }
                l++;
                h--;
            } else if(arr[l].sum + arr[h].sum > k) {
                h--;
            } else {
                l++;
            }
        }
    }
}

```

_Approach 3_
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> v(n);
        for(int &i: v) cin>>i;
        unordered_map<int, pair<int, int> > m;
        bool flag = false;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                m[v[i]+v[j]] = {i, j};
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int sum = v[i] + v[j];
                if(m.find(k - sum) != m.end()) {
                    pair<int, int> p = m[k-sum];
                    if(p.first != i and p.second != i and p.first != j and p.second != j) {
                        printf("%d %d %d %d\n", v[i], v[j], v[p.first], v[p.second]);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
    }
}

```
