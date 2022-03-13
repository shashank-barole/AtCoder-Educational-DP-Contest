#if 1
#include"../stdc++.h"
#endif
#if 0
#include<bits/stdc++.h>
#endif
using namespace std;
int N;
double probabilities[3001];
double dp[3001][3001];

int main()
{
    memset(probabilities,0,sizeof(probabilities));
    memset(dp,0,sizeof(dp));
    cin >> N;
    for(int i=1 ; i<=N ; ++i) cin >> probabilities[i];
    dp[0][0]=1;
    for(int i=1 ; i<=N ; ++i) dp[i][0]=(1 - probabilities[i])*(dp[i-1][0]);
    int minimum_heads = N/2 + 1;
    for(int i=1 ; i<=N ; ++i)
    {
        for(int j=1 ; j<=N ;++j)
        {
            //cout << probabilities[i-1] << "\t" ;
            dp[i][j] = (dp[i-1][j-1]*(probabilities[i])) + (dp[i-1][j]*(1-probabilities[i]));
            //cout << dp[i][j] << "\n";
        }
    }

    // for(int i=0 ; i<=N ; ++i)
    // {
    //     for(int j=0 ; j<=N ;++j)
    //     {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
    double ans=0;
    for(int c=minimum_heads ; c<=N ; c++) ans+=dp[N][c];
    cout << fixed << setprecision(10) << ans << endl;
    //cout << dp[N][N] << endl;
    return 0;
}