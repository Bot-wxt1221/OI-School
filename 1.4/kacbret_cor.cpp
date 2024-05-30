#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define int long long
inline int read();
char temp[300005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  int nxt=-1;
  for(int i=siz;i>=1;i--){
    
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


