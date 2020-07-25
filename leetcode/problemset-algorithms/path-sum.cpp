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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        int currSum = sum - root->val;
        if(root->left == NULL && root->right == NULL) {
            return !currSum;
        }
        if(root->left == NULL) {
            return hasPathSum(root->right, currSum);
        }
        if(root->right == NULL) {
            return hasPathSum(root->left, currSum);
        }
        return hasPathSum(root->right, currSum) or hasPathSum(root->left, currSum);
    }
};
