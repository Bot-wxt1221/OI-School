#include <iostream>
#include <cstdio>
inline int read();
int query(int l,int x){
  printf("? %d %d\n",l,x);
  fflush(stdout);
  int ret;
  scanf("%d",&ret);
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),k;
    k=read();
    int mx=0;
    for(int i=1;i<=n;i++){
      if(query(1,i*n)==n){
        mx=i;
        break;
      }
    }
    for(int i=1;i<=n/k;i++){
      int cur=1;
      for(int j=1;j<=k;j++){
        if(cur>n){
          cur=0;
          break;
        }
        cur=query(cur,i*mx)+1;
      }
      if(cur==n+1){
        printf("! %d\n",mx*i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        goto end;
      }
    }
    printf("! -1\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    end:{};
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

