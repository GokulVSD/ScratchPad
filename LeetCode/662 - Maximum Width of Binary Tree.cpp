// https://leetcode.com/problems/maximum-width-of-binary-tree/

// Use a queue to perform breadth first search, everytime you go down a level,
// multiply a value by 2, and add 1 if it's a right node wrt the parent.
// The width of a level is the difference between the value of the first node
// in a level and the last node in the level. These can be tracked by removing
// the previous level from the queue, before traversing the next level.

// int height(node* node)  
// {  
//     if (node == NULL)  
//         return 0;  
//     else
//     {  
//         /* compute the height of each subtree */
//         int lheight = height(node->left);  
//         int rheight = height(node->right);  
  
//         /* use the larger one */
//         if (lheight > rheight)  
//             return(lheight + 1);  
//         else return(rheight + 1);  
//     }  
// }

// void printGivenLevel(node* root, int level)  
// {  
//     if (root == NULL)  
//         return;  
//     if (level == 1)  
//         cout << root->data << " ";  
//     else if (level > 1)  
//     {  
//         printGivenLevel(root->left, level-1);  
//         printGivenLevel(root->right, level-1);  
//     }  
// }  


class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
      // usigned long long int can be replaced with size_t
      unsigned long long int ans = 1;
    	if(root){
    		queue<pair<TreeNode*, unsigned long long int>> q;
    		q.push({root, 0});
    		
    		while(!q.empty()){
				ans = max(ans, q.back().second-q.front().second+1);
    			int size = q.size();
    			for(int i = 0; i<size; i++){
    				TreeNode* current = q.front().first;
    				unsigned long long int curInd = q.front().second;
    				q.pop();
    				if(current->left){
    					q.push({current->left, curInd*2});
    				}
    				if(current->right){
    					q.push({current->right, curInd*2+1});
    				}
    			}
    		}
    	}
    	return (int)ans;
    }
};