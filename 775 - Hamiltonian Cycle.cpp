//uri: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=716
#include <bits/stdc++.h>
using namespace std;
int n,a,b;
char line[100];
vector<vector<int> >adj;
bool vis[300];
vector<int> path;
void print(){
    for(int i=0;i<n;i++)
        printf("%d ",path[i]+1);
    printf("%d",1);
    puts("");
}
bool dfs(int node,int cnt){
    bool ans =0;
    path.push_back(node);
    if(cnt==n){
        print();
        return true;
    }
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(!vis[adj[node][i]]){
            ans = ans || dfs(adj[node][i],cnt+1);
        }
    }
    vis[node]=0;
    path.pop_back();
    return ans;
}
int main()
{
    while(1){
        if(scanf("%d\n", &n) == -1) break;
        adj.clear();
        path.clear();
        adj.resize(n);
        memset(vis,0,sizeof(vis));
        while(gets(line), strcmp(line, "%")) {
            sscanf(line, "%d %d", &a, &b);
            adj[a - 1].push_back(b - 1); adj[b - 1].push_back(a - 1);
        }
        if(!dfs(0,1))
            puts("N");
    }
    return 0;
}
