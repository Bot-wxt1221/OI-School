#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
inline int read();
long double summ[105];
long double p[105];
long double sum[105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  long double cnt=1;
  for(int i=1;i<=n;i++){
    p[i]=read()/100.0;
    cnt*=p[i];
    summ[i]=1-p[i];
  }
  long double ans=cnt*n;
  std::cerr<<ans;
  for(int i=n+1;i<=3e5;i++){
    long double now=0;
    int curr=0;
    for(int j=1;j<=n;j++){
      long double cur=cnt/(1-summ[j])*(1-summ[j]*(1-p[j]));
      if(cur>now){
        now=cur;
        curr=j;
      }
    }
    ans+=(now-cnt)*i;
    cnt=now;
    summ[curr]*=(1-p[curr]);
    std::cerr<<now<<std::endl;
  }
    printf("%.7Lf",ans);
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
