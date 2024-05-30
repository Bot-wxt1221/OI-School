#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int a[2000005];
char temp[2000005];
int cho[2000005];
int n;
bool is(int xx){
  if(xx==0){
    return cho[n];
  }
  if(xx==n+1){
    return cho[1];
  }
  return cho[xx];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  scanf("%s",temp+1);
  int totans=0;
  if(temp[a[1]]!='L'){
    for(int i=0;i<=n+5;i++){
      cho[i]=0;
    }
    int ans=1;
    cho[a[1]]=1;
    for(int i=2;i<=n;i++){
      if(is(a[i])){
        ans=0;
        break;
      }else if(is(a[i]-1)){
        if(temp[a[i]]=='?'){
          ans*=2;
          ans%=mod;
        }
      }else if(temp[a[i]]=='L'){
        ans=0;
        break;
      }
      cho[a[i]]=1;
    }
    totans+=ans;
  }
  if(temp[a[1]]!='R'){
    for(int i=0;i<=n+5;i++){
      cho[i]=0;
    }
    int ans=1;
    cho[a[1]]=1;
    for(int i=2;i<=n;i++){
      if(is(a[i])){
        ans=0;
        break;
      }else if(is(a[i]+1)&&temp[a[i]]=='?'){
        ans*=2;
        ans%=mod;
      }else if(temp[a[i]]=='R'&&(!is(a[i]+1))){
        ans=0;
        break;
      }
      cho[a[i]]=1;
    }
    totans+=ans;
    totans%=mod;
  }
  printf("%lld",totans);
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

