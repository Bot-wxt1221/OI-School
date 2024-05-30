#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fir[2000005];
int nxt[2000005];
int v[2000005];
int now;
void add(int xx,int yy){
  v[++now]=yy;
  nxt[now]=fir[xx];
  fir[xx]=now;
  return ;
}
int ss[2000005];
int tree[2000005];
int lowbit(int x){
  return x&(-x);
}
int query(int x){
  int sum=0;
  while(x>0){
    sum+=tree[x];
    x-=lowbit(x);
  }
  return sum;
}
void mod(int x,int y){
  while(x<=200005){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int summ[2000005];
void dfs1(int now,int fa){
  int in=query(now);
  int nin=query(fa);
  mod(now,1);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs1(v[i],now);
  }
  int out=query(now);
  int nout=query(fa);
  int ad=now+in-out;
  int nad=nout-nin;
  ss[now]+=ad-nad;
  ss[1]+=nad;
  return ;
}
void dfs2(int now,int fa,int ad){
  ss[now]+=ad;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now,ss[now]);
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
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs1(1,1);
  dfs2(1,1,0);
  for(int i=1;i<=n;i++){
    printf("%lld ",ss[i]);
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


