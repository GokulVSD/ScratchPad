// https://www.hackerrank.com/challenges/jumping-on-the-clouds/

int jumpingOnClouds(vector<int> c) {

    int hops = 0;

    for(vector<int>::iterator i = c.begin()+2; i <= c.end(); i+=2){
        
        ++hops;
        if(*i == 0) continue;
        --i;

    }

    return hops;
}