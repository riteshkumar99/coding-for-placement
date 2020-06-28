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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        TreeNode *cur = root;
        TreeNode **pos = &cur;
        while(*pos) {
            if((*pos)->val > val) {
                pos = &(*pos)->left;
            } else {
                pos = &(*pos)->right;
            }
        }
        *pos = new TreeNode(val);
        return root;
    }
};
