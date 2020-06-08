#include<bits/stdc++.h>
using namespace std;

int firstNonSpaceChar(string str) {
    bool isOK = true;
    for(int i = 0, n = str.size(); i<n; i++) {
        if(str[i] == ' ') {
            if(isOK) {
                continue;
            } else {
                return -1;
            }
        } else if(str[i] == '+' || str[i] == '-') {
            if(isOK) {
                isOK = false;
                continue;
            } else {
                return -1;
            }
        }
        else {
            if(isdigit(str[i])) {
                return i;
            } else {
                return -1;
            }
        }
    }
    return -1;
}

int endOfIntegerInString(string str, int pos) {
    int n = str.size();
    for(int i = pos; i<n; i++) {
        if(!isdigit(str[i])) {
            return (i-1);
        }
    }
    return (n - 1);
}

bool isIntegerPositive(string str, int pos) {
    if(pos == 0) {
        return true;
    } else {
        if(str[pos-1] == '-') {
            return false;
        } else {
            return true;
        }
    }
}

int myAtoi(string str) {
    int startPos = firstNonSpaceChar(str);
    long long ans = 0;
    if(startPos == -1) {
        return ans;
    }
    int endPos = endOfIntegerInString(str, startPos);
    bool isPositive = isIntegerPositive(str, startPos);
    while(startPos <= endPos) {
        ans = (ans * 10) + (str[startPos] - '0');
        if(isPositive && ans > INT_MAX) {
            return INT_MAX;
        } else if(!isPositive && ans > ((long long)(INT_MAX) + 1)) {
            return INT_MIN;
        } else {
            startPos++;
        }
    }
    if(!isPositive) {
        return -ans;
    } else {
        return ans;
    }
}

int main() {
    vector<string> v = {
        "2147483648"
    };
    for(auto str: v) {
        cout<<myAtoi(str)<<"\n";
    }
}
