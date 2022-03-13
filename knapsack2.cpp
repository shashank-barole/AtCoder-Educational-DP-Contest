#if 0
#include<bits/stdc++.h>
#endif

#if 1
#include "../stdc++.h"
#endif
using namespace std;

long long weights[105];
long long values[105];
long long dp[105][100005];

long long solve(int index,int value)
{
    if(value==0) return 0;
    if(index<0) return 1e15;
    if(dp[index][value]!=-1)return dp[index][value];
    long long ans = solve(index-1,value);
    if((value-values[index])>=0)
    {
        ans = min(ans, weights[index]+ solve(index-1,value-values[index]));
    } 
    return dp[index][value] = ans;

}


int main()
{
    int num_items, W;
    cin >>num_items >> W;
    memset(weights,0,sizeof(weights));
    memset(values,0,sizeof(values));
    for(int i=0 ; i<num_items ; ++i)
    {
        cin >> weights[i] >> values[i];
    }
    memset(dp,-1, sizeof(dp));
    for(long val=1e5 ; val>=0 ; val--)
    {
        long long wt = solve(num_items-1,val);
        if(wt<=W) {cout << val << endl; break;}
    }
    return 0;
}