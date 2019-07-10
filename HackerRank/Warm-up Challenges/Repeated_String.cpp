// https://www.hackerrank.com/challenges/repeated-string/

inline int count_till(string s,int x){

    int noa = 0;

    for(int i = 0; i < x; ++i){
        if(s[i] != 'a') continue;
        ++noa;
    }

    return noa;
}

long repeatedString(string s, long n) {

    int m = s.length();

    m = n < m ? n : m;

    long a;

    if(n > m){

        a = count_till(s, m) * (n / m);
        return a + count_till(s, n % m);

    }
    else return count_till(s, m);
}