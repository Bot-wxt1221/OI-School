#include <ctime>
#include <iostream>
#include <cstdio>
#include <map>
#include <random>
inline int read();
int fir[100005];
std::map<__int128,int>mp[100005];
int v[200005];
int nxt[200005];
int now;
int m;
__int128 tt[100005];
int siz[100005];
__int128 a[100005];
__int128 b[100005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dep[100005];
int mxdep=0;
void dfs(int now,int fa,int depth=0){
  dep[now]=depth;
  mxdep=std::max(mxdep,dep[now]);
  if(now<=m){
    a[now]=tt[now];
    b[now]=tt[(now)%m+1];
    siz[now]=1;
  }else{
    a[now]=b[now]=siz[now]=0;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,depth+1);
    a[now]^=a[v[i]];
    b[now]^=b[v[i]];
    siz[now]+=siz[v[i]];
  }
  mp[depth][b[now]]=1;
  return ;
}
int no[100005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  std::mt19937_64 mt(time(NULL));
  while(T--){
    int n=read();
    mxdep=0;
    m=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      mp[i].clear();
      no[i]=0;
    }
    now=0;
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    for(int i=1;i<=m;i++){
      tt[i]=mt();
      tt[i]=(tt[i]<<63)+mt();
    }
    dfs(n,n);
    for(int i=1;i<=n;i++){
      if(!mp[dep[i]][a[i]]&&siz[i]>1){
        no[dep[i]]=1;
      }
    }
    for(int i=1;i<=mxdep;i++){
      if(no[i]==1){
        printf("Tie\n");
        goto end;
      }
    }
    printf("Doddle\n");
    end:{}
  }
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
