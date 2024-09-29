#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map[405][405];
int pos[405*405];
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			memset(pos,0,sizeof(pos));
			int hm=1;
			for(int l=j;l>=1;l--){
				for(int jj=1;jj<=i;jj++){
					if(jj>=pos[map[jj][l]]){
						hm=std::max(hm,pos[map[jj][l]]+1);
						pos[map[jj][l]]=jj;
					}else{
						hm=std::max(hm,jj+1);
					}
				}
				ans=std::max(ans,(j-l+1)*(i-hm+1));
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
