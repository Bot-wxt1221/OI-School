#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
inline int read();
int s,t;
int fir[105];
bool ignore[50005];
int nxt[50005];
int v[50005];
int now;
int u[50005];
int can[50005];
int used[50005];
void add(int x,int y,int z){
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  return ;
}
std::vector<std::pair<int,int> >bk;
namespace Dinic{
  std::queue<int>qu;
  int nfir[100005];
  int dep[100005];
  bool bfs(int now){
    for(int i=1;i<=t;i++){
      dep[i]=0;
    }
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(int i=fir[tt];i!=-1;i=nxt[i]){
        if(dep[v[i]]||can[i]==used[i]||ignore[i]){
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
    for(int &i=nfir[now];i!=-1;i=nxt[i]){
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]||ignore[i]){
        continue;
      }
      int tt=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(tt==0){
        continue;
      }
      nflow+=tt;
      used[i]+=tt;
      bk.push_back(std::make_pair(i,tt));
      used[i^1]-=tt;
      if(nflow==flow){
        return nflow;
      }
    }
    return nflow;
  }
  int solve(int ans=0){
    bk.clear();
    while(bfs(s)){
      for(int i=1;i<=t;i++){
        nfir[i]=fir[i];
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};

std::vector <std::pair<int,int> > anss;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),e,c;
  e=read();
  int TT=0;
  c=read();
  do{
    memset(ignore,0,sizeof(ignore));
    printf("Case %d: ",++TT);
    s=1;
    t=n;
    now=1;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    for(int i=1;i<=e;i++){
      int u=read();
      int v=read();
      int cap=read();
      add(u,v,cap);
      add(v,u,0);
    }
    int ans=Dinic::solve();
    int nnow=0;
    if(ans>=c){
      printf("possible\n");
      goto end;
    }
    anss.clear();
    nnow=now;
    for(int i=2;i<=nnow;i++){
      if(used[i]==can[i]&&can[i]!=0){
        add(u[i],v[i],0x3f3f3f3f);
        add(v[i],u[i],0);
      }
      if(Dinic::solve()+ans>=c){
        anss.push_back(std::make_pair(u[i],v[i]));
      }
      for(int j=0;j<bk.size();j++){
        used[bk[j].first]-=bk[j].second;
        used[bk[j].first^1]+=bk[j].second;
      }
      if(used[i]==can[i]&&can[i]!=0){
        ignore[now]=ignore[now-1]=1;
      }
    }
    if(anss.size()==0){
      printf("not possible\n");
      goto end;
    }
    std::sort(anss.begin(),anss.end());
    printf("possible option:(%d,%d)",anss[0].first,anss[0].second);
    for(int i=1;i<anss.size();i++){
      printf(",(%d,%d)",anss[i].first,anss[i].second);
    }
    printf("\n");
    end:{}
    n=read();
    e=read();
    c=read();
  }while(e!=0||c!=0||n!=0);
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


