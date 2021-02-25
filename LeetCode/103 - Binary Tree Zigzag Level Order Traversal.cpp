// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Can also be done via 102 Level Order Traversal method, and reverse alternating vectors.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zzlo;
        
        if (!root) 
        return zzlo;
        
        int cur = 0;
        zzlo.push_back(vector<int>());
  
        stack<TreeNode*> currentlevel; 
        stack<TreeNode*> nextlevel; 
  
        currentlevel.push(root); 
  
        bool lefttoright = true; 
        while (!currentlevel.empty()) { 
  
            TreeNode* temp = currentlevel.top(); 
            currentlevel.pop(); 
  
            if (temp) {
                
                zzlo[cur].push_back(temp->val);

                if (lefttoright) {
                    if (temp->left) 
                        nextlevel.push(temp->left); 
                    if (temp->right) 
                        nextlevel.push(temp->right); 
                } 
                else { 
                    if (temp->right) 
                        nextlevel.push(temp->right); 
                    if (temp->left) 
                        nextlevel.push(temp->left); 
                } 
            } 
    
            if (currentlevel.empty()) { 
                lefttoright = !lefttoright;
                zzlo.push_back(vector<int>());
                ++cur;
                swap(currentlevel, nextlevel); 
            }
        }
        zzlo.pop_back();
        return zzlo;
    }
};