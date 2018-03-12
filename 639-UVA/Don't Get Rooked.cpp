
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
int n;
char x[5][5];
int res=0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool allow(int i,int j){
	return (i<n&&i>=0&&j<n&&j>=0);
}
bool valid(int row,int col){
	if(x[row][col]=='X')
		return 0;
	for(int i=0;i<4;i++){
		int xx=row,yy=col;
		while(allow(xx,yy)){
			if(x[xx][yy]=='X')
				break;
			if(x[xx][yy]=='1')
				return false;
			//cout<<"here"<<endl;
			xx+=dx[i];yy+=dy[i];
		}

	}
	return true;;
}
void maxQueen(int row,int col,int cont){
	if(col==n){
		col=0;
		row++;
	}
	res=max(res,cont);
	if(row>=n)
		return;
	for(int i=row;i<n;i++){
		for(int j=col;j<n;j++){
			maxQueen(i,j+1,cont);
			if(valid(i,j)){
				x[i][j]='1';
				maxQueen(i,j+1,cont+1);
				x[i][j]='.';
			}
		}
		row=0;
	}
}
int main() {
	while(1){
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++)
			cin>>x[i];
		res=0;
		maxQueen(0,0,0);
		cout<<res<<endl;
	}
	return 0;

}
