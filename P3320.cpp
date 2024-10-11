#include <iostream>
#include <cstdio>
#include <set>
#define int long long
inline int read();
int fir[100005];
std::set<int>se;
bool vised[100005];
int nxt[200005];
int fa[100005][25];
int dis[100005][25];
int v[200005];
int w[200005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dfn[100005];
int tdfn[100005];
int dep[100005];
int cnt;
void dfs(int now,int faa){
  dfn[now]=++cnt;
  tdfn[cnt]=now;
  dep[now]=dep[faa]+1;
  fa[now][0]=faa;
  for(int i=1;i<=20;i++){
    fa[now][i]=fa[fa[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[fa[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==faa){
      continue;
    }
    dis[v[i]][0]=w[i];
    dfs(v[i],now);
  }
}
int getdis(int x,int y){
  while(dep[x]<dep[y]){
    std::swap(x,y);
  }
  int ans=0;
  if(dep[x]>dep[y]){
    for(int i=19;i>=0;i--){
      if(dep[fa[x][i]]>dep[y]){
        ans+=dis[x][i];
        x=fa[x][i];
      }
    }
  }
  if(dep[x]>dep[y]){
    ans+=dis[x][0];
    x=fa[x][0];
  }
  if(x!=y){
    for(int i=19;i>=0;i--){
      if(fa[x][i]!=fa[y][i]){
        ans+=dis[x][i]+dis[y][i];
        x=fa[x][i];
        y=fa[y][i];
      }
    }
  }
  if(x!=y){
    ans+=dis[x][0]+dis[y][0];
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  int ans=0;
  dfs(1,1);
  for(int i=1;i<=m;i++){
    int x=read();
    if(vised[x]){
      auto tt1=se.lower_bound(dfn[x]);
      auto tt2=tt1;
      int a=-1;
      int b=-1;
      ++tt2;
      if(tt2!=se.end()){
        a=*tt2;
        ans-=getdis(tdfn[*tt2],x);
      }
      if(tt1!=se.begin()){
        tt1--;
        b=*tt1;
        ans-=getdis(tdfn[*tt1],x);
      }
      if(a!=-1&&b!=-1){
        ans+=getdis(tdfn[a],tdfn[b]);
      }
      se.erase(dfn[x]);
      vised[x]=0;
    }else{
      auto tt=se.insert(dfn[x]).first;
      auto tt2=tt;
      int a=-1;
      int b=-1;
      if(tt!=se.begin()){
        tt--;
        a=*tt;
        ans+=getdis(tdfn[*tt],x);
      }
      tt2++;
      if(tt2!=se.end()){
        b=*tt2;
        ans+=getdis(tdfn[*tt2],x);
      }
      if(a!=-1&&b!=-1){
        ans-=getdis(tdfn[a],tdfn[b]);
      }
      vised[x]=1;
    }
    int ad=0;
    if(se.size()>1){
      ad+=getdis(tdfn[*se.begin()],tdfn[*(--se.end())]);
    }
    printf("%lld\n",(ans+ad));
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
