#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#define int long long
inline int read();
int pow(int a,int b,int p){
  a%=p;
  if(a==0&&b==0){
    return 1;
  }
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
int ques2(int y,int z,int p){
  int a,b;
  y%=p;
  z%=p;
  int ret=exgcd(y,p,a,b);
  if(z%ret){
    return -1;
  }
  a*=z/ret;
  a%=p;
  a+=p;
  a%=p;
  return a;
}
int bsgs(int a,int b,int mod){
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
  int k=pow(t,mod-2,mod);
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

int ques3(int y,int z,int p){
  int k=0;
  int gcd;
  z%=p;
  y%=p;
  while((gcd=std::__gcd(y,p))>1){
    if(z%gcd){
      return -1;
    }
    k++;
    y/=gcd;
    z/=gcd;
    p/=gcd;
  }
  int ret=bsgs(y,z,p);
  if(ret!=-2){
    return (ret+k)%p;
  }
  for(int i=0;i<=k;i++){
    if(pow(y,i)==z){
      return i;
    }
  }
  return -1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int k=read();
  while(T--){
    int y=read();
    int z=read();
    int p=read();
    switch(k){
      case 1:{
        printf("%lld\n",pow(y,z,p));
        break;
      }
      case 2:{
        int ans=ques2(y,z,p);
        if(ans==-1){
          printf("Orz, I cannot find x!\n");
        }else{
          printf("%lld\n",ans);
        }
        break;
      }
      case 3:{
        if(y%p==0&&z%p==0){
          printf("1\n");
          break;
        }
        int ans=ques3(y,z,p);
        if(ans==-1){
          printf("Orz, I cannot find x!\n");
        }else{
          printf("%lld\n",ans);
        }
        break;
      }
    }
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


