#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[1000005];
int ansa,ansb;
int n;
int gCd(int x,int y){
  if(x>y){//x<y
    std::swap(x,y);
  }
  if(x==0){
    return y;
  }
  return gCd(y%x,x);
}
bool check(int ii){
  ansa=1;
  ansb=1;
  for(int i=1;i<=n;i++){
    if(a[i]==1){
      ansa++;
      ansb++;
    }else if(a[i]==-1){
      ansb--;
      if(ansb<=0){
        return 0;
      }
    }else{
      if(i<=ii){
        ansa++;
        ansb++;
      }else{
        ansb--;
        if(ansb<=0){
          return 0;
        }
      }
    }
  }
  int gg=gCd(ansa,ansb);
  ansa/=gg;
  ansb/=gg;
  return 1;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("magic.in","r",stdin);
  freopen("magic.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    int l=0,r=n;
    while(r-l>3){
      int mid=(l+r)/2;
      if(check(mid)){
        r=mid+1;
      }else{
        l=mid-1;
      }
    }
    bool ans=0;
    for(int i=l;i<=r;i++){
      if(check(i)){
        ans=1;
        printf("%d %d\n",ansa,ansb);
        break;
      }
    }
    if(!ans){
      printf("-1\n");
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


