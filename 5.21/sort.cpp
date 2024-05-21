#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[4194600];
int sum[4194600];
int sum2[4194600];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  #endif
  int n=read();
  int oans=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    aa.mod(a[i]+1,1);
    oans+=i-1-aa.query(a[i]);
  }
  int k=0;
  int cur=1;
  while(cur<n){
    cur*=2;
    k++;
  }
  int tans=0;
  for(int i=k-1;i>=0;i--){
    memset(sum,0,sizeof(sum));
    memset(sum2,0,sizeof(sum2));
    int tt=(1<<k)-1-((1<<(i+1))-1);
    int nans2=0;
    int nans=0;
    for(int j=1;j<=n;j++){
      if((a[j]&((1<<i)))==0){
        nans2+=sum2[tt&a[j]];
        sum[tt&a[j]]++;
      }else{
        sum2[tt&a[j]]++;
        nans+=sum[tt&a[j]];
      }
    }
    nans2=std::min(nans2,nans);
    tans+=nans2;
  }
  printf("%lld",std::min(tans+1,oans));
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

