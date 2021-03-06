//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=1517
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
int bestCalculte(int s,int d){
    int maxSurplus=5;
    while(maxSurplus*s-d*(5-maxSurplus)>0&&maxSurplus>0){
            maxSurplus--;
    }
    if(maxSurplus<=0)
        return -1;
    if(maxSurplus==1)
        return (3*s-9*d);
    int difict=5-maxSurplus;
    int sur=12-2*difict;
    return sur*s-2*difict*d;
}
int main(){
    int s,d;
    while(cin>>s>>d){
        int surplus=bestCalculte(s,d);
        if(surplus<0)
            cout<<"Deficit"<<endl;
        else
            cout<<surplus<<endl;
    }
    return 0;
}
