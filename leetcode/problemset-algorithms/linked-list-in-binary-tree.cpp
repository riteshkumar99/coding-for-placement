/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode *curr, ListNode *head, TreeNode *node) {
        if(curr == NULL) return true;
        if(node == NULL) return false;
        if(node->val == curr->val) {
            if(dfs(curr->next, head, node->left)) return true;
            if(dfs(curr->next, head, node->right)) return true;
        }
        if(curr != head) {
            return false;
        }
        if(dfs(head, head, node->left)) return true;
        if(dfs(head, head, node->right)) return true;
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL && root == NULL) return true;
        if(head == NULL || root == NULL) return false;
        return dfs(head, head, root);
    }
};
