#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int dp[4005][4005];
char s[4005];
char t[4005];
int pre[4005][30];
int pre2[4005][30];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  #endif
  int a=read();
  int b=read();
  int c=read();
  int d=read();
  scanf("%s",s+1);
  scanf("%s",t+1);
  int n1=strlen(s+1);
  int n2=strlen(t+1);
  for(int i=1;i<=n1;i++){
    for(char aa='a';aa<='z';aa++){
      if(s[i]==aa){
        pre[i][aa-'a']=i;
      }else{
        pre[i][aa-'a']=pre[i-1][aa-'a'];
      }
    }
  }
  for(int i=1;i<=n2;i++){
    for(char aa='a';aa<='z';aa++){
      if(t[i]==aa){
        pre2[i][aa-'a']=i;
      }else{
        pre2[i][aa-'a']=pre2[i-1][aa-'a'];
      }
    }
  }
  memset(dp,0x7f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=n1;i++){
    dp[i][0]=i*b;
  }
  for(int i=1;i<=n2;i++){
    dp[0][i]=i*a;
  }
  for(int i=1;i<=n1;i++){
    for(int j=1;j<=n2;j++){
      if(s[i]==t[j]){
        dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]);
      }
      dp[i][j]=std::min(dp[i][j],dp[i][j-1]+a);
      dp[i][j]=std::min(dp[i][j],dp[i-1][j]+b);
      dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]+c);
      int l=pre2[j-1][s[i]-'a'];
      int k=pre[i-1][t[j]-'a'];
      if(l==0||k==0){
        continue;
      }
      dp[i][j]=std::min(dp[i][j],dp[k-1][l-1]+d+(i-k-1)*b+(j-l-1)*a);
    }
  }
  printf("%d",dp[n1][n2]);
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


