#include <iostream>
#include <cstdio>
#define int long long
inline int read();
class st{
  public:
    int a,b,c;
    st(int x=0,int y=0,int z=0){
      a=x;
      b=y;
      c=z;
      return ;
    }
}a[100005],b[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("party.in","r",stdin);
  freopen("party2.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i].a=read();
    a[i].b=read();
    a[i].c=read();
  }
  for(int i=1;i<=n;i++){
    b[i].a=read();
    b[i].b=read();
    b[i].c=read();
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int l=std::max(a[i].a,b[j].a);
      int r=std::min(a[i].b,b[j].b);
      ans=std::max((r-l+1)*a[i].c*b[j].c,ans);
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
