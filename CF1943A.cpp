#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
inline int read();
int seq[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=0;i<=n;i++){
      seq[i]=0;
    }
    for(int i=1;i<=n;i++){
      seq[read()]++;
    }
    int fir=0;
    for(int i=0;i<=n;i++){
      if(seq[i]==0){
        printf("%d\n",i);
        goto end;
      }
      if(seq[i]==1&&!fir){
        fir=1;
      }else if(seq[i]==1&&fir){
        printf("%d\n",i);
        goto end;
      }
    }
    printf("%d\n",n+1);
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
