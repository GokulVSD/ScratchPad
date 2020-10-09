// https://leetcode.com/problems/relative-sort-array/

// map is int to int, since arr1 can have multiple of same value. While loops present
// to insert duplicates back in. Iterating through a map is useful.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (auto i : arr1) m[i]++;
        int pos = 0;
        for (auto j : arr2) {
            while(m[j]-- > 0) arr1[pos++] = j;
        }
        for (auto pair : m) {
            while(pair.second-- > 0) arr1[pos++] = pair.first;
        }
        return arr1;
    }
};