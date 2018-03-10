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
vector<int>x;
bool check;
vector<vector<int> >v;
void permute(vector<int> a, int l, int r)
{
   int i;
   if (l == r)
     v.push_back(a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(a[l],a[i]);
          permute(a, l+1, r);
          swap(a[l], a[i]); //backtrack
       }
   }
}
int optRst(char c,int ind,int rst){
	if(c=='*')
		return rst*=x[ind];
	else if(c=='+')
		return rst+=x[ind];
	else if(c=='-')
		return rst-=x[ind];
	else
		return rst;
}
void BackTracking(int ind,char opt  ,int rst){
	if(ind==5){
		if(rst==23)
			check=1;
		return;
	}
	int y=optRst(opt,ind,rst);
	//cout<<y<<endl;
	BackTracking(ind+1,'*',y);
	BackTracking(ind+1,'+',y);
	BackTracking(ind+1,'-',y);
}
int main(){
	while(1){
		int in,sum=0;
		v.clear();
		x.clear();
		for(int i=0;i<5;i++){
			cin>>in;
			x.push_back(in);
			sum+=in;
		}
		if(!sum)
			break;
		bool enter=0;
		permute(x,0,4);
		for(int i=0;i<v.size();i++){
			check=0;
			x=v[i];
			BackTracking(0,'/',x[0]);
			if(check){
				enter=1;
				cout<<"Possible"<<endl;
				break;
			}

		}
		if(!enter)
			cout<<"Impossible"<<endl;
	}
	return 0;
}

/*#include <iostream>
#include <map>
using namespace std;

map<string, string> m;
map<string, int> ranks;

string find_set(string i)
{
    // find root and make root as parent of i (path compression)
    if (m[i]!= i)
        return m[i]= find_set(m[i]);
    return i;
}
int union_set(string x, string y)
{
    string xroot = find_set(x);
    string yroot = find_set(y);
    if(xroot!=yroot){
    if(ranks[xroot] > ranks[yroot])
    	swap(xroot,yroot);
    m[xroot]=yroot;
    ranks[yroot] += ranks[xroot];

    }
    return max(ranks[yroot], ranks[xroot]);
}

int main() {
	int t,f;
	cin>>t;
	while(t--){
		cin>>f;
		m.clear();
		ranks.clear();
		for(int i=0;i<f;i++){
			string fst,scd;
			cin>>fst>>scd;
			if(!m.count(fst)){
				m[fst]=fst;
				ranks[fst]=1;
			}
			if(!m.count(scd)){
				m[scd]=scd;
				ranks[scd]=1;
			}
			cout<<union_set(fst,scd)<<endl;
		}
	}
	return 0;
}
/*#include<bits/stdc++.h>
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
map<string,string>m;
map<string,int>rank;
string find_set(string i)
{
    // find root and make root as parent of i (path compression)
    if (m[i]!= i)
        return m[i]= find_set(m[i]);
    return i;
}

// A function that does union of two sets of x and y
// (uses union by rank)
int Union_set(string x, string y)
{
    string xroot = find_set(x);
    string yroot = find_set(y);
    if(rank[xroot]>rank[yroot])
    	swap(xroot,yroot);
    m[xroot]=yroot;
    rank[yroot]+=rank[xroot];
    return max(rank[yroot],rank[xroot]);
}
int main() {
	int t,f;
	cin>>t;
	while(t--){
		cin>>f;
		m.clear();
		rank.clear();
		for(int i=0;i<f;i++){
			string fst,scd;
			cin>>fst>>scd;
			if(!m.count(fst)){
				m[fst]=fst;
				rank[fst]=1;
			}
			if(!m.count(scd)){
				m[scd]=scd;
				rank[scd]=1;
			}
			cout<<Union_set(fst,scd)<<endl;
		}
	}
	return 0;
}*/

