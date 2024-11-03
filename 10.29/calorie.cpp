#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
int d[5005];
int map[5005][205];
std::stack<int>st[205];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[5005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=5002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}a;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<m;i++){
    d[i]=read();
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      map[i][j]=read();
    }
  }
  for(int i=1;i<=n;i++){
    st[i].push(m+1);
  }
  int ans=0;
  for(int l=m;l>=1;l--){
    for(int i=1;i<=n;i++){
      while(st[i].size()>1&&map[st[i].top()][i]<map[l][i]){
        int ret=map[st[i].top()][i];
        a.mod(st[i].top(),-map[st[i].top()][i]);
        st[i].pop();
        a.mod(st[i].top(),ret);
      }
      a.mod(st[i].top(),-map[l][i]);
      st[i].push(l);
      a.mod(l,map[l][i]);
    }
    int sum=0;
    for(int r=l;r<=m;r++){
      ans=std::max(ans,a.query(r)-a.query(l-1)-sum);
      sum+=d[r];
    }
  }
  printf("%lld",ans);
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
