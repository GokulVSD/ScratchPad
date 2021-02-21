// https://leetcode.com/problems/longest-nice-substring/

// DFS

class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) return "";
        unordered_map<char, bool> m;
        for(int i = 0; i < s.size(); ++i){
            m[s[i]] = true;
        }
        int i;
        for(i = 0; i < s.size(); ++i){
            if(isupper(s[i])){
                if(!m[tolower(s[i])])
                    break;
            } else if(!m[toupper(s[i])])
                    break;
        }
        if(i == s.size()) return s;
        string s1 = longestNiceSubstring(s.substr(0, i));
        string s2 = longestNiceSubstring(s.substr(i + 1));
        if(s1.size() >= s2.size())
            return s1;
        else
            return s2;
    }
};
