#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define mod 998244353
std::map<int,int>mp,vised[200005];
std::vector<int>vec[200005];
std::vector<int>mp2[200005];
inline int read();
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("list.in","r",stdin);
  freopen("list.out","w",stdout);
  #endif
  int cnt=0;
  int n=read();
  for(int i=1;i<=n;i++){
    int siz=read();
    if(mp[siz]==0){
      mp[siz]=++cnt;
    }
    for(int j=1;j<=siz;j++){
      vec[i].push_back(read());
    }
  }
  int q=read();
  int cntm=0;
  for(int i=1;i<=q;i++){
    int a=read();
    int b=read();
    if(vec[a].size()>vec[b].size()){
      std::swap(a,b);
    }
    //a<b
    int to=0;
    if(vised[b][vec[a].size()]){
      to=vised[b][vec[a].size()];
    }else{
      to=vised[b][vec[a].size()]=i;
      mp2[i].resize(vec[a].size());
      for(int j=0;j<vec[b].size();j++){
        mp2[i][j%vec[a].size()]+=vec[b][j];
        mp2[i][j%vec[a].size()]%=mod;
      }
    }
    int ans=0;
    for(int j=0;j<mp2[to].size();j++){
      ans+=(1ll*mp2[to][j]*vec[a][j])%mod;
      ans%=mod;
    }
    printf("%d\n",ans);
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


