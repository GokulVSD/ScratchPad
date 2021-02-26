// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/

// Use bitmap to store parity of each number, at most 1 odd frequency indicates palindrome permutation.

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if (root == NULL) 
            return 0;
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        if (root->left == NULL && root->right == NULL && (count & (count - 1)) == 0) res++;
        return res;
    }
};