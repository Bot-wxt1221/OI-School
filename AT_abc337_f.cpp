#include <iostream>
#include <cstdio>
inline int read();
int a[400005];
bool ck[400005];
int pic[400005];
int tot[400005];
int nxt[400005];
int pre[400005];
int left[400005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,k;
  m=read();
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=a[i+n]=read();
    tot[a[i]]++;
    nxt[pre[a[i]]]=i;
    pre[a[i]]=i;
  }
  int used=m;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(left[a[i]]==0){
      if(used>0){
        used--;
        pic[i]=1;
        left[a[i]]=k-1;
        ans++;
      }
    }else{
      left[a[i]]--;
      ans++;
    }
  }
  printf("%d\n",ans);
  for(int i=2;i<=n;i++){
    if(pic[i-1]){
      if(!pic[nxt[i-1]]){
        pic[nxt[i-1]]=1;

      }
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

