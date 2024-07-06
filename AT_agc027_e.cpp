#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
inline int read();
char temp[100005];
int dp[100005];
int pre[100005];
int nxt[100005][3];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  if(temp[n]=='a'){
    nxt[n][1]=n;
    nxt[n][2]=nxt[n][0]=n+1;
  }else{
    nxt[n][2]=n;
    nxt[n][1]=nxt[n][0]=n+1;
  }
  bool has=0;
  for(int i=n-1;i>=1;i--){
    if(temp[i]==temp[i+1]){
      has=1;
    }
    if(temp[i]=='a'){
      nxt[i][0]=nxt[n+1][2];
      nxt[i][1]=i;
      nxt[i][2]=nxt[i+1][1];
    }else{
      nxt[i][0]=nxt[i+1][1];
      nxt[i][1]=nxt[i+1][2];
      nxt[i][2]=i;
    }
  }
  for(int i=1;i<=n;i++){
    pre[i]=(pre[i-1]+(temp[i]=='a'?1:2))%3;
  }
  dp[0]=1;
  int ans=0;
  for(int i=0;i<n;i++){
    if((pre[n]-pre[i])%3==0&&i!=0){
      ans+=dp[i];
      ans%=mod;
    }
    dp[nxt[i+1][1]]+=dp[i];
    dp[nxt[i+1][1]]%=mod;
    dp[nxt[i+1][2]]+=dp[i];
    dp[nxt[i+1][2]]%=mod;
  }
  if(has==0){
    printf("1");
    return 0;
  }
  printf("%d",(ans+dp[n])%mod);
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
