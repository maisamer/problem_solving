//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=1217
#include<bits/stdc++.h>
using namespace std;
int fil[51];
int out[51];
void print(int f[]){
    for(int i=1;i<=5;i++)
        cout<<f[i]<<" ";
    cout<<endl;
}
void calculate(int num,int page){
    /*cout<<"fill : "<<endl;
    print(fil);
    cout<<"out : "<<endl;
    print(out);
    cout<<num<<" "<<page<<endl;
    cout<<"///////////////////////////////"<<endl;*/
    if(page>50)
        return;
    bool c=0;
    int i;
    for(i=1;i<=page;i++){
        int r=sqrt(num+fil[i]);
        if(!fil[i]||r*r==(num+fil[i])){
            c=1;
            break;
        }
    }
    if(c){
        fil[i]=num;
        calculate(num+1,page);
    }
    else{
        out[page]=num-1;
        calculate(num,page+1);
    }

}

int main(){
    int t,n;
    cin>>t;
    calculate(1,1);
    while(t--){
        cin>>n;
        cout<<out[n]<<endl;
    }

    return 0;
}
