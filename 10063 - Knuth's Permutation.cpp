//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1004
#include<bits/stdc++.h>
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
string in;
vector<string>ans;
vector<string> com(char x,string y){
    vector<string> v;
    string out;
    //cout<<"in "<<y<<endl;
    for(int i=0;i<=y.size();i++){
        //out=y.substr(0,i)+x+y.substr()
        out="";
        for(int j=0;j<i;j++)
            out+=y[j];
        out+=x;
        //cout<<"out "<<out<<endl;
        for(int j=i;j<y.size();j++){
            //cout<<out<<endl;
            out+=y[j];
        }
        //cout<<out<<endl;
        v.push_back(out);
    }
    return v;
}
void Run(int i,string x){
    if(i==in.size()){
        ans.push_back(x);
        return;
    }
    vector<string>c;
    c=com(in[i],x);
    for(int j=0;j<c.size();j++){
        //cout<<j<<" "<<c[j]<<endl;
        Run(i+1,c[j]);
    }
}
int main(){
    bool enter=0;
    while(cin>>in){
        if(enter)
            puts("");
        enter=1;
        ans.clear();
        string x="";
        x+=in[0];
        //cout<<"x is : "<<x<<endl;
        Run(1,x);
        //vector<string>g=com('c',"ba");
        //cout<<"size is : "<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
