//uri:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1891
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<string,string> >vec;
string s,x,y;
int cnt;
void backTracking(int ind,string ans){
    if(cnt==100)
        return;
    if(ind==s.size()){
        cnt++;
        cout<<ans<<endl;
        return;
    }
    while(ind < s.size() && s[ind] == '0'){
        ++ind;
    }
    if(ind>=s.size())
        return;
    for(int i=0;i<n;i++){
        bool enter=1;
        if(ind+vec[i].second.size()-1<s.size()){
            for(int j=0;j<vec[i].second.size();j++){
                if(s[ind+j]!=vec[i].second[j]){
                    enter=0;
                    break;
                }
            }
            if(!enter) continue;
            backTracking(ind+vec[i].second.size(),ans+vec[i].first);
            if(cnt == 100) return;
        }
    }


}
int main()
{
    int test=1;
    while(1){
        vec.clear();
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            vec.push_back({x,y});
        }
        sort(vec.begin(),vec.end());
        cin>>s;
        printf("Case #%d\n",test++);
        cnt=0;
        backTracking(0,"");
        puts("");
    }
    return 0;
}
