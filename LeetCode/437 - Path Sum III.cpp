// https://leetcode.com/problems/path-sum-iii/description/

// Preorder traversal.

class Solution {
public:
    void solve(TreeNode* root, int targetSum, int &path, vector<int> &add) {
        if (root == NULL) {
            return;
        }

        add.push_back(root->val);

        solve(root->left, targetSum, path, add);
        solve(root->right, targetSum, path, add);

        long long sum = 0;

        for(int i = add.size() - 1; i >= 0; --i) {
            sum += add[i];
            if (sum == targetSum) {
                path++;
            }
        }
        add.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int path = 0;
        vector<int> add;
        solve(root, targetSum, path, add);
        return path;

    }
};