//uri : http://www.spoj.com/problems/CDOWN/
#include <bits/stdc++.h>
using namespace std;
int n,d,cn;
map<string,string> dp;
map<string,bool> vald;
map<string,int>out;
void up(string name,int cnt=0){
    if(cnt==d){
        out[name]++;
        return;
    }
    if(!vald[name])
        return;
    return up(dp[name],cnt+1);
}
bool mycmp(pair<int,string> a,pair<int,string> b){
    if(a.first>b.first)
        return true;
    if(a.first==b.first&&a.second<b.second)
        return true;
    return false;

}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Tree "<<i<<":"<<endl;
        dp.clear(),vald.clear(),out.clear();
        cin>>n>>d;
        string parent,child;
        for(int i=0;i<n;i++){
            cin>>parent>>cn;
            while(cn--){
                cin>>child;
                dp[child]=parent;
                vald[child]=true;
            }
        }
        for(map<string,string>::iterator it=dp.begin();it!=dp.end();it++)
            up(it->first);
        vector<pair<int,string> >v;
        for(map<string,int>::iterator it=out.begin();it!=out.end();it++)
            v.push_back({it->second,it->first});
        sort(v.begin(),v.end(),mycmp);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(i>0&&v[i].first!=v[i-1].first)
                cnt++;
            if(cnt>=3||(i>=3&&v[i].first!=v[i-1].first))
                break;
            cout<<v[i].second<<" "<<v[i].first<<endl;
        }
        /*for(map<string,vector<string> >::iterator it=out.begin();it!=out.end();it++){
            cout<<it->first<<" ";
            for(int i=0;i<it->second.size();i++){
                cout<<it->second[i]<<" ";
            }
            cout<<endl;
        }*/
    }
    return 0;
}
