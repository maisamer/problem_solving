// uri : https://codeforces.com/contest/355/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mx=1000+10;
int b[mx],tr[mx];
int main()
{
    int c[5],n,m,ans;
    for(int i=0;i<4;i++)
        cin>>c[i];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<m;i++)
        cin>>tr[i];
    ans=c[3];
    int bus=0;
    for(int i=0;i<n;i++)
        bus+=min(b[i]*c[0],c[1]);
    bus=min(bus,c[2]);
    int car=0;
    for(int j=0;j<m;j++)
        car+=min(tr[j]*c[0],c[1]);
    car=min(car,c[2]);
    cout<<min(ans,car+bus);
    return 0;
}
