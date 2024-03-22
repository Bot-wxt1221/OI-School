#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
inline int read();
int u[105];
int v[105];
int ma[105][105];
void swap(int x,int y){
  for(int i=1;i<=104;i++){
    std::swap(ma[x][i],ma[y][i]);
  }
}
int matrix(int ma[105][105],int n){
  int ans=1,v=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(ma[i][i]){
        int x=ma[j][i]/ma[i][i];
        for(int k=i;k<=n;k++){
          ma[j][k]+=mod-((x*ma[i][k])%mod);
          ma[j][k]%=mod;
        }
        swap(i,j);
        v=-v;
      }
      swap(i,j);
      v=-v;
    }
  }
  for(int i=1;i<=n;i++){
    ans*=ma[i][i];
    ans%=mod;
  }
  return ans*v;
}
int f[1005];
class poly{
  public:
    int tree[205];
    poly(){
      memset(tree,0,sizeof(tree));
      return ;
    }
};
const poly operator * (const poly &a,const poly &b){
  poly ans;
  for(int i=0;i<=101;i++){
    for(int j=0;j<=3;j++){
      ans.tree[i+j]+=(a.tree[i]*b.tree[j])%mod;
      ans.tree[i+j]%=mod;
    }
  }
  return ans;
}
const poly operator * (const poly &a,int b){
  poly ans;
  b%=mod;
  for(int i=0;i<=101;i++){
    ans.tree[i]%=mod;
    ans.tree[i]=(a.tree[i]*b)%mod;
  }
  return ans;
}
const poly operator + (const poly &a,const poly &b){
  poly ans;
  for(int i=0;i<=101;i++){
    (ans.tree[i]=a.tree[i]+b.tree[i])%=mod;
  }
  return ans;
}

int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
const poly operator / (poly a,int b){
  int inv=pow(b,mod-2);
  for(int i=0;i<=101;i++){
    a.tree[i]*=inv;
    a.tree[i]%=mod;
  }
  return a;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<n;i++){
    u[i]=read();
    v[i]=read();
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i!=j){
          ma[i][j]=mod-1;
        }else{
          ma[i][i]=n-1;
        }
      }
    }
    for(int i=1;i<n;i++){
      ma[u[i]][v[i]]-=k-1;
      ma[u[i]][u[i]]+=k-1;
      ma[v[i]][u[i]]-=k-1;
      ma[v[i]][v[i]]+=k-1;
    }
    f[k]=matrix(ma,n-1);
  }
  poly ans;
  for(int i=1;i<=n;i++){
    poly add;
    add.tree[0]=1;
    for(int j=1;j<=n;j++){
      poly add2;
      if(i==j){
        continue;
      }
      add2.tree[1]=1;
      add2.tree[0]=-j;
      add2=add2/(i-j);
      add=add*add2;
    }
    add=add*f[i];
    ans=ans+add;
  }
  for(int i=0;i<n;i++){
    printf("%lld ",(ans.tree[i]+mod)%mod);
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



