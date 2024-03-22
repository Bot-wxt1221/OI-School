#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
inline int read();
int tree[500005];
int min[500005];
int mx,c;
int phi[500005];
int a[500005];
int p;
int fast1[55][500005];
bool tag1[55][500005];
int fast2[55][500005];
int tag2[55][500005];
int getphi(int x){
  int sq=std::sqrt(x);
  int ans=x;
  for(int i=2;i<=sq;i++){
    if(x%i==0){
      ans/=i;
      ans*=(i-1);
      while(x%i==0){
        x/=i;
      }
    }
  }
  if(x>1){
    ans/=x;
    ans*=(x-1);
  }
  return ans;
}
int pow(int a,int b,int mod2){
  int mod=phi[mod2];
  long long ans=fast2[mod2][b/10000];
  ans*=fast1[mod2][b%10000];
  ans%=mod;
  return ans+mod*(tag2[mod2][b/10000]||tag1[mod2][b%10000]);
}
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    min[now]=0;
    tree[now]=a[l];
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  min[now]=std::min(min[now*2],min[now*2+1]);
  tree[now]=tree[now*2]+tree[now*2+1];
  tree[now]%=p;
  return ;
}
int ql,qr;
int dfs(int a,int c,int pp,int num){
  int p=phi[pp];
  if(num==0){
    return a%p+(a>=p)*p;
  }
  if(p==1){
    return p;
  }
  if(std::__gcd(c,p)==1){
    return pow(c,dfs(a,c,pp+1,num-1)%phi[pp+1],pp);
  }
  return pow(c,dfs(a,c,pp+1,num-1),pp);
}
int query(int now,int l,int r){
  if(l>r){
    return 0;
  }
  if(r<ql||qr<l){
    return 0;
  }
  if(ql<=l&&r<=qr){
    return tree[now];
  }
  int mid=(l+r)/2;
  return (query(now*2,l,mid)+query(now*2+1,mid+1,r))%p;
}
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(min[now]>mx){
    return ;
  }
  if(l==r){
    min[now]++;
    tree[now]=dfs(a[l],c,1,min[now])%p;
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  min[now]=std::min(min[now*2],min[now*2+1]);
  tree[now]=tree[now*2]+tree[now*2+1];
  tree[now]%=p;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  p=read();
  c=read();
  int tmp=p;
  phi[++mx]=tmp;
  while(tmp!=1){
    tmp=getphi(tmp);
    phi[++mx]=tmp;
  }
  for(int i=1;i<=mx;i++){
    fast1[i][0]=1;
    bool tag=0;
    long long ans=1;
    for(int j=1;j<=10000;j++){
      ans*=c;
      if(ans>=phi[i]){
        tag=1;
      }
      ans%=phi[i];
      fast1[i][j]=(1ll*fast1[i][j-1]*c)%phi[i];
      if(1ll*fast1[i][j-1]*c>=phi[i]){
        tag1[i][j]=1;
      }
      tag1[i][j]|=tag1[i][j-1];
    }
    fast2[i][0]=1;
    fast2[i][1]=ans;
    tag2[i][1]=tag;
    for(int j=2;j<=10000;j++){
      fast2[i][j]=(1ll*fast2[i][j-1]*fast2[i][1])%phi[i];
      if(1ll*fast2[i][j-1]*fast2[i][1]>=phi[i]){
        tag2[i][j]=1;
      }
      tag2[i][j]|=tag2[i][j-1];
    }
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  build(1,1,n);
  for(int i=1;i<=m;i++){
    int op=read();
    switch(op){
      case 0:{
        ql=read();
        qr=read();
        mod(1,1,n);
        break;
      }
      case 1:{
        ql=read();
        qr=read();
        printf("%d\n",query(1,1,n));
        break;
      }
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


