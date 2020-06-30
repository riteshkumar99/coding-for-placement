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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        if(root == NULL) return ans;
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if(node->val >= L && node->val <= R) ans += node->val;
            if(node->left && node->val > L) stk.push(node->left);
            if(node->right && node->val < R) stk.push(node->right);
        }
        return ans;
    }
};
