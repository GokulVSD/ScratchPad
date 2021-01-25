// https://leetcode.com/problems/delete-node-in-a-bst/submissions/

// Tedious problem, various sub-conditions when root needs to be deleted.

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *parent = NULL, *cur = root;
        while(cur != NULL){
            if(cur->val < key){
                parent = cur;
                cur = cur->right;
            } else if(cur->val > key){
                parent = cur;
                cur = cur->left;
            } else {
                if(parent == NULL){
                    root = cur;
                    cur = cur->left;
                    if(cur == NULL)
                        return root->right;
                    while(cur->right != NULL){
                        parent = cur;
                        cur = cur->right;
                    }
                    if(parent != NULL){
                        parent->right = NULL;
                        cur->left = root->left;
                    }
                    cur->right = root->right;
                    return cur;
                } else if(parent->val > cur->val){
                    parent->left = cur->right;
                    while(parent->left != NULL)
                        parent = parent->left;
                    parent->left = cur->left;
                } else {
                    parent->right = cur->left;
                    while(parent->right != NULL)
                        parent = parent->right;
                    parent->right = cur->right;
                }
                break;
            }
        }
        return root;
    }
};