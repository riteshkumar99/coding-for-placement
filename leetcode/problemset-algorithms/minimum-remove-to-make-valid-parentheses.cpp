class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> valid(n, false);
        stack<int> stk;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(!stk.empty()) {
                    valid[i] = true;
                    valid[stk.top()] = true;
                    stk.pop();
                }
            }
        }
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(s[i] == '(' || s[i] == ')') {
                if(valid[i]) {
                    ans += s[i];
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
