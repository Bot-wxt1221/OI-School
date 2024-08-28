#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
inline int read();
int exist[30][2];
int fir[100005];
int nxt[200005];
int v[200005];
int w[100005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool vised[100005];
int tot;
int siz[100005];
int mxx[100005];
int bson;
void calcsiz(int now,int fa){
  siz[now]=1;
  mxx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    siz[now]+=siz[v[i]];
    mxx[now]=std::max(mxx[now],siz[v[i]]);
  }
  mxx[now]=std::max(mxx[now],tot-siz[now]);
  if(bson==0||mxx[bson]>mxx[now]){
    bson=now;
  }
  return ;
}
long long ans=0;
void update(int num,int op){
  for(int i=0;i<25;i++){
    int to=0;
    if(num&(1<<i)){
      to=1;
    }
    ans+=1ll*(1<<i)*exist[i][!to]*(1-op);
    exist[i][to]+=op;
  }
  return ;
}
int nww;
void add(int now,int fa,int dis){
  update(dis^nww,1);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    add(v[i],now,dis^w[v[i]]);
  }
  return ;
}
void calcdis(int now,int fa,int dis){
  update(dis,0);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcdis(v[i],now,dis^w[v[i]]);
    if(now==fa){
      add(v[i],now,dis^w[v[i]]);
    }
  }
  return ;
}
void dfs(int now,int fa){
  vised[now]=1;
  for(int i=0;i<25;i++){
    exist[i][0]=1;
    exist[i][1]=0;
  }
  nww=w[now];
  calcdis(now,now,w[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    bson=0;
    tot=siz[v[i]];
    calcsiz(v[i],now);
    calcsiz(bson,bson);
    dfs(bson,bson);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    w[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  tot=n;
  calcsiz(1,1);
  calcsiz(bson,bson);
  dfs(bson,bson);
  printf("%lld",ans);
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
