// https://leetcode.com/problems/sum-of-left-leaves/submissions/

// Simple enough

class Solution {
public:
    int sum = 0;
    void traverse(TreeNode* node, bool left){
        if(node->left != NULL) traverse(node->left, true);
        if(node->right != NULL) traverse(node->right, false);
        if(node->left == NULL && node->right == NULL){
            if(left) sum += node->val;
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        traverse(root, false);
        return sum;
    }
};