#include <iostream>
#include <cstdio>
inline int read();
long double g[1000005];
long double f[1000005];
int lowbit(int x){
  return (x)&(-x);
}
class BIT{
  public:
    long double tree[2000005];
    long double query(int x){
      long double ans=0;
      while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,long double y){
      while(x<=2000001){
        tree[x]+=y;
        x+=lowbit(x);
      }
    }
}t1;
int l,n;
long double calc(int x){
  long double ans=1-g[n];
  if(x>l){
    ans+=g[x-1];
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  l=read();
  int d=read();
  t1.mod(1,1);
  t1.mod(2,-1);
  for(int i=0;i<=n;i++){
    g[i]=t1.query(i+1);
    if(i<l){
      t1.mod(i+2,g[i]/d);
      t1.mod(i+d+2,-g[i]/d);
      g[i]=0;
    }
  }
  for(int i=1;i<=n;i++){
    g[i]+=g[i-1];
  }
  long double sum=0;
  for(int i=n;i>=0;i--){
    f[i]=std::max(sum/d,calc(i));
    sum+=f[i];
    if(i+d<=n){
      sum-=f[i+d];
    }
  }
  printf("%.15Lf",f[0]);
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

