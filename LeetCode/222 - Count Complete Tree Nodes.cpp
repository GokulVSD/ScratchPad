// https://leetcode.com/problems/count-complete-tree-nodes/submissions/

// First find the max depth, then try to find the right most node that is at the max depth.

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int count = 1, max_count = 1, max_l = 1, cur_l = 1;
        
        TreeNode* temp = root;
        while(temp->left != NULL){
            temp = temp->left;
            ++max_l;
        }
        
        stack<TreeNode*> s;
        
        while(root != NULL){
            if(root->right != NULL){
                s.push(root);
                root = root->right;
                ++cur_l;
                count = count*2 + 1;
                max_count = max(count, max_count);
            } else if(root->left != NULL){
                s.push(root);
                root = root->left;
                ++cur_l;
                count = count*2;
                max_count = max(count, max_count);
            } else{
                if(cur_l == max_l)
                    break;
                root = s.top();
                if(root->right != NULL)
                    root->right = NULL;
                else
                    root->left = NULL;
                s.pop();
                --cur_l;
                count /= 2;
            }
        }
        return max_count;
    }
};