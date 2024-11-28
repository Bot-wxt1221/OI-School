#include <cstring>
#include <iostream>
#include <cstdio>
inline int read();
char temp[105];
int cnt[1005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  if(n%2==1){
    printf("No\n");
    return 0;
  }
  for(int i=1;i<=n/2;i++){
    cnt[temp[i*2]]++;
    cnt[temp[i*2-1]]++;
    if(temp[i*2]!=temp[i*2-1]){
      printf("No\n");
      return 0;
    }
  }
  for(int i=1;i<=1000;i++){
    if(cnt[i]!=0&&cnt[i]!=2){
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
