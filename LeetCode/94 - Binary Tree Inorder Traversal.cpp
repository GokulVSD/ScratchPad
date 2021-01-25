// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

// Standard non recursive, left-root-right

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> s;
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
        while(!s.empty()){
            root = s.top();
            s.pop();
            ans.emplace_back(root->val);
            root = root->right;
            while(root != NULL){
                s.push(root);
                root = root->left;
            }
        }
        return ans;
    }
};