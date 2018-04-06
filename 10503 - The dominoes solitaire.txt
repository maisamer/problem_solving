//uri:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1444
#include <bits/stdc++.h>
using namespace std;
int x[19],y[19],n,m,i1,i2,d1,d2;
bool ans;
int mark[20];
void backTracking(int ie,int e,int cnt,int cni){
    if(cnt==n){
        if(ie==e)
            ans=1;
        return;
    }
    if(cnt>n||cni>=m)
        return;
    for(int i=0;i<m;i++){
        if(x[i]==ie&&!mark[i]){
            mark[i]=1;
            backTracking(y[i],e,cnt+1,cni+1);
            mark[i]=0;
        }
        else if(y[i]==ie&&!mark[i]){
            mark[i]=1;
            backTracking(x[i],e,cnt+1,cni+1);
            mark[i]=0;
        }
    }
    return;
}
int main()
{
    for(int i=0;i<20;i++)
        mark[i]=0;
    while(1){
        cin>>n;
        if(n==0)
            break;
        ans=0;
        cin>>m;
        cin>>i1>>i2>>d1>>d2;
        for(int i=0;i<m;i++)
            cin>>x[i]>>y[i];
        backTracking(i2,d1,0,0);
        if(ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
