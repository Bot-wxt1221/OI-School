#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
inline int read();
int fir[200005];
int siz[200005];
int mxson[200005];
int c[200005];
int nxt[400005];
int v[400005];
int now;
int fa[20][200005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int getnum(int x,int y){
  return (x-1)*23+y+1;
}
namespace nw{
int in[5000005];
int out[5000005];
int fir[5000005];
int nxt[20000005];
int dp[5000005];
int v[20000005];
int now;
void add(int x,int y){
  v[++now]=y;
  in[y]++;
  out[x]++;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int num[5000005];
int dfn[5000005];
int low[5000005];
bool instack[5000005];
int cnt=0;
int ans=0;
std::stack<int>st;
std::vector<int>temp;
void dfs(int now,int fa){
  dfn[now]=low[now]=++cnt;
  st.push(now);
  instack[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(!dfn[v[i]]){
      dfs(v[i],now);
      low[now]=std::min(low[now],low[v[i]]);
    }else if(instack[v[i]]){
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  int tans=0;
  bool yes=1;
  if(dfn[now]<=low[now]){
    temp.clear();
    while(st.size()>0&&st.top()!=now){
      instack[st.top()]=0;
      tans+=(st.top()%23==0);
      num[st.top()]=now;
      temp.push_back(st.top());
      st.pop();
    }
    instack[now]=0;
    tans+=(now%23==0);
    num[now]=now;
    temp.push_back(now);
    st.pop();
    for(int i=0;i<temp.size();i++){
      for(int j=fir[temp[i]];j!=-1;j=nxt[j]){
        if(num[v[j]]!=now){
          yes=0;
          break;
        }
      }
      if(yes==0){
        break;
      }
    }
    if(tans>0&&yes&&temp.size()>1){
      ans=std::min(ans,tans-1);
    }
  }
  return ;
}
int getans(){
  ans=0x3f3f3f3f;
  for(int i=1;i<=5000000;i++){
    if(dfn[i]==0){
      dfs(i,i);
    }
  }
  return ans;
}
};

void dfs(int now,int fa){
  ::fa[0][now]=fa;
  siz[now]=1;
  nw::add(getnum(now,1),getnum(now,0));
  for(int i=1;i<20;i++){
    ::fa[i][now]=::fa[i-1][::fa[i-1][now]];
    nw::add(getnum(now,i+1),getnum(now,i));
    nw::add(getnum(now,i+1),getnum(::fa[i-1][now],i));
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(siz[mxson[now]]<siz[v[i]]){
      mxson[now]=v[i];
    }
  }
  return ;
}
int mx[200005];
int csiz[200005];
int dep[200005];
std::map<int,int>vec[200005];
void dfs2(int now,int fa){
  dep[now]=dep[fa]+1;
  if(mxson[now]){
    dfs2(mxson[now],now);
    std::swap(vec[now],vec[mxson[now]]);
  }
  vec[now][c[now]]++;
  if(vec[now][c[now]]==csiz[c[now]]){
    if(mx[c[now]]==0){
      mx[c[now]]=now;
    }
  }
  std::cerr<<siz[mxson[now]]<<std::endl;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==mxson[now]){
      continue;
    }
    dfs2(v[i],now);
    for(auto j=vec[v[i]].begin();j!=vec[v[i]].end();j++){
      vec[now][j->first]+=j->second;
      if(vec[now][j->first]==csiz[j->first]){
        if(mx[j->first]==0){
          mx[j->first]=now;
        }
      }
    }
  }
  return ;
}
void solve(int n){
  int ori=getnum(n,0);
  int tp=mx[c[n]];
  n=fa[0][n];
  nw::add(ori,getnum(tp,0));
  if(dep[tp]>=dep[n]){
    return ;
  }
  int pre=19;
  while(n!=tp){
    int ti=0;
    for(int i=pre;i;i--){
      if(dep[fa[i][n]]>dep[tp]){
        ti=i;
        pre=i;
        break;
      }
    }
    nw::add(ori,getnum(n,ti));
    n=fa[ti][n];
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("city.in","r",stdin);
  freopen("city.out","w",stdout);
  #endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  memset(nw::fir,-1,sizeof(nw::fir));
  for(int i=1;i<=n;i++){
    c[i]=read();
    nw::add(getnum(i,0),getnum(c[i],22));
    nw::add(getnum(c[i],22),getnum(i,0));
    csiz[c[i]]++;
  }
  dfs(1,1);
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    solve(i);
  }
  printf("%d",nw::getans());
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
