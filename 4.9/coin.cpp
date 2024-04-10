#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define mod 998244353
inline int read();
std::map<long long,int>mp;
int a[1000005];
int ans=0;
long long tt=0;
long long cnt=0;
int n;
void dfs(int now){
  if(now==n*2+1){
    if(cnt==n){
      ans+=mp[tt];
    }
    ans%=mod;
    return ;
  }
  if(cnt>=n){
    dfs(now+1);
    return ;
  }
  dfs(now+1);
  if((tt&(1ll<<(now-1)))==0){
    tt|=(1ll<<(now-1));
    cnt++;
    dfs(now+1);
    cnt--;
    tt^=(1ll<<(now-1));
  }
  return ;
}
void dfs2(int now){
  if(now==n*2+1){
    if(cnt==n){
      ans+=mp[tt];
    }
    ans%=mod;
    return ;
  }
  if(cnt<=n){
    dfs(now+1);
    return ;
  }
  dfs2(now+1);
  if((tt&(1ll<<(now-1)))!=0){
    tt^=(1ll<<(now-1));
    cnt--;
    dfs(now+1);
    cnt++;
    tt^=(1ll<<(now-1));
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("coin.in","r",stdin);
  freopen("coin.out","w",stdout);
  #endif
  n=read();
  int m=read();
  for(int i=n+1;i<=2*n;i++){
    a[i]=1;
  }
  do{
    long long tt=0;
    long long ans=1;
    int cnt1=0;
    int cnt2=0;
    for(int i=1;i<=2*n;i++){
      if(a[i]){
        tt|=(1ll<<(i-1));
      }
      if(cnt1==n||cnt2==n){
        if((a[i]^(cnt2==n))){
          if(a[i]){
            cnt2++;
          }else{
            cnt1++;
          }
        }else{
          ans=0;
        }
      }else{
        if(a[i]){
          cnt2++;
        }else{
          cnt1++;
        }
        ans*=(mod+1)/2;
        ans%=mod;
      }
    }
    mp[tt]=ans;
  }while(std::next_permutation(a+1,a+2*n+1));
  for(int i=1;i<=m;i++){
    int t=read();
    cnt=t;
    tt=0;
    for(int i=1;i<=t;i++){
      tt|=(1ll<<(read()-1));
    }
    ans=0;
    dfs(1);
    tt^=((1<<(2*n))-1);
    cnt=2*n-cnt;
    dfs2(1);
    printf("%lld\n",ans);
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

