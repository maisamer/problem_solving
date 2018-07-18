// uri : https://www.spoj.com/problems/ELIS/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1e5+10;
int a[mx];
int n;
int backTracking(int ind,int perv){
    if(ind==n)
        return 0;
    int op1=-1;
    if(perv<a[ind])
        op1=1+backTracking(ind+1,a[ind]);
    int op2=backTracking(ind+1,perv);
    return max(op1,op2);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<backTracking(0,0);
    return 0;
}
