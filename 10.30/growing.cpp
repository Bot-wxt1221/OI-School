#include <iostream>
#include <cstdio>
inline int read();
int h[1000005];
char temp[1000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("growing.in","r",stdin);
	freopen("growing.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  if(n<=1e4&&m<=1e4){
    for(int i=1;i<=n;i++){
      h[i]=read();
    }
    scanf("%s",temp+1);
    for(int i=1;i<=m;i++){
      if(temp[i]=='A'){
        for(int j=2;j<=n;j++){
          if(h[j]<h[j-1]){
            h[j]++;
          }
        }
      }else{
        for(int j=n-1;j>=1;j--){
          if(h[j]<h[j+1]){
            h[j]++;
          }
        }
      }
    }
    for(int i=1;i<=n;i++){
      printf("%d ",h[i]);
    }
    return 0;
  }
  h[0]=h[1]=read();
  printf("%d ",h[1]);
  for(int i=2;i<=n;i++){
    int preh;
    h[i]=read();
    preh=h[i];
    h[i]+=m;
    h[i]=std::min(h[i],h[i-1]);
    h[i]=std::max(h[i],preh);
    printf("%d ",h[i]);
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
