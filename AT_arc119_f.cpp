#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int dp[2][4005][6][2];
char temp[4005];
int *getans(int i,int disa,int disb,int pre){
  if(disa-disb>=2){
    disa=disb+2;
  }
  if(disb-disa>=2){
    disb=disa+2;
  }
  return &dp[i][disa+2][disa-disb+2][pre];
}
void clear(int op){
  for(int i=0;i<=4004;i++){
    for(int j=0;j<=5;j++){
      dp[op][i][j][0]=dp[op][i][j][1]=0;
    }
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
  int k=read();
  scanf("%s",temp+1);
  dp[0][2][2][0]=1;
  int op=1;
  for(int i=0;i<n;i++){
    op^=1;
    clear(op^1);
    for(int j=0;j<=k+2;j++){
      for(int k=j-2;k<=j+2;k++){
        if(temp[i+1]!='B'){
          {
            int &tt=*(getans(op^1,j+1,k,0));
            tt+=(*getans(op,j,k,0));
            tt%=mod;
          }
          {
            int &tt=*(getans(op^1,std::min(j,k)+1,std::min(k,j+2),0));
            tt+=(*getans(op,j,k,1));
            tt%=mod;
          }
        }
        if(temp[i+1]!='A'){
          {
            int &tt=*(getans(op^1,std::min(j,k+2),std::min(j,k)+1,1));
            tt+=(*getans(op,j,k,0));
            tt%=mod;
          }
          {
            int &tt=*(getans(op^1,j,k+1,1));
            tt+=(*getans(op,j,k,1));
            tt%=mod;
          }
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<=k+2;i++){
    for(int j=i-2;j<=i+2;j++){
      if(std::min(i,j)+1<=k){
        ans+=(*getans(op,i,j,0));
        ans%=mod;
        ans+=(*getans(op,i,j,1));
        ans%=mod;
      }
    }
  }
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
