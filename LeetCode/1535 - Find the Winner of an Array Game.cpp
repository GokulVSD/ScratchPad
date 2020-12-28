// https://leetcode.com/problems/find-the-winner-of-an-array-game/

// incase k > what the number of elements remaining in the array, the largest is always the winner.

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 2, score = 1, winner = max(arr[0], arr[1]);
        
        while(score != k && i != arr.size()){
            if(max(arr[i], winner) == winner){
                ++score;
            } else {
                winner = arr[i];
                score = 1;
            }
            ++i;
        }
        return winner;
    }
};