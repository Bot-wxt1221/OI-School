#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define int long long
inline int read();
int seq[5000005];
int yin[5000005];
int yin2[5000005];
int ans[5000005];
int cnt;
std::map<int,int>mp;
int pow(int a,int b,int mod){
  __int128 ans=1;
  __int128 cur=a;
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

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("random_17.txt","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int p=read();
  int sp=std::sqrt((long long)p);
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  int tmp=p-1;
  for(int i=2;i<=sp;i++){
    while(tmp%i==0){
      yin[++cnt]=i;
      tmp/=i;
    }
  }
  if(tmp){
    yin[++cnt]=tmp;
  }
  int cnt2=0;
  for(int i=1;i<=sp;i++){
    if((p-1)%i==0){
      yin2[++cnt2]=i;
      mp[i]=cnt2;
      if((p-1)/i!=i){
        yin2[++cnt2]=(p-1)/i;
        mp[(p-1)/i]=cnt2;
      }
    }
  }
  for(int i=1;i<=n;i++){
    int id=p-1;
    for(int j=1;j<=cnt;j++){
      if(pow(seq[i],id/yin[j],p)==1){
        id/=yin[j];
      }
    }
    ans[mp[id]]++;
  }
  int ans=0;
  for(int i=1;i<=cnt2;i++){
    for(int j=1;j<=cnt2;j++){
      if(yin2[j]%yin2[i]==0){
        ans+=::ans[i]*::ans[j];
      }
    }
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


