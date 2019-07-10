// https://www.hackerrank.com/challenges/counting-valleys/

int countingValleys(int n, string s) {
    
    int lvl = 0, v = 0;

    for(int i = 0; i < n; ++i){

        if(s[i] == 'D'){
            if(lvl-- == 0) 
                ++v;
        }
        else
            ++lvl;
    }
    
    return v;
}