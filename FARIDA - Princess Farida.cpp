//uri : https://www.spoj.com/problems/FARIDA/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1e5+10;
ll a[mx];
int n;

ll dp[mx][3];
ll backTracking(int ind,int last){
    if(ind==n)
        return 0;

    ll &ret=dp[ind][last];
    if(ret!=-1){
        return ret;
    }
    ll op1=-1;
    if(last!=1){
        op1=a[ind]+backTracking(ind+1,1);
    }
    return ret=max(backTracking(ind+1,0),op1);
}
int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<test<<": "<<backTracking(0,2)<<"\n";
    }
    return 0;
}
