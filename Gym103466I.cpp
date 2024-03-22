#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define mod 1000000007
inline int read();
int cnt[55];
int n;
int fra[100005];
int inv[100005];
std::map<std::vector<int>,int>mp;
inline int pow(int a,int b,int p){
  a%=p;
  if(a==0&&b==0){
    return 1;
  }
  long long ans=1;
  long long cur=a;
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
std::vector<int>a;
int dfs(int sum,int used){
  if(sum>=50){
    return fra[n-cnt[0]-used];
  }
  if(used==n-cnt[0]){
    return 1;
  }
  if(mp.count(a)){
    return mp[a];
  }
  int cnt=0;
  bool left=0;
  for(int i=1;i<=sum;i++){
    if(a[i]+1<=::cnt[i]){
      a[i]++;
      cnt+=1ll*dfs(sum+i,used+1)*(::cnt[i]-a[i]+1)%mod;
      cnt%=mod;
      a[i]--;
    }
  }
  return mp[a]=cnt;
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a0;
  scanf("%d%d",&n,&a0);
  for(int i=1;i<=n;i++){
    int temp;
    scanf("%d",&temp);
    cnt[temp]++;
  }
  fra[1]=1;
  for(int i=2;i<=n;i++){
    fra[i]=(1ll*fra[i-1]*i)%mod;
  }
  inv[n]=pow(fra[n],mod-2,mod);
  for(int i=n-1;i>=1;i--){
    inv[i]=(1ll*inv[i+1]*(i+1))%mod;
  }
  a.resize(51);
  inv[0]=1;
  printf("%lld",dfs(a0,0)*1ll*fra[n]%mod*inv[n-cnt[0]]%mod);
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


