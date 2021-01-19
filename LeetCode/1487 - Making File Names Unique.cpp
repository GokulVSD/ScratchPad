// https://leetcode.com/problems/making-file-names-unique/submissions/

// Straightforward problem, it felt a bit easy for a medium difficulty problem.

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> m;
        vector<string> ans;
        for(auto &s: names){
            if(m.find(s) == m.end()){
                ++m[s];
                ans.emplace_back(s);
            } else {
                string temp = s;
                while(m.find(temp) != m.end()){
                    temp = s + "(" + to_string(m[s]++) + ")";
                }
                ++m[temp];
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};