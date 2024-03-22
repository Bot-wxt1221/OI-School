#include <iostream>
#include <cstdio>
#include <unordered_map>
#define int long long
inline int read();
int shai=20000000;
int p;
int pri[20000005];
bool is[20000005];
int phi[20000005];
std::unordered_map<int,__int128>phi_2;
int cnt;
int pow(int a,int b){
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=p;
    }
    cur*=cur;
    cur%=p;
    b/=2;
  }
  return ans;
}
int getphi(int n){
  if(n<=20000000){
    return phi[n];
  }
  if(phi_2[n]){
    return phi_2[n];
  }
  int ans=0;
  for(int i=2,j;i<=n;i=j+1){
    j=(n/(n/i));
    ans+=(getphi(n/i)%p*(((((__int128)(j))*(j+1)*(2*j+1))/6)%p-((((__int128)(i-1))*i*(2*(i-1)+1))/6)%p)%p)%p;
    ans%=p;
    ans+=p;
    ans%=p;
  }
  int inv4=pow(4,p-2);
  return phi_2[n]=(((((((((__int128)n)*n))%p*(((__int128)(n+1))*(n+1))%p)%p*inv4)%p-ans)%p+p)%p);
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  p=read();
  int n=read();
  phi[1]=1;
  for(int i=2;i<=shai;i++){
    if(!is[i]){
      pri[++cnt]=i;
      phi[i]=(i-1)%p;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*i*pri[j]>shai){
        break;
      }
      is[i*pri[j]]=1;
      if(i%pri[j]==0){
        phi[i*pri[j]]=phi[i]*pri[j];
        phi[i*pri[j]]%=p;
        break;
      }
      phi[i*pri[j]]=phi[pri[j]]*phi[i];
      phi[i*pri[j]]%=p;
    }
  }
  for(int i=2;i<=shai;i++){
    phi[i]*=(i*i)%p;
    phi[i]%=p;
    phi[i]+=phi[i-1];
    phi[i]%=p;
  }
  int ans=0;
  int inv4=pow(4,p-2);
  for(int i=1,j;i<=n;i=j+1){
    j=n/(n/i);
    ans+=((getphi(j)-getphi(i-1))%p*((((((__int128)(n/j)))*(n/j))%p*(((__int128)(n/j+1))*(n/j+1))%p)%p*inv4)%p)%p;
    ans%=p;
    ans+=p;
    ans%=p;
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


