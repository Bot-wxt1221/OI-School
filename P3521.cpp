#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
int cnt;
int lowbit(int x){
  return x&(-x);
}
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
  void clear(int x){
    x+=2;
    while(x<=300000){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}a;
int l[200005];
int r[200005];
int w[200005];
std::vector<int>vec[200005];
int ans;
int dfs(){
  int t=read();
  int cur=++cnt;
  if(t==0){
    l[cur]=dfs();
    r[cur]=dfs();
    if(vec[l[cur]].size()<vec[r[cur]].size()){
      std::swap(vec[cur],vec[r[cur]]);
      for(int i=0;i<vec[l[cur]].size();i++){
        vec[cur].push_back(vec[l[cur]][i]);
      }
    }else{
      std::swap(vec[cur],vec[l[cur]]);
      for(int i=0;i<vec[r[cur]].size();i++){
        vec[cur].push_back(vec[r[cur]][i]);
      }
    }
  }else{
    vec[cur].push_back(t);
    w[cur]=t;
  }
  return cur;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  read();
  dfs();
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
