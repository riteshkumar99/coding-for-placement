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
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int &pos, int l, int r) {
        if(l > r) {
            return NULL;
        }
        pos--;
        TreeNode *node = new TreeNode(postorder[pos]);
        int inorder_pos;
        for(inorder_pos = l; inorder_pos<=r; inorder_pos++) {
            if(postorder[pos] == inorder[inorder_pos]) {
                break;
            }
        }
        node->right = buildTreeUtil(inorder, postorder, pos, inorder_pos+1, r);
        node->left = buildTreeUtil(inorder, postorder, pos, l, inorder_pos-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int pos = n;
        return buildTreeUtil(inorder, postorder, pos, 0, n-1);
    }
};
