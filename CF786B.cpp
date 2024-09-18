#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int tree[800005];
int seq[100005];
int fir[2000005];
int nxt[8000005];
int v[8000005];
int w[8000005];
int dp[2000005];
int now;
std::priority_queue<std::pair<int,int> >qu;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    add(now+100000,l,0);
    add(l,now+1000000,0);
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  add(now+100000,now*2+100000,0);
  add(now+100000,now*2+1+100000,0);
  add(now*2+1+1000000,now+1000000,0);
  add(now*2+1000000,now+1000000,0);
  return ;
}
int ql,qr,ww,vv;
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    add(vv,now+100000,ww);
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
void query2(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    add(now+1000000,vv,ww);
    return ;
  }
  int mid=(l+r)/2;
  query2(now*2,l,mid);
  query2(now*2+1,mid+1,r);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  int s=read();
  for(int i=1;i<=2000000;i++){
    fir[i]=-1;
    dp[i]=0x3f3f3f3f3f3f3f3f;
  }
  build(1,1,n);
  for(int i=1;i<=q;i++){
    int op=read();
    switch(op){
      case 1:{
        int u=read();
        int v=read();
        int w=read();
        add(u,v,w);
        break;
      }
      case 2:{
        int v=read();
        int l=read();
        int r=read();
        int w=read();
        ql=l;
        qr=r;
        ww=w;
        vv=v;
        query(1,1,n);
        break;
      }
      case 3:{
        int v=read();
        int l=read();
        int r=read();
        int w=read();
        ql=l;
        qr=r;
        ww=w;
        vv=v;
        query2(1,1,n);
        break;
      }
    }
  }
  dp[s]=0;
  qu.push({0,s});
  while(qu.size()>0){
    int tp=qu.top().second;
    qu.pop();
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(dp[v[i]]>dp[tp]+w[i]){
        dp[v[i]]=dp[tp]+w[i];
        qu.push({-dp[v[i]],v[i]});
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(dp[i]==0x3f3f3f3f3f3f3f3f){
      dp[i]=-1;
    }
    printf("%lld ",dp[i]);
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
