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

struct Iterator {
    stack<TreeNode *> s;
    Iterator(TreeNode *root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    bool isEmpty() {
        return s.empty();
    }
    
    int peek() {
        return s.top()->val;
    }
    
    int next() {
        TreeNode *node = s.top();
        s.pop();
        int val = node->val;
        node = node->right;
        while(node) {
            s.push(node);
            node = node->left;
        }
        return val;
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Iterator *it1 = new Iterator(root1);
        Iterator *it2 = new Iterator(root2);
        vector<int> ans;
        while(!it1->isEmpty() && !it2->isEmpty()) {
            if(it1->peek() < it2->peek()) {
                ans.push_back(it1->next());
            } else {
                ans.push_back(it2->next());
            }
        }
        while(!it1->isEmpty()) {
            ans.push_back(it1->next());
        }
        while(!it2->isEmpty()) {
            ans.push_back(it2->next());
        }
        return ans;
    }
};
