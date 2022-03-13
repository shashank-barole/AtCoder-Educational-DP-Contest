
#if 0
#include "bits/stdc++.h"
#endif

#if 1
#include"../stdc++.h"
#endif

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> hs(n,0), ans(n,INT_MAX);
    for(int i=0 ; i<n ; ++i) cin >> hs[i];
    ans[0]=0;
    for(int i=0 ; i<n ; ++i)
    {
        int last = i+k>n-1 ? n-1:i+k;
        for(int j=i+1 ; j <= last ; ++j)
        {
            ans[j] = min(ans[j], abs(hs[i]-hs[j])+ans[i]);
        }
    }

    cout << ans.back() << endl;
    return 0;
}