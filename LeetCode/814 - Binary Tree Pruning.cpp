// https://leetcode.com/problems/binary-tree-pruning/

// I tried garbage collecting, but Leetcode is throwing errors even 
// though I'm able to execute it locally.

class Solution {
public:
    bool prune(TreeNode* node){
        if(node == NULL) return true;
        if(node->val == 1) return false;
        if(node->val == 0 && prune(node->left) && prune(node->right))
            return true;
        return false;
    }
    // void deleteSubtree(TreeNode** node){
    //     if(node == NULL) return;
    //     deleteSubtree(&((*node)->left));
    //     deleteSubtree(&((*node)->right));
    //     delete *node;
    //     *node = NULL;
    // }
    TreeNode* pruneTree(TreeNode*& root) {
        if(root == NULL) return NULL;

        if(prune(root)) root = NULL;
        else {
            pruneTree(root->left);
            pruneTree(root->right);
        }
        
        return root;
    }
};