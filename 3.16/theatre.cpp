#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
inline int read();
int tott[500005];
int to[500005];
int mx1[100005];
int x1[100005];
int y11[100005];
int x2[100005];
int y2[100005];
int tree[500005];
int lowbit(int x){
  return x&(-x);
}
int query(int now){
  int ans=-0x3f3f3f3f3f3f3f3f;
  while(now>0){
    ans=std::max(ans,tree[now]);
    now-=lowbit(now);
  }
  return ans;
}
void mod(int x,int y){
  while(x<=500000){
    tree[x]=std::max(tree[x],y);
    x+=lowbit(x);
  }
  return ;
}
int n,m;
class node{
  public:
    int toans,x,y;
}ans[500005];
const bool operator < (const node &a,const node &b){
  return a.x==b.x?a.y<b.y:a.x<b.x;
}
int solve(){
  std::sort(ans+1,ans+n+m+1);
  memset(tree,-0x3f,sizeof(tree));
  for(int i=1;i<=n+m;i++){
    if(ans[i].toans==0){
      mod(ans[i].y,-ans[i].x-to[ans[i].y]);
    }else{
      mx1[ans[i].toans]=std::max(mx1[ans[i].toans],ans[i].x+to[ans[i].y]+query(ans[i].y));
    }
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("theatre.in","r",stdin);
  freopen("theatre.out","w",stdout);
  #endif
  int c=read();
  int h=read();
  n=read();
  int tottt=0;
  for(int i=1;i<=n;i++){
    x1[i]=read();
    y11[i]=read();
    tott[++tottt]=y11[i];
    tott[++tottt]=h-y11[i]+1;
  }
  m=read();
  for(int i=1;i<=m;i++){
    x2[i]=read();
    y2[i]=read();
    tott[++tottt]=y2[i];
    tott[++tottt]=h-y2[i]+1;
  }
  memset(mx1,0,sizeof(mx1));
  int cnt=0;
  std::sort(tott+1,tott+tottt+1);
  tottt=std::unique(tott+1,tott+tottt+1)-tott-1;
  for(int i=1;i<=tottt;i++){
    to[i]=tott[i];
  }
  for(int i=1;i<=n;i++){
    ans[i].x=x1[i];
    ans[i].y=std::lower_bound(tott+1,tott+tottt+1,y11[i])-tott;
    ans[i].toans=0;
  }
  for(int i=1;i<=m;i++){
    ans[i+n].x=x2[i];
    ans[i+n].y=std::lower_bound(tott+1,tott+tottt+1,y2[i])-tott;
    ans[i+n].toans=i;
  }
  solve();
  for(int i=1;i<=n;i++){
    ans[i].x=x1[i];
    ans[i].y=std::lower_bound(tott+1,tott+tottt+1,h-y11[i]+1)-tott;
    ans[i].toans=0;
  }
  for(int i=1;i<=m;i++){
    ans[i+n].x=x2[i];
    ans[i+n].y=std::lower_bound(tott+1,tott+tottt+1,h-y2[i]+1)-tott;
    ans[i+n].toans=i;
  }
  solve();
  for(int i=1;i<=n;i++){
    ans[i].x=c-x1[i]+1;
    ans[i].y=std::lower_bound(tott+1,tott+tottt+1,y11[i])-tott;
    ans[i].toans=0;
  }
  for(int i=1;i<=m;i++){
    ans[i+n].x=c-x2[i]+1;
    ans[i+n].y=std::lower_bound(tott+1,tott+tottt+1,y2[i])-tott;
    ans[i+n].toans=i;
  }
  solve();
  for(int i=1;i<=n;i++){
    ans[i].x=c-x1[i]+1;
    ans[i].y=std::lower_bound(tott+1,tott+tottt+1,h-y11[i]+1)-tott;
    ans[i].toans=0;
  }
  for(int i=1;i<=m;i++){
    ans[i+n].x=c-x2[i]+1;
    ans[i+n].y=std::lower_bound(tott+1,tott+tottt+1,h-y2[i]+1)-tott;
    ans[i+n].toans=i;
  }
  solve();
  int cur=0x3f3f3f3f3f3f3f3f;
  int num=0;
  for(int i=1;i<=m;i++){
    if(mx1[i]<cur){
      cur=mx1[i];
      num=i;
    }
  }
  printf("%lld\n%lld",cur,num);
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


