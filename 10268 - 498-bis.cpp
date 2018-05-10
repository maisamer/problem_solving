#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<pair<int,int>,int> pik;
typedef pair<ll,ll> pi;
ll ans,x,n,a[1000000];
// a0nx^n?1 + a1(n ? 1)x^n?2 + . . . + an?1.
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
    while(cin>>x){
       cin.ignore();
       getline(cin,line);
       stringstream sin;
       sin<<line;
       n=0;
       while(sin>>a[n])
            n++;
       ans=0;
       for(ll i=0;i<n-1;i++){
            ans+=a[i]*(n-i-1)*pow(x,n-i-2);
       }
       printf("%lld\n",ans);
    }
    return 0;
}
