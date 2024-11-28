#include <iostream>
#include <cstdio>
inline int read();
int fir[5005];
int v[5005];
int w[5005];
int ans[5005];
int nxt[5005];
int now;
bool in[5005];
int dfn[5005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt=0;
int cntt=0;
void dfs(int now,int fa){
  in[now]=1;
  dfn[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(dfn[v[i]]==0){
      dfs(v[i],now);
    }
    if(in[v[i]]){
      ans[i]=2;
      cntt=2;
    }else{
      ans[i]=1;
    }
  }
  in[now]=0;
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
  }
  cntt=1;
  for(int i=1;i<=n;i++){
    if(dfn[i]){
      continue;
    }
    dfs(i,i);
  }
  printf("%d\n",cntt);
  for(int i=1;i<=m;i++){
    printf("%d ",ans[i]);
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
