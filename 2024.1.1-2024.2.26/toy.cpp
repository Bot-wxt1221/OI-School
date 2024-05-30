#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int a[100005];
int mint[100005][105];
int bef[100005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int t=read(),n;
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=100;i++){
    memset(bef,0,sizeof(bef));
    int sum=0;
    for(int j=1;j<=n;j++){
      sum+=a[j];
      sum%=i;
      mint[j][i]=bef[sum];
      mint[j][i]=std::max(mint[j][i],mint[j-1][i]);
      bef[sum]=j;
    }
  }
  int ans=0;
  for(int i=1;i<=t;i++){
    int l=read();
    int r=read();
    int k=read();
    int w=read();
    if(mint[r][k]>=l){
      ans+=w;
    }else{
      ans-=w;
    }
  }
  int s=read();
  printf("%d",ans+s);
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


