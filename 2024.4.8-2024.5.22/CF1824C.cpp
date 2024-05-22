#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
inline int read();
std::vector<int>vec[100005];
int siz[200005];
int f[200005];
int v[200005];
int a[200005];
std::set<int>se[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  vec[x].push_back(now);
  return ;
}
void dfs(int now,int fa,int op){
  std::map<int,int>mp;
  siz[now]=1;
  mp.clear();
  bool leaf=1;
  for(int ii=0;ii!=vec[now].size();ii++){
    int i=vec[now][ii];
    if(v[i]==fa){
      continue;
    }
    leaf=0;
    dfs(v[i],now,op^a[v[i]]);
    f[now]+=f[v[i]]+1;
    siz[now]+=siz[v[i]];
  }
  if(leaf){
    se[now].insert(op);
    f[now]=0;
  }else{
    for(int ii=0;ii!=vec[now].size();ii++){
      int i=vec[now][ii];
      if(v[i]==fa){
        continue;
      }
      if(se[now].size()<se[v[i]].size()){
        std::swap(se[now],se[v[i]]);
      }
      for(auto j=se[v[i]].begin();j!=se[v[i]].end();j++){
        if(se[now].count(*j)){
          mp[*j]++;
        }else{
          se[now].insert(*j);
        }
      }
    }
    if(mp.size()==0){
      f[now]--;
      return ;
    }
    int mx=0;
    for(auto j=mp.begin();j!=mp.end();j++){
      mx=std::max(mx,j->second);
    }
    f[now]-=(mx+1);
    se[now].clear();
    for(auto j=mp.begin();j!=mp.end();j++){
      if(j->second==mx){
        se[now].insert(j->first);
      }
    }
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
    a[i]=read();
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
  }
  dfs(1,1,a[1]);
  printf("%d",f[1]+(se[1].count(0)==0));
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

