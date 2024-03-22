#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
std::string tt[205];
long double dp[1005][205];
int pre[1005][205];
long double gai[1005][205];
char temp[1005];
char ans[1005];
int main(){
  #ifdef ONLINE_JUDGE
  freopen("decoding.in","r",stdin);
  freopen("decoding.out","w",stdout);
  #endif
  int d=read();
  int K=read();
  int t=read();
  for(int i=1;i<=d;i++){
    scanf("%s",temp+1);
    tt[i]=std::string(temp+1);
  }
  int n=read();
  for(int i=0;i<=n;i++){
    for(int k=0;k<=d;k++){
      dp[i][k]=-0x3f3f3f3f;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=t;j++){
      long double tt;
      scanf("%Lf",&tt);
      gai[i][j-1]=log2(tt);
    }
  }
  for(int i=1;i<=d;i++){
    double gi=0;
    for(int j=0;j<tt[i].size();j++){
      gi+=gai[j+1][tt[i][j]-'a'];
    }
    dp[tt[i].size()][i]=gi;
    pre[tt[i].size()][i]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=d;j++){
      for(int k=1;k<=d;k++){
        for(int kk=0;kk<K-1;kk++){
          if(tt[j][kk]!=tt[k][kk+1]){
            goto end;
          }
        }
        dp[i][j]=std::max(dp[i][j],dp[i-1][k]+gai[i][tt[j][K-1]-'a']);
        if(dp[i-1][k]+gai[i][tt[j][K-1]-'a']==dp[i][j]){
          pre[i][j]=k;
        }
        end:{}
      }
    }
  }
  int tt;
  long double maxx=-0x3f3f3f3f;
  for(int i=1;i<=d;i++){
    maxx=std::max(maxx,dp[n][i]);
    if(maxx==dp[n][i]){
      tt=i;
    }
  }
  if(maxx==-0x3f3f3f3f){
    printf("---");
    return 0;
  }
  int nn=0;
  int num=n;
  while(tt!=0){
    nn=tt;
    ans[num]=(::tt[tt][K-1]);
    tt=pre[num--][tt];
  }
  for(int i=0;i<K-1;i++){
    ans[i+1]=::tt[nn][i];
  }
  printf("%s",ans+1);
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


