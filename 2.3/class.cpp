#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int X[5005];
int Y[5005];
int x[1005];
int y[1005];
int x2[1005];
int y2[1005];
int map[2005][2005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("ex_d5.in","r",stdin);
  freopen("class.out","w",stdout);
  #endif
  int n=read();
  int nowx=0,nowy=0;
  for(int i=1;i<=n;i++){
    x[i]=read();
    y[i]=read();
    X[++nowx]=x[i];
    Y[++nowy]=y[i];
  }
  int m=read();
  for(int i=1;i<=m;i++){
    x2[i]=read();
    y2[i]=read();
    X[++nowx]=x2[i];
    Y[++nowy]=y2[i];
  }
  std::sort(X+1,X+nowx+1);
  nowx=std::unique(X+1,X+nowx+1)-X-1;
  std::sort(Y+1,Y+nowy+1);
  nowy=std::unique(Y+1,Y+nowy+1)-Y-1;
  for(int i=1;i<=n;i++){
    x[i]=std::lower_bound(X+1,X+nowx+1,x[i])-X;
    y[i]=std::lower_bound(Y+1,Y+nowy+1,y[i])-Y;
  }
  for(int i=1;i<=m;i++){
    x2[i]=std::lower_bound(X+1,X+nowx+1,x2[i])-X;
    y2[i]=std::lower_bound(Y+1,Y+nowy+1,y2[i])-Y;
  }
  int a=read();
  int b=read();
  for(int i=1;i<=n;i++){
    map[y[i]][x[i]]+=a;
  }
  for(int i=1;i<=m;i++){
    map[y2[i]][x2[i]]-=b;
  }
  for(int i=1;i<=nowx;i++){
    for(int j=1;j<=nowy;j++){
      map[j][i]+=map[j][i-1];
      map[j][i]+=map[j-1][i];
      map[j][i]-=map[j-1][i-1];
    }
  }
  std::sort(x+1,x+n+1);
  std::sort(y+1,y+n+1);
  register int ans=0;
  for(register int ii=1;ii<=n;ii++){
    register int i=y[ii];
    for(register int jj=ii;jj<=n;jj++){
      register int j=y[jj]; 
      register int _min=0;
      for(register int kk=1;kk<=n;kk++){
        register int k=x[kk];
        register int sumk;
        sumk=map[j][k]-map[i-1][k];
        _min=std::min(_min,sumk);
        ans=std::max(ans,sumk-_min);
        if(kk!=1&&x[kk]-1<=x[kk-1]){
          continue;
        }
        k=x[kk]-1;
        sumk=map[j][k]-map[i-1][k];
        _min=std::min(_min,sumk);
        ans=std::max(ans,sumk-_min);
      }
    }
  }
  printf("%d",ans);
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


