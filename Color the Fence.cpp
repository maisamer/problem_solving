// uri : https://codeforces.com/contest/349/problem/B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1e5+9;
int a[10];
int t;
int v,mn=0,bs=-1,tmp,d,pn;
int func(){
    int mn=INT_MAX;
    for(int i=0;i<9;i++)
        mn=min(mn,a[i]);
    return mn;
}
int main()
{
    cin>>v;
    for(int i=0;i<9;i++){
        cin>>a[i];
    }
    for(int i=0;i<9;i++){
        d=v/a[i];
        if(d>=mn){
            mn=d;
        }
    }
    if(mn==0){
        cout<<-1;
        return 0;
    }
    //cout<<mn<<endl;
    int rm;
    int sm=func();
   // cout<<"smsll "<<sm<<endl;
    for(int i=0;i<mn;i++){
       // cout<<"here "<<v<<endl;
        int dec=8;
        while(dec>=0){
            rm=v-a[dec];
            if(rm/sm>=mn-i-1&&rm>=0){
                cout<<dec+1;
                v-=a[dec];
                break;
            }
            dec--;
        }

    }
    return 0;
}
