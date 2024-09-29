#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
inline int read();
char temp[1000005];
std::stack<int>st;
bool vised[1000005];
int to[1000005];
int node[1000005];
int seq2node[1000005];
std::vector<int>son[1000005];
std::vector<int>un;
class qnode{
public:
	qnode *pre,*nxt;
	int num;
	qnode(){
		num=0;
		nxt=pre=NULL;
		return ;
	}
}a[1000005];
bool cmp(qnode *a,qnode *b){
	while(temp[a->num]==temp[b->num]){
		a=a->nxt;
		b=b->nxt;
		if(a==NULL&&b==NULL){
			return 0;
		}
	}
	return temp[a->num]<temp[b->num];
}
int noww;
bool cmp2(int l,int r){
	return cmp(&a[son[noww][l]],&a[son[noww][r]]);
}
int ql,qr;
void dfs(int now){
	std::vector<int>tt;
	for(int i=0;i<son[now].size();i++){
		if(son[now][i]>qr||son[now][i]<ql){
			continue;
		}
		dfs(son[now][i]);
		tt.push_back(i);
	}
	int pre=now;
	a[pre].pre=NULL;
	noww=now;
	std::stable_sort(tt.begin(),tt.end(),cmp2);
	int mx=0;
	for(int i=0;i<tt.size();i++){
		if(tt[i]>=mx){
			a[pre].nxt=&a[son[now][tt[i]]];
			a[son[now][tt[i]]].pre=&a[pre];
			pre=to[son[now][tt[i]]];
			mx=tt[i];
		}
	}
	a[pre].nxt=&a[to[now]];
	a[to[now]].pre=&a[pre];
	a[to[now]].nxt=NULL;
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	#endif
	scanf("%s",temp+1);
	int n=strlen(temp+1);
	for(int i=1;i<=n;i++){
		if(temp[i]=='('){
			temp[i]=1;
		}else{
			temp[i]=2;
		}
	}
	st.push(0);
	to[0]=n+1;
	un.push_back(0);
	for(int i=1;i<=n;i++){
		a[i].num=i;
		if(temp[i]==1){
			st.push(i);
		}else{
			if(st.size()==1){
				un.push_back(i);
				vised[i]=1;
				continue;
			}
			to[st.top()]=i;
			int pretop=st.top();
			st.pop();
			son[st.top()].push_back(pretop);
		}
	}
	bool usee=0;
	int lstt=0;
	while(st.size()>0){
		usee=1;
		lstt=std::max(lstt,st.top());
		vised[st.top()]=1;
		st.pop();
	}
	dfs(0);
	un.push_back(n+1);
	for(int i=0;i<un.size()-1;i++){
		if(i==un.size()-2){
			if(usee){
				continue;
			}
		}
		ql=un[i]+1;
		qr=un[i+1]-1;
		dfs(0);
		for(auto cur=&a[0];cur!=NULL;cur=cur->nxt){
			vised[cur->num]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(vised[i]){
			if(temp[i]==1){
				putchar('(');
			}else{
				putchar(')');
			}
		}
	}
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
