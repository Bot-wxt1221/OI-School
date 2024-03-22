#include <iostream>
#include <cstdio>
#include <map>
#define int long long
inline int read();
int a[100005];
std::map<int,int>mp;
int pow(int a,int b,int p){
  if(b==0){
    return 1;
  }
  if(a==0&&b==0){
    return 1;
  }
  int ans=1;
  int cur=a%p;
  int tag=0,tag2=0;
  if(a>=p){
    tag=1;
  }
  while(b){
    if(b%2==1){
      ans*=cur;
      if(ans>=p){
        tag=1;
      }
      tag|=tag2;
      ans%=p;
    }
    cur*=cur;
    if(cur>=p){
      tag2=1;
    }
    cur%=p;
    b/=2;
  }
  return ans+tag*p;
}
int phi(int p){
  if(mp[p]){
    return mp[p];
  }
  mp[p]=1;
  auto to=mp.find(p);
  int tp=p;
  for(int i=2;i*i<=tp;i++){
    if(p%i==0){
      (to->second)*=(i-1);
      p/=i;
      while(p%i==0){
        (to->second)*=i;
        p/=i;
      }
    }
  }
  if(p>1){
    (to->second)*=(p-1);
  }
  return to->second;
}
int dfs(int l,int r,int p){
  if(p==1){
    return a[l]%p+(a[l]>=p)*p;
  }
  if(l==r){
    return a[l]%p+(a[l]>=p)*p;
  }
  return pow(a[l],dfs(l+1,r,phi(p)),p);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int p=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    printf("%lld\n",dfs(l,r,p)%p);
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


