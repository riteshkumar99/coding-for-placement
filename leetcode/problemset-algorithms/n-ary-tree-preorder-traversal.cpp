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
    vector<int> preorder(Node* root) {
        stack<Node*> stk;
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        stk.push(root);
        while(!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            for(int i = node->children.size()-1; i>=0; i--) {
                stk.push(node->children[i]);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};
