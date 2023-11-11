// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
// Use two queues for each alternating level.

class Solution {
public:
    int getMax(queue<TreeNode*>& q, queue<TreeNode*>& alt) {
        int lvl_max = INT_MIN;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            lvl_max = max(lvl_max, node->val);
            if (node->left != NULL) {
                alt.push(node->left);
            }
            if (node->right != NULL) {
                alt.push(node->right);
            }
        }
        return lvl_max;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> que1, que2;
        que1.push(root);
        while (!que1.empty() || !que2.empty()) {
            ans.push_back(getMax(que1, que2));
            auto tmp = que1;
            que1 = que2;
            que2 = tmp;
        }
        return ans;
    }
};