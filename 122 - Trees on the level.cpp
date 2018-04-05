//uri:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=58
#include <bits/stdc++.h>
using namespace std;
class node{
    public :
        int val,level;
        node *left,*right;
        node(int l){
            this->level=l;
            this->val=-1;
            this->left = NULL;
            this->right = NULL;
        }
};
int val;
string path;
map<string,bool> all;
bool flag;
vector<int>ans;
void print(){
    for(int i=0;i<ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
}
bool bfs(node *u){
    queue<node*>q;
    q.push(u);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            node *cur=q.front();
            q.pop();
            if(cur->val==-1){
                puts("not complete");
                return 0;
            }
            ans.push_back(cur->val);
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
    }
    return 1;
}
int main()
{
    string s;
    node *root =new node(0);
    flag=0;
    while(cin>>s){
        if(s=="()"){
            if(flag){
                puts("not complete");
                flag=0;
                all.clear();
                ans.clear();
                root = new node(0);
                continue;
            }
            if(bfs(root))
                print();
            flag=0;
            all.clear();
            ans.clear();
            root = new node(0);
        }
        else{   // if it new node :)
            stringstream ss;
            for(int i = 0; i < s.size(); i++)
                if(s[i] == '(' || s[i] == ')'|| s[i] == ',') s[i] = ' ';
            ss << s;
            ss >> val;
            path = "";
            ss >> path;
            if(path==""){ // root
                if(root->val==-1) root->val=val;
                else{
                    flag=1;
                    continue;
                }
            }else{
                //cout<<path<<" "<<val<<endl;
                if(all[path]){
                    flag=1;
                    continue;
                }
                all[path]=1;
                node *cur=root;
                for(int i=0;i<path.size();i++){
                    if(path[i]=='L'){ // left node
                        if(cur->left==NULL)
                            cur->left=new node(i+1);
                        cur=cur->left;
                    }else{ // right node
                        if(cur->right==NULL)
                            cur->right=new node(i+1);
                        cur=cur->right;
                    }
                }
                cur->val=val;
            }

        }
    }
    return 0;
}
