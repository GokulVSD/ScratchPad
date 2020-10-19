// https://leetcode.com/problems/average-of-levels-in-binary-tree/

// Simple DFS

class Solution {
public:
    vector<pair<double, int>> sums;
    void dfs(TreeNode* node, int lvl){
        if(sums.size() <= lvl)
            sums.push_back(make_pair(node->val, 1));
        else
            sums[lvl] = make_pair(sums[lvl].first + node->val, sums[lvl].second + 1);
        if(node->left)
            dfs(node->left, lvl  + 1);
        if(node->right)
            dfs(node->right, lvl  + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector<double> avgs(sums.size());
        for(int i = 0; i < sums.size(); ++i)
            avgs[i] = sums[i].first / sums[i].second;
        return avgs;
    }
};