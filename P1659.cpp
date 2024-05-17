#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 19930726
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

char temp[5000005];
char temp2[5000005];
int p[5000005];
int tt[5000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  int cnt=0;
  temp2[++cnt]='~';
  temp2[++cnt]='#';
  for(int i=1;i<=siz;i++){
    temp2[++cnt]=temp[i];
    temp2[++cnt]='#';
  }
  int r=0;
  int mid=0;
  int ans=0;
  for(int i=1;i<=cnt;i++){
    if(i<=r){
      p[i]=std::min(p[2*mid-i],r-i+1);
    }
    while(temp2[i-p[i]]==temp2[i+p[i]]){
      p[i]++;
    }
    if(p[i]+i>r){
      r=p[i]+i-1;
      mid=i;
    }
    tt[p[i]-1]++;
  }
  ans=1;
  for(int i=5000000-1;i>=1;i-=2){
    tt[i]+=tt[i+2];
    int used=std::min(tt[i],k);
    k-=used;
    ans=1ll*ans*pow(i,used)%mod;
  }
  if(k>0){
    ans=-1;
  }
  printf("%d",ans);
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

