#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
std::vector<int>vec2[200005];
std::vector<std::pair<int,int> >vec[200005];
int lowbit(int x){
  return x&(-x);
}
#define MAXN 300000
class node{
  public:
    int fa[MAXN+5];
    int getfa(int x){
      return x==fa[x]?x:fa[x]=getfa(fa[x]);
    }
    bool query(int x,int y){
      return getfa(x)==getfa(y);
    }
    node(int n){
      for(int i=1;i<=n;i++){
        fa[i]=i;
      }
    }
    node(){
      return ;
    }
}l,r;
class BIT{
public:
  int tree[300005];
  int query(int now){
    now+=2;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=2;
    while(x<=300000){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}a;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    vec2[read()].push_back(i);
  }
  int m=read();
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    vec[y].push_back(std::make_pair(x,z));
  }
  l=r=node(n+2);
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<vec[i].size();j++){
      int v=a.query(vec[i][j].first);
      if(v>=vec[i][j].second){
        ans+=vec[i][j].second;
      }else{
        ans+=v;
        a.mod(l.getfa(vec[i][j].first+1),vec[i][j].second-v);
        a.mod(r.getfa(vec[i][j].first+1)-1,v-vec[i][j].second);
      }
    }
    for(int j=0;j<vec2[i].size();j++){
      l.fa[vec2[i][j]+1]=l.getfa(vec2[i][j]);
      r.fa[vec2[i][j]+1]=r.getfa(vec2[i][j]+2);
    }
  }
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
