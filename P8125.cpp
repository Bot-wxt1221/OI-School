#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int a[2000005];
int l[2000005];
int inf[2000005];
std::queue<int>qu[2000005];
int fir[2000005];
int nxt[4000005];
int v[4000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int d=read();
  int t=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fir[i]=-1;
  }
  int mn=0x3f3f3f3f,tt=0;
  for(int i=1;i<=n;i++){
    mn=std::min(mn+1,a[i]);
    if(mn==a[i]){
      tt=i;
    }
    if(a[i]>tt){
      l[i]=tt;
      inf[i]=mn;
    }
  }
  mn=0x3f3f3f3f;
  tt=0;
  for(int i=n;i>=1;i--){
    mn=std::min(mn+1,a[i]);
    if(mn==a[i]){
      tt=i;
    }
    if(a[i]>tt&&inf[i]>mn){
      l[i]=tt;
      inf[i]=mn;
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(a[i]>tt&&inf[i]<0x3f3f3f3f){
      ans++;
      qu[std::min(i,l[i])].push(std::max(l[i],i));
    }else if(a[i]<=tt){
      ans++;
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

