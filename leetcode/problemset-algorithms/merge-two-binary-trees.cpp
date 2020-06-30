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
    void solve(TreeNode *node, int isRight, TreeNode *a, TreeNode *b) {
        if(a == NULL && b == NULL) return;
        if(a == NULL) {
            if(isRight) {
                node->right = b;
            } else {
                node->left = b;
            }
        } else if(b == NULL) {
            if(isRight) {
                node->right = a;
            } else {
                node->left = a;
            }
        } else {
            if(isRight) {
                node->right = new TreeNode(a->val + b->val);
                solve(node->right, 0, a->left, b->left);
                solve(node->right, 1, a->right, b->right);
            } else {
                node->left = new TreeNode(a->val + b->val);
                solve(node->left, 0, a->left, b->left);
                solve(node->left, 1, a->right, b->right);
            }
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        if(t1 == NULL) {
            return t2;
        }
        if(t2 == NULL) {
            return t1;
        }
        TreeNode *root = new TreeNode(t1->val + t2->val);
        solve(root, 0, t1->left, t2->left);
        solve(root, 1, t1->right, t2->right);
        return root;
    }
};
