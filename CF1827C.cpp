#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define int long long
inline int read();
char temp[500005];
int hash[500005];
int invhash[500005];
int pw[500005];
int inv[500005];
int pal[500005];
int nxt[500005];
std::priority_queue<int>qu;
std::vector<int>in[500005];
int base=50;
int mod=998244353;
int dp[500005];
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    y>>=1;
    x*=x;
    x%=mod;
  }
  return ans;
}
int calcA(int l,int r){
  return (1ll*(hash[r]-hash[l-1])*inv[l]%mod+mod)%mod;
}
int calcB(int l,int r){
  return (1ll*(invhash[r]-invhash[l-1])*inv[500000-r+1]%mod+mod)%mod;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  pw[0]=1;
  for(int i=1;i<=500000;i++){
    pw[i]=1ll*pw[i-1]*base%mod;
  }
  inv[500000]=pow(pw[500000],mod-2);
  for(int i=500000-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*base%mod;
  }
  while(T--){
    int n=read();
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      dp[i]=0;
      hash[i]=hash[i-1];
      hash[i]+=1ll*pw[i]*(temp[i]-'a'+2)%mod;
      hash[i]%=mod;
      invhash[i]=invhash[i-1];
      invhash[i]+=1ll*pw[500000-i+1]*(temp[i]-'a'+2);
      invhash[i]%=mod;
    }
    for(int i=2;i<=n;i++){
      //i-1 & i
      int l=1,r=std::min(i-1,n-i+1);
      while(r-l>3){
        int mid=(l+r)/2;
        if(calcA(i-mid,i+mid-1)==calcB(i-mid,i+mid-1)){
          l=mid;
        }else{
          r=mid;
        }
      }
      pal[i]=0;
      for(int mid=r;mid>=l;mid--){
        if(calcA(i-mid,i+mid-1)==calcB(i-mid,i+mid-1)){
          pal[i]=mid;
          break;
        }
      }
      in[i-pal[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
      for(int j=0;j<in[i].size();j++){
        qu.push(-in[i][j]);
      }
      in[i].clear();
      while(qu.size()>0&&-qu.top()<=i){
        qu.pop();
      }
      if(qu.size()==0){
        nxt[i]=-1;
      }else{
        nxt[i]=2*-qu.top()-i;
      }
    }
    qu=std::priority_queue<int>();
    int ans=0;
    for(int i=n;i>=1;i--){
      if(nxt[i]==-1){
        dp[i]=0;
      }else{
        dp[i]=dp[nxt[i]]+1;
      }
      ans+=dp[i];
    }
    for(int i=1;i<=n;i++){
      dp[i]=0;
    }
    printf("%lld\n",ans);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
