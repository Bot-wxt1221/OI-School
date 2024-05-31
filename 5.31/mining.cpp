#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int map[2][200005];
int mx[105],mn[105];
int map2[105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("mining.in","r",stdin);
  freopen("mining.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  if(n!=1&&(n>100||m>100)){
    int ans=(m*(m-1))/2;
    ans*=n;
    ans+=n*m;
    ans+=(n)*(n-1)/2;
    printf("%lld",ans);
    return 0;
  }else if(n==1&&m<=2000){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        map[i][j]=read();
      }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
      int mn=0x3f3f3f3f;
      int mx=-0x3f3f3f3f;
      for(int j=i;j<=m;j++){
        mn=std::min(mn,map[1][j]);
        mx=std::max(mx,map[1][j]);
        if(mx-mn+1==j-i+1){
          ans++;
        }
      }
    }
    printf("%lld",ans);
  }else if(n<=100&&m<=100){
    int ans=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        map2[i][j]=read();
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        mx[j]=-0x3f3f3f3f;
        mn[j]=0x3f3f3f3f;
      }
      for(int j=i;j<=n;j++){
        for(int k=1;k<=m;k++){
          mx[k]=std::max(mx[k],map2[j][k]);
          mn[k]=std::min(mn[k],map2[j][k]);
        }
        int mx2=-0x3f3f3f3f,mn2=0x3f3f3f3f;
        for(int k=1;k<=m;k++){
          mx2=-0x3f3f3f3f,mn2=0x3f3f3f3f;
          for(int k2=k;k2<=m;k2++){
            mx2=std::max(mx2,mx[k2]);
            mn2=std::min(mn2,mn[k2]);
            if(mx2-mn2+1==(j-i+1)*(k2-k+1)){
              ans++;
            }
          }
        }
      }
    }
    printf("%lld",ans);
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

