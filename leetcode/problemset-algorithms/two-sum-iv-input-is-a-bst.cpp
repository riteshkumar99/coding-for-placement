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
    void inorder(TreeNode *node, vector<int> &arr) {
        if(node == nullptr) {
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int sum = arr[l] + arr[r];
            if(sum == k)
                return true;
            if(sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
};
