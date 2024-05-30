#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[105],b[105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("mex.in","r",stdin);
  freopen("mex2.out","w",stdout);
  #endif
  int n=read();
  read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int ans=0;
  for(int i=0;i<(1<<(n-1));i++){
    for(int j=1;j<=n;j++){
      b[j]=a[j];
    }
    int ni=i|(1<<(n-1));
    int pre=1;
    int mex=-1;
    ans++;
    for(int j=1;j<=n;j++){
      if(ni&(1<<(j-1))){
        int curmex=0;
        std::sort(b+pre,b+j+1);
        b[pre-1]=-1;
        for(int k=pre;k<=j;k++){
          if(b[k]-b[k-1]>1){
            int curmex=b[k-1]+1;
            if(mex==-1||curmex==mex){
              mex=curmex;
            }else{
              ans--;
              goto end;
            }
            goto end2;
          }
        }
        curmex=b[j]+1;
        if(mex==-1||curmex==mex){
          mex=curmex;
        }else{
          ans--;
          goto end;
        }

        end2:{}
        pre=j+1;
      }
    }
    end:{}
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

