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
    int solve(TreeNode *node, bool isGrandParentEven, bool isParentEven) {
        int sum = 0;
        if(isGrandParentEven) {
            sum += node->val;
        }
        if(node->left != NULL) {
            sum += solve(node->left, isParentEven, (node->val % 2 == 0));
        }
        if(node->right != NULL) {
            sum += solve(node->right, isParentEven, (node->val % 2 == 0));
        }
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return solve(root, false, false);
    }
};
