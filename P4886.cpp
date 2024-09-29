#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int w[200005];
int x[100005];
int y[100005];
int now;
bool vised[100005];
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt;
int siz[100005];
int mx[100005];
int mx2,m;
void getsiz(int now,int fa){
  siz[now]=1;
  mx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    getsiz(v[i],now);
    siz[now]+=siz[v[i]];
    mx[now]=std::max(mx[now],siz[v[i]]);
  }
  mx[now]=std::max(mx[now],cnt-siz[now]);
  if(mx2==0||mx[mx2]>mx[now]){
    mx2=now;
  }
}
int dis[100005];
int beg[100005];
void calcdis(int now,int fa,int bg){
  beg[now]=bg;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]]=dis[now]+w[i];
    calcdis(v[i],now,bg==0?v[i]:bg);
  }
  return ;
}
std::vector<int>tmp;
int ans=0;
void dfs(int now,int fa){
  memset(dis,0,sizeof(dis));
  calcdis(now,fa,0);
  tmp.clear();
  int mx=0;
  for(int i=1;i<=m;i++){
    int td=dis[x[i]]+dis[y[i]];
    if(mx<td){
      mx=td;
      tmp.clear();
    }
    if(mx==td){
      tmp.push_back(i);
    }
  }
  vised[now]=1;
  ans=std::min(ans,mx);
  int lst=0;
  for(int i=0;i<tmp.size();i++){
    if(beg[x[tmp[i]]]!=beg[y[tmp[i]]]){
      return ;
    }else{
      if(lst==0){
        lst=beg[x[tmp[i]]];
        if(lst!=beg[x[tmp[i]]]){
          return ;
        }
      }
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]||v[i]!=lst){
      continue;
    }
    mx2=0;
    cnt=siz[v[i]];
    getsiz(v[i],now);
    getsiz(mx2,mx2);
    dfs(mx2,mx2);
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
  m=read();
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
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
  }
  cnt=n;
  mx2=0;
  ans=0x3f3f3f3f;
  getsiz(1,1);
  getsiz(mx2,mx2);
  dfs(mx2,mx2);
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
