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
class FindElements {
public:
    TreeNode *start;
    FindElements(TreeNode* root) {
        start = root;
    }
    
    bool find(int target) {
        string s = "";
        while(target) {
            if(target % 2) {
                s = 'l' + s;
                target /= 2;
            } else {
                s = 'r' + s;
                target = (target / 2) - 1;
            }
        }
        TreeNode *node = start;
        for(auto c: s) {
            if(node == NULL) break;
            if(c == 'l') {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node != NULL;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
