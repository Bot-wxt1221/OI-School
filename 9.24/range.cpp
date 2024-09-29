#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[1000005];
int mn[27];
int mn2[27];
int ad[1000005][27];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	#endif
	int n=read();
	scanf("%s",temp+1);
	for(int i=1;i<=n;i++){
		for(int j='a';j<='z';j++){
			ad[i][j-'a'+1]=ad[i-1][j-'a'+1];
			if(temp[i]==j){
				ad[i][j-'a'+1]++;
			}
		}
	}
	int rans=0;
	for(int i='a';i<='z';i++){
		memset(mn,0x3f,sizeof(mn));
		memset(mn2,0,sizeof(mn2));
		int ans=0;
		for(int j=1;j<=n;j++){
			ans-=(temp[j]==i);
			if(temp[j]!=i){
				rans=std::max(rans,ans+ad[j][temp[j]-'a'+1]-mn[temp[j]-'a'+1]);
				mn2[temp[j]-'a'+1]=std::min(mn2[temp[j]-'a'+1],ans+ad[j-1][temp[j]-'a'+1]);
			}else{
				for(int j=1;j<=26;j++){
					mn[j]=std::min(mn[j],mn2[j]);
				}
			}
		}
	}
	printf("%d",rans);
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
