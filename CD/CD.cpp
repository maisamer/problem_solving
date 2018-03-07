#include<bits/stdc++.h>
using namespace std;
bool ans;
int n,t;
int a[21];
vector<int>v;
struct item{
	int sum;
	vector<int>index;
};
struct item out;
void back(int pos,int sum){
	//cout<<"fun"<<msum<<endl;
	if(pos>=t);
	else{
    for(int i=pos;i<t;i++){
        sum+=a[i];
        v.push_back(i);
        if(out.sum<sum&&sum<=n){
        	out.sum=sum;
        	out.index=v;
        }
        //out.push_back(it);
        //cout<<sum<<" pos "<<pos<<endl;
        back(i+1,sum);
        v.pop_back(); //hena ana bshel i number in a array
        sum-=a[i];
    }
	}
	//cout<<sum<<endl;
	//pos--;
}
/*bool comp(struct item a,struct item b){
    if(a.sum<b.sum)
        return true;
    /*if(a.sum==b.sum&&a.index.size()>b.index.size())
        return true;
    return false;
}
struct item showBest(){
	//struct item ou;
    sort(out.begin(),out.end(),comp);
	for(int i=out.size()-1;i>=0;i--){
	/*	cout<<"sum "<<i<<" is "<<out[i].sum<<endl<<"and index is : "<<endl;
		for(int j=0;j<out[i].index.size();j++)
			cout<<out[i].index[j]<<" ";
		cout<<endl;

		if(n>=out[i].sum){
            struct item ou=out[i];
            return ou;
		}

	}
	//return ou;
}*/
int main(){
	while(cin>>n>>t){
		for(int i=0;i<t;i++)
			cin>>a[i];
		v.clear();
		out.sum=0;
		out.index.clear();
		back(0,0);
		for(int i=0;i<out.index.size();i++)
			cout<<a[out.index[i]]<<" ";
		cout<<"sum:"<<out.sum<<endl;
	}
	return 0;
}
