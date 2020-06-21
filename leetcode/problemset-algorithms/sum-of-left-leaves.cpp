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
    int findSum(TreeNode *node, bool isLeft) {
        if(node->left == NULL && node->right == NULL) {
            if(isLeft) {
                return node->val;
            } else {
                return 0;
            }
        }
        int sum = 0;
        if(node->left) {
            sum += findSum(node->left, true);
        }
        if(node->right) {
            sum += findSum(node->right, false);
        }
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL) {
            return sum;
        }
        if(root->left) {
            sum += findSum(root->left, true);
        }
        if(root->right) {
            sum += findSum(root->right, false);
        }
        return sum;
    }
};
