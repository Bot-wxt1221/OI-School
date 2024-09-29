#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
std::vector<std::pair<int,int>>vec;
int n;
int a[5];
void dfs(int now,int depth){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i]>0;
		}
		if(cnt<=2){
			if(a[1]==0){
				printf("%ld\n",vec.size());
				for(int i=0;i<vec.size();i++){
					printf("%d %d\n",vec[i].first,vec[i].second);
				}
				exit(0);
				return ;
			}
		}
		if(depth>10){
			return ;
		}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int preai=a[i];
			int preaj=a[j];
			if(a[i]<a[j]){				
				vec.push_back({j,i});
				a[j]-=a[i];
				a[i]*=2;
			}else{
				vec.push_back({i,j});
				a[i]-=a[j];
				a[j]*=2;
			}
			dfs(now+1,depth+1);
			a[i]=preai;
			vec.pop_back();
			a[j]=preaj;
		}
	}
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	#endif
	n=read();
	read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1,0);
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
