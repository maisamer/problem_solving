//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1335
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n=100000;
vector<ll>a;
void prime(){
    int pos=1,pev=0;
    vector<bool> isPrime(18409202, true);
    a=vector<ll>(n+1);
    for(ll num=3;pos<=n;num+=2){
        if(isPrime[num]){
            for(ll i=num*num;i<18409202;i+=num)
                isPrime[i]=0;
            if(pev+2==num){
                a[pos]=pev;
                pos++;
            }
            pev=num;
        }
    }

}

int main(){
    int s;
    prime();
    //print();
    while(scanf("%d",&s)==1){
        cout<<"("<<a[s]<<", "<<a[s]+2<<")\n";
    }
    return 0;
}
