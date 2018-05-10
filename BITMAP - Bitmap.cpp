//uri:http://www.spoj.com/problems/BITMAP/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int OO = 10000;
int n,t,m;
vector<pair<int,int> >ones;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int a[190][190],out[190][190],sz,tx,ty;
void bfs(pair<int,int> x){
    queue<pair<int,int> >q;
    q.push(x);
    while(!q.empty()){
        sz=q.size();
        while(sz--){
            pair<int,int>cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                tx=cur.first+dx[i];
                ty=cur.second+dy[i];
                if(tx<n&&tx>=0&&ty<m&&ty>=0&&out[cur.first][cur.second]+1<out[tx][ty]){
                    out[tx][ty]=out[cur.first][cur.second]+1;
                    q.push({tx,ty});
                }
            }
        }
    }
}
int main(){
    char in;
    scanf("%d",&t);
    while(t--){
        ones.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>in;
                a[i][j]=in-'0';
                if(a[i][j]){
                    ones.push_back({i,j});
                    out[i][j]=0;
                    continue;
                }
                out[i][j]=OO;
            }
        }
        for(int i=0;i<ones.size();i++)
            bfs(ones[i]);
        for(int i=0;i<n;i++){
            printf("%d",out[i][0]);
            for(int j=1;j<m;j++)
                printf(" %d",out[i][j]);
            puts("");
        }

    }
    return 0;
}
