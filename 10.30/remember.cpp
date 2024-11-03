#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
inline void write(int ans);
int a[1000005];
int cnt[100];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("remember.in","r",stdin);
	freopen("remember.out","w",stdout);
	#endif
  int n=read();
  int ans1=0;
  int ans2=0;
  int ans3=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=n;i>=1;i--){
    int left=n-i;
    for(int k=0;k<32;k++){
      if(a[i]&(1<<k)){
        ans1+=cnt[k]*(1<<k);
        ans2+=left*(1<<k);
        ans3+=(left-cnt[k])*(1<<k);
      }else{
        ans2+=cnt[k]*(1<<k);
        ans3+=cnt[k]*(1<<k);
      }
    }
    for(int k=0;k<32;k++){
      if(a[i]&(1<<k)){
        cnt[k]++;
      }
    }
  }
  write(ans1);
  write(ans2);
  write(ans3);
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
inline void write(int ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	int n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
}
