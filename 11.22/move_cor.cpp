#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int a[100005];
int b[100005];
int now;
int sum[100005];
std::vector<int>vec,vec2;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
}
int faa[100005];
int getfa(int x){
  return faa[x]==x?x:faa[x]=getfa(faa[x]);
}
void dfs(int now,int fa){
  sum[now]=a[now]-b[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    sum[now]+=sum[v[i]];
  }
  return ;
}
int tt;
void dfs2(int now,int fa){
  vec2.push_back(sum[now]);
  if(now==tt){
    vec=vec2;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  vec2.pop_back();
}
int ans=0;
void dfs3(int now,int fa){
  sum[now]=a[now]-b[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs3(v[i],now);
    sum[now]+=sum[v[i]];
  }
  ans+=std::abs(sum[now]);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    faa[i]=i;
  }
  int flagx=0,flagy=0;
  for(int i=1;i<=n;i++){
    int x=read();
    int y=read();
    if(getfa(x)==getfa(y)){
      flagx=x;
      flagy=y;
      continue;
    }
    faa[getfa(x)]=getfa(y);
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  tt=flagy;
  dfs(flagx,flagx);
  dfs2(flagx,flagx);
  std::sort(vec.begin(),vec.end());
  int tt=vec[vec.size()/2];
  ans=std::abs(tt);
  a[flagx]+=tt;
  a[flagy]-=tt;
  dfs3(1,1);
  printf("%lld",ans);
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
