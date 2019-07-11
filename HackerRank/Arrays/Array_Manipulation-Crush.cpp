// https://www.hackerrank.com/challenges/crush/

long arrayManipulation(int n, vector<vector<int>> queries) {

    // creating a height map and finding highest point

    vector<long> arr(n + 1);

    for(auto &a : queries){

        arr[ a[0] ] += a[2];

        if(a[1] < n)
            arr[ a[1] + 1 ] -= a[2];
    
    }

    long x = 0, max = 0;

    for(auto i : arr){

        x += i;
        if(x > max) max = x;

    }

    return max;

}