#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define mod 998244353
#define int __int128
inline int read();
int a[25];
int b[25];
class Poly{
  public:
    std::map<int,int>vec;
};
Poly operator * (Poly a,Poly b){
  Poly ans;
  for(auto i=a.vec.begin();i!=a.vec.end();i++){
    for(auto j=b.vec.begin();j!=b.vec.end();j++){
      ans.vec[i->first+j->first]+=(i->second*j->second)%mod;
      ans.vec[i->first+j->first]%=mod;
    }
  }
  return ans;
}
int pow(int a,int b){
  long long ans=1;
  long long cur=a;
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
int t[25];
Poly aa,bb;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  aa.vec[0]=1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
  }
  for(int i=1;i<=n;i++){
    t[i]=1;
    for(int j=1;j<=n;j++){
      if(i==j){
        continue;
      }
      int tt=a[j];
      tt*=pow(a[i],mod-2);
      tt%=mod;
      tt=mod-tt;
      tt++;
      tt%=mod;
      t[i]*=tt;
      t[i]%=mod;
    }
    t[i]=pow(t[i],mod-2);
    bb.vec.clear();
    bb.vec[0]=1;
    bb.vec[b[i]+1]=mod-pow(a[i],b[i]+1);
    aa=aa*bb;
  }
  int ans=0;
  for(auto i=aa.vec.begin();i!=aa.vec.end();i++){
    if(i->first>m){
      continue;
    }
    int tt=(m-i->first);
    int xi=0;
    for(int j=1;j<=n;j++){
      xi+=(pow(a[j],tt)*t[j]%mod);
      xi%=mod;
    }
    ans+=(xi*i->second)%mod;
    ans%=mod;
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

