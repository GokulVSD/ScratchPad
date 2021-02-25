// https://leetcode.com/problems/most-common-word/submissions/

// Straight forward

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        int mlen = 0; string ms = "";
        for(auto &b : banned)
            m[b] = INT_MIN;
        int start = 0, length = 0;
        for(int i = 0; i <= paragraph.size(); ++i){
            char c = i != paragraph.size() ? paragraph[i] : ' ';
            if(c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.'){
                if(length){
                    string s = paragraph.substr(start, length);
                    transform(s.begin(), s.end(), s.begin(), ::tolower);
                    int n = ++m[s];
                    if(n > mlen){
                        mlen = n;
                        ms = s;
                    }
                }
                start = i + 1;
                length = 0;
            } else {
                length++;
            }
        }
        return ms;
    }
};