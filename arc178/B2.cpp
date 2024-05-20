#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
inline int pow(int a,int k){
  long long res=1;
  while(k){
    if(k&1){
      #ifdef mod
      res=1ll*res*a%mod;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=1ll*a*a%mod;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}
class Matrix{
  public:
    int map[5][5];
};
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      ans.map[i][j]=0;
      for(int k=1;k<=3;k++){
        ans.map[i][j]+=(1ll*a.map[i][k]*b.map[k][j])%mod;
      }
    }
  }
  return ans;
}
Matrix a,b;
inline Matrix pow(Matrix a,int k){
  Matrix res;
  res.map[1][1]=res.map[2][2]=1;
  res.map[2][1]=res.map[1][2]=0;
  while(k){
    if(k&1){
      #ifdef mod
      res=res*a;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=a*a;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int jin1=0,jin2=0;
  while(T--){
    int ans=0;
    int a1=read();
    int a2=read();
    int a3=read();
    if(a3<a2||a3<a1){
      printf("0\n");
      continue;
    }
    if(a3-std::max(a1,a2)>1){
      printf("0\n");
      continue;
    }
    if(a1>a2){
      std::swap(a1,a2);
    }
    if(a1==a2&&a2==a3){
      a.map[1][1]=55;
      a.map[1][2]=45;
      b.map[1][1]=55;
      b.map[1][2]=45;
      b.map[2][1]=45;
      b.map[2][2]=55;
      if(a1==1){
        printf("36\n");
      }else{
        a=a*pow(b,a1-2);
        int dp1=a.map[1][1];
        int dp2=a.map[1][2];
        int ans=0;
        for(int j=1;j<=9;j++){
          for(int k=1;k<=9;k++){
            if(j+k+1<10){
              ans+=dp2;
              ans%=mod;
            }
            if(j+k<10){
              ans+=dp1;
              ans%=mod;
            }
          }
        }
        printf("%lld\n",ans);
      }
    }else {
      a.map[1][1]=55;
      a.map[1][2]=45;
      b.map[1][1]=55;
      b.map[1][2]=45;
      b.map[2][1]=45;
      b.map[2][2]=55;
      if(a1==1){
        int ans=45;
        if(a3==a2){
          ans=45*(pow(10,a2-a1-1)*9-1)%mod;
          ans%=mod;
          ans+=45*pow(10,a2-a1-1)%mod*9%mod;
          ans%=mod;
        }
        printf("%lld\n",ans);
      }else{
        a=a*pow(b,a1-2);
        int dp1=a.map[1][1];
        int dp2=a.map[1][2];
        int ans=0;
        int ans2=0;
        for(int j=(a1==a2);j<=9;j++){
          for(int k=1;k<=9;k++){
            if(j+k+1>=10){
              ans+=dp2;
              ans%=mod;
            }else{
              ans2+=dp2;
              ans2%=mod;
            }
            if(j+k>=10){
              ans+=dp1;
              ans%=mod;
            }else{
              ans2+=dp1;
              ans2%=mod;
            }
          }
        }
        int tans=ans;
        if(a3==a2){
          ans=((__int128)tans)*(pow(10,a2-a1-1)*9-1)%mod;
          ans%=mod;
          ans+=((__int128)ans2)*pow(10,a2-a1-1)%mod*9%mod;
          ans%=mod;
        }
        printf("%lld\n",ans);
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

