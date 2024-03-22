#include <cmath>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[5];
int b[5];
void exgcd(int a,int b,int &g,int &x,int &y) {
    if (b == 0) {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,g,y,x);
    y-=(a/b)*x;
    return ;
}

void china(int &a1,int &b1,int &a2,int &b2){
    int d=a2-a1;
    int g,x,y;
    exgcd(b1,b2,g,x,y);
    if(d%g==0){
        x=(((x*d/g)%(b2/g)+(b2/g)))%(b2/g);
        a1+=x*b1;
        b1=(b1*b2)/g;
    }
    return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int TT=0;
  while(T--){
    int n=read()*2;
    int m=read()*2;
    int x1=read()*2;
    int y1=read()*2;
    int x2=read()*2;
    int y2=read()*2;
    int ans=0;
    int x,y,p,mod;
    if(x1==x2&&y1==y2){
      ans=0;
      goto out;
    }
    if(x1==x2){
      ans=(m)-((y1+y2)/2);
      goto out;
    }else if(y1==y2){
      ans=(n)-((x1+x2)/2);
      goto out;
    }
    b[1]=n;
    a[1]=n-(x1+x2)/2;
    b[2]=m;
    a[2]=m-(y1+y2)/2;
    exgcd(n,m,p,x,y);
    if((a[2]-a[1])%p!=0){
      ans=-0x3f3f3f3f;
      goto out;
    }
    x=x*((a[2]-a[1])/p);
    mod=m/p;
    x%=mod;
    x+=mod;
    x%=mod;
    ans=x*n+a[1];
    out:{}
    int x1t=((ans)+x1)%(2*n);
    if(x1t>n){
      x1t=2*n-x1t;
    }
    int y1t=((ans)+y1)%(2*m);
    if((y1t)>m){
      y1t=2*m-y1t;
    }
    if(ans!=-0x3f3f3f3f){
      printf("Case #%lld:\n%.1lf %.1lf\n",++TT,x1t/2.0,y1t/2.0);
    }else{
      fail:{}
      printf("Case #%lld:\nCollision will not happen.\n",++TT);
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


