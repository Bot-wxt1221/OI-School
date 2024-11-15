#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#define int long long
inline int read();
int tt[50005];
int ccc;
int pow(__int128 x,int y){
  __int128 ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans=std::min(ans,(__int128)1e18+5);
    }
    x*=x;
    y>>=1;
    x=std::min(x,(__int128)1e18+5);
  }
  return ans;
}
int ti=1;
bool judge(int n,int cnt){
  int l=1,r=n;
  while(r-l>3){
    int mid=(l+r)/2;
    if(pow(mid,cnt)>n){
      r=mid;
    }else{
      l=mid;
    }
  }
  for(int i=l;i<=r;i++){
    if(pow(i,cnt)==n){
      ti=i;
      return 1;
    }
  }
  return 0;
}
int exgcd(int a,int b,int &x,int &y) {
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  int ret=exgcd(b,a%b,y,x);
  y-=(a/b)*x;
  return ret;
}
bool is_prime[40005];
int pr[40005];
int cnt;
std::map<int,int>mp;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
  int T=read();
  for(int i=2;i<=4e3;i++){
    if(is_prime[i]==0){
      pr[++cnt]=i;
    }
    for(int j=1;j<=cnt;j++){
      if(i*pr[j]>4e3){
        break;
      }
      is_prime[i*pr[j]]=1;
      if(i%pr[j]==0){
        break;
      }
    }
  }
  for(int i=5e4;i>=1;i--){
    __int128 ans=i*i*i*i;
    for(int j=1;j<=64;j++){
      mp[ans]=j+3;
      ans*=i;
      if(ans>1e18){
        break;
      }
    }
  }
  while(T--){
    int n=read();
    int mx=0;
    int mn=0x3f3f3f3f;
    bool yes=0;
    ccc=0;
    if(mp[n]){
      printf("yes\n");
      goto end;
    }
    for(int i=2;i<=4;i++){
      if(judge(n,i)){
        printf("yes\n");
        goto end;
      }
    }
    for(int ii=1;ii<=cnt;ii++){
      int i=pr[ii];
      if(n<i*i){
        break;
      }
      int cntt=0;
      while(n%i==0){
        n/=i;
        cntt++;
      }
      if(cntt){
        tt[++ccc]=cntt;
        if(cntt==1){
          yes=1;
          break;
        }
        mx=std::max(mx,cntt);
        mn=std::min(mn,cntt);
      }
    }
    if(n!=1){
      if(mp[n]){
        tt[++ccc]=mp[n];
        n=1;
        mx=std::max(mx,tt[ccc]);
        mn=std::min(mn,tt[ccc]);
      }
    }
    if(n!=1){
      for(int i=4;i>=2;i--){
        if(judge(n,i)){
          tt[++ccc]=i;
          n=1;
          mx=std::max(mx,tt[ccc]);
          mn=std::min(mn,tt[ccc]);
          break;
        }
      }
    }
    if(n==1&&yes==0){
      if(ccc<=2){
        printf("yes\n");
        goto end;
      }
      std::sort(tt+1,tt+ccc+1);
      ccc=std::unique(tt+1,tt+ccc+1)-tt-1;
      for(int i=2;i<=mn;i++){
        for(int j=i+1;j<=mx;j++){
          bool yes=1;
          int taa=0,tbb=0;
          int ret=exgcd(i,j,taa,tbb);
          for(int k=1;k<=ccc;k++){
            int ta=taa;
            int tb=tbb;
            if(tt[k]%ret!=0){
              yes=0;
              break;
            }
            ta*=tt[k]/ret;
            tb*=tt[k]/ret;
            int preta=ta;
            int tt=j/ret;
            ta%=tt;
            ta+=tt;
            ta%=tt;
            tb-=(ta-preta)/tt*(i/ret);
            if((ta>=0)&&(tb>=0)){
            }else{
              yes=0;
              break;
            }
          }
          if(yes){
            printf("yes\n");
            goto end;
          }
        }
      }
    }
    printf("no\n");
    end:{}
  }
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
