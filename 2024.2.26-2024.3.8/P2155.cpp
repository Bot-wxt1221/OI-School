#include <iostream>
#include <cstdio>
inline int read();
int pr[10000005];
bool yes[10000005];
int cnt=0;
int inv[10000005];
int f2[10000005];
int dinv[10000005];
int jie[10000005];
int num[10000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int R=read();
  for(int i=2;i<=10000000;i++){
    if(!yes[i]){
      pr[++cnt]=i;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*pr[j]*i>10000000){
        break;
      }
      yes[pr[j]*i]=1;
      if(i%pr[j]==0){
        break;
      }
    }
  }
  inv[1]=1;
  for(int i=2;i<=std::min(10000000,R-1);i++){
    inv[i]=1ll*(R-R/i)*inv[R%i]%R;
  }
  f2[0]=1;
  for(int i=1;i<=cnt;i++){
    f2[i]=1ll*f2[i-1]*(pr[i]-1)%R;
  }
  dinv[0]=1;
  for(int i=1;i<=cnt;i++){
    if(pr[i]!=R){
      dinv[i]=1ll*dinv[i-1]*(inv[pr[i]%R])%R;
    }else{
      dinv[i]=dinv[i-1];
    }
  }
  jie[0]=1;
  for(int i=1;i<=10000000;i++){
    if(i!=R){
      jie[i]=1ll*jie[i-1]*i%R;
    }else{
      jie[i]=jie[i-1];
    }
  }
  for(int i=2;i<=10000000;i++){
    if(yes[i]){
      num[i]=num[i-1];
    }else{
      num[i]=num[i-1]+1;
    }
  }
  while(T--){
    int n=read(),m;
    m=read();
    if(n>=R&&m<R){
      printf("0\n");
      continue;
    }
    printf("%lld\n",(1ll*jie[n]*f2[num[m]]%R)*dinv[num[m]]%R);
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


