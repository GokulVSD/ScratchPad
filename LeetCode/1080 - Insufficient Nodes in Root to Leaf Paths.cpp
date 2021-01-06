// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/submissions/

// Simple recursive tree pruning. Leetcode annoyingly accesses root after execution, preventing me from being able to deallocate memory pointed by root.

class Solution {
public:
    bool prune(TreeNode* cur, int sum, int limit){
        if(cur->left == NULL && cur->right == NULL){
            if(sum + cur->val < limit){
                return true;
            } else return false;
        }
        if(cur->left != NULL){
            if(prune(cur->left, sum + cur->val, limit)){
                cur->left = NULL;
            }
        }
        if(cur->right != NULL){
            if(prune(cur->right, sum + cur->val, limit)){
                cur->right = NULL;
            }
        }
        if(cur->left == NULL && cur->right == NULL){
            return true;
        } else return false;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(prune(root, 0, limit)){
            return NULL;
        }
        return root;
    }
};