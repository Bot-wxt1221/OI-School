#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int minldep[500005];
void dfs2(int now,int fa){
  minldep[now]=0x3f3f3f3f;
  bool leaf=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
    minldep[now]=std::min(minldep[now],minldep[v[i]]+1);
    leaf=0;
  }
  if(leaf){
    minldep[now]=1;
  }
  return ;
}
int ans=0;
void dfs(int now,int fa){
  if(now==1){
    int tt=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(minldep[v[i]]>minldep[tt]){
        tt=v[i];
      }
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(tt==v[i]||v[i]==fa){
        continue;
      }
      dfs(v[i],now);
      ans=std::max(ans,minldep[v[i]]+1);
    }
    if(tt!=0){
      dfs(tt,now);
      ans=std::max(ans,minldep[tt]);
    }
  }else{
    int tt=0,tt2=0x3f3f3f3f;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(minldep[v[i]]<tt2){
        tt=v[i];
        tt2=minldep[v[i]];
      }
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(tt==v[i]||v[i]==fa){
        continue;
      }
      dfs(v[i],now);
      ans=std::max(ans,minldep[v[i]]+1);
    }
    if(tt!=0){
      dfs(tt,now);
    }
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("flag.in","r",stdin);
  freopen("flag.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    now=0;
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    ans=0;
    dfs2(1,1);
    dfs(1,1);
    printf("%d\n",ans);
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

