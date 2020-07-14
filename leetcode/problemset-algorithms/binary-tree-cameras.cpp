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
    array<int, 3> solve(TreeNode *node) {
        if(node == NULL) {
            return array<int, 3>{0, 0, 99999};
        }
        array<int, 3> L = solve(node->left), R = solve(node->right);
        int mL12 = min(L[1], L[2]), mR12 = min(R[1], R[2]);
        int d0 = L[1] + R[1];
        int d1 = min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + min(L[0], mL12) + min(R[0], mR12);
        return array<int, 3>{d0, d1, d2};
    }
public:
    int minCameraCover(TreeNode* root) {
        array<int, 3> ans = solve(root);
        return min(ans[1], ans[2]);
    }
};
