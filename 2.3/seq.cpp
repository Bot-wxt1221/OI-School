#include <iostream>
#include <cstdio>
#include <set>
inline int read();
int f[1005];
std::set<int>se;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("seq.in","r",stdin);
  freopen("seq.out","w",stdout);
  #endif
  int n=read();
  f[0]=f[1]=1;
  for(int i=1;i<=10000;i++){
    se.insert(i);
  }
  for(int i=2;i<=n;i++){
    for(int k=1;(i-2*k)>=0;k++){
      if(2*f[i-k]-f[i-2*k]<=0){
        continue;
      }
      auto tt=se.find(2*f[i-k]-f[i-2*k]);
      if(tt!=se.end()){
        se.erase(tt);
      }
    }
    f[i]=*se.begin();
    for(int k=1;(i-2*k)>=0;k++){
      if(2*f[i-k]-f[i-2*k]<=0){
        continue;
      }
      auto tt=se.find(2*f[i-k]-f[i-2*k]);
      if(tt==se.end()){
        se.insert(2*f[i-k]-f[i-2*k]);
      }
    }
  }
  printf("%d",f[n]);
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



