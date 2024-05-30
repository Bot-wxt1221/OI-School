#include <iostream>
#include <cstdio>
inline int read();
char temp[1005][1005];
char temp2[1005][1005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=n;i++){
    scanf("%s",temp2[i]+1);
  }
  int cnt1=0,cnt2=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(temp[i][j]==temp2[i][j]){
        cnt1++;
      }else{
        cnt2++;
      }
    }
  }
  if(cnt1<=n*m/2){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(temp[i][j]=='.'){
          temp[i][j]='X';
        }else{
          temp[i][j]='.';
        }
        printf("%c",temp[i][j]);
      }
      printf("\n");
    }
  }else{
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        printf("%c",temp[i][j]);
      }
      printf("\n");
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

