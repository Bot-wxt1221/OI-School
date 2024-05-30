#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <random>
#define mod 1000000000000000177
inline int read();
int a[300005];
long long hs[300005];
std::vector<int> te;
std::map<long long,int>mp;
long long ans=0;
void cdq(int l,int r){
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  cdq(mid+1,r);
  int siz=0;
  long long ha=0;
  te.clear();
  mp.clear();
  for(int i=mid;i>=l;i--){
    if(siz>0&&te[siz-1]==a[i]){
      te.pop_back();
      ha-=(((__int128)a[i])*hs[siz])%mod;
      ha%=mod;
      ha+=mod;
      ha%=mod;
      siz--;
    }else{
      te.push_back(a[i]);
      siz++;
      ha+=(((__int128)a[i])*hs[siz])%mod;
      ha+=mod;
      ha%=mod;
    }
    mp[ha]++;
  }
  ha=0;
  siz=0;
  te.clear();
  for(int i=mid+1;i<=r;i++){
    if(siz>0&&te[siz-1]==a[i]){
      te.pop_back();
      ha-=(((__int128)a[i])*hs[siz])%mod;
      ha%=mod;
      ha+=mod;
      ha%=mod;
      siz--;
    }else{
      te.push_back(a[i]);
      siz++;
      ha+=(((__int128)a[i])*hs[siz])%mod;
      ha+=mod;
      ha%=mod;
    }
    ans+=mp[ha];
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("bracketplus.in","r",stdin);
  freopen("bracketplus.out","w",stdout);
  #endif
  srand(time(NULL));
  std::mt19937_64 ran;
  for(int i=1;i<=300000;i++){
    hs[i]=ran()%mod;
  }
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    ans=0;
    cdq(1,n);
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

