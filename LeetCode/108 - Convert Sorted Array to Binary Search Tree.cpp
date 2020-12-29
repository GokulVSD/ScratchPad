// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/

// Simple enough

class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int left, int right){
        if(left <= right){
            int mid = (left + right)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = buildTree(nums, left, mid - 1);
            node->right = buildTree(nums, mid + 1, right);
            return node;
        }
        else return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};