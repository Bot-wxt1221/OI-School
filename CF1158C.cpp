#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int a[500005];
int ans[500005];
int cnt,n;
bool tans=1;
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[3000005];
  int query(int now){
    now+=2;
    int ans=0x3f3f3f3f;
    while(now>0){
      ans=std::min(tree[now],ans);
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=2;
    while(x<=3000002){
      tree[x]=std::min(tree[x],y);
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x){
    x+=2;
    while(x<=3000002){
      tree[x]=0x3f3f3f3f;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
void dfs(int l,int r){
  if(tans==0){
    return ;
  }
  if(l>r){
    return ;
  }
  if(l==r){
    ans[l]=++cnt;
    return ;
  }
  int lst=0;
  for(int i=l;i<=r;i++){
    if(a[i]==-1){
      a[i]=i+1;
    }
    if(a[i]>r+1){
      tans=0;
      return ;
    }
    dfs(i+1,a[i]-1);
    ans[i]=++cnt;
    lst=a[i];
    i=a[i]-1;
  }
  if(lst<=r)
    ans[lst]=++cnt;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  memset(aa.tree,0x3f,sizeof(aa.tree));
  while(T--){
    n=read();
    cnt=0;
    tans=1;
    for(int i=1;i<=n;i++){
      a[i]=read();
      ans[i]=-1;
    }
    dfs(1,n);
    if(tans==0){
      printf("-1\n");
      continue;
    }
    bool yes=1;
    for(int i=n;i>=1;i--){
      if(a[i]==n+1){
        a[i]=0x3f3f3f3f;
      }
      if(ans[i]>n||ans[i]<0){
        if(yes){
          printf("-1");
        }
        yes=0;
        continue;
      }
      if(aa.query(1000001-(ans[i]+1))!=a[i]&&a[i]!=-1){
        if(yes){
          printf("-1");
        }
        yes=0;
      }
      aa.mod(1000001-ans[i],i);
    }
    for(int i=1;i<=n;i++){
      if(yes){
        printf("%d ",ans[i]);
      }
      if(ans[i]>n||ans[i]<0){
        continue;
      }
      aa.clear(1000001-ans[i]);
    }
    printf("\n");
  }
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
