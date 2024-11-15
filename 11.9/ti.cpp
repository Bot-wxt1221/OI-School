#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int a[4005];
int lowbit(int x){
  return (x)&(-x);
}
class BIT{
  public:
    int tree[4005];
    int query(int x){
      int ans=0;
      while(x>0){
        ans=std::max(ans,tree[x]);
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=4001){
        tree[x]=std::max(tree[x],y);
        x+=lowbit(x);
      }
    }
}t1;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  if(n==0){
    printf("0");
    return 0;
  }
  for(int i=1;i<=n;i++){
    a[i]=a[i+n]=read();
  }
  int ans=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    memset(t1.tree,0,sizeof(t1.tree));
    for(int j=i;j<=i+n-1;j++){
      int mx=t1.query(a[j]);
      t1.mod(a[j],mx+1);
    }
    ans=std::min(ans,n-t1.query(4000));
  }
  printf("%d",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
