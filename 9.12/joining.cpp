#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 998244353
inline int read();
class node{
public:
  std::string a;
  int cnt;
  int mdd;
};
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    y>>=1;
    x*=x;
    x%=mod;
  }
  return ans;
}
bool operator < (node a,node b){
  return a.a+b.a>b.a+a.a;
}
char temp[2000005];
std::vector<node>vec;
int cnt[500005];
class num{
public:
  int cnt;
  int real;
  num(int x,int y){
    cnt=x;
    real=y;
    return ;
  }
};
num operator * (num a,int b){
  if(b==0){
    a.cnt++;
  }else{
    a.real*=b;
    a.real%=mod;
  }
  return a;
}
num operator / (num a,int b){
  if(b==0){
    a.cnt--;
  }else{
    a.real*=pow(b,mod-2);
    a.real%=mod;
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
  int tot=1;
  num cheng(0,1);
  for(int i=1;i<=n;i++){
    int siz=read();
    tot*=pow(siz,mod-2);
    tot%=mod;
    for(int j=1;j<=siz;j++){
      scanf("%s",temp+1);
      std::string b(temp+1);
      int cnt=1;
      int ans=0;
      for(int k=b.size()-1;k>=0;k--){
        ans+=(b[k]-'0')*cnt%mod;
        ans%=mod;
        cnt*=10;
        cnt%=mod;
      }
      vec.push_back(node({b,i,ans}));
    }
    cnt[i]=siz;
    cheng=cheng*siz;
  }
  int totsum=0;
  std::random_shuffle(vec.begin(),vec.end());
  std::sort(vec.begin(),vec.end());
  for(int i=vec.size()-1;i>=0;i--){
    cheng=cheng/cnt[vec[i].cnt];
    cnt[vec[i].cnt]+=pow(10,vec[i].a.size())-1;
    cnt[vec[i].cnt]%=mod;
    if(cheng.cnt==0){
      totsum+=cheng.real*tot%mod*vec[i].mdd%mod;
      totsum%=mod;
    }
    cheng=cheng*cnt[vec[i].cnt];
  }
  printf("%lld",totsum);
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
