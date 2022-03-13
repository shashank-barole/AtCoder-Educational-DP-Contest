#if 1
#include"../stdc++.h"
#endif
#if 0
#include<bits/stdc++.h>
#endif
using namespace std;
const int MOD = 1e9 + 7;
int H,W;
char grid[1001][1001];
int ans[1001][1001];

bool is_valid(int r,int c)
{
    if(r>=1 && r<=H && c>=1 && c<=W && grid[r][c]=='.') return true;
    return false;
}

int solve(int r,int c)
{
    if(is_valid(r,c))
    {
        if(ans[r][c]!=-1)return ans[r][c];
        if(r==H && c==W) return 1;
        ans[r][c]=0;
        (ans[r][c]+=solve(r+1,c) + 0LL) %=MOD;
        (ans[r][c]+=solve(r,c+1) + 0LL) %=MOD;
        return ans[r][c];
    }
    else
    {
        return 0;
    }


    
}
int main()
{
    memset(grid,0,sizeof(grid));
    memset(ans,-1,sizeof(ans));
    cin >> H >> W;
    for(int i=1 ; i<=H ; ++i)
    {
        for(int j=1 ; j<=W ; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve(1,1) << endl;

    return 0;
}