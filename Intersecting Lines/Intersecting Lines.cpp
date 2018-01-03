/*
* Intersecting Lines problem
*/

#include<bits/stdc++.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define EPS 1e-9
#define dcmp(a,b) fabs( a - b ) < EPS

typedef long long         ll;
struct Line{
	double a,b,c;
	Line(pair<double,double>p1,pair<double,double>p2){
		b=p2.first-p1.first;
		a=p1.second-p2.second;
		c=p1.first*p2.second-p2.first*p1.second;
	}
};
bool sameLine;
bool intersect(Line l1,Line l2,pair<double,double> &p){
	double det = l1.a*l2.b-l1.b*l2.a;
	if(dcmp(det,0)){
		if((l1.c-l1.a)/l1.b==(l2.c-l2.a)/l2.b)
			sameLine=true;
		return false;
	}
	p.first=(l1.b*l2.c-l2.b*l1.c)/det;
	p.second=(l1.c*l2.a-l2.c*l1.a)/det;
	return true;
}

int main() {
	int n;
	pair<double,double> p1,p2,p3,p4;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while(n--){
		sameLine=false;
		cin>>p1.first>>p1.second>>p2.first>>p2.second>>p3.first>>p3.second>>p4.first>>p4.second;
		Line l1=Line(p1,p2);
		Line l2=Line(p3,p4);
		pair<double,double>p;
		bool inter=intersect(l1,l2,p);
		if(inter)
			cout<<"POINT "<<fixed<<setprecision(2)<<p.first<<" "<<fixed<<setprecision(2)<<p.second<<endl;
		else{
			cout<<(sameLine?"LINE":"NONE")<<endl;}
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
