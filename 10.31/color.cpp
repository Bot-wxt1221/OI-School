#include <iostream>
#include <cstdio>
#include <vector>
#define mod 1000000007
inline int read();
std::vector<std::pair<int,int> >vec[50005];
int pre[50005];
int dp[5015][5015];
int sumhang[50005];
int sumlie[50005];
int shang[50005];
int ll[1000005];
int rr[1000005];
int xx[1000005];
int xia[50005];
int to[1000005];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	#endif
	int T=1;
	while(T--){
		int n=read();
		int m=read();
		pre[0]=0;
		for(int i=1;i<=n+3;i++){
			pre[i]=0;
			sumhang[i]=0;
			sumlie[i]=0;
			for(int j=0;j<=i;j++){
				dp[i][j]=0;
			}
			vec[i+3].clear();
		}
		for(int i=1;i<=m;i++){
			int l=read();
			int r=read();
			int x=read();
			ll[i]=l;
			rr[i]=r;
			xx[i]=x;
			if(x==1){
				pre[l+4]++;
				pre[r+4]--;
			}
		}
		int cnt=0;
		for(int i=1;i<=n+3;i++){
			pre[i]+=pre[i-1];
			if(pre[i]){
				to[i]=to[i-1];
			}else{
				to[i]=++cnt;
			}
		}
		for(int i=1;i<=m;i++){
			vec[to[rr[i]+3]].push_back({to[ll[i]+3],xx[i]});
		}
		dp[2][1]=1;
		sumhang[2]++;
		sumlie[1]++;
		n=cnt;
		for(int i=1;i<=n;i++){
			shang[i]=1;
			xia[i]=i-1;
		}
		int prehang=1;
		for(int i=4;i<=n;i++){
			int mn1=0x3f3f3f3f,mx1=0,mn2=0x3f3f3f3f,mx2=0;
			for(int kk=0;kk<vec[i].size();kk++){
				if(vec[i][kk].second==1){
				}else if(vec[i][kk].second==2){
					mx1=std::max(mx1,vec[i][kk].first);
					mn2=std::min(mn2,vec[i][kk].first);
				}else{
					mx2=std::max(mx2,vec[i][kk].first);
				}
			}
			for(int j=prehang;j<mx1;j++){
				for(int k=shang[j];k<=xia[j];k++){
					sumhang[j]-=dp[j][k];
					sumhang[j]%=mod;
					sumlie[k]-=dp[j][k];
					sumlie[k]%=mod;
					dp[j][k]=0;
				}
			}
			prehang=std::max(prehang,mx1);
			for(int j=prehang;j<i;j++){
				while(shang[j]<mx2){
					sumhang[j]-=dp[j][shang[j]];
					sumhang[j]%=mod;
					sumlie[shang[j]]-=dp[j][shang[j]];
					sumlie[shang[j]]%=mod;
					dp[j][shang[j]]=0;
					shang[j]++;
				}
				while(xia[j]>=mn2){
					sumhang[j]-=dp[j][xia[j]];
					sumhang[j]%=mod;
					sumlie[xia[j]]-=dp[j][xia[j]];
					sumlie[xia[j]]%=mod;
					dp[j][xia[j]]=0;
					xia[j]--;
				}
			}
			for(int j=1;j<i;j++){
				int ret=sumhang[j];
				dp[i][j]+=ret;
				sumhang[i]+=ret;
				sumhang[i]%=mod;
				sumlie[j]+=ret;
				sumlie[j]%=mod;
			}
			for(int k=1;k<i;k++){
				int ret=sumlie[k]-dp[i][k];
				dp[i][k]+=ret;
				sumhang[i]+=ret;
				sumhang[i]%=mod;
				sumlie[k]+=ret;
				sumlie[k]%=mod;
			}
		}
		int i=n;
		int ans=0;
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				ans+=dp[j][k];
				ans%=mod;
			}
		}
		ans=1ll*ans*3%mod;
		ans%=mod;
		ans+=mod;
		ans%=mod;
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
