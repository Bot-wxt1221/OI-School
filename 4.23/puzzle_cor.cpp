#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int t[155][155];
bool kkk[155];
int kk[154];
int n,m,k;
int ans=0;
int maxx(int now,int used){
  if(kkk[now]){
    return n;
  }
  int ret=0;
  for(int i=0;i<(1<<used);i++){
    int ans=0;
    for(int j=1;j<=n;j++){
      int cur=t[j][now];
      int cnt=0;
      for(int k=1;k<=used;k++){
        if(i&(1<<(k-1))){
          cur^=(t[j][kk[k]]);
          cnt++;
        }
      }
      if(cnt&1){
        cur^=1;
      }
      ans+=cur;
    }
    ret=std::max(ret,ans);
  }
  return ret;
}
inline void write(int a){
  static char tt[128];
  int cnt=0;
  while(a){
    tt[++cnt]=a%10+'0';
    a/=10;
  }
  for(int i=cnt;i>=1;i--){
    putchar(tt[i]);
  }
  return ;
}

void anss(int used){
  int nans=0;
  for(int i=0;i<m;i++){
    nans+=maxx(i,used)*(((__int128)1)<<i);
  }
  ans=std::max(ans,nans);
  return ;
}
void dfs(int now,int used){
  if(now==0||used==k){
    anss(used);
    return ;
  }
  now--;
  while(maxx(now,used)==n){
    now--;
  }
  for(int i=0;i<7;i++){
    if(now-i<0){
      continue;
    }
    kk[used+1]=now-i;
    kkk[now-i]=1;
    dfs(now-i,used+1);
    kkk[now-i]=0;
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  k=read();
  for(int i=1;i<=n;i++){
    int a=read();
    for(int j=0;j<m;j++){
      if((((__int128)1)<<j)&a){
        t[i][j]=1;
      }else{
        t[i][j]=0;
      }
    }
  }
  dfs(m,0);
  write(ans);
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

