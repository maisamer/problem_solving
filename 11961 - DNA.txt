//URI:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3112
#include <bits/stdc++.h>
using namespace std;
int t,sz,n,k;
string x;
const string dna="ACGT";
set<string>v;
void backTracking(int ind,int cnt,string ans){
    if(cnt>k)
        return;
    if(ind==n){
        v.insert(ans);
        return;
    }
    for(int i=0;i<dna.size();i++)
        backTracking(ind+1,dna[i]==x[ind]?cnt:cnt+1,ans+dna[i]);
}
int main()
{
    cin>>t;
    while(t--){
        v.clear();
        cin>>n>>k>>x;
        backTracking(0,0,"");
        printf("%d\n",v.size());
        for(set<string>::iterator it=v.begin();it!=v.end();it++)
            cout<<(*it)<<endl;

    }
    return 0;
}
