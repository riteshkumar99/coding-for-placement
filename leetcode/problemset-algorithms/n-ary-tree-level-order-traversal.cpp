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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ans;
        if(root == NULL) {
            return ans;
        }
        int level = -1;
        queue<pair<Node *, int> > stk;
        stk.push({root, 0});
        while(!stk.empty()) {
            pair<Node *, int> p = stk.front();
            stk.pop();
            if(level < p.second) {
                level++;
                ans.push_back(vector<int>(0));
            }
            ans[level].push_back(p.first->val);
            for(auto e: p.first->children) {
                stk.push({e, level+1});
            }
        }
        return ans;
    }
};
