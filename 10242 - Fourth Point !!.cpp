//uri : https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1183
#include<bits/stdc++.h>

using namespace std;
double x[4],y[4];
int main()
{
    set<pair<double,double> >s;
    set<pair<double,double> >::iterator it;
    while(cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3]){
        s.clear();
        double rx,ry;
        pair<double,double>p1,p2;
        for(int i=0;i<4;i++){
            if(s.find(make_pair(x[i],y[i]))!=s.end()){
                rx=x[i],ry=y[i];
                s.erase({x[i],y[i]});
            }else{
                s.insert({x[i],y[i]});
            }
        }
        it=s.begin();
        p1.first=it->first,p1.second=it->second;
        it++;
        p2.first=it->first,p2.second=it->second;
        cout<<fixed<<setprecision(3)<<p1.first+p2.first-rx<<" "<<setprecision(3)<<p1.second+p2.second-ry<<endl;
    }
    return 0;
}
