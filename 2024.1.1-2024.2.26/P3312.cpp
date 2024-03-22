#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int mu[500005];
bool fin[500005];
int g[500005];
int p[500005];
int tree[1000005];
class que{
  public:
    int n,m,a,id;
    que(int x=0,int y=0,int z=0,int aa=0){
      n=x;
      m=y;
      a=z;
      id=aa;
      return ;
    }
}op[200005];
bool operator < (que a,que b){
  return a.a<b.a;
}
class ff{
  public:
    int pos,da;
    ff(int x=0,int y=0){
      pos=x;
      da=y;
      return ;
    }
}f[200005];
bool operator < (ff a,ff b){
  return a.da==b.da?a.pos<b.pos:a.da<b.da;
}
int lowbit(int x){
  return (x)&(-x);
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
void mod(int x,int y){
  while(x<=1000000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
void init(){
  int tot=0;
  mu[1]=1;
  f[1]=ff(1,1);
  for(int i=2;i<=100000;i++){
    if(fin[i]==0){
      f[i]=ff(i,i+1);
      g[i]=i+1;
      p[++tot]=i;
      mu[i]=-1;
    }
    for(int j=1;j<=tot;j++){
      if(i*p[j]>100000){
        break;
      }
      fin[i*p[j]]=1;
      if(i%p[j]==0){
        g[i*p[j]]=g[i]*p[j]+1;
        f[i*p[j]]=ff(i*p[j],f[i].da*g[i*p[j]]/g[i]);
        mu[i*p[j]]=0;
        break;
      }
      g[i*p[j]]=p[j]+1;
      f[i*p[j]]=ff(i*p[j],f[i].da*f[p[j]].da);
      mu[i*p[j]]=-mu[i];
    }
  }
  return ;
}
int ans[1000005];
int solve(int n,int m){
  int ans=0;
  for(int i=1,j;i<=std::min(n,m);i=j+1){
    j=std::min(n/(n/i),m/(m/i));
    ans+=(query(j)-query(i-1))*(n/i)*(m/i);
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  init();
  for(int i=1;i<=n;i++){
    op[i].n=read();
    op[i].m=read();
    op[i].a=read();
    op[i].id=i;
  }
  std::sort(op+1,op+n+1);
  std::sort(f+1,f+100001);
  int j=1;
  for(int i=1;i<=n;i++){
    while(j<=100000&&f[j].da<=op[i].a){
      for(int k=f[j].pos;k<=100000;k+=f[j].pos){
        mod(k,f[j].da*mu[k/f[j].pos]);
      }
      j++;
    }
    ans[op[i].id]=solve(op[i].n,op[i].m);
  }
  for(int i=1;i<=n;i++){
    printf("%lld\n",ans[i]&((1ll<<31)-1));
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


