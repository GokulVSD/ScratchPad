// https://www.hackerrank.com/challenges/frequency-queries/

vector<int> freqQuery(vector<vector<int>> queries) {

    vector<int> res;

    unordered_map<int, int> m;

    unordered_map<int, int> freq;


    /* Unbelievably, Test case #10 fails without reserving
    space for the maps. The constaints given specify 10^9,
    but HackerRank only allowed me to reserve 10^7 for each
    map.
    */
    m.reserve(10000000);
    freq.reserve(10000000);

    for(auto &q : queries){

        int n = q[1]; 

        if(q[0] == 1){

            if(freq[ m[ n ] ] > 0)
                --freq[ m[ n ] ];

            ++m[ n ];

            ++freq[ m[ n ] ];

        }
        else if(q[0] == 2){

            if(m[ n ] > 0){

                --freq[ m[ n ] ];

                --m[ n ];

                ++freq[ m[ n ] ];

            }

        }
        else{

            if(freq[ n ] > 0)
                res.emplace_back(1);
            else
                res.emplace_back(0);

        }
        
    }

    return res;

}