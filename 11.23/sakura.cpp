#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mod 1000000007
inline int read();
int fir[1000005];
int nxt[2000005];
int v[2000005];
int h[2000005];
std::pair<int,int>pa[2000005];
int ans[1000005];
bool vised[1000005];
int siz[1000005];
int fa[1000005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void Union(int x,int y){
  int fx=getfa(x);
  int fy=getfa(y);
  if(fx==fy){
    return ;
  }
  fa[fx]=fy;
  siz[fy]+=siz[fx];
  return ;
}
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("sakura.in","r",stdin);
	freopen("sakura.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    h[i]=read();
    pa[i]={h[i],i};
  }
  std::sort(pa+1,pa+n+1);
  for(int i=1;i<=n;i++){
    int ti=pa[i].second;
    vised[ti]=1;
    int siz=1;
    long long tt=1;
    ans[ti]-=(pa[i].first);
    for(int j=fir[ti];j!=-1;j=nxt[j]){
      if(vised[v[j]]){
        tt*=ans[getfa(v[j])]+pa[i].first;
        tt%=mod;
        Union(v[j],ti);
      }
    }
    ans[ti]+=tt;
    ans[ti]%=mod;
  }
  printf("%d",(ans[getfa(1)]+m)%mod);
	return 0 ;
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
