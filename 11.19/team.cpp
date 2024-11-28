#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int map[1005][1005];
int ans[1005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	#endif
  int n=read();
  int tot=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      map[i][j]=read();
      tot+=map[i][j];
      ans[i]+=map[i][j];
      ans[j]+=map[i][j];
    }
  }
  int tans=0;
  std::sort(ans+1,ans+n+1);
  std::reverse(ans+1,ans+n+1);
  for(int i=1;i<=n/2;i++){
    if(ans[i]>0){
      tans+=ans[i];
    }
  }
  tans=tans-tot;
  tans/=2;
  printf("%lld",tans);
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
