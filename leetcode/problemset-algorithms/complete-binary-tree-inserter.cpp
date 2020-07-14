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
class CBTInserter {
    queue<TreeNode *> que;
    TreeNode *root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode *> bfs_que;
        bfs_que.push(root);
        while(!bfs_que.empty()) {
            TreeNode *node = bfs_que.front();
            bfs_que.pop();
            if(node->left == NULL || node->right == NULL) {
                que.push(node);
            }
            if(node->left) {
                bfs_que.push(node->left);
            }
            if(node->right) {
                bfs_que.push(node->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode *node = new TreeNode(v);
        TreeNode *parent = que.front();
        if(parent->left == NULL) {
            parent->left = node;
        } else {
            parent->right = node;
            que.pop();
        }
        que.push(node);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
