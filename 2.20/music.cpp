#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
inline int read();
int a[200005];
std::multiset<int>se;
std::multiset<int>::iterator it[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("music.in","r",stdin);
  freopen("music.out","w",stdout);
  #endif
  int n=read(),k,m,c,d;
  k=read();
  m=read();
  c=read();
  d=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  if(k==1){
    int mx=0;
    for(int i=1;i<=n;i++){
      mx=std::max(mx,a[i]);
    }
    printf("%lld",mx+c+(m-1)*d);
    return 0;
  }
  for(int i=1;i<=n;i++){
    it[i]=se.insert(a[i]);
  }
  int nn=c;
  for(int i=1;i<=m;i++){
    se.erase(it[i]);
    it[i]=se.insert(nn+a[i]);
    nn+=d;
  }
  std::multiset<int>::iterator itt=se.begin();
  for(int i=1;i<=n-k;i++){
    itt++;
  }
  int ans=*itt;
  for(int i=2;i+m-1<=n;i++){
    it[i-1]=se.insert(a[i-1]);
    nn=c;
    for(int j=i;j+i-1<=m;j++){
      se.erase(it[j]);
      it[j]=se.insert(nn+a[j]);
      nn+=d;
    }
    std::multiset<int>::iterator itt=se.begin();
    for(int i=1;i<=n-k;i++){
      itt++;
    }
    ans=std::max(ans,*itt);
  }
  printf("%lld",ans);
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


