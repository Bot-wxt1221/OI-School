#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int ans[1000005];
bool pr[1000005];
int del[1000005];
int prl[1000005];
int now;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  for(int i=2;i<=1000000;i++){
    if(pr[i]==0){
      prl[++now]=i;
    }
    for(int j=1;j<=now;j++){
      if(1ll*prl[j]*i>1000000){
        break;
      }
      pr[prl[j]*i]=1;
      if(i%prl[j]==0){
        break;
      }
    }
  }
  prl[++now]=4;
  for(int ii=1;ii<=now;ii++){
    int i=prl[ii];
    for(int cur=i;cur<=1000000;cur+=i){
      int add=(i-(cur/i)%i)%i;
      if(i==4){
        add=(2*(cur/i))%4;
      }
      del[cur]+=add;
      del[cur]%=mod;
      if(cur+i<=1000000){
        del[cur+i]-=add;
        del[cur+i]%=mod;
        del[cur+i]+=mod;
        del[cur+i]%=mod;
      }
    }
  }
  for(int i=1;i<=1000000;i++){
    del[i]+=del[i-1];
    del[i]%=mod;
  }
  for(int i=1;i<=1000000;i++){
    del[i]+=del[i-1];
    del[i]%=mod;
  }
  int T=read();
  while(T--){
    printf("%lld\n",del[read()]);
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

