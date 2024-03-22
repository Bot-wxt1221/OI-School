#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int n;
int getpos(int x,int y){
  return (x-1)*n+y;
}
int fa[900050];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int x[305],y[305];
int ans[900050];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    y[i]=read();
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      fa[getpos(i,j)]=getpos(i,j);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      for(int k=j+1;k<=n;k++){
        if((y[j]-y[i])*(x[k]-x[j])==(y[k]-y[j])*(x[j]-x[i])){
          fa[getfa(getpos(i,j))]=getfa(getpos(k,j));
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      ans[getfa(getpos(i,j))]++;
    }
  }
  int maxx=-1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      maxx=std::max(maxx,ans[getpos(i,j)]);
    }    
  }
  if(maxx+1>=(n)-(n/3)+1){
    printf("%lld",n-maxx-1);
  }else{
    printf("%lld",n/3);
  }
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


