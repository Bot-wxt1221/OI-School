#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
std::priority_queue<std::pair<int,std::pair<int,int> > >qu;
char temp[75];
int fa[75];
int siz[75];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int dp[75][(1<<18)];
bool vised[75][(1<<18)];
int tfa[75];
int uu[605];
int vv[605];
int ww[605];
int v[605];
int w[605];
int fir[75];
int nxt[605];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
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
  int a=read();
  int b=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    uu[i]=read();
    vv[i]=read();
    ww[i]=read();
    if(uu[i]>n||vv[i]>n){
      exit(-1);
    }
    add(uu[i],vv[i],ww[i]);
    add(vv[i],uu[i],ww[i]);
    if(ww[i]==a){
      if(getfa(uu[i])!=getfa(vv[i])){
        fa[getfa(uu[i])]=getfa(vv[i]);
      }
    }
  }
  for(int i=1;i<=n;i++){
    siz[getfa(i)]++;
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(siz[i]>=4){
      tfa[i]=++cnt;
    }
  }
  memset(dp,0x3f,sizeof(dp));
  dp[1][0]=0;
  qu.push({0,{1,0}});
  while(qu.size()>0){
    auto tp=qu.top().second;
    qu.pop();
    if(vised[tp.first][tp.second]){
      vised[tp.first][tp.second]=1;
      continue;
    }
    for(int i=fir[tp.first];i!=-1;i=nxt[i]){
      int sta=tp.second;
      if(tfa[getfa(v[i])]!=0&&(sta&(1<<(tfa[getfa(v[i])]-1)))){
        continue;
      }
      if(getfa(tp.first)!=getfa(v[i])){
        if(tfa[getfa(tp.first)]!=0){
          sta|=(1<<(tfa[getfa(tp.first)]-1));
        }
      }
      if(getfa(tp.first)==getfa(v[i])&&w[i]==b){
        continue;
      }
      if(dp[v[i]][sta]>dp[tp.first][tp.second]+w[i]){
        dp[v[i]][sta]=dp[tp.first][tp.second]+w[i];
        qu.push({-dp[v[i]][sta],{v[i],sta}});
      }
    }
  }
  for(int i=1;i<=n;i++){
    int mn=0x3f3f3f3f;
    for(int j=0;j<(1<<18);j++){
      mn=std::min(mn,dp[i][j]);
    }
    printf("%d ",mn);
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
