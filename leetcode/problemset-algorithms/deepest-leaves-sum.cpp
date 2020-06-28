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
    int find_deepest_level(TreeNode *root) {
        if(root->left && root->right) {
            return 1 + max(find_deepest_level(root->left), find_deepest_level(root->right));
        } else if(root->left) {
            return 1 + find_deepest_level(root->left);
        } else if(root->right) {
            return 1 + find_deepest_level(root->right);
        } else {
            return 1;
        }
    }
    
    int find_level_sum(TreeNode *node, int level, int requiredLevel) {
        if(level == requiredLevel) return node->val;
        if(level > requiredLevel) return 0;
        int sum = 0;
        if(node->left) {
            sum += find_level_sum(node->left, level+1, requiredLevel);
        }
        if(node->right) {
            sum += find_level_sum(node->right, level+1, requiredLevel);
        }
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        int deepestLevel = find_deepest_level(root);
        return find_level_sum(root, 1, deepestLevel);
    }
};
