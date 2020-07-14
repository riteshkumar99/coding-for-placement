/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        stack<pair<TreeNode *, bool> > stk;
        stk.push({root, false});
        while(!stk.empty()) {
            pair<TreeNode *, bool> p = stk.top();
            stk.pop();
            if(p.second == false) {
                if(p.first->left == NULL) {
                    ans.push_back(p.first->val);
                    if(p.first->right) {
                        stk.push({p.first->right, false});
                    }
                } else {
                    p.second = true;
                    stk.push(p);
                    stk.push({p.first->left, false});
                }
            } else {
                ans.push_back(p.first->val);
                if(p.first->right) {
                    stk.push({p.first->right, false});
                }
            }
        }
        return ans;
    }
};
