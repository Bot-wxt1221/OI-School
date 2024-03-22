#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#define int long long
inline int read();
int mod;
int pow(int a,int b){
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
int exgcd(int x,int y,int &a,int &b){
  if(y==0){
    a=1;
    b=0;
    return x;
  }else{
    int ta,tb;
    int ret=exgcd(y,x%y,ta,tb);
    a=tb;
    b=(ta)-(x/y)*tb;
    return ret;
  }
}
int bsgs(int a,int b){
  a%=mod;
  b%=mod;
  std::map<int,int>mp;
  int smod=std::sqrt(mod)+1;
  int t=1;
  for(int i=1;i<=smod;i++){
    if(mp[t]==0){
      mp[t]=i;
    }
    t*=a;
    t%=mod;
  }
  int k=pow(t,mod-2);
  int w=b;
  for(int i=1;i<=smod;i++){
    if(mp[w]){
      return (i-1)*smod+mp[w]-1;
    }
    w*=k;
    w%=mod;
  }
  return -2;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int p=read(),a,b;
    a=read();
    b=read();
    mod=p;
    int x1=read();
    int t=read();
    if(x1==t){
      printf("1\n");
      continue;
    }
    if(a==0){
      if(b==t){
        printf("2\n");
      }else{
        printf("-1\n");
      }
      continue;
    }
    if(a==1){
      int tx=((t-x1)%p+p)%p;
      if(b==0){
        printf("-1\n");
      }else{
        int ans=tx*pow(b,mod-2);
        ans%=mod;
        printf("%lld\n",ans+1);
      }
      continue;
    }
    printf("%lld\n",bsgs(a,((t-(b*pow(1-a,mod-2)))%mod+mod)%mod*pow((x1-(b*pow(1-a,mod-2)%mod))%mod+mod,mod-2))+1);
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


