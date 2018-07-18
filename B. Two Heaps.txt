//uri : https://codeforces.com/contest/353/problem/B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1e5+10;
int a;
map<int,int>h,h1,h2;
vector<int> v;
int ans[105];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>a;
        h[a]++;
        v.push_back(a);
    }
    int s1=n,s2=n;
    bool fl=1,fl2=0;
    for(map<int,int>::iterator it=h.begin();it!=h.end();it++){
        if(it->second>2){
            //cout<<"???"<<it->first<<it->second<<endl;
            int s=it->second-2;
            s1-=s/2;
            s2-=s/2;
            h1[it->first]=s/2+1;
            h2[it->first]=s/2+1;
            //cout<<h1[it->first]<<endl;
           // cout<<h2[it->first]<<endl;
            if(s&1){
                if(fl){
                    s1--;
                   // cout<<"herr"<<endl;
                    h1[it->first]++;
                    fl=0;
                }else{
                    fl=1;
                    h2[it->first]++;
                    s2--;
                }
            }
        }
        else if(it->second&1){
            if(fl2){
                h1[it->first]++;
                fl2=0;
            }else{
                fl2=1;
                h2[it->first]++;
            }
        }
        else{
           h1[it->first]++;
           h2[it->first]++;
        }

    }
    cout<<s1*s2<<endl;
    for(int i=0;i<2*n;i++){
        if(h1[v[i]]){
            cout<<1<<" ";
            h1[v[i]]--;
        }else if(h2[v[i]]){
            cout<<2<<" ";
            h2[v[i]]--;
        }
    }
    return 0;
}
