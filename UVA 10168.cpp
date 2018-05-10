//uri:https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1109
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 10000001
vector<bool>prime(mx,1);
void SieveOfEratosthenes()
{
    for (int p=2; p*p<=mx; p++)
        if (prime[p] == true){
            for (int i=p*2; i<=mx; i += p)
                prime[i] = false;
        }
}
int main(){
    int s;
    SieveOfEratosthenes();
    while(scanf("%d",&s)==1){
        if(s<8)
            puts("Impossible.");
        else{
            if(s&1){
                printf("2 3 ");
                s-=5;
            }
            else{
                printf("2 2 ");
                s-=4;
            }
            for(int i=2;i<s;i++){
                if(prime[i]&&prime[s-i]){
                    printf("%d %d\n",i,s-i);
                    break;
                }
            }
        }
    }
    return 0;
}
