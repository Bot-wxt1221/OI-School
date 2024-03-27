#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int map[1000005];
int tag[1000005];
int h,m,n;
int getans(){
  int ret=0;
  for(int i=1;i<=n;i++){
    int cur=1;
    int used=0;
    while(used<h){
      if(tag[cur]){
        cur=cur*2+1;
      }else{
        cur*=2;
      }
      tag[cur/2]^=1;
      used++;
    }
    if(map[cur]){
      ret++;
    }
  }
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("lct.in","r",stdin);
  freopen("lct.out","w",stdout);
  #endif
  h=read();
  m=read();
  n=read();
  for(int i=1;i<=m;i++){
    map[read()+(1<<h)-1]++;
  }
  int nodenum=(1<<(h))-1;
  int ans=0;
  for(int i=0;i<(1<<nodenum);i++){
    for(int j=1;j<=nodenum;j++){
      if(i&(1<<(j-1))){
        tag[j]=1;
      }else{
        tag[j]=0;
      }
    }
    ans=std::max(ans,getans());
  }
  printf("%lld",ans);
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

