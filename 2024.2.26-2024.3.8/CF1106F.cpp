#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#define int long long
#define mod 998244352
inline int read();
class matrix{
public:
  int map[105][105];
  matrix(int n=0){
    memset(map,0,sizeof(map));
    for(int i=1;i<=101;i++){
      map[i][i]=n;
    }
    return ;
  }
};
int pow(int a,int b,int md){
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=md;
    }
    cur*=cur;
    cur%=md;
    b/=2;
  }
  return ans;
}
int exgcd(int x,int y,int &a,int &b){
  if(y==0){
    a=1;
    b=0;
    return x;
  }else{
    int ta,tb;
    int ret=exgcd(y,x%y,ta,tb);
    a=tb;
    b=(ta)-(x/y)*tb;
    return ret;
  }
}
const matrix operator * (const matrix &a,const matrix &b){
  matrix ans;
  for(int i=1;i<=101;i++){
    for(int j=1;j<=101;j++){
      for(int k=1;k<=101;k++){
        ans.map[i][k]+=a.map[i][j]*b.map[j][k]%mod;
        ans.map[i][k]%=mod;
      }
    }
  }
  return ans;
}
matrix pow(matrix a,int b){
  matrix ans(1);
  matrix cur=a;
  while(b){
    if(b%2==1){
      ans=ans*cur;
    }
    cur=cur*cur;
    b/=2;
  }
  return ans;
}
int bsgs(int a,int b,int md){
  a%=md;
  b%=md;
  std::map<int,int>mp;
  int smod=std::sqrt(md)+1;
  int t=1;
  for(int i=1;i<=smod;i++){
    if(mp[t]==0){
      mp[t]=i;
    }
    t*=a;
    t%=md;
  }
  int k=pow(t,md-2,md);
  int w=b;
  for(int i=1;i<=smod;i++){
    if(mp[w]){
      return (i-1)*smod+mp[w]-1;
    }
    w*=k;
    w%=md;
  }
  return -2;
}

matrix base,base2;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int k=read();
  for(int i=1;i<=k;i++){
    if(i<k){
      base.map[i+1][i]=1;
    }
    base.map[k-i+1][k]=read();
  }
  int n=read();
  int m=read();
  matrix ret=pow(base,n-k);
  base2.map[1][k]=1;
  base2=base2*ret;
  int ret2=bsgs(3,m,mod+1);
  if(ret2==-2){
    printf("-1\n");
    return 0;
  }
  int a;
  int b;
  int ret3=exgcd(base2.map[1][k],mod,a,b);
  if(ret2%ret3){
    printf("-1\n");
    return 0;
  }else{
    a=(ret2/ret3)*a;
    a%=(mod);
    a+=mod;
    a%=mod;
    printf("%lld\n",pow(3,a,mod+1));
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


