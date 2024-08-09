#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[5005];
int nxt[10005];
int a[5005];
int v[10005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::vector<std::pair<int,int> >vec[5005];
long long cha[5005];
bool leaf[5005];
long long ans=0;
void dfs(int now,int fa){
  vec[now].clear();
  vec[now].push_back(std::make_pair(0,now));
  cha[now]=-a[now];
  leaf[now]=1;
  int tt=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    tt=1;
    leaf[now]=0;
    dfs(v[i],now);
    cha[now]+=a[v[i]];
    auto preend=vec[now].size();
    for(int j=0;j<vec[v[i]].size();j++){
      vec[now].push_back(std::make_pair(vec[v[i]][j].first+1,vec[v[i]][j].second));
    }
    std::inplace_merge(vec[now].begin(),vec[now].begin()+preend,vec[now].end());
  }
  if(cha[now]<0&&tt){
    for(int i=0;i<vec[now].size();i++){
      if(cha[vec[now][i].second]>0||leaf[vec[now][i].second]){
        long long tt=std::min(cha[vec[now][i].second],-cha[now]);
        if(leaf[vec[now][i].second]){
          tt=-cha[now];
        }
        cha[vec[now][i].second]-=tt;
        cha[now]+=tt;
        ans+=vec[now][i].first*tt;
      }
      if(cha[now]>=0){
        break;
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
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      a[i]=read();
    }
    ans=0;
    for(int i=2;i<=n;i++){
      int tt=read();
      add(tt,i);
      add(i,tt);
    }
    dfs(1,1);
    printf("%lld\n",ans);
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
