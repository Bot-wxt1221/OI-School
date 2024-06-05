#include <iostream>
#include <cstdio>
inline int read();
class Union{
public:
  int fa[200005];
  int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
  }
  Union(){
    for(int i=1;i<=200000;i++){
      fa[i]=i;
    }
    return ;
  }
}U[11];
int u[400005];
int v[400005];
int w[400005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  int ans=(n-1)*10;
  for(int i=1;i<=n-1+q;i++){
    int u=read();
    int v=read();
    int w=read();
    for(int j=w+1;j<=10;j++){
      if(U[j].getfa(u)!=U[j].getfa(v)){
        ans--;
        U[j].fa[U[j].getfa(u)]=U[j].getfa(v);
      }
    }
    if(i>n-1){
      printf("%d\n",ans);
    }
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

