//============================================================================
// Name        : test.cpp
// Author      : Mai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

#define MP make_pair
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int adj[8][8];

bool valid(int x,int y){
	return x<8&&x>=0&&y>=0&&y<8;
}
int BFS(int s1,int s2,int d1,int d2){
	memset(adj,-1,sizeof(adj));
	queue<pair<int,int> >q;
	q.push(MP(s1,s2));
	int stp=0;
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			pair<int,int>cur=q.front();
			q.pop();
			if(d1==cur.first&&d2==cur.second)
				return stp;
			adj[cur.first][cur.second]=1;
			for(int i=0;i<8;i++){
				int nx=cur.first+dx[i];
				int ny=cur.second+dy[i];
				if(valid(nx,ny)&&adj[nx][ny]!=1)
					q.push(MP(nx,ny));
			}
		}
		stp++;
	}
}

int main() {
	string in1,in2;
	map<char,int>m;
	m['a']=0,m['b']=1,m['c']=2,m['d']=3,m['e']=4,m['f']=5,m['g']=6,m['h']=7;
	while(cin>>in1>>in2){
	int s1=in1[1]-'0';
	s1--;
	int s2=m[in1[0]];
	int d1=in2[1]-'0';
	d1--;
	int d2=m[in2[0]];
	cout<<"To get from "<<in1<<" to "<<in2<<" takes "<<BFS(s1,s2,d1,d2)<<" knight moves."<<endl;
	}
	return 0;
}
