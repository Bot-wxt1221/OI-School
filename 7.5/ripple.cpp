#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int x[5000005];
int y[5000005];
int c[5000005];
int d[5000005];
class zhi{
  public:
    int k,y;
    zhi(int xx=0,int yy=0){
      k=xx;
      y=yy;
      return ;
    }
    int qiu(int x){
      return k*x+y;
    }
};
zhi operator+(zhi a,zhi b){
  return zhi(a.k+b.k,a.y+b.y);
}
zhi operator- (zhi a){
  return zhi(-a.k,-a.y);
}
zhi matrx[6005][6005],matrx2[6005][6005];
int ans[3005][3005];
int ans2[3005][3005];
void add(int x,int y,zhi z,zhi matrix[6005][6005]){
  x++;
  y++;
  x=std::max(x,0);
  x=std::min(x,6003);
  y=std::max(y,0);
  y=std::min(y,6003);
  matrix[x][y]=matrix[x][y]+z;
  return ;
}
zhi get(int x,int y,zhi matrix[6005][6005]){
  x++;
  y++;
  x=std::max(x,0);
  x=std::min(x,6003);
  y=std::max(y,0);
  y=std::min(y,6003);
  return matrix[x][y];
}
void add2(int x1,int y1,int x2,int y2,zhi aa,zhi matrix[6005][6005]){
  add(x2,y2,aa,matrix);
  add(x1-1,y1-1,aa,matrix);
  add(x1-1,y2,-aa,matrix);
  add(x2,y1-1,-aa,matrix);
  return ;
}
void calc(int n,int m,int k){
  memset(matrx,0,sizeof(matrx));
  memset(matrx2,0,sizeof(matrx2));
  for(int i=1;i<=k;i++){
    int tx=x[i]+y[i];
    int ty=x[i]-y[i]+3001;
    int tt=c[i]/d[i];
    zhi ad(-d[i],d[i]*(x[i]+y[i])+c[i]);
    if((x[i]+y[i])%2==1){
      add2(tx,ty,tx+tt,ty+tt,ad,matrx);
      add2(tx,ty,tx+tt,ty+tt,-ad,matrx2);
    }else{
      add2(tx,ty,tx+tt,ty+tt,ad,matrx2);
      add2(tx,ty,tx+tt,ty+tt,-ad,matrx);
    }
  }
  for(int i=1;i<=n+m+5;i++){
    for(int j=1;j<=n+m+3003;j++){
      matrx[i][j]=matrx[i][j]+matrx[i-1][j];
      matrx[i][j]=matrx[i][j]+matrx[i][j-1];
      matrx[i][j]=matrx[i][j]+(-matrx[i-1][j-1]);
      matrx2[i][j]=matrx2[i][j]+matrx2[i-1][j];
      matrx2[i][j]=matrx2[i][j]+matrx2[i][j-1];
      matrx2[i][j]=matrx2[i][j]+(-matrx2[i-1][j-1]);
      if((i+j-3001)%2==0){
        int tx=(i+j-3001)/2;
        int ty=i-tx;
        if(tx<=0||ty<=0||tx>3000||ty>3000){
          continue;
        }
        if((tx+ty)%2==1){
          ans2[tx][ty]=matrx[i][j].qiu(tx+ty);
        }else{
          ans2[tx][ty]=matrx2[i][j].qiu(tx+ty);
        }
      }
    }
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("ripple.in","r",stdin);
  freopen("ripple.out","w",stdout);
  #endif
  int n=read(),m,k;
  m=read();
  k=read();
  for(int i=1;i<=k;i++){
    x[i]=read();
    y[i]=read();
    c[i]=read();
    d[i]=read();
  }
  calc(n,m,k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans[i][j]+=ans2[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    x[i]=n-x[i]+1;
  }
  calc(n,m,k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans[i][j]+=ans2[n-i+1][j];
    }
  }
  for(int i=1;i<=m;i++){
    y[i]=m-y[i]+1;
  }
  calc(n,m,k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans[i][j]+=ans2[n-i+1][m-j+1];
    }
  }
  for(int i=1;i<=n;i++){
    x[i]=n-x[i]+1;
  }
  calc(n,m,k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans[i][j]+=ans2[i][m-j+1];
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int base=1;
    for(int j=1;j<=m;j++){
      base=(base*233ll)%998244353;
      ans+=(1ll*base*::ans[i][j])%998244353;
      ans%=998244353;
    }
    printf("%d ",ans);
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
