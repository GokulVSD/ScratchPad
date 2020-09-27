// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Honestly, this problem should be classified as easy.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != NULL){
            s.push(cur);
            cur = cur->left;
        }
        while(k--){
            cur = s.top();
            s.pop();
            if(k > 0 && cur->right != NULL){
                s.push(cur->right);
                cur = cur->right;
                while(cur->left != NULL){
                    s.push(cur->left);
                    cur = cur->left;
                } 
            }  
        }
        return cur->val;
    }
};