#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
#define mod 998244353
inline int read();
int x[500005];
int siz[500005];
bool feng[500005];
int y[500005];
bool yes[500005];
std::vector<int>vec[500005];
int fac[2000005];
int fa[500005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
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
int inv[500005];
int C(int n,int m){
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("per.in","r",stdin);
  freopen("per.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  fac[0]=1;
  for(int i=1;i<=n;i++){
    fa[i]=i;
    fac[i]=fac[i-1]*i%mod;
    siz[i]=1;
  }
  inv[n]=pow(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
    vec[x[i]].push_back(y[i]);
    vec[y[i]].push_back(x[i]);
    if(x[i]==y[i]){
      yes[x[i]]=1;
    }
  }
  for(int i=1;i<=n;i++){
    std::sort(vec[i].begin(),vec[i].end());
    vec[i].resize(std::unique(vec[i].begin(),vec[i].end())-vec[i].begin());
    if(vec[i].size()==1){
      feng[i]=1;
    }
  }
  for(int i=1;i<=n;i++){
    if(vec[i].size()>2){
      printf("0\n");
      return 0;
    }
    if(vec[i].size()>1&&yes[i]){
      printf("0\n");
      return 0;
    }
    if(vec[i].size()==2){
      if(getfa(vec[i][1])==getfa(vec[i][0])){
        goto end;
      }
      siz[getfa(vec[i][1])]+=siz[getfa(vec[i][0])];
      siz[getfa(vec[i][0])]=0;
      feng[getfa(vec[i][1])]|=feng[getfa(vec[i][0])];
      fa[getfa(vec[i][0])]=getfa(vec[i][1]);
      end:{}
      if(getfa(vec[i][1])==getfa(i)){
        continue;
      }
      siz[getfa(vec[i][1])]+=siz[getfa(i)];
      feng[getfa(vec[i][1])]|=feng[getfa(i)];
      siz[getfa(i)]=0;
      fa[getfa(i)]=getfa(vec[i][1]);
    }
  }
  int free=n;
  int ans=1;
  int cntt=0;
  for(int i=1;i<=n;i++){
    if(yes[i]){
      free--;
      continue;
    }
    if(vec[i].size()==0){
    }else if(vec[i].size()==1&&siz[getfa(i)]==1){
      free--;
      cntt++;
    }else if(fa[i]==i){
      ans*=2;
      free-=siz[i];
      free+=feng[i];
      ans%=mod;
    }
  }
  int tans=0;
  cntt/=2;
  for(int i=0;i<=cntt;i++){
    tans+=fac[(free+cntt-i)]*(i%2==0?1:-1)*pow(2,cntt-i)%mod*C(cntt,i)%mod;
    tans%=mod;
  }
  ans*=tans;
  ans%=mod;
  printf("%lld",(ans+mod)%mod);
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

