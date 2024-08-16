#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
inline int read();
int fir[50005];
int nxt[100005];
int v[100005];
int seq[50005];
int w[100005];
std::vector<std::pair<int,int> >vec;
std::vector<int>yes;
std::vector<int>fail;
int now;
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  w[now]=z;
  return ;
}
int dep[50005];
bool done[50005];
bool leaf[50005];
bool need[50005];
int to[50005][20];
int m;
bool cmp(int x,int y){
  return dep[x]==dep[y]?x<y:dep[x]<dep[y];
}
void dfs2(int now,int fa,int tp){
  if(leaf[now]){
    need[tp]=1;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||done[v[i]]){
      continue;
    }
    dfs2(v[i],now,tp==0?v[i]:tp);
  }
  return ;
}
bool check(int x){
  yes.clear();
  fail.clear();
  vec.clear();
  memset(done,0,sizeof(done));
  memset(need,0,sizeof(need));
  for(int i=1;i<=m;i++){  
    int cur=seq[i];
    for(int j=19;j>=0;j--){
      if(dep[seq[i]]-dep[to[cur][j]]<=x&&to[cur][j]!=1){
        cur=to[cur][j];
      }
    }
    int son=cur;
    if(dep[seq[i]]<=x){
      cur=1;
    }
    if(cur==1){
      vec.push_back(std::make_pair(x-dep[seq[i]],son));
    }else{
      done[cur]=1;
    }
  }
  std::sort(vec.begin(),vec.end());
  bool ans=1;
  dfs2(1,1,0);
  for(int i=0;i<vec.size();i++){
    if(done[vec[i].second]==0&&need[vec[i].second]){
      done[vec[i].second]=1;
    }else{
      yes.push_back(vec[i].first);
    }
  }
  for(int i=fir[1];i!=-1;i=nxt[i]){
    if(done[v[i]]==0&&need[v[i]]){
      fail.push_back(v[i]);
    }
  }
  std::sort(fail.begin(),fail.end(),cmp);
  int curyes=0;
  for(int i=0;i<fail.size();i++){
    bool ok=0;
    while(curyes<yes.size()){
      if(yes[curyes]>=dep[fail[i]]){
        ok=1;
        curyes++;
        break;
      }
      curyes++;
    }
    if(ok==0){
      ans=0;
      break;
    }
  }
  return ans;
}
void dfs(int now,int fa){
  to[now][0]=fa;
  leaf[now]=1;
  for(int i=1;i<20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    leaf[now]=0;
    dep[v[i]]=dep[now]+w[i];
    dfs(v[i],now);
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
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  m=read();
  for(int i=1;i<=m;i++){
    seq[i]=read();
  }
  int l=0,r=0x3f3f3f3f;
  dfs(1,1);
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }
  check(0);
  for(int i=l;i<=r;i++){
    if(check(i)){
      printf("%d",i);
      return 0;
    }
  }
  printf("-1");
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
