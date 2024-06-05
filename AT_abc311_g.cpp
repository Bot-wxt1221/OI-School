#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[305][305];
int sum1[305];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[305];
  int query(int now){
    int ans=0;
    while(now>0){
      ans=std::max(ans,tree[now]);
      now-=lowbit(now);
    }
    return ans;
  }
  void add(int now,int y){
    while(now<=302){
      tree[now]=std::max(tree[now],y);
      now+=lowbit(now);
    }
    return ;
  }
}b;
int mn[306];
int sum[305];
int ans[305];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      a[i][j]=read();
    }
  }
  int anss=0;
  for(int i=1;i<=n;i++){
    memset(mn,0x3f,sizeof(mn));
    memset(sum,0,sizeof(sum));
    memset(sum1,0,sizeof(sum1));
    for(int j=i;j<=n;j++){
      memset(b.tree,0,sizeof(b.tree));
      for(int k=1;k<=m;k++){
        mn[k]=std::min(mn[k],a[j][k]);
        sum1[k]+=a[j][k];
        sum[k]=sum[k-1]+sum1[k];
        b.add(mn[k],k);
        int tt=b.query(mn[k]-1);
        ans[k]=sum[k]-sum[tt];
      }
      memset(b.tree,0,sizeof(b.tree));
      for(int k=m;k>=1;k--){
        b.add(mn[k],m-k+1);
        int tt=b.query(mn[k]-1);
        ans[k]+=sum[m-tt]-sum[k];
        anss=std::max(anss,ans[k]*mn[k]);
      }
    }
  }
  printf("%lld",anss);
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

