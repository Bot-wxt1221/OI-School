#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int fa[25];
int ans[25];
int tfa[25];
int dp[2][1000005];
bool vised[25];
int sta;
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int fir[25];
int nxt[100005];
int v[100005];
int used[25];
int higher[25];
int w[100005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int mn;
bool vised2[25];
void dfs(int now,int cur){
  mn=std::min(mn,cur);
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(vised[v[i]]){
      continue;
    }
    vised[v[i]]=1;
    dfs(v[i],cur+w[i]);
  }
  return ;
}
void dfs2(int now,int cur){
  sta|=(1<<(cur-mn));
  higher[now]=cur-mn;
  vised2[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(vised2[v[i]]){
      continue;
    }
    vised2[v[i]]=1;
    dfs2(v[i],cur+w[i]);
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
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    fa[getfa(x)]=getfa(y);
    add(y,x,z);
    add(x,y,-z);
  }
  int cntt=0;
  for(int i=1;i<=n;i++){
    if(fa[i]==i){
      sta=0;
      mn=0x3f3f3f3f;
      dfs(i,0);
      dfs2(i,0);
      tfa[i]=(++cntt);
      used[tfa[i]]=sta;
    }
  }
  for(int i=1;i<=cntt;i++){
    memset(dp,0,sizeof(dp));
    int op=0;
    dp[op][0]=1;
    for(int j=1;j<=cntt;j++){
      if(i==j){
        continue;
      }
      op^=1;
      for(int fir=0;fir<n;fir++){
        int nxsta=(used[j]<<fir);
        if(nxsta>=(1<<n)){
          continue;
        }
        for(int stt=0;stt<(1<<n);stt++){
          if(stt&nxsta){
            continue;
          }
          dp[op][stt|nxsta]|=dp[op^1][stt];
        }
      }
    }
    int cnt=0;
    int tt=0;
    op^=1;
    for(int fir=0;fir<n;fir++){
      int nxsta=(used[i]<<fir);
      if(nxsta>=(1<<n)){
        continue;
      }
      for(int stt=((1<<n)-1)&(~nxsta);stt<=(((1<<n)-1)&(~nxsta));stt++){
        if(stt&nxsta){
          continue;
        }
        if(dp[op^1][stt]){
          cnt+=dp[op^1][stt];
          tt=fir;
        }
      }
    }
    if(cnt>1){
      ans[i]=1;
    }else{
      ans[i]=-tt;
    }
  }
  for(int i=1;i<=n;i++){
    if(ans[tfa[getfa(i)]]==1){
      printf("-1 ");
    }else{
      printf("%lld ",-ans[tfa[getfa(i)]]+higher[i]+1);
    }
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

