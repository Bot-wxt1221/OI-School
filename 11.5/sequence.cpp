#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
inline int read();
int seq[5000005];
bool not_prime[5000005];
int min[5000005];
int primeseq[1000005];
int cnt;
int l[1000005];
int r[1000005];
std::vector<int>tt;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  for(int i=2;i<=5e6;i++){
    if(not_prime[i]==0){
      primeseq[++cnt]=i;
      min[i]=cnt;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*primeseq[j]*i>((long long)5e6)){
        break;
      }
      not_prime[primeseq[j]*i]=1;
      min[primeseq[j]*i]=j;
      if(i%primeseq[j]==0){
        break;
      }
    }
  }
  for(int i=1;i<=cnt;i++){
    l[i]=n+1;
    r[i]=n;
  }
  long long ans=0;
  int l4=n+1,r4=n;
  for(int i=n;i>=1;i--){
    int ti=seq[i];
    int pre=-1;
    tt.clear();
    while(ti>1){
      if(min[ti]!=pre){
        tt.push_back(min[ti]);
      }
      pre=min[ti];
      ti/=primeseq[min[ti]];
    }
    int mx=i-1;
    int mxx=i-1;
    for(int j=0;j<tt.size();j++){
      if(l[tt[j]]!=i+1){
        l[tt[j]]=r[tt[j]]=i;
      }else{
        l[tt[j]]=i;
      }
      mx=std::max(mx,r[tt[j]]);
      if(tt[j]!=1){//primeseq[1]=2
        mxx=std::max(mxx,r[tt[j]]);
      }
    }
    if(seq[i]%4==0){
      if(l4!=i+1){
        l4=r4=i;
      }else{
        l4=i;
      }
    }
    if(seq[i]%2==1||mxx==mx||(seq[i]%4==0&&mx==r4)){
      ans+=(mx-i+1)+(n-mx)*2;
    }else{
      ans+=(mx-i+1)+(n-mx)*3;
    }
  }
  printf("%lld",ans);
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
