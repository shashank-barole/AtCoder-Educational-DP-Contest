#if 0
#include<bits/stdc++.h>
#endif


#if 1
#include "../stdc++.h"
#endif
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector< vector<int> > scores(N, vector<int> (3,0));
    vector< vector<int> > dp(N+1, vector<int> (3,0));
    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<3 ; ++j)
        {
            cin >> scores[i][j];
        }
    }


    for(int day=1 ; day <= N ; ++day)
    {
        dp[day][0] = max(dp[day-1][1],dp[day-1][2]) + scores[day-1][0]; 
        dp[day][1] = max(dp[day-1][0],dp[day-1][2]) + scores[day-1][1]; 
        dp[day][2] = max(dp[day-1][1],dp[day-1][0]) + scores[day-1][2]; 
    }
    cout << *max_element(dp.back().begin(),dp.back().end()) << endl;
    return 0;
}