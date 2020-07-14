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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        stack<pair<TreeNode *, short> > stk;
        stk.push({root, 0});
        while(!stk.empty()) {
            pair<TreeNode *, short> p = stk.top();
            if(p.second == 0) {
                stk.top().second = 1;
                if(p.first->left != NULL) {
                    stk.push({p.first->left, 0});
                }
            } else if(p.second == 1) {
                stk.top().second = 2;
                if(p.first->right != NULL) {
                    stk.push({p.first->right, 0});
                }
            } else {
                ans.push_back(p.first->val);
                stk.pop();
            }
        }
        return ans;
    }
};
