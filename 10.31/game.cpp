#include <iostream>
#include <cstdio>
inline int read();
int dp[25][25][25];
int com[25][25][25];
bool dfs(int a,int b,int c){
	if(com[a][b][c]){
		return dp[a][b][c];
	}
	com[a][b][c]=1;
	int &ans=dp[a][b][c];
	for(int i=0;i<=a+b;i++){
		int ta=i;
		int tb=a+b-i;
		if(std::abs(ta-tb)<std::abs(a-b)){
			ans|=!(dfs(ta,tb,c));
		}
	}
	std::swap(b,c);
	for(int i=0;i<=a+b;i++){//a c
		int ta=i;
		int tb=a+b-i;
		if(std::abs(ta-tb)<std::abs(a-b)){
			ans|=!(dfs(ta,tb,c));
		}
	}
	std::swap(b,c);
	std::swap(a,c);
	for(int i=0;i<=a+b;i++){//a c
		int ta=i;
		int tb=a+b-i;
		if(std::abs(ta-tb)<std::abs(a-b)){
			ans|=!(dfs(ta,tb,c));
		}
	}
	return ans;
}
int a[15];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(dfs(a[i],a[j],a[k])){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
inline int read(){
	int f=0,x=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(x=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		f=(f<<3)+(f<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
