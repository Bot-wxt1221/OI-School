#include <iostream>
#include <cstdio>
inline int read();
class Union{
public:
  int fa[100005];
  bool mark[100005];
  int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
  }
  Union(){
    for(int i=1;i<=100000;i++){
      fa[i]=i;
      mark[i]=0;
    }
    return ;
  }
}U[36];

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    for(int ii=0;ii<30;ii++){
      if(z&(1<<ii)){
        int fx;
        U[ii].fa[fx=U[ii].getfa(x)]=U[ii].getfa(y);
        U[ii].mark[U[ii].getfa(y)]|=U[ii].mark[fx];
        if(!(z&1)){
          U[ii].mark[U[ii].getfa(x)]|=1;
        }
      }
    }
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int u=read();
    int v=read();
    for(int ii=0;ii<30;ii++){
      if(U[ii].getfa(u)==U[ii].getfa(v)){
        printf("0\n");
        goto end;
      }
    }
    for(int ii=0;ii<30;ii++){
      if(U[ii].mark[U[ii].getfa(u)]){
        printf("1\n");
        goto end;
      }
    }
    printf("2\n");
    end:{}
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
