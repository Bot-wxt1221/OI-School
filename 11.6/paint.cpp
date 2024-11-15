#include <iostream>
#include <cstdio>
inline int read();
int a[55],x[55],b[55],y[55];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    a[i]=read();
    x[i]=read();
    b[i]=read();
    y[i]=read();
  }
  int ans=0;
  for(int i=0;i<(1<<(n));i++){
    for(int j=i;j;j=(j-1)&(i)){
      int preans=ans;
      for(int k=1;k<=m;k++){
        int ta=((i&(1<<(a[k]-1)))>0)+((j&(1<<(a[k]-1)))>0);
        int tb=((i&(1<<(b[k]-1)))>0)+((j&(1<<(b[k]-1)))>0);
        if(ta==x[k]&&tb==y[k]){
          ans--;
          break;
        }
      }
      ans++;
      if(ans!=preans){
        for(int k=1;k<=n;k++){
        }
        ans--;
      }
    }
    int preans=ans;
    int j=0;
    for(int k=1;k<=m;k++){
      int ta=((i&(1<<(a[k]-1)))>0)+((j&(1<<(a[k]-1)))>0);
      int tb=((i&(1<<(b[k]-1)))>0)+((j&(1<<(b[k]-1)))>0);
      if(ta==x[k]&&tb==y[k]){
        ans--;
        break;
      }
    }
    ans++;
      if(ans!=preans){
        for(int k=1;k<=n;k++){
          printf("%d",((i&(1<<(k-1)))>0)+((j&(1<<(k-1)))>0));

        }
      printf("\n");
      }

  }
  printf("%d",ans);
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
