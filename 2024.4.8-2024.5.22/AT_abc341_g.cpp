#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
std::stack<long double>st2;
int st[2000005];
int tp;
int a[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    a[i]+=a[i-1];
  }
  for(int i=n;i>=0;i--){
    while(tp>1&&(a[i]-a[st[tp]])*1.0/(i-st[tp])<(a[st[tp]]-a[st[tp-1]])*1.0/(st[tp]-st[tp-1])){
      tp--;
    }
    st[++tp]=i;
    int cur=i;
    if(tp>1){
      cur=st[tp-1];
    }
    if(i==n){
    }else{
      st2.push(((long double)(a[cur]-a[i]))/(cur-i));
    }
  }
  while(st2.size()>0){
    printf("%.8Lf\n",st2.top());
    st2.pop();
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

