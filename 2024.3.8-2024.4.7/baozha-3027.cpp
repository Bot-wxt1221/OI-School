#include <iostream>
#include <cstdio>
#include <map>
#define mod 2004
#define int long long
inline int read();
std::map<int,int> poly[2];
int C[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int a=read();
  int b=read();
  int op=0;
  poly[op][0]=1;
  for(int i=1;i<=n;i++){
    int aa=0;
    int bb=read();
    op^=1;
    poly[op].clear();
    for(auto i=poly[op^1].begin();i!=poly[op^1].end();i++){
      poly[op][i->first+aa]+=mod-i->second;
      poly[op][i->first+aa]%=mod;
      poly[op][i->first+bb+1]+=i->second;
      poly[op][i->first+bb+1]%=mod;
    }
  }
  int ans=0;
  C[0]=1;
  for(auto i=poly[op].begin();i!=poly[op].end();i++){
    int tt=i->second;

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

