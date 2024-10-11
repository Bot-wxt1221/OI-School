#include <iostream>
#include <cstdio>
inline int read();
char temp[205][205];
int a[1005];
int ans[205][205];
int b[1005];
bool vised[205][205];
std::pair<int,int> c[1005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("garden.in","r",stdin);
	freopen("garden.out","w",stdout);
	#endif
	int n=read();
	int m=read();
	int k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",temp[i]+1);
	}
	for(int i=1;i<=k;i++){
		a[i]=read();
		b[i]=read();
		if(vised[a[i]+101][b[i]+101]){
			i--;
			k--;
			continue;
		}
		vised[a[i]+101][b[i]+101]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int kk=1;kk<=k;kk++){
				if(i+a[kk]<0||j+b[kk]<0){
					continue;
				}
				ans[i][j]+=std::max((int)(temp[i+a[kk]][j+b[kk]]-'0'),0);
			}
		}
	}
	int ans=0;
	for(int ti=-n+1;ti<n;ti++){
		for(int tj=-m+1;tj<m;tj++){
			int cnt=0;
			for(int k1=1;k1<=k;k1++){
				for(int k2=1;k2<=k;k2++){
					if(a[k2]-a[k1]==ti&&b[k2]-b[k1]==tj){
						c[++cnt]={ti+a[k1],tj+b[k1]};
					}
				}
			}
			for(int i=1;i+ti<=n;i++){
				for(int j=1;j+tj<=m;j++){
					if(i<0||j<0||i+ti<0||j+tj<0){
						continue;
					}
					int cntt=0;
					for(int k=1;k<=cnt;k++){
						if(i+c[k].first<0||j+c[k].second<0){
							continue;
						}
						cntt+=std::max((int)(temp[i+c[k].first][j+c[k].second]-'0'),0);
					}
					ans=std::max(ans,::ans[i][j]+::ans[i+ti][j+tj]-cntt);
				}
			}
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
