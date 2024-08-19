#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[300005];
int nxt[600005];
int v[600005];
int w[600005];
int a[300005];
int dep[300005];
int cnt[300005];
int dfn[300005];
int b[300005];
int c[300005];
int now,m;
int tfa[300005];
int to[300005][22];
int qdep[300005];
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnttt=0;
void dfs(int now,int fa){
  dfn[++cnttt]=now;
  to[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<22;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    tfa[v[i]]=i;
    qdep[v[i]]=qdep[now]+w[i];
    dfs(v[i],now);
  }
  return ;
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  for(int i=21;i>=0;i--){
    if(dep[to[x][i]]>dep[y]){
      x=to[x][i];
    }
  }
  if(dep[x]>dep[y]){
    x=to[x][0];
  }
  for(int i=21;i>=0;i--){
    if(to[x][i]!=to[y][i]){
      x=to[x][i];
      y=to[y][i];
    }
  }
  if(x!=y){
    x=to[x][0];
    y=to[y][0];
  }
  return x;
}
int n;
bool check(int ans){
  memset(cnt,0,sizeof(cnt));
  int mn=0;
  int cntt=0;
  for(int i=1;i<=m;i++){
    int leng;
    leng=qdep[a[i]]+qdep[b[i]]-qdep[c[i]]*2;
    if(leng<=ans){
      continue;
    }
    cntt++;
    cnt[a[i]]++;
    cnt[b[i]]++;
    cnt[c[i]]-=2;
    mn=std::max(mn,leng-ans);
  }
  for(int i=n;i>=1;i--){
    cnt[to[dfn[i]][0]]+=cnt[dfn[i]];
  }
  for(int ii=2;ii<=n;ii++){
    int i=tfa[ii];
    if(w[i]<mn){
      continue;
    }
    if(cnt[ii]!=cntt){
      continue;
    }
    return 1;
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    int c=read();
    add(a,b,c);
    add(b,a,c);
  }
  dfs(1,1);
  for(int i=1;i<=m;i++){
    a[i]=read();
    b[i]=read();
    c[i]=getlca(a[i],b[i]);
  }
  int l=0,r=0x3f3f3f3f;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }
  for(int i=l;i<=r;i++){
    if(check(i)){
      printf("%d",i);
      return 0;
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
