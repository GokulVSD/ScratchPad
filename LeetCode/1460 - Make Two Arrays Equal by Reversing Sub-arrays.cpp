// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

// Any number of reverse of subarrays basically means anagram

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> m(1001);
        for(int i = 0; i < arr.size(); ++i){
            ++m[arr[i]];
            --m[target[i]];
        }
        for(auto v: m){
            if(v != 0)
                return false;
        }
        return true;
    }
};


// Naive approach

// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         int n = arr.size();
//         bool found;
//         for(int i = 0; i < n; ++i){
//             if(arr[i] != target[i]){
//                 found = false;
//                 for(int j = i + 1; j < n; ++j){
//                     if(arr[j] == target[i]){
//                         found = true;
//                         swap(arr[i], arr[j]);
//                     }
//                 }
//                 if(!found) return false;
//             }
//         }
//         return true;
//     }
// };