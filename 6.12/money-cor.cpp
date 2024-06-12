#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define mod 998244353
inline int read();
std::map<int,int>mp;
int seq[1000006];
int f[1000006];
int pow(int x,int y){
	if(y==0){
		return 1;
	}
	if(y%2==0){
		int tt=pow(x,y/2);
		return (1ll*tt*tt)%mod;
	}
	return (1ll*pow(x,y-1)*x)%mod;
}
std::pair<int,int>pa[1000006];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read()*pow(1000000,mod-2)%mod;
  int tt=n;
  int cnt=0;
  mp[n]=0;
  int fr=0;
  int tt2=0;
  while(n){
    seq[++cnt]=(n*2)/m;
    n*=2;
    n%=m;
    if(mp[n]){
      fr=cnt+1;
      tt2=mp[n]+1;
      seq[cnt+1]=(n*2)/m;
      break;
    }
    mp[n]=cnt;
  }
  if(n==0){
    for(int i=cnt;i>=1;i--){
      if(!seq[i]){
        f[i]=f[i+1]*q%mod;
      }else{
        f[i]=(f[i+1])+(1-f[i+1])*q%mod;
        f[i]%=mod;
      }
    }
    printf("%lld",(f[1]+mod)%mod);
    return 0;
  }else{
    pa[fr]=std::make_pair(1,0);
    for(int i=fr-1;i>=tt2;i--){
      if(!seq[i]){
        pa[i]=pa[i+1];
        pa[i].first=pa[i].first*q%mod;
        pa[i].second=pa[i].second*q%mod;
      }else{
        pa[i].first=(pa[i+1].first+(-pa[i+1].first)%mod*q%mod)%mod;
        pa[i].second=(pa[i+1].second+(1-pa[i+1].second)%mod*q%mod)%mod;
      }
    }
    f[tt2]=pa[tt2].second*pow((1-pa[tt2].first+mod)%mod,mod-2)%mod;
    for(int i=tt2-1;i>=1;i--){
      if(!seq[i]){
        f[i]=f[i+1]*q%mod;
      }else{
        f[i]=(f[i+1])+(1-f[i+1])*q%mod;
        f[i]%=mod;
      }
    }
    printf("%lld",(f[1]+mod)%mod);
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

