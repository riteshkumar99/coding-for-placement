class Solution {
public:
    int recur(TreeNode *node, TreeNode * &ans) {
        int leftLen, rightLen; // we store the max length of left and right subtree in these vars
        TreeNode *leftNode, *rightNode; // we store the ans for left and right subtree in these vars
        if(node->left == NULL && node->right == NULL) { // current node is leaf node, then this is present answer
            ans = node;
            return 1;
        } else if(node->left == NULL) { // left subtree is NULL, hence, answer will be same as right subtree
            return 1 + recur(node->right, ans);
        } else if(node->right == NULL) { // right subtree is NULL, hence, answer will be same as left subtree
            return 1 + recur(node->left, ans);
        } else { // both left and right subtree are not NULL
            leftLen = 1 + recur(node->left, leftNode); // find max depth of left subtree and corresponding answer
            rightLen = 1 + recur(node->right, rightNode); // find max depth of right subtree and corresponding answer
            if(leftLen == rightLen) { // this makes current node as potential answer
                ans = node;
                return leftLen;
            } else if(leftLen > rightLen) { // left child node is potential answer
                ans = leftNode;
                return leftLen;
            } else { // right child node is potential answer
                ans = rightNode;
                return rightLen;
            }
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode *ans = NULL;
        if(root == NULL) return ans;
		// store answer to the problem in variable ans
        recur(root, ans);
        return ans;
    }
};
