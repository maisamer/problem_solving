#include<bits/stdc++.h>
using namespace std;
bool ans;
void back(int a[],int n,int pos,int sum,int msum){
	//cout<<"fun"<<msum<<endl;
	if(sum==msum){
		ans=1;
		//return;
	}
	if(pos>=n)
		return;
    for(int i=pos+1;i<n;i++){
        sum+=a[i];
        back(a,n,i,sum,msum);
        //cout<<sum<<endl;
        sum-=a[i];
    }
	//pos--;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		ans=0;
		int sum=0;
		string x;
		stringstream ss;
		getline(cin,x);
		int a[21];
		int n=0;
		int b;
		ss<<x;
		while(ss>>b){
			a[n++]=b;
			sum+=b;
		}
		if(sum%2){
			cout<<"NO"<<endl;
			continue;
		}
		back(a,n,-1,0,sum/2);
		cout<<(ans?"YES":"NO")<<endl;

	}
	return 0;
}
