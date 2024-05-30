#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[1000005];
int st[1000005][25];
int tree[1000005];
int tree2[1000005];
int anss[1000005];
int n,q;
int lowbit(int now){
    return now&(-now);
}
void add(int i,int now){
    int temp=i;
    while(i<=n){
        tree[i]+=now;
        tree2[i]+=now*temp;
        i+=lowbit(i);
    }
    return ;
}
void add_two(int l,int r,int now){
    add(r+1,-now);
    add(l,now);
    return ;
}
int que(int l){
    int temp=l;
    int ans=0;
    while(l>0){
        ans-=tree2[l];
        ans+=(temp+1)*tree[l];
        l-=lowbit(l);
    }
    return ans;
}
int que_two(int l,int r){
    return que(r)-que(l-1);
}
class node{
  public:
    int l,r,i;
    node(int x=0,int y=0){
      l=x;
      r=y;
      return ;
    }
}no[1000005];
bool operator < (node a,node b){
  return a.l>b.l;
}
int ans(int l,int r){
  int siz=r-l+1;
  int lg=std::log2(siz);
  return st[l][lg]&st[r-(1<<lg)+1][lg];
}
void add(int x){
  int cur=a[x];
  int curx=x;
  while(curx<=n){
    int l=curx,r=n;
    while(r-l>3){
      int mid=(l+r)/2;
      if(ans(x,mid)==cur){
        l=mid;
      }else{
        r=mid-1;
      }
    }
    int i;
    for(i=r;i>=l;i--){
      if(ans(x,i)==cur){
        break;
      }
    }
    int tt=std::sqrt(cur);
    if(tt*tt==cur){
      add_two(curx,i,1);
    }
    curx=i+1;
    cur=ans(x,i+1);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    int q=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      tree[i]=0;
      tree2[i]=0;
      st[i][0]=a[i];
    }
    for(int k=1;k<=24;k++){
      for(int i=1;i+(1<<k)-1<=n;i++){
        st[i][k]=st[i][k-1]&(st[i+(1<<(k-1))][k-1]);
      }
    }
    for(int i=1;i<=q;i++){
      no[i].l=read();
      no[i].r=read();
      no[i].i=i;
    }
    std::sort(no+1,no+q+1);
    int pre=n+1;
    for(int i=1;i<=q;i++){
      while(pre>no[i].l){
        pre--;
        add(pre);
      }
      anss[no[i].i]=que_two(1,no[i].r);
    }
    for(int i=1;i<=q;i++){
      printf("%lld\n",anss[i]);
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

