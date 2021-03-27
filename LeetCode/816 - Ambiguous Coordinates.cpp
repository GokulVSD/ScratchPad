// https://leetcode.com/problems/ambiguous-coordinates/submissions/

// Generate all x and y, then for each of them, generate all possible values, ans is their cartesian product

class Solution {
public:
    vector<string> generate(string s){
        vector<string> ans;
        for(int i = 1; i < s.size(); ++i){
            string left = s.substr(0, i);
            string right = s.substr(i);
            if((left[0] != '0' || left == "0") && right[right.size() - 1] != '0')
                ans.push_back(left + "." + right);
        }
        if(s.size() == 1 || s[0] != '0') ans.push_back(s);
        return ans;
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        for(int i = 1; i < S.size() - 2; ++i)
            for(string left: generate(S.substr(1, i)))
                for(string right: generate(S.substr(i + 1, S.size() - i - 2)))
                    ans.push_back("("+left+", "+right+")");
        return ans;
    }
};