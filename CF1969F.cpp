#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <map>
#include <utility>
#define int long long
inline int read();
int dp[1005];
int cn2t[1005];
int mp[1005][1005];
int a[1005];
std::bitset<1005>bit;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int cnt=0;
  memset(dp,0x3f,sizeof(dp));
  int st=0;
  int acnt=0;
  for(int i=1;i<=n;i+=2){
    bit[a[i]]=bit[a[i]]^1;
    if(bit[a[i]]==0){
      cnt--;
      acnt++;
    }else{
      cnt++;
    }
    bit[a[i+1]]=bit[a[i+1]]^1;
    if(bit[a[i+1]]==0){
      cnt--;
      acnt++;
    }else{
      cnt++;
    }
    if(cnt==k){
      st=i;
      break;
    }
  }
  if(st==0){
    printf("%lld\n",acnt);
    return 0;
  }
  st+=2;
  dp[st]=1;
  for(int i=st;i<=n;i+=2){
    bit=0;
    int cntt=2;
    int zhuan=0;
    cn2t[a[i]]=1;
    cn2t[a[i+1]]=1;
    bit[a[i]]=1;
    bit[a[i+1]]=bit[a[i+1]]^1;
    if(bit[a[i]]==0){
      cntt=0;
    }
    for(int j=i+2;j<=n+1;j+=2){
      if(cntt==2){
        int fir=bit._Find_first();
        int nxt=bit._Find_next(fir);
        if(mp[fir][nxt]){
          goto tt2;
        }
        zhuan++;
        mp[fir][nxt]=1;
        dp[j]=std::min(dp[j],dp[i]+1);
      }
      tt2:{}
      cn2t[a[j]]++;
      cn2t[a[j+1]]++;
      bit[a[j]]=bit[a[j]]^1;
      if(bit[a[j]]){
        cntt++;
      }else{
        cntt--;
      }
      bit[a[j+1]]=bit[a[j+1]]^1;
      if(bit[a[j+1]]){
        cntt++;
      }else{
        cntt--;
      }
    }
    int mn=0x3f3f3f3f;
    for(int j=1;j<=k;j++){
      for(int k2=j+1;k2<=k;k2++){
        if(mp[j][k2]){
          mp[j][k2]=0;
          continue;
        }
        bit[j]=bit[j]^1;
        bit[k2]=bit[k2]^1;
        mn=std::min(mn,(int)(k-bit.count()));
        bit[j]=bit[j]^1;
        bit[k2]=bit[k2]^1;
      }
    }
    dp[n+2]=std::min(dp[n+2],dp[i]+mn/2);
  }
  dp[n+2]=std::min(dp[n+2],dp[n+1]+k/2-1);
  printf("%lld",n/2-dp[n+2]);
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

