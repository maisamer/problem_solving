//uri:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
#include <bits/stdc++.h>

using namespace std;
int n,t,a[105],dp[105][50006],tot,case1,case2;
int Divide_Coin(int ind=0,int taken=0){
    if(ind == n)
        return abs(taken-(tot-taken));
    int &ret=dp[ind][taken];
    if(ret!=-1)
        return ret;
    ret = min(Divide_Coin(ind+1,taken+a[ind]),Divide_Coin(ind+1,taken));
    return ret;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tot=0;
        for(int i=0;i<n;i++){
           scanf("%d",&a[i]);
           tot+=a[i];
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",Divide_Coin());
    }
    return 0;
}
