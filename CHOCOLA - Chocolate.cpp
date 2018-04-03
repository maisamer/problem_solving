//uri : http://www.spoj.com/problems/CHOCOLA/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define clr(v, d) memset(v, d, sizeof(v))
int m,n,x,t;
vector<int>v,h;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
        n--,m--;
        h.clear(),v.clear();
        for(int i=0;i<m;i++){
            cin>>x;
            h.push_back(x);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end(),cmp);
        sort(h.begin(),h.end(),cmp);
        int i=0,j=0,ans=0,hi=1,vi=1;
        while(i<m&&j<n){
            if(v[j]>h[i]){
                ans+=v[j]*vi;
                hi++;
                j++;
            }else{
                ans+=h[i]*hi;
                vi++;
                i++;
            }
        }
        if(i<m){
            int sum=0;
            while(i<m){
                sum+=h[i];
                i++;
            }
            ans+=sum*hi;
        }else{
            int sum=0;
            while(j<n){
                sum+=v[j];
                j++;
            }
            ans+=sum*vi;
        }
        cout<<ans<<endl;
    }
    return 0;
}
