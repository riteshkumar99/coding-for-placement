**Problem**

Given a binary number, write a program that prints 1 if given binary number is a multiple of 3.  Else prints 0. The given number can be big upto 2^100. It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.

Output:
For each test case, output a 1 if string is multiple of 3, else 0.

Constraints:
1<=T<=100
1<=Length of Input String<=100

Example:
Input:
2
011
100

Output:
1
0

**Solution**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        int count_even =  0, count_odd = 0;
        bool isEven = true;
        for(int i = s.length()-1; i>=0; i--) {
            if(isEven) {
                count_even += (s[i] == '1');
            } else {
                count_odd += (s[i] == '1');
            }
            isEven = !isEven;
        }
        cout<<(abs(count_even - count_odd) % 3 == 0)<<"\n";
    }
}

```
