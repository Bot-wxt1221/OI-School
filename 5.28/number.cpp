#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int C[105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  #endif
  C[1][1]=1;
  for(int i=1;i<=100;i++){
    C[i][1]=i;
    for(int j=2;j<=i;j++){
      C[i][j]=C[i-1][j]+C[i-1][j-1];
      if(C[i][j]>(int)1e19){
        C[i][j]=(int)1e19+1;
      }
    }
  }
  C[0][0]=1;
  int T=read();
  while(T--){
    int m=read(),k;
    k=read();
    k--;
    int bkk=k;
    int bm=m;
    int ans=0;
    for(int i=63;i>=1;i--){
      if(k==0||m<=C[i-1][k]){
        ans*=2;
      }else{
        m-=C[i-1][k];
        ans*=2;
        ans++;
        k--;
      }
    }
    m=bm+1;
    k=bkk;
    int bkans=ans;
    ans=0;
    for(int i=63;i>=1;i--){
      if(k==0||m<=C[i-1][k]){
        ans*=2;
      }else{
        m-=C[i-1][k];
        ans*=2;
        ans++;
        k--;
      }
    }
    bkans++;
    printf("%lld %lld\n",(long long)bkans,(long long)(ans-bkans+1));
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

