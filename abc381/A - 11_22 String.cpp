#include <iostream>
#include <cstdio>
inline int read();
char temp[105];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  scanf("%s",temp+1);
  if(n%2==0){
    printf("No\n");
    return 0;
  }
  for(int i=1;i<=n/2;i++){
    if(temp[i]!='1'){
      printf("No\n");
      return 0;
    }
  }
  if(temp[(n+1)/2]!='/'){
    printf("No");
    return 0;
  }
  for(int i=(n+1)/2+1;i<=n;i++){
    if(temp[i]!='2'){
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
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
