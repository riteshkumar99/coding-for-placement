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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) {
            return ans;
        }
        int level = 0;
        queue<TreeNode *> que;
        ans.push_back(vector<int>(0));
        que.push(root);
        que.push(NULL);
        while(!que.empty()) {
            while(que.front()) {
                TreeNode *node = que.front();
                que.pop();
                ans[level].push_back(node->val);
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
            }
            que.pop();
            if(que.empty()) break;
            que.push(NULL);
            level++;
            ans.push_back(vector<int>(0));
        }
        for(int i = 1, n = ans.size(); i<n; i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
