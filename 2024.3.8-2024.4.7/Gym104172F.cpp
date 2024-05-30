#include <algorithm>
#include <cstdio>
#include <iostream>
inline int read();
char ss[200005];
int n;
class Bignum{
  public:
    char ss[100005];
    int cnt;
    Bignum(){
      cnt=0;
      return ;
    }
};
const bool operator < (const Bignum &a,const Bignum &b){
  if(a.cnt!=b.cnt){
    return a.cnt<b.cnt;
  }
  for(int i=a.cnt;i>=1;i--){
    if(a.ss[i]!=b.ss[i]){
      return a.ss[i]<b.ss[i];
    }
  }
  return 0;
}
const Bignum &operator += (Bignum &a,const Bignum &b){
  int rem=0;
  for(int i=1;i<=std::max(a.cnt,b.cnt)+1;i++){
    if(i>a.cnt){
      a.ss[i]=0;
    }
    if(i<=b.cnt){
      a.ss[i]+=b.ss[i];
    }
    a.ss[i]+=rem;
    rem=0;
    rem+=a.ss[i]/10;
    a.ss[i]%=10;
  }
  a.cnt=std::max(a.cnt,b.cnt)+1;
  while(a.ss[a.cnt]==0){
    a.cnt--;
  }
  return a;
}
int a[15];
int tt;
int k;
Bignum anss;
Bignum ans2;
Bignum ttt;
int L,R;
void dfs(int now,int sum){
  if(sum>=n&&now!=k+1){
    return ;
  }
  if((k-now+1)*(R)+sum<n){
    return ;
  }
  if((k-now+1)*(L)+sum>n){
    return ;
  }
  if(now==k+1){
    if(sum!=n){
      return ;
    }
    ans2.cnt=0;
    int nxt=0;
    for(int i=1;i<=k;i++){
      ttt.cnt=a[i];
      for(int j=1;j<=a[i];j++){
        ttt.ss[a[i]-j+1]=ss[j+nxt]-'0';
      }
      ans2+=ttt;
      nxt+=a[i];
    }
    if(ans2<anss){
      anss=ans2;
      for(int i=1;i<=k;i++){
        std::cerr<<a[i]<<std::endl;
      }
      std::cerr<<std::endl;
    }
    return ;
  }
  for(int i=L;i<=R;i++){
    a[now]=i;
    dfs(now+1,sum+i);
  }
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    k=read()+1;
    scanf("%s",ss+1);
    tt=n/k;
    anss.cnt=200001;
    L=std::max(1,tt-1);
    R=std::min(n,tt+1);
    dfs(1,0);
    L=std::max(1,tt);
    R=std::min(n,tt+2);
    dfs(1,0);
    while(anss.cnt){
      putchar(anss.ss[anss.cnt--]+'0');
      anss.ss[anss.cnt+1]=0;
    }
    putchar('\n');
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


