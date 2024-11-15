#include <cstring>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
char temp[25];
bool dis[25];
int dp[25][2];
int siz;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    scanf("%s",temp+1);
    siz=strlen(temp+1);
    int m=read();
    memset(dis,0,sizeof(dis));
    int tt=0;
    for(int i=1;i<=m;i++){
      dis[(tt=read())]=1;
    }
    memset(dp,0,sizeof(dp));
    dp[1][0]=0;
    dp[1][1]=0;
    for(int j=1;j<=temp[1]-'0';j++){
      if(dis[j]==0){
        if(j!=temp[1]-'0'){
          dp[1][0]++;
        }else{
          dp[1][1]++;
        }
      }
    }
    for(int i=2;i<=siz;i++){
      for(int j=0;j<=9;j++){
        if(dis[j]==0){
          dp[i][0]+=dp[i-1][0];
          if(j<temp[i]-'0'){
            dp[i][0]+=dp[i-1][1];
          }else if(j==temp[i]-'0'){
            dp[i][1]+=dp[i-1][1];
          }
        }
      }
    }
    int ret=dp[siz][0]+dp[siz][1]+!dis[0];
    int ttt=1;
    for(int i=1;i<siz;i++){
      ret+=ttt*(9-m+dis[0]);
      ttt*=(10-m);
    }
    printf("%lld\n",ret);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
