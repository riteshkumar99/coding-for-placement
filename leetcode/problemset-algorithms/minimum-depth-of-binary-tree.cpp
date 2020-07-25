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
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        if(root->left) {
            leftHeight = minDepth(root->left);
        }
        if(root->right) {
            rightHeight = minDepth(root->right);
        }
        if(leftHeight == 0) {
            return 1 + rightHeight;
        }
        if(rightHeight == 0) {
            return 1 + leftHeight;
        }
        return 1 + min(leftHeight, rightHeight);
    }
};
