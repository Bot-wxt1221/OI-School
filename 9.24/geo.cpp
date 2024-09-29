#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <vector>
#define int long long
inline int read();
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    int ans=0x3f3f3f3f3f3f3f3f;
    while(now>0){
      ans=std::min(ans,tree[now]);
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=1000002){
      tree[x]=std::min(tree[x],y);
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
int ans[1000005];
std::set<int>se;
std::pair<int,int> pa[1000005];
int w[1000005];
int h[1000005];
std::vector<std::pair<std::pair<int,int>,int> >que;
std::vector<std::pair<std::pair<int,int>,int> >vec;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  memset(aa.tree,0x3f,sizeof(aa.tree));
  int q=read();
  for(int i=1;i<=n;i++){
    w[i]=read();
    h[i]=read();
    pa[i].first=h[i];
    pa[i].second=i;
  }
  std::sort(pa+1,pa+n+1);
  for(int i=1;i<=n;i++){
    auto ret=se.insert(pa[i].second).first;
    auto tt=ret;
    if(ret!=se.begin()){
      vec.push_back({{*(--tt),*ret},0});
    }
    tt=ret;
    if((++tt)!=se.end()){
      vec.push_back({{*ret,*(tt)},0});
    }
  }
  for(int i=0;i<vec.size();i++){
    vec[i].second=(w[vec[i].first.second]-w[vec[i].first.first])*(h[vec[i].first.second]+h[vec[i].first.first]);
  }
  std::sort(vec.begin(),vec.end());
  std::reverse(vec.begin(),vec.end());
  for(int i=1;i<=q;i++){
    int l=read();
    que.push_back({{l,read()},i});
  }
  int cur=0;
  std::sort(que.begin(),que.end());
  std::reverse(que.begin(),que.end());
  for(int i=0;i<que.size();i++){
    while(cur<vec.size()&&vec[cur].first.first>=que[i].first.first){
      aa.mod(vec[cur].first.second,vec[cur].second);
      cur++;
    }
    ans[que[i].second]=aa.query(que[i].first.second);
  }
  for(int i=1;i<=q;i++){
    printf("%lld\n",ans[i]);
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
