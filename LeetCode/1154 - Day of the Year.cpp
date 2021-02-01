// https://leetcode.com/problems/day-of-the-year/submissions/

// You can precompute how many days have passed for a given month.

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 7)), day = stoi(date.substr(8));
        int leap = year % 4 == 0 ? (year % 100 == 0 ? year % 400 == 0 : true) : false;
        vector<int> m{0, 0, 31, 59 + leap, 90 + leap, 120 + leap, 151 + leap, 181 + leap, 212 + leap, 243 + leap, 273 + leap, 304 + leap, 334 + leap};
        
        return m[month] + day;
    }
};