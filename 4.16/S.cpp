#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[55];
bool del[55];
int l[55];
int r[55];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("S.in","r",stdin);
  freopen("S.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=q;i++){
    l[i]=read();
    r[i]=read();
  }
  int mn=0x3f3f3f3f3f3f3f3f;
  for(int i=0;i<(1<<n);i++){
    int cnt=0;
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        cnt++;
        del[j]=1;
      }else{
        del[j]=0;
      }
    }
    if(cnt>m){
      continue;
    }
    int ans=0;
    for(int kk=1;kk<=q;kk++){
      int mx=0;
      for(int j=l[kk];j<=r[kk];j++){
        if(del[j]==0){
          mx=std::max(mx,a[j]);
        }
      }
      ans+=mx;
    }
    mn=std::min(mn,ans);
  }
  printf("%lld",mn);
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

