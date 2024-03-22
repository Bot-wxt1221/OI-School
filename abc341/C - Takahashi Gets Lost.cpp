#include <iostream>
#include <cstdio>
inline int read();
char T[505];
char S[505][505];
int to[300][2];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int h=read();
  int w=read();
  int n=read();
  to['L'][0]=0;
  to['L'][1]=-1;
  to['R'][0]=0;
  to['R'][1]=1;
  to['U'][0]=-1;
  to['U'][1]=0;
  to['D'][0]=1;
  to['D'][1]=0;
  scanf("%s",T+1);
  for(int i=1;i<=h;i++){
    scanf("%s",S[i]+1);
  }
  int ans=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(S[i][j]=='#'){
        continue;
      }
      ans++;
      int ii=i,jj=j;
      for(int k=1;k<=n;k++){
        ii+=to[T[k]][0];
        jj+=to[T[k]][1];
        if(S[ii][jj]=='#'){
          ans--;
          break;
        }
      }
    }
  }
  printf("%d",ans);
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


