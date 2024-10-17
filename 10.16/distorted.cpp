#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[505][505];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("distorted.in","r",stdin);
	freopen("distorted.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        a[i][j]=read();
      }
    }
    // 1
    int ans=a[(n+1)/2][(n+1)/2];

    //2
    int min11=0x3f3f3f3f3f3f3f;
    int min21=0x3f3f3f3f3f3f3f;
    for(int i=1;i<=n/2;i++){
      min11=std::min(min11,a[(n+1)/2][i]);
      min21=std::min(min21,a[(n+1)/2][i+(n+1)/2]);
    }
    ans=std::min(ans,min11+min21);

    int min12=0x3f3f3f3f3f3f3f;
    int min22=0x3f3f3f3f3f3f3f;
    for(int i=1;i<=n/2;i++){
      min12=std::min(min12,a[i][(n+1)/2]);
      min22=std::min(min22,a[i+(n+1)/2][(n+1)/2]);
    }
    ans=std::min(ans,min12+min22);
    
    int min1=std::min(min12,min11),min2=std::min(min11,min22),min3=std::min(min12,min21),min4=std::min(min21,min22);
    for(int i=1;i<=n/2;i++){
      for(int j=1;j<=n/2;j++){
        min1=std::min(min1,a[i][j]);
        min2=std::min(min2,a[i+((n+1)/2)][j]);
        min3=std::min(min3,a[i][j+((n+1)/2)]);
        min4=std::min(min4,a[i+((n+1)/2)][j+((n+1)/2)]);
      }
    }
    ans=std::min(ans,min1+min2+min3+min4);
    
    ans=std::min(ans,min3+min4+min11);
    ans=std::min(ans,min12+min2+min4);
    ans=std::min(ans,min22+min1+min3);
    ans=std::min(ans,min21+min1+min2);

    printf("%lld\n",ans);
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
