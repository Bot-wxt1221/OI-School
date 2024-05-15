#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdio>
inline long long read();
std::vector<std::pair<long long, std::pair<int,int> > >qu;
int siz[1000005];
int fa[1000005];
int getfa(int x){
  return x==fa[x]?fa[x]:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("hospital.in","r",stdin);
  freopen("hospital.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n+1;i++){
    fa[i]=i;
  }
  for(int i=1;i<=n;i++){
    long long tt=read();
    if(tt!=-1){
      qu.push_back(std::make_pair(tt,std::make_pair(i,n+1)));
    }
  }
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    long long w=read();
    qu.push_back(make_pair(w,std::make_pair(u,v)));
  }
  std::sort(qu.begin(),qu.end());
  long long ans=0;
  int tt=0;
  for(int i=0;i<qu.size();i++){
    auto tp=qu[i];
//    qu.pop();
    auto tt2=tp.second;
    if(getfa(tt2.first)==getfa(tt2.second)){
      continue;
    }
    tt++;
    if(siz[getfa(tt2.first)]>siz[getfa(tt2.second)]){
      std::swap(tt2.first,tt2.second);
    }
    fa[getfa(tt2.first)]=getfa(tt2.second);
    siz[getfa(tt2.second)]+=siz[getfa(tt2.first)];
    ans+=tp.first;
  }
  if(tt!=n){
    printf("No Solution!");
    return 0;
  }
  printf("%lld",ans);
  return 0;
}
inline long long read(){
  long long x=0,f=1;char c=getchar();
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

