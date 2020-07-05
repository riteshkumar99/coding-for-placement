class Solution {
public:
    bool isValid(string S) {
        stack<string> stk;
        for(auto c: S) {
            if(c == 'a') {
                stk.push("a");
            } else if(c == 'b') {
                if(stk.empty() || stk.top() != "a") {
                    return false;
                } else {
                    stk.pop();
                    stk.push("ab");
                }
            } else {
                if(stk.empty() || stk.top() != "ab") {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
