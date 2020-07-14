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
    TreeNode *buildTreeUtil(vector<int> &preorder, vector<int> &inorder, int &pos, int l, int r) {
        if(l > r) {
            return NULL;
        }
        pos++;
        TreeNode *node = new TreeNode(preorder[pos]);
        int inorder_pos;
        for(inorder_pos = l; inorder_pos<=r; inorder_pos++) {
            if(preorder[pos] == inorder[inorder_pos]) {
                break;
            }
        }
        node->left = buildTreeUtil(preorder, inorder, pos, l, inorder_pos-1);
        node->right = buildTreeUtil(preorder, inorder, pos, inorder_pos+1, r);
        return node;
    }    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = -1;
        return buildTreeUtil(preorder, inorder, pos, 0, inorder.size()-1);
    }
};
