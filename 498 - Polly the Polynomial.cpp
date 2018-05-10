#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<pair<int,int>,int> pik;
typedef pair<ll,ll> pi;
ll ans,n,c[1000],x[1000],t;
ll pow(ll b,ll p){
    if(p==0)
        return 1;
    if(p&1)
        return b*pow(b*b,p/2);
    else
        return pow(b*b,p/2);
}
int main(){
    string line;
    while(getline(cin,line)){
       stringstream sx,sc;
       sc<<line;
       n=0,t=0;
       while(sc>>c[n])
            n++;
       getline(cin,line);
       sx<<line;
       while(sx>>x[t])
            t++;
       for(int i=0;i<t;i++){
           ans=0;
           for(int j=0;j<n;j++){
                ans+=c[j]*pow(x[i],n-j-1);
           }
           printf("%lld",ans);
           if(i<t-1) printf(" ");
       }
       puts("");
    }
    return 0;
}
