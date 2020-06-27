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
    int MOD = 1000000007;
    int find_total_sum(TreeNode *root) {
        int val = root->val;
        if(root->left) {
            val = (val + find_total_sum(root->left)) % MOD;
        }
        if(root->right) {
            val = (val + find_total_sum(root->right)) % MOD;
        }
        return val % MOD;
    }
    
    int solve(TreeNode *root, long long &val, int total_sum) {
        int currSum = root->val;
        if(root->left) {
            currSum = (currSum + solve(root->left, val, total_sum)) % MOD;
        }
        if(root->right) {
            currSum = (currSum + solve(root->right, val, total_sum)) % MOD;
        }
        val = max(val, (1LL *  (total_sum - currSum) * currSum));
        return currSum % MOD;
    }
    
    int maxProduct(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int total_sum = find_total_sum(root);
        long long val = 0;
        solve(root, val, total_sum);
        return (int) (val % MOD);
    }
};
