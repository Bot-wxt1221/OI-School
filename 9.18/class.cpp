#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
char temp[100005];
int siz[25];
long long dp[(1<<16)];
std::vector<int>vec[16][16];
std::vector<int>se[16];
long long get(int siz,int k){
  return ((1ll*k*(k-1))+1ll*(siz-k)*(siz-k-1));
}
long long get2(int S,int u,int siz,int k){
  long long ans=get(siz,k);
  for(int i=1;i<=15;i++){
    if(S&(1<<(i-1))){
      ans+=vec[i][u][k]*4;
    }
  }
  return ans;
}
long long w(int S,int u){
  int l=0,r=siz[u];
  while(r-l>4){
    int mid1=(r-l)/3+l;
    int mid2=r-(r-l)/3;
    if(get2(S,u,siz[u],mid1)>get2(S,u,siz[u],mid2)){
      l=mid1;
    }else{
      r=mid2;
    }
  }
  long long mn=0x3f3f3f3f3f3f3f3f;
  for(int i=l;i<=r;i++){
    mn=std::min(mn,get2(S,u,siz[u],i));
  }
  return mn;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  for(int i=1;i<=n;i++){
    siz[temp[i]-'A'+1]++;
    se[temp[i]-'A'+1].push_back(i);
  }
  for(int i=1;i<=15;i++){
    for(int j=1;j<=15;j++){
      int cur=0;
      vec[i][j].resize(siz[j]+5);
      int ret=0;
      for(int k=1;k<=siz[j];k++){
        while(cur<se[i].size()&&se[i][cur]<se[j][k-1]){
          ret++;
          cur++;
        }
        vec[i][j][k]=vec[i][j][k-1]+ret;
      }
      cur=siz[i]-1;
      ret=0;
      int pre=0;
      for(int k=siz[j];k>0;k--){
        while(cur>=0&&se[i][cur]>se[j][k-1]){
          ret++;
          cur--;
        }
        vec[i][j][k-1]+=pre+ret;
        pre=ret+pre;
      }
    }
  }
  for(int i=0;i<(1<<15);i++){
    dp[i]=0x3f3f3f3f3f3f3f3f;
  }
  dp[0]=0;
  for(int i=1;i<(1<<15);i++){
    for(int j=1;j<=15;j++){
      if(i&(1<<(j-1))){
        dp[i]=std::min(dp[i],dp[i^(1<<(j-1))]+w(i^(1<<(j-1)),j));
      }
    }
  }
  long long ans=(dp[(1<<15)-1]);
  printf("%lld",ans/4);
  if(ans%4==1){
    printf(".25");
  }else if(ans%4==2){
    printf(".5");
  }else if(ans%4==3){
    printf(".75");
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
