/*
Hint:	

You are given N and M and you have M selected tickets numbered
Tickets from 1 to N should not be divisible by any of the selected tickets
for example if we have a, b, c, ... selected tickets
then any ticket that is divisible by a or b or c or .... or LCM(a,b) or LCM(a,c) or ..... or LCM(a,b,c)

Lets Assume N = 10 and M = 2
Selected = 2 3
Then our numbers from 1 to N should not be divisible by 
2
3
LCM(2,3) = 6
Lets see what number those selected numbers divides
List-----------1 2 3 4 5 6 7 8 9 10
Divisible by:---2 2 2 2 2----------------We will exclude(2,4,6,8,10)
Divisible by:-----3 3 3-------------------We will exclude(3,6,9)
Divisible by:----------- 6-----------------------We will exclude(6)
Notice that we excluded "6" 3 times, we need to solve this problem

The solution for that is to determine the size of set of the selected number {2,3}
LCM(2,3) is the LCM of the set {2,3} the size = 2 which is even then we should subtract N/LCM(2,3) from
forbidden count, in case of LCM(2,3) = 6 >>> N/LCM(2,3) = 1 which is what we want to subtract.
In case of the size of the set is odd, we need to add N/LCM(a) to the forbidden count, if set is {2}
then it's size is 1 which is odd then add N/LCM(1,2) to the forbidden count.
The reason for that is, if you have an even set then the product of it's numbers is excluded previously
more than once, so we need to subtract it to avoid redundant so that we excluded it those numbers only once.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 10000001
int a[16];
int n,m,sum;
long long gcd(ll x,ll y){
    long long t;
    while(x%y)
        t = x, x = y, y = t%y;
    return y;
}
void dfs(int idx, long long p, int cnt) {
    if(idx == m) {
        if(cnt&1)
            sum -= n/p;
        else
            sum += n/p;
        return;
    }
    if(p > n)       return;
    dfs(idx+1, p*a[idx]/gcd(p, a[idx]) , cnt+1);
    dfs(idx+1, p, cnt);
}
int main(){
    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        sum=0;
        dfs(0,1,0);
        printf("%d\n",sum);
    }
    return 0;
}
