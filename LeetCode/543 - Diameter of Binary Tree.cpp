// https://leetcode.com/problems/diameter-of-binary-tree/

// The longest path can be rooted at any node, when rooted at some node, the longest path rooted
// at a node is the max depth of its left subtree + max depth of its right subtree + 1 (itself).

class Solution {
public:
 int depth(TreeNode* root,int &longest){
        if(root == NULL) return 0;
        int l = depth(root->left, longest);
        int r = depth(root->right, longest);
        longest = max(longest, l + r + 1);
        return max(l, r) + 1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int longest = 0;
        depth(root, longest);
        return longest - 1;
    }
};