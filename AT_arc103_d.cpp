#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
inline int read();
std::vector<std::pair<int,int> >vec;
std::map<int,int>mp;
int siz[100005];
class node{
  public:
    int i,d;
    node(int ti=0,int td=0){
      i=ti;
      d=td;
      return ;
    }
}a[100005];
bool operator < (node a,node b){
  return a.d>b.d;
}
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int sum;
void dfs(int now,int fa,int dis){
  sum+=dis;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dis+1);
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
    a[i].d=read();
    a[i].i=i;
    fir[i]=-1;
    siz[i]=1;
    mp[a[i].d]=i;
  }
  std::sort(a+1,a+n+1);
  int tp=0,tp2;
  for(int i=1;i<=n;i++){
    int tt=a[i].d-n+2*siz[a[i].i];
    if((mp[tt]==0&&tp==0)||(tt>=a[i].d)){
      tp=a[i].i;
      tp2=a[i].d;
      continue;
    }else if(mp[tt]==0&&tp!=0){
      printf("-1\n");
      return 0;
    }
    int mt=mp[tt];
    siz[mt]+=siz[a[i].i];
    vec.push_back(std::make_pair(mt,a[i].i));
    add(mt,a[i].i);
  }
  dfs(tp,tp,0);
  if(sum!=tp2){
    printf("-1\n");
    return 0;
  }
  for(int i=0;i<vec.size();i++){
    printf("%lld %lld\n",vec[i].first,vec[i].second);
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

