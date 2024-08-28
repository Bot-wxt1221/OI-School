#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
inline int read();
std::vector<int>vec[3000005],temp;
bool mark[100005],mark2[100005];
int fin[100005];
int fir[100005];
int u[200005];
int v[200005];
int nxt[200005];
int w[200005];
int k[200005];
int d[200005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  u[now]=x;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ans;
class Union{
public:
  std::stack<std::pair<int,std::pair<int,int> > >st;
  std::stack<std::pair<int,int> >st2;
  int fa[20005];
  int siz[20005];
  int getfa(int x){
    return x==fa[x]?x:getfa(fa[x]);
  }
  Union(){
    for(int i=1;i<=20000;i++){
      fa[i]=i;
      siz[i]=1;
    }
    return ;
  }
  void fallback(int now){
    while(st.size()>0&&st.top().first>=now){
      fa[st.top().second.first]=st.top().second.second;
      siz[st2.top().first]=st2.top().second;
      st.pop();
      st2.pop();
    }
  }
  bool merge(int now,int x,int y){
    int fx=getfa(x);
    int fy=getfa(y);
    if(fx==fy){
      return 0;
    }
    if(siz[fx]>siz[fy]){
      std::swap(x,y);
      std::swap(fx,fy);
    }
    st.push({now,{fx,fa[fx]}});
    fa[fx]=fy;
    st2.push({fy,siz[fy]});
    siz[fy]+=siz[fx];
    return 1;
  }
}a,b;
bool cmp(int x,int y){
  return w[x]<w[y];
}
long long eva(int now,int l,int r,int dep){
  long long ad=0;
  for(int i=0;i<vec[dep].size();i++){
    if(b.merge(now,u[vec[dep][i]],v[vec[dep][i]])){
      mark2[vec[dep][i]]=1;
    }
  }
  b.fallback(now);
  for(int i=l;i<=r;i++){
    b.merge(now,u[k[i]],v[k[i]]);
  }
  for(int i=0;i<vec[dep].size();i++){
    if(b.merge(now,u[vec[dep][i]],v[vec[dep][i]])){
      mark[vec[dep][i]]=1;
      a.merge(now,u[vec[dep][i]],v[vec[dep][i]]);
      ad+=w[vec[dep][i]];
    }
  }
  b.fallback(now);
  for(int i=0;i<vec[dep].size();i++){
    if(mark[vec[dep][i]]){
      b.merge(now,u[vec[dep][i]],v[vec[dep][i]]);
    }
  }
  for(int i=0;i<vec[dep].size();i++){
    if(!mark[vec[dep][i]]&&mark2[vec[dep][i]]){
      vec[dep+1].push_back(vec[dep][i]);
    }
    mark[vec[dep][i]]=mark2[vec[dep][i]]=0;
  }
  return ad;
}
long long anss[500005];
int dym[400005];
void cdq(int now,int l,int r,int dep,long long ans){
  int mid=(l+r)/2;
  if(l==r){
    w[k[l]]=d[l];
    bool check=0;
    long long ret=0;
    for(int i=0;i<vec[dep].size();i++){
      if(w[vec[dep][i]]>w[k[l]]&&!check){
        check=1;
        ret+=1ll*b.merge(now,u[k[l]],v[k[l]])*w[k[l]];

      }
      ret+=b.merge(now,u[vec[dep][i]],v[vec[dep][i]])*w[vec[dep][i]];
    }
    if(check==0){
      ret+=b.merge(now,u[k[l]],v[k[l]])*w[k[l]];
    }
    ::anss[l]=ans+ret;
    a.fallback(now);
    b.fallback(now);
    return ;
  }
  long long ret=eva(now,l,r,dep);
  ans+=ret;
  for(int i=mid+1;i<=r;i++){
    dym[k[i]]--;
    if(dym[k[i]]==0){
      vec[dep+1].push_back(k[i]);
    }
  }
  std::sort(vec[dep+1].begin(),vec[dep+1].end(),cmp);
  cdq(now*2,l,mid,dep+1,ans);
  for(int i=mid+1;i<=r;i++){
    dym[k[i]]++;
  }
  for(int i=0;i<vec[dep+1].size();i++){
    if(dym[vec[dep+1][i]]==0){
      temp.push_back(vec[dep+1][i]);
    }
  }
  std::swap(vec[dep+1],temp);
  temp.clear();
  for(int i=l;i<=mid;i++){
    dym[k[i]]--;
    if(dym[k[i]]==0){
      vec[dep+1].push_back(k[i]);
    }
  }
  std::sort(vec[dep+1].begin(),vec[dep+1].end(),cmp);
  cdq(now*2+1,mid+1,r,dep+1,ans);
  for(int i=l;i<=mid;i++){
    dym[k[i]]++;
  }
  a.fallback(now);
  b.fallback(now);
  vec[dep+1].clear();
  ans-=ret;
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
  int q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    int c=read();
    add(a,b,c);
  }
  for(int i=1;i<=q;i++){
    k[i]=read();
    d[i]=read();
    dym[k[i]]++;
  }
  for(int i=1;i<=m;i++){
    if(!dym[i]){
      vec[1].push_back(i);
    }
  }
  std::sort(vec[1].begin(),vec[1].end(),cmp);
  cdq(1,1,q,1,0);
  for(int i=1;i<=q;i++){
    printf("%lld\n",anss[i]);
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
