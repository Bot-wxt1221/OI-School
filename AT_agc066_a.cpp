#include <iostream>
#include <cstdio>
inline int read();
int a[505][505];
int a2[505][505];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int d=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[i][j]=read();
    }
  }
  for(int tt=0;tt<2*d;tt++){
    int diff=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if((i+j)%2){
          int aa=(tt-a[i][j])%(2*d);
          aa+=(2*d);
          aa%=(2*d);
          int bb=(a[i][j]-tt)%(2*d);
          bb+=2*d;
          bb%=(2*d);
          if(std::abs(aa)<std::abs(bb)){
            diff+=std::abs(aa);
            a2[i][j]=a[i][j]+aa;
          }else{
            diff+=std::abs(bb);
            a2[i][j]=a[i][j]-bb;
          }
        }else{
          int tt2=(tt+d)%(2*d);
          int aa=(tt2-a[i][j])%(2*d);
          aa+=(2*d);
          aa%=(2*d);
          int bb=(a[i][j]-tt2)%(2*d);
          bb+=2*d;
          bb%=(2*d);
          if(std::abs(aa)<std::abs(bb)){
            diff+=std::abs(aa);
            a2[i][j]=a[i][j]+aa;
          }else{
            diff+=std::abs(bb);
            a2[i][j]=a[i][j]-bb;
          }
        }
      }
    }
    if(diff<=(d*n*n)/2){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          printf("%d ",a2[i][j]);
        }
        printf("\n");
      }
      goto end;
    }
  }
  end:{};
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

