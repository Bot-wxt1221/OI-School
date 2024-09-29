#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int seq[4][4]={{0},{0,1},{0,2,1},{0,3,1,2}};
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	#endif
	int n=read();
	if(n<=3){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				ans^=(seq[i][j]+j);
			}
		}
		printf("%lld",ans);
	}else{
		int ans=0;
		int ret;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=i;j++){
				ans^=(seq[i][j]+j);
			}
		}
		if(n%2==1){
			ans^=((((n-3)/2)%2)<<1);
			ans^=4;
		}else{
			ans^=((seq[3][1]+1)^(seq[3][2]+2)^(seq[3][3]+3));
			ans^=4;
		}
		ret=n/2;
		int tans=0;
		for(int i=0;i<62;i++){
			if(n<(1ll<<(i))){
				continue;
			}
			int cnt=(ret+1)/(1ll<<(i+1));
			cnt*=((1ll<<(i)));
			cnt+=std::max(((ret+1)%(1ll<<(i+1)))-(1ll<<(i)),0ll);
			if(cnt&1){
				tans^=(1ll<<(i));
			}
		}
		printf("%lld",ans^(tans<<2));
	}
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?f=-1:0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
