#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
int dp[(1<<20)+5];
std::vector<int>vec;
bool vised[45][45];
int used[45];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int x=read();
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    vised[x][y]=vised[y][x]=1;
  }
  int prel=1;
  int prer=(n)/2;
  int nxtl=prer+1;
  int nxtr=n;
  for(int i=0;i<(1<<(n/2));i++){
    bool yes=1;
    int cnt=0;
    vec.clear();
    for(int j=prel;j<=prer;j++){
      if(i&(1<<(j-1))){
        vec.push_back(j);
        dp[i]=std::max(dp[i],dp[i^(1<<(j-1))]);
        cnt++;
        for(int kk=0;kk<vec.size();kk++){
          int k=vec[kk];
          if(j==k){
            continue;
          }
          if(i&(1<<(k-1))){
            if(vised[j][k]==0){
              yes=0;
            }
          }
        }
      }
    }
    dp[i]=std::max(dp[i],yes*cnt);
  }
  int ans=0;
  for(int i=0;i<(1<<(n-(n/2)));i++){
    bool yes=1;
    memset(used,0,sizeof(used));
    vec.clear();
    int cnt=0;
    for(int j=nxtl;j<=nxtr;j++){
      if(i&(1<<(j-nxtl))){
        vec.push_back(j);
        for(int k=1;k<=n;k++){
          used[k]+=vised[j][k];
        }
        cnt++;
        for(int kk=0;kk<vec.size();kk++){
          int k=vec[kk];
          if(j==k){
            continue;
          }
          if(i&(1<<(k-nxtl))){
            if(vised[j][k]==0){
              yes=0;
            }
          }
        }
      }
    }
    if(yes==0){
      continue;
    }
    int sta=0;
    for(int j=prel;j<=prer;j++){
      if(used[j]==cnt){
        sta|=(1<<(j-prel));
      }
    }
    ans=std::max(ans,cnt+dp[sta]);
  }
  long double ans2=(long double)x*x*(ans)*(ans-1)/2/ans/ans;
  printf("%.6Lf",ans2);
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
