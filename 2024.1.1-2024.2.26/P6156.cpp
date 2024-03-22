#include <iostream>
#include <cstdio>
#define int unsigned int
inline int read();
int pow(int a,int n){
  int res=1;
	while(n)
	{
		if(n&1)
			res=res*a;
		a=a*a;
		n>>=1;
	}
	return res;
}

bool pr[20000005];
int prl[20000005];
int pw[20000005];
int pws[20000005];
int expo[20000005];
int G[20000005];
int F[20000005];
int sum[20000005];
void init(int N,int k){
  pw[1]=pws[1]=1;
  G[1]=1;
  int cnt=0;
  for(int i=2;i<=2*N;i++){
    if(pr[i]==0){
      prl[++cnt]=i;
      pw[i]=pow(i,k);
      expo[i]=1;
      G[i]=i-1;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*i*prl[j]>N){
        break;
      }
      pr[i*prl[j]]=1;
      G[i*prl[j]]=((G[i])*G[prl[j]]);
      expo[i*prl[j]]=1;
      pw[i*prl[j]]=(pw[i]*pw[prl[j]]);
      if(i%prl[j]==0){
        if(expo[i]==1){
          G[i*prl[j]]=((G[i/prl[j]])*(-prl[j]));
        }else{
          G[i*prl[j]]=0;
        }
        expo[i*prl[j]]=expo[i]+1;
        break;
      }
    }
  }
  for(int i=1;i<=2*N;i++){
    pws[i]=pws[i-1]+pw[i];
  }
  for(int i=1;i<=N;i++){
    F[i]=F[i-1];
    F[i]+=(pws[i*2]+pws[i*2-1]-(pws[i]*2));
    sum[i]=(sum[i-1]+(G[i]*pw[i]));
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else

  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int n=read();
  long long k;
  scanf("%lld",&k);
  init(n+1,k);
  while(T--){
    int n=read();
    int ans=0;
    for(int i=1,j;i<=n;i=j+1){
      j=((n/(n/i)));
      ans+=(F[n/i]*(sum[j]-sum[i-1]));
    }
    printf("%u\n",ans);
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


