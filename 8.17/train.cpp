#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int h[3005];
int n;
int rev;
void work(int l,int r){
  if(rev){
    printf("%d ",(l)+(n-r));
    for(int i=r+1;i<=n;i++){
      printf("%d ",1);
    }
    printf("%d ",r-l+1);
    for(int i=1;i<l;i++){
      printf("%d ",1);
    }
  }else{
    printf("%d ",(l)+(n-r));
    for(int i=1;i<l;i++){
      printf("%d ",1);
    }
    printf("%d ",r-l+1);
    for(int i=r+1;i<=n;i++){
      printf("%d ",1);
    }
  }
  printf("\n");
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("train.in","r",stdin);
  freopen("train.out","w",stdout);
  #endif
  n=read();
  int w=read();
  for(int i=1;i<=n;i++){
    h[i]=read();
  }
  if(n%2==1){
    for(int i=1;i<=n;i++){
      h[i]=-h[i];
    }
  }
  printf("%d\n",n);
  for(int i=1;i<=n;i++){
    int mn=i;
    for(int j=i+1;j<=n;j++){
      if(h[j]<h[mn]){
        mn=j;
      }
    }
    work(i,mn);
    rev^=1;
    std::reverse(h+i,h+mn+1);
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
