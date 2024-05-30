#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
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
int c[100005];
int dp[100005];
int dp2[100005];
int sum[100005];
int cnt=0;
int dfn[100005];
int bk[100005];
void dfs1(int now,int fa){
  dp2[now]=c[now];
  dfn[now]=++cnt;
  sum[cnt]=c[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs1(v[i],now);
    dp2[now]+=dp2[v[i]];
    dp[now]+=dp2[v[i]];
    dp[now]+=dp[v[i]];
    bk[v[i]]=cnt;
  }
  return ;
}
int rans[100005];
int n;
void dfs2(int now,int fa){
  rans[now]=rans[fa];
  if(now!=fa){
    rans[now]+=sum[n];
    rans[now]-=sum[bk[now]]-sum[dfn[now]-1];
    rans[now]-=sum[bk[now]]-sum[dfn[now]-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
inline void write(int ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[129];
	int n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
}


signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    c[i]=read();
  }
  dfs1(1,1);
  for(int i=1;i<=n;i++){
    sum[i]+=sum[i-1];
  }
  rans[1]=dp[1];
  dfs2(1,1);
  int mx=0x3f3f3f3f3f3f3f3f;
  mx*=mx;
  for(int i=1;i<=n;i++){
    mx=std::min(mx,rans[i]);
  }
  write(mx);
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

