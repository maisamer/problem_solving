//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=316
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
vector<vector<pair<int,pair<int,int> > > >sys;
int mark[10002];
int Run(int tm,int s,int tr,int cnt){
    if(cnt>0&&s==tr)
        return 9999;
    if(!mark[tr]) return tr;
    for(int i=0;i<sys[tr].size();i++)
        if(tm>=sys[tr][i].second.first&&tm<=sys[tr][i].second.first+sys[tr][i].second.second)
            return Run(tm,s,sys[tr][i].first,cnt+1);
    return tr;
}
int main(){
    printf("CALL FORWARDING OUTPUT\n");
    int n;
    scanf("%d", &n);
    //sys=vector<vector<pair<int,pair<int,int> > > >(10005);
    //7777 1000 2000 7777
    int s,stm,dtm,fw;
    for(int i=1;i<=n;i++){
        sys = vector<vector<pair<int, pair<int,int> > > > (10002);
        for(int i=0;i<10002;++i) mark[i] = 0;
        while(1){
            scanf("%d", &s);
            if(s==0)
                break;
            mark[s] = 1;
            scanf("%d %d %d", &stm, &dtm, &fw);
            sys[s].push_back(make_pair(fw,make_pair(stm,dtm)));
        }
        int tm ;
        printf("SYSTEM %d\n", i);
        while(1){
            scanf("%d", &tm);
            if(tm==9000)
                break;
            int in;
            scanf("%d", &in);
            printf("AT %04d CALL TO %04d RINGS %04d\n",tm,in,Run(tm,in,in,0));
        }
    }

    printf("END OF OUTPUT\n");
    return 0;
}
