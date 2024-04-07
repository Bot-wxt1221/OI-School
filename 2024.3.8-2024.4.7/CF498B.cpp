#include <iostream>
#include <cstdio>
inline int read();
long double p[5005];
int t[5005];
long double dp[2][5005];
long double pow(long double a,int b){
  long double ans=1;
  long double cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
    }
    cur*=cur;
    b/=2;
  }
  return ans;
}

int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int T=read();
  for(int i=1;i<=n;i++){
    int pi=read();
    t[i]=read();
    p[i]=pi/100.0; 
  }
  int op=0;
  dp[0][0]=1;
  long double ans=0;
  for(int i=1;i<=n;i++){
    op^=1;
    long double pre=0;
    for(int j=0;j<=T;j++){
      dp[op][j]=0;
    }
    for(int j=i;j<=T;j++){
      pre=(pre)*(1-p[i])+dp[op^1][j-1];
      if(j>=t[i]){
        dp[op][j]+=dp[op^1][j-t[i]]*pow(1-p[i],t[i]);
      }
      if(j>t[i]){
        pre-=dp[op^1][j-t[i]-1]*pow(1-p[i],t[i]);
      }
      dp[op][j]+=pre*p[i];
      ans+=dp[op][j];
    }
  }
  printf("%.9Lf",ans);
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


