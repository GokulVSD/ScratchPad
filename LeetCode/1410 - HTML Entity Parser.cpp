// https://leetcode.com/problems/html-entity-parser/submissions/

// Kinda annoying how C++ handles substr and replace different from other languages.

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> m;
        m["quot"] = "\"";
        m["apos"] = "'";
        m["amp"] = "&";
        m["gt"] = ">";
        m["lt"] = "<";
        m["frasl"] = "/";
        string s;
        int i = 0, j = 1;
        while(i < text.size() && j < text.size()){
            if(text[i] != '&')
                ++i;
            else if(text[j] == '&'){
                i = j;
                ++j;
            }
            else if(text[j] == ';'){
                s = text.substr(i + 1, j - i - 1);
                if(m.find(s) != m.end())
                    text.replace(i, j - i++ + 1, m[s]);
                else
                    i = j + 1;
                j = i + 1;
            }
            else{
                if(j - i > 6){ // optimisation
                    i = j + 1;
                    j = i;
                }
                ++j;
            }
        }
        return text;
    }
};