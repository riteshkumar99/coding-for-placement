/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findSol(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode * &ans) {
        if(node == NULL) {
            return false;
        }
        bool left = findSol(node->left, p, q, ans);
        bool right = findSol(node->right, p, q, ans);
        bool mid = (node == p or node == q);
        if((left + right + mid) >= 2) {
            ans = node;
        }
        return left or right or mid;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = NULL;
        findSol(root, p, q, ans);
        return ans;
    }
};
