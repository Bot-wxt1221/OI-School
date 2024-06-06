#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
inline int read();
int a[2000005];
std::stack<int>st;
std::priority_queue<int>vec;
int l[2000005];
int inf[2000005];
std::vector<int>qu[2000005];
int fir[2000005];
int cnt=0;
int nxt[4000005];
int v[4000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int rr[4000005];
int ll[4000005];
void build(int l,int r,int fa){
  for(int i=l;i<r;i++){
    if(qu[i].size()!=0){
      cnt++;
      add(fa,cnt);
      ll[cnt]=i;
      int bk=*(--qu[i].end());
      rr[cnt]=bk;
      qu[i].pop_back();
      build(i,bk,cnt);
      i=(bk)-1;
    }
  }
  return ;
}
int dep[2000005];
int mx[2000005];
int bson[2000005];
int siz[2000005];
int fa[2000005];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  mx[now]=std::max(mx[now],dep[now]);
  siz[now]=1;
  ::fa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    mx[now]=std::max(mx[now],mx[v[i]]);
    siz[now]+=siz[v[i]];
    if(mx[v[i]]>mx[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
void dfs2(int now,int fa,int dep){
  if(bson[now]){
    dfs2(bson[now],now,dep+1);
  }else{
    vec.push(dep);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,1);
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
  int d=read();
  int t=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  ll[1]=1;
  rr[1]=n;
  for(int i=1;i<=n;i++){
    while(st.size()>0&&a[st.top()]+(i-st.top())>std::min(t,a[i])){
      st.pop();
    }
    if(st.size()>0){
      l[i]=st.top();
    }
    st.push(i);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(a[i]>t&&l[i]>0){
      ans++;
      qu[std::min(i,l[i])].push_back(std::max(l[i],i));
    }else if(a[i]<=t){
      l[i]=0;
      ans++;
    }else{
      l[i]=0;
    }
  }
  for(int i=1;i<=n+1;i++){
    fir[i]=-1;
    std::sort(qu[i].begin(),qu[i].end());
  }
  build(1,n,++cnt);
  dfs(1,1);
  dfs2(1,1,0);
  while(d>0&&vec.size()>0){
    ans-=vec.top();
    std::cerr<<vec.top()<<std::endl;
    vec.pop();
    d--;
  }
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

