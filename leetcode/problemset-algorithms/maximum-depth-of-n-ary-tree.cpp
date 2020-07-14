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
    int maxDepth(Node* root) {
        int ans = 0;
        if(root == NULL) {
            return ans;
        }
        stack<pair<Node*, int> > stk;
        stk.push({root, 1});
        while(!stk.empty()) {
            pair<Node *, int> p = stk.top();
            stk.pop();
            if(p.first->children.size() == 0) {
                ans = max(ans, p.second);
            } else {
                for(auto e: p.first->children) {
                    stk.push({e, p.second+1});
                }
            }
        }
        return ans;
    }
};
