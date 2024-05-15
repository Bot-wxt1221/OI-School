#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int b[800005];
int c[800005];
std::pair<int,int> a[800005],d[800005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),k;
    k=read()-1;
    int cnt=0,cnt2=0;
    for(int i=1;i<=n;i++){
      b[i]=read();
      c[i]=read();
      if(c[i]-b[i]>0){
        d[++cnt]=(std::make_pair(b[i],c[i]));
      }else{
        a[++cnt2]=std::make_pair(c[i],b[i]);
      }
    }
    std::sort(a+1,a+cnt2+1);
    std::sort(d+1,d+cnt+1);
    for(int i=1;i<=cnt;i++){
      if(d[i].first>k){
        printf("NO\n");
        goto end;
      }
      k-=d[i].first;
      k+=d[i].second;
    }
    for(int i=cnt2;i>=1;i--){
      if(a[i].second>k){
        printf("NO\n");
        goto end;
      }
      k-=a[i].second;
      k+=a[i].first;
    }
    printf("YES\n");
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

