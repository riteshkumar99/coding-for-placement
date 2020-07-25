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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr) {
            return ans;
        }
        vector<pair<double, int> > count;
        int level = -1;
        stack<pair<TreeNode *, int> > stk;
        stk.push({root, 0});
        while(!stk.empty()) {
            pair<TreeNode *, int> p = stk.top();
            stk.pop();
            if(p.second > level) {
                count.push_back({0, 0});
                level++;
            }
            count[p.second].first += (double)p.first->val;
            count[p.second].second++;
            if(p.first->left) {
                stk.push({p.first->left, p.second+1});
            }
            if(p.first->right) {
                stk.push({p.first->right, p.second+1});
            }
        }
        for(int i = 0, n = count.size(); i<n; i++) {
            ans.push_back(count[i].first/count[i].second);
        }
        return ans;
    }
};