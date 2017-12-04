//============================================================================
// Name        : test.cpp
// Author      : Mai
// Version     :
// Copyright   : Your copyright notice
// Description : king's path in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define MP make_pair

map<pair<int,int>,int >m;
set<pair<int,int> > myset;
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

int BFS(int s1,int s2,int d1,int d2){
	queue<pair<int,int> >q;
	q.push(MP(s1,s2));
	m[{s1,s2}]=1;
	int stp=0;
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			pair<int,int>cur=q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int nx=cur.first+dx[i];
				int ny=cur.second+dy[i];
				if(m[{nx,ny}]==1||myset.count({nx,ny})==0)
					continue;
				if(d1==nx&&d2==ny)
					return stp+1;
				q.push({nx,ny});
				m[{nx,ny}]=1;
			}
		}
		stp++;
	}
	return -1;
}

int main() {
	int s1,s2,d1,d2;
	cin>>s1>>s2>>d1>>d2;
	int d;
	cin>>d;
	int a,b,r;
	for(int i=0;i<d;i++){
		cin>>r>>a>>b;
		for(int j=a;j<=b;j++)
			myset.insert({r,j});
	}
	//cout<<myset.size()<<endl;
	cout<<BFS(s1,s2,d1,d2);
	return 0;
}
