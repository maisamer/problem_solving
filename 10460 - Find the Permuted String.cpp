//uri : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1401
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int index;
        cin>>index;
        index--;
        vector<int>v(s.size());
        for(int i=s.size();i;i--){
            v[i-1]=index%i;
            index/=i;
        }
        vector<char>c;
        for(int i=0;i<s.size();i++){
            c.insert(c.begin()+v[i],s[i]);
        }
        for(int i=0;i<s.size();i++)
            cout<<c[i];
        cout<<endl;
    }
    return 0;
}
