#include <iostream>
#include <cstdio>
#define int unsigned long long
#define mod 1000000007
inline int read();
namespace Mker
{
	unsigned long long SA,SB,SC;
	void init(){scanf("%llu%llu%llu",&SA,&SB,&SC);}
	unsigned long long rand()
	{
	    SA^=SA<<32,SA^=SA>>13,SA^=SA<<1;
	    unsigned long long t=SA;
		SA=SB,SB=SC,SC^=t^SA;return SC;
	}
}
int fast1[1000005];
int fast2[1000005];
int fast3[1000005];
int fast4[1000005];
long long pow1(int a){
  return fast1[a%100000]*fast2[a/100000]%mod;
}
long long pow2(int a){
  return fast3[a%100000]*fast4[a/100000]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  Mker::init();
  int ans=1;
  fast1[0]=1;
  for(int j=1;j<=100000;j++){
    ans*=94153035;
    ans%=mod;
    fast1[j]=(1ll*fast1[j-1]*94153035)%mod;
  }
  fast2[0]=1;
  fast2[1]=ans;
  for(int j=2;j<=100000;j++){
    fast2[j]=(1ll*fast2[j-1]*fast2[1])%mod;
  }
  ans=1;
  fast3[0]=1;
  for(int j=1;j<=100000;j++){
    ans*=905847205;
    ans%=mod;
    fast3[j]=(1ll*fast3[j-1]*905847205)%mod;
  }
  fast4[0]=1;
  fast4[1]=ans;
  for(int j=2;j<=100000;j++){
    fast4[j]=(1ll*fast4[j-1]*fast4[1])%mod;
  }
  ans=0;
  while(T--){
    int n=Mker::rand()%(1000000006);
    ans=ans^((233230706*(((pow1(n)-pow2(n))%mod)+mod)%mod)%mod);
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


