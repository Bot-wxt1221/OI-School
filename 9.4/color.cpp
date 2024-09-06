#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int fa[1200055];
int x[1200055];
int y[1200055];
int c[1200055];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int ans;
int clear;
int ad=0;
void Union(int x,int y){
  if(getfa(x)==getfa(y)){
    return ;
  }
  ans--;
  fa[getfa(x)]=getfa(y);
  return ;
}
int totans[1200055];
void check(int x,int y){
  if(getfa(x)==getfa(x+ad)){
    clear=0;
  }
  if(getfa(y)==getfa(y+ad)){
    clear=0;
  }
  if(getfa(ad-1)==getfa(ad)){
    clear=0;
  }
  return ;
}
int pw[1200055];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read();
  pw[0]=1;
  for(int i=1;i<=1200050;i++){
    fa[i]=i;
    pw[i]=1ll*pw[i-1]*2%mod;
  }
  clear=1;
  ans=(n+m+2)*2;
  fa[getfa(n+m+1)]=getfa(n+m+2+n+m+2);
  fa[getfa(n+m+2)]=getfa(n+m+1+n+m+2);
  ans-=2;
  ad=(n+m+2);
  totans[0]+=pw[ans/2-3];
  for(int i=1;i<=q;i++){
    int x=read();
    ::x[i]=x;
    int y=read();
    ::y[i]=y;
    int c=read();
    ::c[i]=c;
    if(x==1&&y==1){
      if(c==0){
      }else{
        clear=0;
      }
      if(clear){
        totans[i]+=pw[ans/2-3]*clear;
      }
      continue;
    }else if(x==1){
      Union(y+n,n+m+c+1);
      Union(y+n+n+m+2,n+m+c+1+n+m+2);
    }else if(y==1){
      Union(x,n+m+c+1);
      Union(x+n+m+2,n+m+c+1+n+m+2);
    }else if(c){
      //x,y+n;
      Union(x,y+n+n+m+2);
      Union(y+n,x+n+m+2);
    }else{
      Union(x,y+n);
      Union(x+n+m+2,y+n+n+m+2);
    }
    check(x,y+n);
    if(clear){
      totans[i]+=clear*pw[ans/2-3];
    }
  }
  for(int i=1;i<=1200050;i++){
    fa[i]=i;
  }
  clear=1;
  ans=(n+m+2)*2;
  fa[getfa(n+m+1)]=getfa(n+m+2+n+m+2);
  fa[getfa(n+m+2)]=getfa(n+m+1+n+m+2);
  ans-=2;
  ad=(n+m+2);
  totans[0]+=pw[ans/2-3];
  totans[0]%=mod;
  for(int i=1;i<=q;i++){
    int x=::x[i];
    int y=::y[i];
    int c=!::c[i];
    if(x==1&&y==1){
      if(c==0){
      }else{
        clear=0;
      }
      if(clear){
        totans[i]+=pw[ans/2-3]*clear;
        totans[i]%=mod;
      }
      continue;
    }else if(x==1){
      Union(y+n,n+m+c+1);
      Union(y+n+n+m+2,n+m+c+1+n+m+2);
    }else if(y==1){
      Union(x,n+m+c+1);
      Union(x+n+m+2,n+m+c+1+n+m+2);
    }else if(c){
      //x,y+n;
      Union(x,y+n+n+m+2);
      Union(y+n,x+n+m+2);
    }else{
      Union(x,y+n);
      Union(x+n+m+2,y+n+n+m+2);
    }
    check(x,y+n);
    if(clear){
      totans[i]+=clear*pw[ans/2-3];
      totans[i]%=mod;
    }
  }
  for(int i=0;i<=q;i++){
    printf("%d\n",totans[i]);
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
