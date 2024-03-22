#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
std::stack<int>st;
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read()-1;
  if(n==0){
    printf("0");
  }
  while(n){
    st.push(n%5);
    n/=5;
  }
  while(st.size()>0){
    int tp=st.top();
    st.pop();
    printf("%lld",tp*2);
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


