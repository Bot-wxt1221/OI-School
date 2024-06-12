#include <iostream>
#include <cstdio>
inline int read();
int a[305],b[305];
int c[305],d[305];
bool yes[305];
bool yes2[305];
int fa[305];
int tfa[305];
int siz[305];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=2*n;i++){
    fa[i]=i;
    siz[i]=1;
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(getfa(a[i])==getfa(i)){
      continue;
    }
    siz[getfa(i)]+=siz[getfa(a[i])];
    fa[getfa(a[i])]=getfa(i);
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
    if(getfa(b[i]+n)==getfa(i+n)){
      continue;
    }
    siz[getfa(i+n)]+=siz[getfa(b[i]+n)];
    fa[getfa(b[i]+n)]=getfa(i+n);
  }
  int cntt=0;
  for(int i=1;i<=2*n;i++){
    if(fa[i]==i&&siz[i]!=1){
      tfa[fa[i]]=++cntt;
    }
  }
  int mn=n;
  for(int i=0;i<(1<<cntt);i++){
    int cnt=0;
    for(int j=1;j<=n;j++){
      if(j==a[j]){
      }else if(i&(1<<(tfa[getfa(j)]-1))){
        c[j]=a[j];
        if(yes[c[j]]){
          goto end;
        }
        yes[c[j]]=1;
      }else{
        c[j]=j;
        yes[c[j]]=1;
      }
    }
    for(int j=1;j<=n;j++){
      if(j==b[j]){
      }else if(i&(1<<(tfa[getfa(j+n)]-1))){
        d[j]=b[j];
        if(yes2[d[j]]){
          goto end;
        }
        yes2[d[j]]=1;
      }else{
        d[j]=j;
        yes2[d[j]]=1;
      }
      if(d[j]==c[j]){
        cnt++;
      }
    }
    mn=std::min(mn,cnt);
    end:{}
    for(int j=1;j<=n;j++){
      yes[c[j]]=0;
      yes2[d[j]]=0;
    }
  }
  printf("%d",n-mn);
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

