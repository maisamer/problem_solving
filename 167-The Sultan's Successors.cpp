//PROBLEM LINK : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=103

#include<bits/stdc++.h>
using namespace std;
int cnt;
vector<pair<int,int> >v;
int board [8][8];
int pos[8];
bool R[8],D1[15],D2[15];
void backTracking(int c,int sum){
	if(c==8){
		cnt=max(cnt,sum);
	}
	else{
		for(int i=0;i<8;i++){
	        if(R[i] || D1[c-i+7] || D2[c+i]) continue;
			R[i]=D1[c-i+7]=D2[c+i]=true;
			pos[c]=i;
			backTracking(c+1,sum+board[i][c]);
			R[i]=D1[c-i+7]=D2[c+i]=false;
		}

	}
}
int main(){
    int T;

    cin>>T;

    for(int tc=0;tc<T;tc++){
    	for(int i=0;i<8;i++)
    		for(int j=0;j<8;j++)
    			cin>>board[i][j];

        for(int i=0;i<8;i++) R[i]=false;
        for(int i=0;i<15;i++) D1[i]=D2[i]=false;
        cnt=0;
        backTracking(0,0);
        cout<<setw(5)<<setiosflags(ios::right)<<cnt<<endl;
    }

	return 0;
}
