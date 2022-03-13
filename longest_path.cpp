#if 1
#include"../stdc++.h"
#endif
#if 0
#include<bits/stdc++.h>
#endif
using namespace std;
long long lengths[(int)1e6];
int vertices,edges;
vector< vector<int> > graph(1e5+1);


long long solve(int v)
{
    if(lengths[v]) return lengths[v];
    for(vector<int>::iterator child = graph[v].begin(); child!=graph[v].end() ; child++)
    {
        lengths[*child] = solve(*child);
        lengths[v] = max(lengths[v], 1+lengths[*child]);
    }
    return lengths[v];
}

int main()
{
    memset(lengths,0,sizeof(lengths));
    cin >> vertices >> edges;
    for(int i=0 ; i<edges ; ++i)
    {
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    for(int i=1 ; i<=vertices ; ++i)
            solve(i);
    int ans=0;
    for(int i=1 ; i<=vertices ; ++i) ans = max(ans *1LL,lengths[i]);
    cout << ans << endl;
    return 0;
}