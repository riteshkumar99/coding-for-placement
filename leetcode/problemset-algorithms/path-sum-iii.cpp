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
    int pathSumUtil(TreeNode *root, int sum) {
        if(root == NULL) {
            return 0;
        }
        sum -= root->val;
        return (sum == 0) + pathSumUtil(root->left, sum) + pathSumUtil(root->right, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        return pathSumUtil(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
