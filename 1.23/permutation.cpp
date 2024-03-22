#include <iostream>
#include <cstdio>
inline int read();
int a[100005];
int b[100005];
int c[100005];
int n,m;
int seq[100005];
int num[100005];
bool yes=0;
void dfs(int now){
  if(yes){
    return ;
  }
  if(now==n+1){
    int nn=0;
    for(int i=1;i<=m;i++){
      if(num[b[i]]>std::min(num[a[i]],num[c[i]])&&num[b[i]]<std::max(num[a[i]],num[c[i]])){
        nn++;
      }
    }
    if(nn<((m/2)+(m%2))){
      return ;
    }
    for(int i=1;i<=n;i++){
      printf("%d ",seq[i]);
    }
    yes=1;
    return ;
  }
  for(int i=1;i<=n;i++){
    if(num[i]!=0){
      continue;
    }
    num[i]=now;
    seq[now]=i;
    dfs(now+1);
    num[i]=0;
    seq[now]=0;
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	#endif
  n=read();
  m=read();
  for(int i=1;i<=m;i++){
    a[i]=read();
    b[i]=read();
    c[i]=read();
  }
  dfs(1);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


