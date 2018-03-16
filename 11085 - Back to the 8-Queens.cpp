
//probleb link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2026
#include<bits/stdc++.h>
using namespace std;

bool R[8],D1[15],D2[15];
int C,pos[8],cont;
int in[8];
int minMove=INT_MAX;
int cntMovs(){
    int moves=0;
    for(int i=0;i<8;i++){
        if(pos[i]==in[i]) continue;
        moves++;
        //cout<<pos[i]<<" ";
    }
    //cout<<endl;
    //cout<<"moves are : "<<moves<<endl;
    return moves;
}
void search(int c){
    if(c==8){
        minMove=min(minMove,cntMovs());
        return;
    }
    else{
        for(int i=0;i<8;i++){
            if(R[i] || D1[c-i+7] || D2[c+i]) continue;
            R[i]=D1[c-i+7]=D2[c+i]=true;
            pos[c]=i;
            search(c+1);
            R[i]=D1[c-i+7]=D2[c+i]=false;
        }
    }
}

int main(){
    int caSe=0;
    while(cin>>in[0]>>in[1]>>in[2]>>in[3]>>in[4]>>in[5]>>in[6]>>in[7]){
        for(int i=0;i<8;i++) in[i]--;
        for(int i=0;i<8;i++) R[i]=false;
        for(int i=0;i<15;i++) D1[i]=D2[i]=false;
        minMove=INT_MAX;
        search(0);
        cout<<"Case "<<++caSe<<": "<<minMove<<endl;
    }

    return 0;
}
