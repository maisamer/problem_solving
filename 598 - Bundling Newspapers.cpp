//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=539
#include <bits/stdc++.h>
using namespace std;
string sub[20];
string line;
int m,a,b,n;
void backTrack(int l,int cnt,int ind,string st){
    if(cnt==l){
        st.erase(st.size()-2,2);
        cout<<st<<endl;
        return;
    }
    for(int i = ind; i < n; i++)
        backTrack(l, cnt + 1, i + 1, st + sub[i] + ", ");

}
int main()
{
    scanf("%d\n\n", &m);
    while(m--){
       getline(cin,line);
        if(line != "*") {
            if(sscanf(line.c_str(), "%d %d\n", &a, &b) == 1)
                b = a;
        } else a = 0, b = 0;
        for(n=0;;n++){
            getline(cin,line);
            if(line.length()==0)
                break;
            sub[n]=line;
        }
        if(a==0&&b==0)
            a=1,b=n;
        else if(a!=0&&b==0)
            b=a;
        for(int i=a;i<=b;i++){
            printf("Size %d\n",i);
            backTrack(i,0,0,"");
            puts("");
        }
        if(m)
            puts("");

    }

    return 0;
}
