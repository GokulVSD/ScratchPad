// https://leetcode.com/problems/water-and-jug-problem/submissions/

// if z is a multiple of gcd(x, y), then it is possible. Need to consider edge cases, z must be able to be contained in x and y combined. if z is 0, it is always possible, else if either x or y is 0, then the other should be equal to z, else not possible.

class Solution {
public:
    int gcd(int a, int b){
        // Everything divides 0 
        if (a == 0)
            return b;
        if (b == 0)
            return a;
  
        // base case
        if (a == b)
            return a;
  
        // a is greater
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0)
            return true;
        if(x == 0){
            if(y == z)
                return true;
            else return false;
        }
        if(y == 0){
            if(x == z)
                return true;
            else return false;
        }
        int i = gcd(x, y); // can use __gcd()
        return z % i == 0 && z <= x + y;
    }
};