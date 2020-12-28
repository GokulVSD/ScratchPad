// https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

// This should be classified as easy.

class Solution {
public:
    void traverse(TreeNode* cur, int level, vector<vector<int>> &lo){
        if(cur == NULL) return;
        else {
            if(level >= lo.size())
                lo.emplace_back(vector<int>());
            
            lo[level].emplace_back(cur->val);
            
            if(cur->left != NULL) traverse(cur->left, level + 1, lo);
            if(cur->right != NULL) traverse(cur->right, level + 1, lo);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lo;
        traverse(root, 0, lo);
        return lo;
    }
};