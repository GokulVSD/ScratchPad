// https://leetcode.com/problems/groups-of-special-equivalent-strings/

// Tried a bunch to figure out a better solution, couldn't. Can't split into two unordered sets as considering even and odd separately will lead to incorrect grouping in some cases.

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string,string>> seen;
        for(const auto &s : A) {
            pair<string,string> p;
            for (int i = 0; i < s.size (); ++i) {
                if (i % 2)
                    p.first  += s[i];
                else
                    p.second += s[i];
            }
            sort(p.first.begin(), p.first.end());
            sort(p.second.begin(), p.second.end());
            seen.insert(p);
        }
    return seen.size();
    }
};