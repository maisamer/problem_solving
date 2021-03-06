//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=618
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
bool flag;
int n,l,u;
int out;
bool vis[11];
int way[20];
vector<vector<int> >adj;
void pathDFS(int st,int cnt){
    if(cnt == l) {
        flag = 1;
        cout<<"(1";
        for(int i = 0; i < cnt; i++)
            cout<<","<<way[i];
        cout<<")"<<endl;
        return ;
    }
    for(int i=0;i<adj[st].size();i++){
        if(!vis[adj[st][i]]){
            vis[adj[st][i]]=1;
            way[cnt]=adj[st][i]+1;
            pathDFS(adj[st][i],cnt+1);
            vis[adj[st][i]]=0;
        }
    }
}
int main(){
    bool fst=0;
    while(cin>>n>>l){
        if(fst)
            cout<<endl;
        fst=1;
        adj=vector<vector<int> >(n);
        clr(vis,0);
        flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>u;
                if(u)
                    adj[i].push_back(j);
            }
        }
        vis[0]=1;
        pathDFS(0,0);
        if(!flag)
             cout<<"no walk of length "<<l<<endl;
        cin>>u;
    }
    return 0;
}
