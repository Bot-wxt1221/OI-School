#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
inline int read();
char temp[5005];
int to[5005][5005];
int dp[5005][5005];
int ans[5005][5005];
int ans2[5005][5005];
int pw1[5005];
int pw2[5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  pw1[0]=1;
  for(int i=n;i>=1;i--){
    for(int j=n;j>=1;j--){
      if(temp[i]==temp[j]){
        to[i][j]=to[i+1][j+1]+1;
      }else{
        to[i][j]=0;
      }
    }
  }
  for(int i=1;i<=n;i++){
    pw1[i]=(1ll*pw1[i-1]*2)%mod;
    pw2[i]=(1ll*pw2[i-1]*2)%mod+(temp[i]=='1');
    pw2[i]%=mod;
    for(int j=1;j<=i;j++){
      int siz;
      if(j==1){
        dp[i][j]=1;
        ans[i][j]=1;
        goto end;
      }
      if(temp[j]=='0'){
        dp[i][j]=0;
        ans[i][j]=0x7f7f7f7f;
        goto end;
      }
      siz=i-j+1;
      dp[i][j]+=(0ll+dp[j-1][j-1]-dp[j-1][std::max(j-siz,0)])%mod;
      dp[i][j]%=mod;
      dp[i][j]+=mod;
      dp[i][j]%=mod;
      ans[i][j]=ans2[j-1][std::min(std::max(j-siz+1,1),j-1)]+1;
      if(j-1>=siz&&(to[j-siz][i-siz+1]>=siz||(temp[j-siz+to[j-siz][i-siz+1]]<temp[i-siz+1+to[j-siz][i-siz+1]]))){
        dp[i][j]+=(0ll+dp[j-1][j-siz]-dp[j-1][j-siz-1]+mod)%mod;
        dp[i][j]%=mod;
        ans[i][j]=std::min(ans[i][j],ans[j-1][j-siz]+1);
      }
      end:{}
      ans2[i][j]=ans[i][j];
      dp[i][j]+=dp[i][j-1];
      dp[i][j]%=mod;
    }
    for(int j=i-1;j>=1;j--){
      ans2[i][j]=std::min(ans2[i][j+1],ans2[i][j]);
    }
  }
  double com=1e20;
  int rans=0;
  for(int i=1;i<=n;i++){
    if((dp[n][i]-dp[n][i-1])%mod==0){
      continue;
    }
    int tt=ans[n][i];
    double gr=0,p=1;
    for(int j=i;j<=n;j++){
      if(temp[j]=='1'){
        gr+=p;
      }
      p*=0.5;
    }
    double cur=log2(gr)+(n-i+1);
    if(n-i+1<=30){
      cur+=log2((double(tt))/(gr*(1<<(n-i)))+1);
    }
    if(cur<com){
      com=cur;
      rans=(pw2[n]-(1ll*pw2[i-1]*pw1[n-i+1])%mod+mod)%mod;
      rans+=ans[n][i];
      rans%=mod;
    }
  }

  printf("%d\n%d",dp[n][n],rans);
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

