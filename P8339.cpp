#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[2000005];
int t[2000005];
int c[2000005];
int nxt[2000005];
int v[2000005];
int dep[2000005];
int now;
int to[2000005][30];
std::vector<int>vec2;
std::vector<int> lca[2000005],lson[2000005];
std::vector<std::pair<int,int> >ques[2000005];
int ans[2000005];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[2000005];
  int query(int now){
    now++;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x++;
    while(x<=2000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
std::vector<int>vec[2000005],to2[2000005],del[2000005];
namespace ng{
  int now,to,cur=2000000;
  int fir[2000005];
  int nxt[4000005];
  int v[4000005];
  void add(int x,int y){
    v[++now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  void dfs2(int now,int fa,int num){
    if(t[now]==-1&&num==0&&c[now]==c[to]){
      //yes
      to2[to].push_back(now);
      return ;
    }
    num=std::max(num,0);
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      dfs2(v[i],now,num+t[v[i]]*(c[v[i]]==c[to]));
    }
    return ;
  }
};
int cnt;
int l[1000005];
int r[1000005];
void dfs(int now,int fa){
  ng::add(now,vec[c[now]].back());
  ng::add(vec[c[now]].back(),now);
  l[now]=++cnt;
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<30;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  vec[c[now]].push_back(now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    ng::fir[ng::cur]=-1;
    ng::add(now,ng::cur);
    ng::add(ng::cur,now);
    vec[c[now]].push_back(ng::cur);
    ng::cur--;
    dfs(v[i],now);
    vec[c[now]].erase(vec[c[now]].end()-1);
  }
  vec[c[now]].erase(vec[c[now]].end()-1);
  r[now]=cnt;
  return ;
}
int son=0;
int getlca(int x,int y){
  if(dep[x]>dep[y]){
    std::swap(x,y);
  }
  son=y;
  while(dep[x]<dep[y]){
    int i=29;
    for(i=29;i>0;i--){
      if(dep[x]<dep[to[y][i]]){
        break;
      }
    }
    son=y;
    y=to[y][i];
  }
  while(x!=y){
    int i=29;
    for(i=29;i>0;i--){
      if(to[x][i]!=to[y][i]){
        break;
      }
    }
    x=to[x][i];
    son=y;
    y=to[y][i];
  }
  return x;
}

void dfs3(int now,int fa){
  for(int i=0;i<to2[now].size();i++){
    int lca=::lca[now][i];
    son=lson[now][i];
    if(lca==to2[now][i]){
      aa.mod(1,1);
      aa.mod(l[son],-1);
      aa.mod(r[son]+1,1);
    }else if(lca!=now){
      aa.mod(l[to2[now][i]],1);
      aa.mod(r[to2[now][i]]+1,-1);
    }else{
      del[son].push_back(to2[now][i]);
    }
  }
  for(int i=0;i<ques[now].size();i++){
    ans[ques[now][i].second]+=aa.query(l[ques[now][i].first]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    for(int j=0;j<del[v[i]].size();j++){
      aa.mod(l[del[v[i]][j]],-1);
      aa.mod(r[del[v[i]][j]]+1,1);
    }
    dfs3(v[i],now);
    for(int j=0;j<del[v[i]].size();j++){
      aa.mod(l[del[v[i]][j]],1);
      aa.mod(r[del[v[i]][j]]+1,-1);
    }
  }
  for(int i=0;i<to2[now].size();i++){
    int lca=::lca[now][i];
    son=lson[now][i];
    if(lca==to2[now][i]){
      aa.mod(1,-1);
      aa.mod(l[son],1);
      aa.mod(r[son]+1,-1);
    }else if(lca!=now){
      aa.mod(l[to2[now][i]],-1);
      aa.mod(r[to2[now][i]]+1,1);
    }else{
    }
  }
  return ;
}
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    t[i]=read();
    if(t[i]==2){
      t[i]=-1;
    }
    c[i]=read();
    ng::fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    ng::fir[i+n]=-1;
    vec[i].push_back(i+n);
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  for(int i=1;i<=n;i++){
    if(t[i]==1){
      ng::to=i;
      ng::dfs2(i,i,1);
    }
  }
  for(int i=1;i<=m;i++){
    int s=read();
    int e=read();
    ques[s].push_back(std::make_pair(e,i));
  }
  for(int now=1;now<=n;now++){
    for(int i=0;i<to2[now].size();i++){
      int lca=getlca(now,to2[now][i]);
      ::lca[now].push_back(lca);
      lson[now].push_back(son);
      if(lca==to2[now][i]){
      }else if(lca!=now){
      }else{
        aa.mod(l[to2[now][i]],1);
        aa.mod(r[to2[now][i]]+1,-1);
      }
    }
  }
  dfs3(1,1);
  for(int i=1;i<=m;i++){
    printf("%d\n",ans[i]);
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
