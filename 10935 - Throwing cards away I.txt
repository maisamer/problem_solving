// uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876
#include <bits/stdc++.h>
using namespace std;
queue<int>q;
int n;
void init(){
    for(int i=1;i<=n;i++)
        q.push(i);
}
int main()
{
    while(1){
        cin>>n;
        if(!n) break;
        if(n==1){
           printf("Discarded cards:\n");
           printf("Remaining card: %d\n",n);
           continue;
        }
        init();
        printf("Discarded cards: %d",q.front());
        q.pop();
        while(q.size()>1){
            q.push(q.front());
            q.pop();
            printf(", %d",q.front());
            q.pop();
        }
        puts("");
        printf("Remaining card: %d\n",q.front());
        q.pop();
    }

    return 0;
}
