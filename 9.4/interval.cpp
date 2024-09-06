#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int l[200005];
int r[200005];
int seq[1200005];
int cnt;
int pre[1200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("interval.in","r",stdin);
  freopen("interval.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int ans=0x3f3f3f3f;
    cnt=0;
    for(int i=1;i<=n;i++){
      l[i]=read();
      r[i]=read();
      seq[++cnt]=l[i];
      pre[cnt]=0;
      
      seq[++cnt]=r[i];
      pre[cnt]=0;
    }
    std::sort(seq+1,seq+cnt+1);
    cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
    for(int i=1;i<=n;i++)   {
      l[i]=std::lower_bound(seq+1,seq+cnt+1,l[i])-seq;
      r[i]=std::lower_bound(seq+1,seq+cnt+1,r[i])-seq;
      pre[l[i]]++;
      pre[r[i]]--;
    }
    for(int i=1;i<=cnt;i++){
      pre[i]+=pre[i-1];
    }
    std::sort(l+1,l+n+1);
    std::sort(r+1,r+n+1);
    int curl=1;
    int curr=1;
    int suf=n;
    int pree=0;
    for(int i=1;i<=cnt;i++){
      while(curr<=n&&l[curr]<=i){
        curr++;
        suf--;
      }
      while(curl<=n&&r[curl]<=i){
        curl++;
        pree++;
      }
      if(pree&&suf){
        ans=std::min(ans,pre[i]);
      }
    }
    if(ans==0x3f3f3f3f){
      printf("-1\n");
    }else{
      printf("%d\n",ans);
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
