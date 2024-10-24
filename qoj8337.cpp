#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 1000000009
inline int read();
int count[5005][(1<<9)+5][2];
int dp[5005][(1<<9)+5][2];
void adda(int ii,int i,int j,int S,int d,int t){
  (dp[ii+1][(S^((1<<(t-1)))^(d?(1<<(d-1)):0))][j]+=dp[ii][S][i])%=mod;
  (count[ii+1][(S^((1<<(t-1)))^(d?(1<<(d-1)):0))][j]+=count[ii][S][i])%=mod;
  return ;

}
void addb(int ii,int i,int j,int S,int d){
            (dp[ii+1][(S^(d?(1<<(d-1)):0))][j]+=dp[ii][S][i]+(d!=0)*(ii?10:10-d)*count[ii][S][i]%mod)%=mod;
            (count[ii+1][(S^(d?(1<<(d-1)):0))][j]+=count[ii][S][i])%=mod;
  return ;
}
int solve(char *x,int n){
  memset(dp,0,sizeof(dp));
  memset(count,0,sizeof(count));
  count[0][0][1]=1;
  for(int i=0;i<n;i++){
    for(int S=0;S<(1<<9);S++){
      for(int d=0;d<=9;d++){
        bool yes=1;
        for(int t=d;t>=1;t--){
          if(S&(1<<(t-1))){
            yes=0;
              if(d<x[i+1]-'0'){
                adda(i,0,0,S,d,t);
                adda(i,1,0,S,d,t);
          }else if(d==x[i+1]-'0'){
                adda(i,0,0,S,d,t);
                adda(i,1,1,S,d,t);
          }else{
                adda(i,0,0,S,d,t);
          }
            break;
          }
        }
        if(yes){
              if(d<x[i+1]-'0'){
                addb(i,0,0,S,d);
                addb(i,1,0,S,d);
          }else if(d==x[i+1]-'0'){
                addb(i,0,0,S,d);
                addb(i,1,1,S,d);
          }else{
                addb(i,0,0,S,d);
          }
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<9);i++){
    for(int u=0;u<=1;u++){
      ans+=dp[n][i][u];
      ans%=mod;
    }
  }
  return ans;
}
char L[5005],R[5005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  scanf("%s",L+1);
  scanf("%s",R+1);
  int t1=solve(R,n);
  L[n]--;
  L[0]=1;
  for(int i=n;i>=1;i--){
    if(L[i]<'0'){
      L[i]+=10;
      L[i-1]-=1;
    }
  }
  if(L[0]==1){
    t1-=solve(L,n);
  }
  t1%=mod;
  t1+=mod;
  t1%=mod;
  printf("%lld",t1);
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
