#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map[405][405];
int num[405*405];
int num2[405*405];
int dp[405][405][405];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
	int n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=read();
		}
	}
	int ans=0;
	for(int siz=1;siz<=m;siz++){
		for(int l=1;l+siz-1<=m;l++){
      int r=l+siz-1;
      int dw=n;
      for(int u=n;u>=1;u--){
        dp[l][r][u]=0x3f3f3f3f;
        if(l<r){
          dp[l][r][u]=std::min(dp[l+1][r][u],dp[l][r-1][u]);          
        }
        if(u!=n){
          dp[l][r][u]=std::min(dp[l][r][u],dp[l][r][u+1]);
        }
        if(l==r){
          num[map[u][l]]++;
          while(num[map[u][l]]>1){
            num[map[dw][l]]--;
            dw--;
          }
        }else{
          num[map[u][l]]++;
          num2[map[u][r]]++;
          while(num[map[u][r]]||num2[map[u][l]]){
            while(num[map[u][r]]||num2[map[u][r]]>1){
              num[map[dw][l]]--;
              num2[map[dw][r]]--;
              dw--;
            }
            while(num2[map[u][l]]||num[map[u][l]]>1){
              num[map[dw][l]]--;
              num2[map[dw][r]]--;
              dw--;
            }
          }
        }
        dp[l][r][u]=std::min(dp[l][r][u],dw);
        ans=std::max(ans,(siz)*(dp[l][r][u]-u+1));
      }
      for(int u=1;u<=n;u++){
        num[map[u][l]]=num2[map[u][r]]=0;
        num2[map[u][l]]=num[map[u][r]]=0;
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
