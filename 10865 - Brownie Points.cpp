// uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1806
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll x[200001],y[200001],n,im,cx,cy,stan=0,ollie=0;
int main()
{
    while(1){
        cin>>n;
        if(n==0)
            break;
        stan=0,ollie=0;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        im=n/2;
        for(int i=0;i<n;i++){
            cx=x[i]-x[im];
            cy=y[i]-y[im];
            if(cx==0||cy==0)
                continue;
            else if(cx*cy>0)
                stan++;
            else
                ollie++;
        }
        printf("%d %d\n",stan,ollie);
    }
    return 0;
}
