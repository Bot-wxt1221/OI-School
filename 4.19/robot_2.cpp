#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
int read(){
	int x=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9'){
		a=='-'?f=-1:0;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=(x<<3)+(x<<1)+(a^'0');
		a=getchar();
	}
	return f*x;
}
int a[300005];
int a2[300005];
int b[300005];
int b2[300005];
int c[600005];
int c2[600005];
int main(){
//	freopen("robot.in","r",stdin);
//	freopen("robot.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			a2[i]=read();
			a[i]=read()+a[i-1];
			c[i]=a[i];
		}
		int tim=0;
		int m=read();
		for(int i=1;i<=m;i++){
			b2[i]=read();
			b[i]=read()+b[i-1];
			c[i+n]=b[i];
			tim+=b[i];
		}
		std::sort(c+1,c+n+m+1);
		int cnt=std::unique(c+1,c+n+m+1)-c-1;
		for(int i=1;i<=cnt;i++){
			c2[i]=b2[std::lower_bound(b+1,b+m+1,c[i])-b]-a2[std::lower_bound(a+1,a+n+1,c[i])-a];
		}
		int tans=0;
		c[cnt+1]=0x3f3f3f3f;
		for(int i=-tim;i<=tim;i++){
			int now=i;
			int ans=0;
			if(i==0){
				ans++;
			}
			for(int j=1;j<=cnt;j++){
				if(c2[j]==0){
					if(now==0){
						ans+=(c[j]-c[j-1]);
					}
					continue;
				}
				int tt=-now/c2[j];
				if(now+c2[j]*tt==0&&tt>0&&tt<=c[j]-c[j-1]){
					ans++;
				}
				now+=c2[j]*(c[j]-c[j-1]);
			}
			tans=std::max(tans,ans);
      if(tans==201){
      printf("%d\n",i);
      }
		}
		printf("%d\n",tans);
	}
	return 0;
}
