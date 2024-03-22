#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
inline int rd();
int f[25][2525][55];
int m[2525];
int di[2525];
int fs(int si,int pe,int md,int lim){
  if(si==0){
    return (pe%md)==0;
  }
  if(lim==0&&f[si][pe][m[md]]!=-1){
    return f[si][pe][m[md]];
  }
  int ans=0;
  int mx=lim?di[si]:9;
  for(int i=0;i<=mx;i++){
    ans+=(fs(si-1,(pe*10+i)%2520,(i==0?md:md*i/std::__gcd(md,i)),lim&&(i==mx)));
  }
  if(lim==0){
    f[si][pe][m[md]]=ans;
  }
  return ans;
}
int calc(int x){
  int si=0;
  while(x){
    di[++si]=x%10;
    x/=10;
  }
  return fs(si,0,1,1);
}
signed main(){
  int T=rd();
  memset(f,-1,sizeof(f));
  int cnt=0;
  for(int i=1;i<=2520;i++){
    if(2520%i==0){
      m[i]=++cnt;
    }
  }
  while(T--){
    int l=rd();
    int r=rd();
    printf("%lld\n",calc(r)-calc(l-1));
  }
	return 0;
}
inline int rd(){
  int x=0;
  scanf("%lld",&x);
	return x;
}
