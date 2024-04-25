#include <iostream>
#include <cstdio>
inline int read();
class Matrix{
  public:
    int map[5][5];
};
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  for(int i=1;i<=4;i++){
    for(int j=1;j<=4;j++){
      ans.map[i][j]=0;
      for(int k=1;k<=4;k++){
        ans.map[i][j]+=(a.map[i][k]*b.map[k][j]);
      }
    }
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("algebra.in","r",stdin);
  freopen("algebra.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int a=read();
    int b=read();
    int c=read();
    int d=read();
    if(b==0){
      if(c==0){
        if(a==1){
          printf("1\nB 4\n");
        }else if(a==-1){
          printf("1\nB 2\n");
        }
      }else{
        if(a>0){
          printf("3\nB 1\nA %d\nB 3\n",-c);
        }else{
          printf("3\nB 1\nA %d\nB 1\n",c);
        }
      }
    }else if(c==0){
      if(a>0){
        printf("1\nA %d\n",b);
      }else{
        printf("2\nA %d\nB 2\n",-b);
      }
    }else if(a==0){
      if(d==0){
        if(b==1){
          printf("1\nB 1\n");
        }else{
          printf("1\nB 3\n");
        }
      }else{
        if(b==1){
          printf("2\nB 1\nA %d\n",-d);
        }else{
          printf("2\nB 3\nA %d\n",d);
        }
      }
    }else if(d==0){
      if(b<0){
        printf("2\nA %d\nB 3\n",a);
      }else{
        printf("2\nA %d\nB 1\n",-a);
      }
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

