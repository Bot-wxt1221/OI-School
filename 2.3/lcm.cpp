#include <iostream>
#include <cstdio>
#include <vector>
inline int read();

bool inseq[400005];
int del[400005];

int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("lcm.in","r",stdin);
  freopen("lcm.out","w",stdout);
  #endif
  int n=read();
  int lst=0;
  for(int i=1;i<=n;i++){
    inseq[lst=read()]=1;
  }
  int ans=0;
  for(int i=2;i<=lst;i++){
    if(del[i]==0&&inseq[i]){
      ans++;
      for(int j=2;(i-1)*j+1<=lst;j++){
        del[(i-1)*j+1]=1;
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
O(n/1)+O(n/2)+(O(n/3))+...+O(n/n)=O(nlogn)
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


