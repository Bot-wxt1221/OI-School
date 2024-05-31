#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
int fir[105];
int nxt[205];
int v[205];
int w[205];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int fa[65];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int tfa[65],tto[65];
int dep[105];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    tto[v[i]]=w[i];
    tfa[v[i]]=now;
    dfs(v[i],now);
  }
  return ;
}
int a[65],b[65];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("decoration.in","r",stdin);
  freopen("decoration.out","w",stdout);
  #endif
  int n=read(),m,k;
  m=read();
  k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y,i);
    add(y,x,i);
  }
  for(int i=1;i<=m;i++){
    a[i]=read();
    b[i]=read();
  }
  dfs(1,1);
  int tans=0;
  for(int i=0;i<(1<<m);i++){
    for(int j=1;j<n;j++){
      fa[j]=j;
    }
    int tt=1;
    for(int j=1;j<=m;j++){
      if((1<<(j-1))&i){
        tt*=-1;
        int ta=a[j];
        int tb=b[j];
        int pre=0;
        while(ta!=tb){
          if(dep[ta]<dep[tb]){
            std::swap(ta,tb);
          }
          if(pre!=0){
            fa[getfa(tto[ta])]=getfa(pre);
          }
          pre=tto[ta];
          ta=tfa[ta];
        }
      }
    }
    int cnt=0;
    for(int j=1;j<n;j++){
      if(getfa(j)==j){
        cnt++;
      }
    }
    tans+=pow(k,cnt)*tt;
    tans%=mod;
  }
  printf("%lld",(tans+mod)%mod);
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

