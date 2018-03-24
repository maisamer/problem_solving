// uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2445
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
int m,c;
int prices[25][25];
int DP[210][25];
int maxMoney(int mony,int g){
    //cout<<"///////////////"<<endl;
    if(mony<0)
        return -10000;
    if(g==c)
        return m-mony;
    int &ret=DP[mony][g];
    if(ret!=-1)
        return DP[mony][g];
    for(int i=1;i<=prices[g][0];i++)
        ret=max(ret,maxMoney(mony-prices[g][i],g+1));
    return ret;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>m>>c;
        for(int i=0;i<c;i++){
            cin>>prices[i][0];
            for(int j=1;j<=prices[i][0];j++){
                cin>>prices[i][j];
            }
        }
        clr(DP,-1);
        int out = maxMoney(m,0);
        if(out<0)
            puts("no solution");
        else
            printf("%d\n",out);
    }

}
