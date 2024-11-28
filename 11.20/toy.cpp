#include <iostream>
#include <cstdio>
inline int read();
char temp[3000005];
int pre[3000005];
int tt[3000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	#endif
  int b=read();
  int a=read();
  int n=read();
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    if(temp[i]=='1'){
      pre[i]=i;
    }else{
      pre[i]=pre[i-1];
    }
    tt[i]=tt[i-1]+temp[i]-'0';
  }
  int curb=1;
  int cura=a;
  long long ans=n-a;
  while(cura<n){
    int fir=pre[cura];
    int cnt=0;
    while(tt[fir]-tt[curb]>=b){
      curb++;
      cnt++;
    }
    ans+=b;
    if(cnt==0){
      printf("IMPOSSIBLE");
      return 0;
    }
    cura+=cnt;
  }
  printf("%lld",ans+b);
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
