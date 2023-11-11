// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution {
public:
    bool possible(string a, string b) {
        int j = 0;
        for (int i = 0; i < a.size(); ++i) {
            while(j < b.size() && a[i] != b[j]) {
                ++j;
            }
            if (j >= b.size() || a[i] != b[j]) return false;
            ++j;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string cur = "";
        for (auto &w : dictionary) {
            if (possible(w, s)) {
                if (cur.size() < w.size() || (cur.size() == w.size() && w < cur)) {
                    cur = w;
                }
            }
        }
        return cur;
    }
};