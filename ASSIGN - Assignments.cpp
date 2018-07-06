//uri : https://www.spoj.com/problems/ASSIGN/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int msz=22;
const int mask=(1<<20)+10;
int n,cnt=0;
int in[msz][msz];
ll dp[mask];
ll rec(int x){
    int ind=__builtin_popcount(x);
    if(ind==n)
        return 1;
    ll &ret = dp[x];
    if(ret!=-1)
        return dp[x];
    ll ans=0;
    for(int i=0;i<n;i++)
        if(in[ind][i]&&!((x>>i)&1))
            ans+=rec(x|(1<<i));

    return ret=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>in[i][j];
        memset(dp,-1,sizeof(dp));
        cout<<rec(0)<<endl;

    }
    return 0;
}
