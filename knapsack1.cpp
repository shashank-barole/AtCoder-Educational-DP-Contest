#if 0
#include<bits/stdc++.h>
#endif


#if 1
#include "../stdc++.h"
#endif
using namespace std;

int main()
{
    int num_items, W;
    cin >>num_items >> W;
    vector<int> weights(num_items,0);
    vector<int> values(num_items,0);
    for(int i=0 ; i<num_items ; ++i)
    {
        cin >> weights[i] >> values[i];
    }

    vector< vector<long> > dp(num_items+1, vector<long>(W+1,0));
    for(int it = 0 ; it<=num_items ; ++it)
    {
        for(int wt=0 ; wt<=W ; wt++ )
        {
            if(it==0 || wt==0) continue;
            else if(weights[it-1] > wt) dp[it][wt] = dp[it-1][wt];
            else dp[it][wt] = max(dp[it-1][wt],dp[it-1][wt-weights[it-1]] + values[it-1]);
        }
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << endl;
    return 0;
}