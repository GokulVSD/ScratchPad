// https://www.hackerrank.com/challenges/2d-array/

int hourglassSum(vector<vector<int>> arr) {

    int max = -64;
    int temp;

    for(int i = 0; i < 4; ++i){

        for(int j = 0; j < 4; ++j){

            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] +
            arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            
            max = temp > max ? temp : max;

        }
    }

    return max;
}