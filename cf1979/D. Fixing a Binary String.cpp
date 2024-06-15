#include <ctime>
#include <iostream>
#include <cstdio>
#include <random>
#define int long long
inline int read();
int pw(int x,int y,int md){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pw(x,y/2,md);
    return (1ll*tt*tt)%md;
  }
  return (1ll*pw(x,y-1,md)*x)%md;
}
char temp[100005];
int suf[100005][15];
int pre[100005][15];
int mod[15]={0,10000019,10000079,10000103,10000121,10000139,10000141,10000169,10000189,10000223,10000229};
int tar[15];
int tar2[15];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  std::mt19937 a(time(NULL));
  while(T--){
    int n=read();
    int k=read();
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=10;j++){
        if(i==1){
          pre[0][j]=0;
        }
        pre[i][j]=pre[i-1][j]+(temp[i]-'0')*pw(2,n-i,mod[j])%mod[j];
      }
    }
    for(int i=n;i>=1;i--){
      for(int j=1;j<=10;j++){
        if(i==n){
          suf[i+1][j]=0;
        }
        suf[i][j]=(suf[i+1][j]*1ll*2+temp[i]-'0')%mod[j];
      }
    }
    for(int i=1;i<=10;i++){
      tar[i]=tar2[i]=0;
      for(int j=n;j>=1;j--){
        tar[i]*=2;
        tar2[i]*=2;
        tar[i]%=mod[i];
        tar2[i]%=mod[i];
        if((j/k+(j%k>0))%2==0){
          tar[i]++;
        }else{
          tar2[i]++;
        }
      }
    }
    for(int i=1;i<=n;i++){
      bool yes=1;
      bool yes2=1;
      for(int j=1;j<=10;j++){
        int tt=pre[i][j];
        tt=(suf[i+1][j]+pre[i][j])%mod[j];
        if(tt!=tar[j]){
          yes=0;
        }
        if(tt!=tar2[j]){
          yes2=0;
        }
      }
      if(yes||yes2){
        printf("%lld\n",i);
        goto end;
      }
    }
    printf("-1\n");
    end:{};
  }
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
