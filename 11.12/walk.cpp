#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int x[15];
int y[15];
int ny[15];
int nx[15];
void out(int x)
{
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

class fra{
public:
  __int128 a=0x3f3f3f3f3f3f3f3f,b=1;
}ans,b;
bool operator < (fra a,fra b){
  return (__int128)a.a*b.b<(__int128)b.a*a.b;
}
namespace std{
 int ttabs(int a){
  if(a<0){
    return -a;
  }
  return a;
} 
}
#define abs ttabs
int dp[(1<<13)+5][15];
int getans(int fi,int fj,int i,int j){
  int tx=x[fi]-x[fj];
  int ty=y[fi]-y[fj];

  int xx=x[i]-x[j];
  int xy=y[i]-y[j];
  if(tx==0||ty==0){
    return std::abs(xx)+std::abs(xy);
  }
  int k=(tx*xx+ty*xy)*tx;
  int ret=xx*(tx*tx+ty*ty)-k;
  k=std::abs(k);
  ret=std::abs(ret);
  int ans=k*std::abs(ty);
  ans+=ret*std::abs(tx);
  return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    y[i]=read();
  }
  x[n+1]=x[1];
  y[n+1]=y[1];
  n++;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      int xx=x[i]-x[j];
      int yy=y[i]-y[j];
      if(xx==0&&yy==0){
        continue;
      }
      memset(dp,0x3f,sizeof(dp));
      dp[1][1]=0;
      int ans=0x3f3f3f3f3f3f3f3f;
      for(int k=0;k<(1<<n);k++){
        for(int kk=1;kk<=n;kk++){
          for(int kk2=1;kk2<=n;kk2++){
            if(kk==kk2){
              continue;
            }
            if((k&(1<<(kk-1)))&&(k&(1<<(kk2-1)))){
              dp[k][kk]=std::min(dp[k][kk],dp[k^(1<<(kk-1))][kk2]+getans(i,j,kk2,kk));
              if(k==((1<<(n))-1)&&kk==n){
                ans=std::min(ans,dp[k][kk]);
              }
            }
          }
        }
      }
      if(xx==0||yy==0){
        b.a=(__int128)ans*ans;
        b.b=(__int128)1;
      }else{
        int ttx=xx;
        int tty=yy;
        int tt=std::__gcd(ans,xx);
        ans/=tt;
        ttx/=tt;
        tt=std::__gcd(ans,yy);
        ans/=tt;
        tty/=tt;
        __int128 ttt=ans*ans;
        int lst=xx*xx+yy*yy;
        tt=std::__gcd(ttt,lst);
        ttt/=tt;
        lst/=tt;
        b.a=(__int128)ttt;
        b.b=((__int128)(ttx*ttx*(lst))*tty*tty);
      }
      int tt=std::__gcd(b.a,b.b);
      b.a/=tt;
      b.b/=tt;
      ::ans=std::min(::ans,b);
    }
  }
  out(::ans.a);
  putchar(' ');
  out(::ans.b);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
