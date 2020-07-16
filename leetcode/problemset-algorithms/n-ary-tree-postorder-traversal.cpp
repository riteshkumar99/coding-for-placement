/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        stack<pair<Node *, bool> > stk;
        stk.push({root, false});
        while(!stk.empty()) {
            pair<Node *, bool> p = stk.top();
            if(p.second == false) {
                stk.top().second = true;
                int nChildren = p.first->children.size();
                if(nChildren == 0) {
                    stk.pop();
                    ans.push_back(p.first->val);
                } else {
                    for(int i = nChildren - 1; i>=0; i--) {
                        stk.push({p.first->children[i], false});
                    }
                }
            } else {
                stk.pop();
                ans.push_back(p.first->val);
            }
        }
        return ans;
    }
};
