// URI : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=1625
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
int a;
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)
            break;
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            sum+=a;
            ans=max(ans,sum);
            if(sum<0)
                sum=0;
        }
        if(ans>0)
            printf("The maximum winning streak is %d.\n",ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
