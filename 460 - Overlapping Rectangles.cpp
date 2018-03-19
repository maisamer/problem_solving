//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=401
#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
int main()
{
    int t,x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> t;
    bool enter=0;
    while(t--){
        if(enter)
            cout<<endl;
        enter=1;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if(max(x1,x3)<min(x2,x4)&&max(y1,y3)<min(y2,y4))
            printf("%d %d %d %d\n",max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
        else
            printf("No Overlap\n");
    }
	return 0;
}

