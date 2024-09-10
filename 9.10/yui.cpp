#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int f[1000005];
int pow(int x,int y){
	if(y==0){
		return 1;
	}
	if(y&1){
		return (1ll*pow(x,y-1)*x)%mod;
	}
	long long temp=pow(x,y/2);
	return temp*temp%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
	m=n;
	f[0]=1;
	int cur=1;
	int pw=pow(2,n);
	for(int i=1;i<=m;i++){
		if(i==1){
			f[i]=cur-f[i-1];
		}else{
			f[i]=cur-f[i-1]-(i-1)*(pw-i+1)%mod*f[i-2]%mod;
		}
		f[i]%=mod;
		cur*=(pw-i);
		cur%=mod;
	}
	f[m]+=mod;
	f[m]%=mod;
  int ans=1;
  int pww=pow(2,n)-1;
  for(int i=1;i<=n;i++){
    ans*=pww;
    ans%=mod;
    pww--;
  }
  ans-=f[m];
  ans+=mod;
  ans%=mod;
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
