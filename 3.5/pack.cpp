#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
class node{
  public:
    int a,b;
    node(int x=0,int y=0){
      a=x;
      b=y;
      return ;
    }
}a[100005];
int aa[100005];
int aa2[100005];
const bool operator < (const node &a,const node &b){
  return a.a==b.a?a.b>b.b:a.a>b.a;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("pack.in","r",stdin);
  freopen("pack.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i].a=read();
    a[i].b=read();
  }
  std::sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    aa[n-i+1]=a[i].a;
  }
  for(int i=1;i<=n;i++){
    a[i].a+=a[i-1].a;
    a[i].b+=a[i-1].b;
    aa2[i]=a[i].a;
  }
  for(int i=1;i<=m;i++){
    int ans=0;
    int ci=read();
    int pre=1;
    while(1){
      int pos=std::upper_bound(aa+1,aa+n-pre+2,ci)-aa-1;
      pos=n-pos+1;
      int pos2=std::upper_bound(aa2+pos,aa2+n+1,aa2[pos-1]+ci)-aa2-1;
      if(pos>pos2){
        break;
      }
      pre=pos2+1;
      ci-=a[pos2].a-a[pos-1].a;
      ans+=a[pos2].b-a[pos-1].b;
    }
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


