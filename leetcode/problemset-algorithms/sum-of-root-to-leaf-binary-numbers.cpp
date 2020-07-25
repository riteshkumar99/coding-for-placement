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
    void dfs(TreeNode *node, int num, int &sum) {
        num = (num<<1) + node->val;
        if(node->left == nullptr and node->right == nullptr) {
            sum += num;
        } else{
            if(node->left) {
                dfs(node->left, num, sum);
            }
            if(node->right) {
                dfs(node->right, num, sum);
            }
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, num = 0;
        if(root == nullptr) {
            return sum;
        }
        dfs(root, num, sum);
        return sum;
    }
};
