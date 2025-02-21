#include <iostream>
#include <cstdio>
#define int long long
#define modd 998244353
inline int read();
int a[200005];
int dp[200005];
int p[200005];
class node{
public:
  int mx,s;
  node(int a=0,int d=0){
    mx=a;
    s=d;
    return ;
  }
}tree[200005*4];
int ans=0,sum=0;
void querymn(int now,int l,int r,int ql,int qr,int op){
  if(qr<l||r<ql){
    return ;
  }
  if(l==r){
    if(tree[now].mx>=op){
      sum+=dp[l];
      sum%=modd;
    }
    return ;
  }
  int mid=(l+r)/2;
  if(ql<=r&&tree[now*2+1].mx>op){
    sum+=tree[now].s;
    sum%=modd;
    querymn(now*2+1,mid+1,r,ql,qr,op);
  }else if(tree[now*2].mx>op){
    querymn(now*2,l,mid,ql,qr,op);
  }
  return ;
}
void mod(int now,int l,int r,int ql,int qr,int op){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now].mx=op;
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid,ql,qr,op);
  mod(now*2+1,mid+1,r,ql,qr,op);
  tree[now].mx=std::max(tree[now*2].mx,tree[now*2+1].mx);
  ans=sum=0;
  querymn(now*2,l,mid,l,mid,tree[now*2+1].mx);
  tree[now].s=sum;
  return ;
}
void query(int now,int l,int r,int ql,int qr,int op){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    if(tree[now].mx<=ans){
      return ;
    }
    querymn(now,l,r,l,r,ans);
    ans=tree[now].mx;
    return ;
  }
  int mid=(l+r)/2;
  query(now*2+1,mid+1,r,ql,qr,op);
  query(now*2,l,mid,ql,qr,op);
  return ;
}
int pre[200005];
int suf[200005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    p[a[i]]=i;
  }
  pre[0]=n;
  for(int i=1;i<=n;i++){
    pre[i]=std::min(a[i],pre[i-1]);
  }
  for(int i=n;i>=1;i--){
    suf[i]=std::max(a[i],suf[i+1]);
  }
  int anss=0;
  for(int i=1;i<=n;i++){
    int pp=p[i];
    if(pre[pp-1]>=i){
      dp[pp]=1;
    }else{
      ans=sum=0;
      query(1,1,n,1,pp-1,0);
      dp[pp]=sum;
    }
    if(suf[pp+1]<=i){
      anss+=dp[pp];
      anss%=modd;
    }
    mod(1,1,n,pp,pp,i);
  }
  printf("%lld\n",anss);
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
