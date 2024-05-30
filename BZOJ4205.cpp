#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
inline int read();
int s,t;
std::vector<int>edge[500005];
int v[3000005];
int now=1;
int can[3000005];
int used[3000005];
void add(int x,int y,int z){
  v[++now]=y;
  edge[x].push_back(now);
  can[now]=z;
  used[now]=0;
  return ;
}
namespace Dinic{
  std::queue<int>qu;
  int nfir[500005];
  int dep[500005];
  bool bfs(int now){
    memset(dep,0,sizeof(dep));
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(auto i:edge[tt]){
        if(dep[v[i]]||can[i]==used[i]){
          continue;
        }
        dep[v[i]]=dep[tt]+1;
        qu.push(v[i]);
      }
    }
    return dep[t];
  }
  int dfs(int now,int flow){
    if(flow==0||now==t){
      return flow;
    }
    int nflow=0;
    for(int &ii=nfir[now];ii<edge[now].size();ii++){
      int i=edge[now][ii];
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]){
        continue;
      }
      int tt=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(tt==0){
        continue;
      }
      nflow+=tt;
      used[i]+=tt;
      used[i^1]-=tt;
      if(nflow==flow){
        return nflow;
      }
    }
    return nflow;
  }
  int solve(int ans=0){
    while(bfs(s)){
      for(int i=1;i<=t;i++){
        nfir[i]=0;
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
std::vector<int>vec[205];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n1=read();
  int n2=read();
  s=200*200*3*3+n1+n2+1;
  t=s+1;
  now=1;
  for(int i=1;i<=200;i++){
    int ti=i;
    bool cnt=0;
    for(int j=2;j<=200&&ti>1;j++){
      cnt=0;
      while(ti%j==0){
        cnt=1;
        ti/=j;
      }
      if(cnt){
        vec[i].push_back(j);
      }
    }
  }
  for(int i=2;i<=200;i++){
    for(int j=2;j<=200;j++){
      for(int ti=0;ti<vec[i].size()&&vec[i][ti]!=0;ti++){
        for(int tj=0;tj<vec[j].size()&&vec[j][tj]!=0;tj++){
          int vv=(vec[i][ti]-1)*200+vec[j][tj]+200*200;
          int uu=(i-1)*200+j;
          add(uu,vv,0x3f3f3f3f);
          add(vv,uu,0);
          add(uu+200*200*3,vv+200*200*3,0x3f3f3f3f);
          add(vv+200*200*3,uu+200*200*3,0);
          add(uu+200*200*6,vv+200*200*6,0x3f3f3f3f);
          add(vv+200*200*6,uu+200*200*6,0);
          uu=vv;
          vv=(i-1)*200+j+200*200*2;
          add(uu,vv,0x3f3f3f3f);
          add(vv,uu,0);
          add(uu+200*200*3,vv+200*200*3,0x3f3f3f3f);
          add(vv+200*200*3,uu+200*200*3,0);
          add(uu+200*200*6,vv+200*200*6,0x3f3f3f3f);
          add(vv+200*200*6,uu+200*200*6,0);
        }
      }
    }
  }
  for(int i=1;i<=n1;i++){
    int a=read();
    int b=read();
    int c=read();
    add(s,200*200*9+i,1);
    add(200*200*9+i,s,0);
    add(200*200*9+i,(a-1)*200+b,1);
    add((a-1)*200+b,200*200*9+i,0);
    add(200*200*9+i,(a-1)*200+c+200*200*3,1);
    add((a-1)*200+c+200*200*3,200*200*9+i,0);
    add(200*200*9+i,(b-1)*200+c+200*200*6,1);
    add((b-1)*200+c+200*200*6,200*200*9+i,0);
  }
  for(int i=1;i<=n2;i++){
    int a=read();
    int b=read();
    int c=read();
    add(200*200*9+n1+i,t,1);
    add(t,200*200*9+n1+i,0);
    add((a-1)*200+b+200*200*2,200*200*9+n1+i,1);
    add(200*200*9+i+n1,(a-1)*200+b+200*200*2,0);
    add((a-1)*200+c+200*200*2+200*200*3,200*200*9+i+n1,1);
    add(200*200*9+i+n1,(a-1)*200+c+200*200*2+200*200*3,0);
    add((b-1)*200+c+200*200*2+200*200*6,200*200*9+i+n1,1);
    add(200*200*9+i+n1,(b-1)*200+c+200*200*2+200*200*6,0);
  }
  printf("%d",Dinic::solve());
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

