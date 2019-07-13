// https://www.hackerrank.com/challenges/count-triplets-1/

// calculates nCr, may be very useful in the future.
// long comb(long n, int r) 
// { 
//     long res = 1; 
  
//     if ( r > n - r ) 
//         r = n - r; 
  
//     for (int i = 0; i < r; ++i){

//         res *= (n - i); 
//         res /= (i + 1); 

//     } 
  
//     return res; 
// } 

long countTriplets(vector<long> arr, long r) {

    /* can't use array as a map since elements can be
    larger than 10^7.
    */

    unordered_map<long, long> potential;
    unordered_map<long, long> count;

    potential.reserve(100000);
    count.reserve(100000);

    long triplets = 0;

    for(int i = 0; i < arr.size(); ++i){

        long cur = arr[i];
        long prev = arr[i] / r;

        if(arr[i] % r == 0){
        
            triplets += count[prev];

            count[cur] += potential[prev];
        
        }

        ++potential[cur];

    }

    return triplets;

}