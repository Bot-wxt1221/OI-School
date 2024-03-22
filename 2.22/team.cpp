#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int __int128
inline int read();
int a[2000005];
int lowbit(int x){
  return x&(-x);
}
class BIT{
  public:
    int tree[2000005];
    int query(int x){
      int ans=-0x3f3f3f3f3f3f3f3f;
      while(x>0){
        ans=std::max(ans,tree[x]);
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=2000001){
        tree[x]=std::max(tree[x],y);
        x+=lowbit(x);
      }
    }
}t1,t2;
class BIT2{
  public:
    int tree[2000005];
    int query(int x){
      int ans=0x3f3f3f3f3f3f3f3f;
      while(x>0){
        ans=std::min(ans,tree[x]);
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=2000001){
        tree[x]=std::min(tree[x],y);
        x+=lowbit(x);
      }
    }
}t12,t22;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("team.in","r",stdin);
  freopen("team.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    for(int i=1;i<=2000001;i++){
      t1.tree[i]=t2.tree[i]=-0x3f3f3f3f3f3f3f3f;
      t12.tree[i]=t22.tree[i]=0x3f3f3f3f3f3f3f3f;
    }
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      a[i]+=1e6+1;
    }
    int ans=-0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
      if(t2.query(a[i]-1)!=-0x3f3f3f3f3f3f3f3f){
        ans=std::max(ans,t2.query(a[i]-1)*(int)(a[i]-1e6-1));
      }
      if(t22.query(a[i]-1)!=0x3f3f3f3f3f3f3f3f){
        ans=std::max(ans,t22.query(a[i]-1)*(int)(a[i]-1e6-1));
      }
      if(t1.query(a[i]-1)!=-0x3f3f3f3f3f3f3f3f){
        t2.mod(a[i],t1.query(a[i]-1)*(a[i]-1e6-1));
        t22.mod(a[i],t1.query(a[i]-1)*(a[i]-1e6-1));
      }
      if(t12.query(a[i]-1)!=0x3f3f3f3f3f3f3f3f){
        t2.mod(a[i],t12.query(a[i]-1)*(a[i]-1e6-1));
        t22.mod(a[i],t12.query(a[i]-1)*(a[i]-1e6-1));
      }
      t12.mod(a[i],(a[i]-1e6-1));
      t1.mod(a[i],(a[i]-1e6-1));
    }
    if(ans==-0x3f3f3f3f3f3f3f3f){
      printf("-1\n");
    }else{
      printf("%lld\n",(long long)ans);
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


