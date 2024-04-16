#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[1000005];
bool cmp(int a,int b){
  return a>b;
}
int C(int n,int m){
  int ans=1;
  for(int i=m;i>=1;i--){
    ans*=(n-i+1);
  }
  for(int i=1;i<=m;i++){
    ans/=i;
  }
  return ans;
}
void solve1(int n){
  if(n<=2){
    printf("0\n");
    return ;
  }
  std::sort(a+1,a+n+1,cmp);
  int ans=0;
  for(int i=0;i<(1<<3);i++){
    int big=0;
    int num=0;
    for(int j=0;j<3;j++){
      if(i&(1<<j)){//进入三元组
        num++;
      }else{
        big=std::max(big,a[j+1]+1);
      }
    }
    if(num==3){
      ans++;
      continue;
    }
    for(int k=4;k<=n;k++){
      if(a[k]+n>=big){
        ans+=C(k-1-3,2-num);
      }
    }
  }
  printf("%lld\n",ans);
  return ;
}
void solve2(int n){
  if(n<=2){
    printf("0\n");
    return ;
  }
  std::sort(a+1,a+n+1,cmp);
  int ans=0;
  for(int i=3;i<=n;i++){
    if(a[i]+n>=a[1]+1){
      ans+=(i-1)*(i-2)/2;
    }else if(a[i]+n>=a[2]+1){
      ans+=i-2;
    }
  }
  printf("%lld\n",ans);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("T.in","r",stdin);
  freopen("T.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int p=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    if(p==1){
      solve1(n);
    }else{
      solve2(n);
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

