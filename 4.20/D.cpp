#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
inline int read();
int a[100005];
std::vector<int>vec[100005];
std::bitset<1200000005>bit;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  #endif
  int T=read();
  for(int i=1;i*i<=(1<<30);i++){
    bit[i*i]=1;
  }
  bit[0]=1;
  while(T--){
    int n=read();
    int q=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    for(int i=1;i<=n;i++){
      int cur=0;
      for(int j=i;j<=n;j++){
        cur&=a[j];
        if(bit[cur]){
          vec[i].push_back(j);
        }
      }
    }
    for(int i=1;i<=q;i++){
      int l=read();
      int r=read();
      int ans=0;
      for(int i2=l;i2<=r;i2++){
        ans+=std::max(int(std::upper_bound(vec[i2].begin(),vec[i2].end(),r)-vec[i2].begin()-1),0);
      }
      printf("%d\n",ans);
    }
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

