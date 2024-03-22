#include <iostream>
#include <cstdio>
inline int read();
int mu[500005];
bool fin[500005];
int p[500005];
int tot=0;
int solve(int n,int m){
  int ans=0;
  for(int i=1,j;i<=std::min(n,m);i=j+1){
    j=std::min((n/(n/i)),(m/(m/i)));
    ans+=(mu[j]-mu[i-1])*(n/i)*(m/i);
  }
  return ans;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  if(n==1){
    printf("0");
    return 0;
  }
  mu[1]=1;
  for(int i=2;i<=500000;i++){
    if(fin[i]==0){
      p[++tot]=i;
      mu[i]=-1;
    }
    for(int j=1;j<=tot;j++){
      if(i*p[j]>500000){
        break;
      }
      fin[i*p[j]]=1;
      if(i%p[j]==0){
        mu[i*p[j]]=0;
        break;
      }
      mu[i*p[j]]=-mu[i];
    }
  }
 for(int i=1;i<=500000;i++){
    mu[i]+=mu[i-1];
  }
  printf("%d\n",solve(n-1,n-1)+2);
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


