#include <iostream>
#include <cstdio>
inline int read();
char temp[200005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    scanf("%s",temp+1);
    bool ok=(temp[1]=='1'||temp[n]=='1');
    for(int i=2;i<=n;i++){
      if(temp[i]=='1'&&temp[i-1]=='1'){
        ok=1;
      }
    }
    if(ok){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
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
