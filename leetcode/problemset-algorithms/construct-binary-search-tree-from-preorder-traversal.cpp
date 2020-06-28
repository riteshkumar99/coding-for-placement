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
    TreeNode *formBST(vector<int> &preorder, int l, int h) {
        if(l > h) {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[l]);
        if(l == h) {
            return node;
        }
        int index = l + 1;
        while(index <= h && preorder[index] < preorder[l]) {
            index++;
        }
        node->left = formBST(preorder, l+1, index-1);
        node->right = formBST(preorder, index, h);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return formBST(preorder, 0, preorder.size()-1);
    }
};
