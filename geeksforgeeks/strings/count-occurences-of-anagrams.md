**Problem**

```
Given a word S and a text C. Return the count of the occurences of anagrams of the word in the text.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a text S consisting of only lowercase characters.
The second line contains a word consisting of only lowercase characters.

Output:
Print the count of the occurences of anagrams of the word C in the text S.

Constraints:
1 <= T <= 50
1 <= |S| <= |C| <= 50

Example:
Input:
2
forxxorfxdofr
for
aabaabaa
aaba

Output:
3
4
```

**Solution**

```cpp
#include<bits/stdc++.h>
using namespace std;

bool check(unordered_map<char, int> &ma, unordered_map<char, int> &mb) {
    for(pair<char, int> i: mb) {
        if(ma[i.first] < i.second) return false;
    }
    return true;
}

int main() {
    int t;
    string a, b;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        int n = a.length(), m = b.length(), count = 0;
        unordered_map<char, int> ma, mb;
        for(char c: b) mb[c]++;
        for(int i = 0; i<m; i++) ma[a[i]]++;
        if(check(ma, mb)) count++;
        for(int i = m; i<n; i++) {
            ma[a[i-m]]--;
            ma[a[i]]++;
            if(check(ma, mb)) count++;
        }
        cout<<count<<'\n';
    }
}

```
