#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
inline int read();
int fa[500005];
int tof[500005];
bool bro[500005];
__int128 a[500005];
__int128 gcd(__int128 x,__int128 y){
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}
int getfa(int x){
  if(x==fa[x]){
    return x;
  }
  bro[fa[x]]|=bro[x];
  int tfa=getfa(fa[x]);
  tof[x]*=tof[fa[x]];
  fa[x]=tfa;
  return tfa;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fa[i]=i;
    tof[i]=1;
    bro[i]=0;
    a[i]=read();
  }
  for(int i=1;i<=m;i++){
    int T=read();
    switch(T){
      case 1:{
        int x=read();
        int c=read();
        a[x]=c;
        break;
      }
      case 2:{
        int x=read();
        int y=read();
        if(x==y){
          continue;
        }
        int tx=getfa(x);
        int ty=getfa(y);
        if(tx!=ty){
          fa[tx]=ty;
          bro[ty]|=bro[tx];
          tof[tx]=-tof[x]*tof[y];
        }else if(tof[x]==tof[y]){
          bro[getfa(tx)]=1;
        }
        break;
      }
      case 3:{
        static int tt=0;
        int x=read();
        int y=read();
        int v=read();
        if(getfa(x)!=getfa(y)||bro[getfa(x)]){
          printf("0\n");
        }else{
          __int128 tta=((__int128)tof[x])*tof[y]*v*a[x];
          __int128 ttb=a[y];
          __int128 ttc=gcd(tta,ttb);
          tta/=ttc;
          ttb/=ttc;
          if(ttb<0){
            tta*=-1;
            ttb*=-1;
          }
          printf("%lld/%lld\n",(long long)tta,(long long)ttb);
        }
        break;
      }
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

