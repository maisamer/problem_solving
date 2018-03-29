//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=448
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
  //sum ans = max(ans, sum); // we keep the maximum RSQ overall if (sum < 0) sum = 0; // but we reset the running sum } // if it ever dips below 0 printf("Max 1D Range Sum = %d\n", ans);
int main(){
    int t,s,a;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        scanf("%d", &s);
        int sum = 0, startM=2 ,endM ,Msum=0,tmp=1;
        for(int c=2;c<=s;c++){
            scanf("%d", &a);
            sum+=a;
            if(sum<0){
                sum=0;
                tmp=c;
            }
           if (sum >= Msum) {
                if (sum > Msum || (sum == Msum && (c - tmp > endM - startM))) {
                    startM = tmp;
                    endM = c;
                }
                Msum = sum;
            }
        }

        //cout<<"sum "<<Msum<<endl;
        if(Msum>0)
            printf("The nicest part of route %d is between stops %d and %d\n",i,startM,endM);
        else
            printf("Route %d has no nice parts\n",i);
    }
	return 0;

}
