#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mod 32767
inline int read();
int a[1000005];
int b[1000005];
std::pair<int,int>pa[1000005],pb[1000005];
int fa[1000005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
  fa[getfa(x)]=getfa(y);
  return ;
}
std::vector<int>col;
std::pair<int,std::pair<int,int> > paa[1000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  a[1]=read();
  a[2]=read();
  int x=read();
  int y=read();
  int z=read();
  for(int i=3;i<=n;i++){
    a[i]=((1ll*a[i-1]*x)%mod+(1ll*a[i-2]*y)%mod+z)%mod;
  }
  b[1]=read();
  b[2]=read();
  x=read();
  y=read();
  z=read();
  for(int i=3;i<=n;i++){
    b[i]=((1ll*b[i-1]*x)%mod+(1ll*b[i-2]*y)%mod+z)%mod;
  }
  for(int i=1;i<=n;i++){
    fa[i]=i;
    pa[i]={a[i],i};
    pb[i]={b[i],i};
  }
  std::sort(pa+1,pa+n+1);
  std::reverse(pa+1,pa+n+1);
  std::sort(pb+1,pb+n+1);
  std::reverse(pb+1,pb+n+1);
  int ans=0;
  for(int i=1;i<=n;i++){
    merge(pa[i].second,pb[i].second);
    ans=std::max(ans,pa[i].first*pa[i].first-pb[i].first*pb[i].first);
  }
  for(int i=1;i<=n;i++){
    if(fa[i]==i){
      col.push_back(i);
    }
  }
  int cnt=0;
  for(int i=1;i<n;i++){
    if(getfa(pa[i].second)!=getfa(pb[i+1].second)){
      paa[++cnt].second.second=getfa(pa[i].second);
      paa[cnt].second.first=getfa(pb[i+1].second);
      paa[cnt].first=pa[i].first*pa[i].first-pb[i+1].first*pb[i+1].first;
    }
  }
  std::sort(paa+1,paa+cnt+1);
  for(int i=1;i<=cnt;i++){
    if(getfa(paa[i].second.first)==getfa(paa[i].second.second)){
      continue;
    }
    fa[getfa(paa[i].second.first)]=getfa(paa[i].second.second);
    ans=std::max(ans,paa[i].first);
  }
  printf("%d",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
