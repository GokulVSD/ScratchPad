// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/

/* times out on 3 test cases, I need to implement 
Binary Searching for the count vector, I expect that should make it fast enough.
*/

int activityNotifications(vector<int> a, int d) {

    // utilising counting sort: https://www.geeksforgeeks.org/counting-sort/

    vector<int> count(201);

    for(int i = 0; i < d; ++i)
        ++count[ a[i] ];

    int tmp = 0;

    for(int i = 0; i < 201; ++i){

        tmp += count[i];
        
        count[i] = tmp;

    }

    bool odd = d & 1;

    int mid1 = d/2, mid2 = d/2 + 1;

    int notifs = 0;

    double comp;

    for(int i = d; i < a.size(); ++i){

        // finding median from count vector
        for(int j = 0; j < 201; ++j){

            if(count[j] > mid1){

                comp = j;

                if(!odd){

                    for(int k = j; k < 201; ++k){

                        if(count[k] > mid2){

                            comp = (comp + k) / 2.0;

                            break;

                        }

                    }

                }

                break;

            }

        }

        if(a[i] >= 2*comp)
            ++notifs;

        // removing (i - d)th spenditure
        for(int j = a[i - d]; j < 201; ++j)
            --count[j];

        // removing (i)
        for(int j = a[i]; j < 201; ++j)
            ++count[j];

    }

    return notifs;

}