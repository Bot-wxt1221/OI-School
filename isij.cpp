#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
inline int read();
std::map<int,int>mp;
int fir[400005];
int nxt[800005];
int v[800005];
bool vised[400005];
int z[800005];
int now;
std::pair<int,int> qu[400005];
void add(int x,int y,int w){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  z[now]=w;
  return ;
}
bool yes;
long long depth[400005];
void dfs(int now,int fa,long long dep){
  if(vised[now]){
    if(depth[now]==dep){
      return ;
    }else{
      yes=0;
      return ;
    }
  }
  depth[now]=dep;
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dep+z[i]);
  }
  return ;
}
int fa[400005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int k=read();
    int cnt=0;
    mp.clear();
    now=0;
    yes=1;
    memset(vised,0,sizeof(vised));
    memset(fir,-1,sizeof(fir));
    memset(depth,0,sizeof(depth));
    for(int i=1;i<=k;i++){
      int x=read();
      if(mp[x]==0){
        mp[x]=++cnt;
      }
      x=mp[x];
      int y=read();
      if(mp[y]==0){
        mp[y]=++cnt;
      }
      y=mp[y];
      int c=read();
      add(x,y,c);
      add(y,x,-c);
    }
    for(int i=1;i<=cnt;i++){
      if(vised[i]==0){
        dfs(i,i,0);
      }
    }
    if(yes==0){
      printf("No\n");
      continue;
    }
    for(int i=1;i<=cnt;i++){
      qu[i]={-depth[i],i};
    }
    std::sort(qu+1,qu+cnt+1);
    for(int ii=1;ii<=cnt;ii++){
      int i=qu[ii].second;
      fa[i]=i;
      for(int j=fir[i];j!=-1;j=nxt[j]){
        if(z[j]<0){
          continue;
        }
        int fx=getfa(v[j]);
        if(depth[fx]==depth[i]&&fx!=i){
          yes=0;
        }
        fa[fx]=getfa(i);
      }
    }
    if(yes==0){
      printf("No\n");
    }else{
      printf("Yes\n");
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
