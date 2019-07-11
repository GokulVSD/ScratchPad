// https://www.hackerrank.com/challenges/new-year-chaos/

void minimumBribes(vector<int> q) {

    /* for each person, we can check if the person is more than two spots
    ahead of inital (for bribe condition violation), and number of people
    who have bribed this person.
    */

    int bribes = 0;

    for(int i = 0; i < q.size(); ++i){

        if(q[i] > i + 3){
            cout << "Too chaotic\n";
            return; 
        }

        for(int j = q[i] - 2 > 0 ? q[i] - 2 : 0; j < i; ++j)
            if(q[j] > q[i])
                ++bribes;

    }

    cout << bribes << "\n";

}