#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline long long read();
int mod;
int prl[1000005];
bool is[1000005];
int cnt;
int pow(int a,int b){
  a%=mod;
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=mod;
    }
    cur*=cur;
    cur%=mod;
    b/=2;
  }
  return ans;
}
int mm[1000005];
int cheng[1000005];
int inv[1000005];
inline int C(int n,int k){
  return ((1ll*cheng[n]*inv[k]%mod)*inv[n-k])%mod;
}
int kk;
int g[1000005];
int num[1000005];
int to[1000005];
int to2[1000005];
//int H(int n,int k){
//  cntt++;
//  if(mp[k].find(n)!=mp[k].end()){
//    return mp[k][n];
//  }
//  if(k==0){
//    mm[0]=n%mod;
//    for(int i=1;i<=kk;i++){
//      mm[i]=pow(n+1,i+1);
//      for(int j=0;j<i;j++){
//        mm[i]-=(1ll*C(i+1,j)*mm[j])%mod;
//        mm[i]%=mod;
//        mm[i]+=mod;
//        mm[i]%=mod;
//      }
//      mm[i]+=mod-1;
//      mm[i]%=mod;
//      mm[i]=(mm[i]*1ll*cheng[i]%mod*inv[i+1])%mod;
//    }
//    return mp[k][n]=(mm[kk]-1);
//  }
//  int ans=H(n,k-1);
//  if(prl[k]*prl[k]<=n){
//    ans-=1ll*pow(prl[k],kk)*((H(n/prl[k],k-1)-H(prl[k]-1,k-1))%mod)%mod;
//  }
//  ans%=mod;
//  ans+=mod;
//  ans%=mod;
//  return mp[k][n]=ans;
//}
int sp[1000005];
int sum(int a){
  return a*(a+1)%mod*(a*2+1)%mod*inv[3]%mod%mod;
}
int kkk[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  long long n=read();
  kk=read();
  mod=read();
  int sn=std::sqrt((long long)(n));
  cheng[0]=1;
  for(int i=1;i<=100;i++){
    cheng[i]=1ll*cheng[i-1]*i%mod;
  }
  inv[100]=pow(cheng[100],mod-2);
  for(int i=99;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  inv[0]=1;
  for(int i=2;i<=sn;i++){
    if(is[i]==0){
      prl[++cnt]=i;
      sp[cnt]=(sp[cnt-1]+pow(i,kk))%mod;
      kkk[cnt]=pow(i,kk);
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*prl[j]*i>sn){
        break;
      }
      is[prl[j]*i]=1;
      if(i%prl[j]==0){
        break;
      }
    }
  }
  int ans=0;
  int cntt=0;
  for(int l=1,r;l<=n;l=r+1){
    r=(n)/(n/l);
    num[++cntt]=n/l;
    mm[0]=(n/l)%mod;
    for(int i=1;i<=kk;i++){
      mm[i]=pow(n/l+1,i+1);
      for(int j=0;j<i;j++){
        mm[i]-=(1ll*C(i+1,j)*mm[j])%mod;
      }
      mm[i]+=mod-1;
      mm[i]%=mod;
      mm[i]=(mm[i]*1ll*cheng[i]%mod*inv[i+1])%mod;
    }
    g[cntt]=(mm[kk]-1);
    if(num[cntt]>1000000){
      to2[n/num[cntt]]=cntt;
    }else{
      to[num[cntt]]=cntt;
    }
  }
  for(int i=1;i<=cnt;i++){
    for(int j=1;j<=cntt&&1ll*num[j]>=1ll*prl[i]*prl[i];j++){
      int tmp=num[j]/prl[i];
      if(tmp<=1000000){
        tmp=to[tmp];
      }else{
        tmp=to2[n/tmp];
      }
      g[j]-=1ll*kkk[i]*((g[tmp]-sp[i-1]+mod)%mod)%mod;
      g[j]%=mod;
    }
  }
  for(int l=1,r;l<=sn;l=r+1){
    r=(n)/(n/l);
    int tt;
    int i=l;
    if(n/i<=1000000){
      tt=g[to[n/i]];
    }else{
      tt=g[to2[n/(n/i)]];
    }
    ans+=1ll*(1ll*(sum(r)-sum(l-1))%mod)*(tt)%mod;
    ans%=mod;
  }
  ans+=mod;
  ans%=mod;
  printf("%lld",ans);
  return 0;
}
inline long long read(){
  long long x=0,f=1;char c=getchar();
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

