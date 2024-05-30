#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
inline int lowbit(int x){
  return x&(-x);
}
inline void print(int n){
  static char tt[35];
  int ttt=0;
  while(n){
    tt[++ttt]=n%10;
    n/=10;
  }
  if(ttt==0){
    tt[++ttt]=0;
  }
  while(ttt){
    putchar('0'+tt[ttt]);
    ttt--;
  }
  putchar('\n');
  return ;
}
class BIT{
public:
  std::vector<int>mp;
  void add(int x,int y){
    x++;
    while(x<mp.size()){
      mp[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  int query(int x){
    x++;
    if(x<=0){
      return 0;
    }
    x=std::min(x,int(mp.size()-1));
    int ans=0;
    while(x>0){
      ans+=mp[x];
      x-=lowbit(x);
    }
    return ans;
  }
}dist[100005],ch[100005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int val[100005];
namespace nw{
  int fir[100005];
  int nxt[100005];
  int v[100005];
  int now;
};
int siz[100005];
int maxx[100005];
bool vised[100005];
int sum;
int rt;
void calcsiz(int now,int fa){
  siz[now]=1;
  maxx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    maxx[now]=std::max(maxx[now],siz[v[i]]);
    siz[now]+=siz[v[i]];
  }
  maxx[now]=std::max(maxx[now],sum-siz[now]);
  if(maxx[now]<maxx[rt]||rt==0){
    rt=now;
  }
  return ;
}
int top;
int dis[100005];
int tp[100005];
void calcdis1(int now,int fa){
  dist[top].add(dis[now],val[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    dis[v[i]]=dis[now]+1;
    calcdis1(v[i],now);
  }
  return ;
}
void calcdis2(int now,int fa){
  ch[top].add(dis[now],val[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    dis[v[i]]=dis[now]+1;
    calcdis2(v[i],now);
  }
  return ;
}
int dep[100005];
int ccc;
void dfs(int now,int fa){
  vised[now]=1;
  top=now;
  dis[now]=0;
  calcdis1(now,fa);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    rt=0;
    sum=siz[v[i]];
    calcsiz(v[i],now); 
    calcsiz(rt,0);
    top=rt;
    dist[rt].mp.resize(siz[rt]+2);
    ch[rt].mp.resize(siz[rt]+2);
    dis[v[i]]=1;
    calcdis2(v[i],-1);
    tp[rt]=now;
    dep[rt]=dep[now]+1;
    dfs(rt,now);
  }
  return ;
}
int to[100005][35];
int tdis[100005][35];
int lcadep[100005];
void dfs2(int now,int fa){
  lcadep[now]=lcadep[fa]+1;
  to[now][0]=fa;
  if(now!=fa){
    tdis[now][0]=1;
  }else{
    tdis[now][0]=0;
  }
  for(int i=1;i<=16;i++){
    to[now][i]=to[to[now][i-1]][i-1];
    tdis[now][i]=tdis[now][i-1]+tdis[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
inline int dislca(int x,int y){
  if(lcadep[x]>lcadep[y]){
    std::swap(x,y);
  }
  int dis=0;
  int i=16;
  while(lcadep[x]<lcadep[y]){
    for(;i>0;i--){
      if(lcadep[x]<lcadep[to[y][i]]){
        break;
      }
    }
    dis+=tdis[y][i];
    y=to[y][i];
  }
  i=16;
  while(x!=y){
    for(;i>0;i--){
      if(to[x][i]!=to[y][i]){
        break;
      }
    }
    dis+=tdis[y][i];
    dis+=tdis[x][i];
    x=to[x][i];
    y=to[y][i];
  }
  return dis;
}
std::vector<std::pair<int,int> >ttt;
void dfs11(int now,int fa,int dep){
  ttt.push_back(std::make_pair(dep,now));
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs11(v[i],now,dep+1);
  }
  return ;
}
int dd[100005][55];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    val[i]=0;
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
  }
  dfs11(1,1,0);
  std::sort(ttt.begin(),ttt.end());
  sum=n;
  calcsiz(1,1);
  calcsiz(rt,-1);
  int rtt=rt;
  ch[rt].mp.resize(n+2);
  dist[rt].mp.resize(n+2);
  dfs(rt,-1);
  int lstans=0;
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    int j=i;
    while(j!=rtt){
      dd[i][dep[i]-dep[j]]=dislca(i,j);
      j=tp[j];
    }
    dd[i][dep[i]-dep[j]]=dislca(i,j);
    j=tp[j];
  }
  long long tans=0;
  for(int i=1;i<=n;i++){
    int x=ttt[i-1].second;
    int y=k;
    lstans=dist[x].query(y);
    int j=x;
    while(j!=rtt){
      int &diss=dd[x][dep[x]-dep[tp[j]]];
      lstans+=dist[tp[j]].query(y-diss);
      lstans-=ch[j].query(y-diss);
      j=tp[j];
    }
    int &diss=dd[x][dep[x]-dep[tp[j]]];
    lstans-=ch[j].query(y-diss);
    j=tp[j];
//    print(lstans);
    tans+=1ll*lstans*(lstans-1)/2;
    y=1;
    dist[x].add(0,y-val[x]);
    j=x;
    while(j!=rtt){
      int &diss=dd[x][dep[x]-dep[tp[j]]];
      dist[tp[j]].add(diss,y-val[x]);
      ch[j].add(diss,y-val[x]);
      j=tp[j];
    }
    val[x]=y;
  }
  printf("%lld",tans);
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
