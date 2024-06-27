#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
char temp[100005];
int cnt[15];
int mr;
int dp[15][100005];
int ans=0;
int cnt2[15];
int tt[15];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (1ll*tt*tt)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
void dfs(int now){
  if(now==10){
    int num=0;
    int tt=0;
    for(int i=1;i<=9;i++){
      num+=std::max(cnt2[i]-cnt[i],0ll);
      if(cnt2[i]==5){
        tt++;
      }
    }
    if(num>mr){
      return ;
    }
    int sta=1;
    for(int i=1;i<=9;i++){
      int v0=sta&1;
      int v1=(sta>>1)&1;
      int v2=(sta>>2)&1;
      int v3=(sta>>3)&1;
      if(cnt2[i]==0){
        sta=v0;
      }else if(cnt2[i]==1){
        sta=v1|(v2<<1)|(v0<<2);
      }else if(cnt2[i]==2){
        sta=v0|(v3<<1)|(v1<<2)|(v2<<3);
      }else if(cnt2[i]==3){
        sta=(v0|v1)|(v2<<1)|(v0<<2)|(v3<<3);
      }else if(cnt2[i]==4){
        sta=(v0|v1)|((v2|v3)<<1)|((v0|v1)<<2)|(v2<<3);
      }else if(cnt2[i]==5){
        sta=(v0|v1)|((v2|v3)<<1)|((v0|v1)<<2)|((v2|v3)<<3);
      }
    }
    if((sta&1)==0){
      return ;
    }
    ans+=dp[tt][mr-num];
    ans%=mod;
    return ;
  }
  for(int i=0;i<=5;i++){
    cnt2[now]=i;
    if(i!=5&&cnt[now]>cnt2[now]){
      continue;
    }
    dfs(now+1);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("dxg.in","r",stdin);
  freopen("dxg.out","w",stdout);
  #endif
  int n=read();
  for(int i=0;i<=9;i++){
    dp[i][0]=1;
  }
  for(int j=1;j<=100000;j++){
    for(int i=1;i<=9;i++){
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  scanf("%s",temp+1);
  mr=0;
  for(int i=1;i<=n;i++){
    if('1'<=temp[i]&&temp[i]<='9'){
      cnt[temp[i]-'0']++;
    }else{
      mr++;
    }
  }
  dfs(1);
  printf("%lld",ans);
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
