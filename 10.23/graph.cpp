#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
inline int read();
std::vector<int>vec[500005];
int u[500005];
int y[500005];
bool ans[500005];
int v[500005];
int pre[500005];
int del[500005];
int n,m;
std::priority_queue<std::pair<int,int> >qu;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
	n=read();
	m=read();
	int q=read();
	for(int i=1;i<=m;i++){
		u[i]=read();
		v[i]=read();
    vec[u[i]].push_back(i);
    del[i]=0x3f3f3f3f;
	}
	for(int i=1;i<=q;i++){
		int x=read();
		y[i]=x;
		if(del[x]==0x3f3f3f3f){
			del[x]=i;
		}
	}
  pre[1]=1;
  for(int i=0;i<vec[1].size();i++){
    qu.push({del[vec[1][i]],vec[1][i]});
  }
  while(qu.size()>0){
    auto tp=qu.top();
    qu.pop();
    int now=v[tp.second];
    if(pre[now]){
      continue;
    }
    pre[now]=tp.second;
    for(int i=0;i<vec[now].size();i++){
      qu.push({del[vec[now][i]],vec[now][i]});
    }
  }
  for(int i=n;i!=1;i=u[pre[i]]){
    ans[pre[i]]=1;
  }
	for(int i=1;i<=q;i++){
		if(ans[y[i]]||del[y[i]]!=i){
			printf("0\n");
		}else{
			printf("1\n");
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
