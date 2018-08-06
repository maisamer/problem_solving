// uri : https://www.spoj.com/problems/GNYR09F/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1e5+10;
int a[mx];
int n,k,data;
//     ind  rem
int dp[105][105][2];
int backTracking(int ind,int rem,int last){
    if(ind<0){
        if(rem==0)
            return 1;
        else
            return 0;
    }
    if(rem<0)
        return 0;
    int &ret=dp[ind][rem][last];
    if(ret!=-1){
        return ret;
    }
    return ret=backTracking(ind-1,rem,0)+backTracking(ind-1,last==1?rem-1:rem,1);
}
int main()
{
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin>>data>>n>>k;
        if(k>=n)
	cout<<data<<" "<<0<<endl;
        cout<<data<<" "<<backTracking(n-2,k,0)+backTracking(n-2,k,1)<<"\n";
    }
    return 0;
}
