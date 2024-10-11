#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int seq[1000005];
int cnt,ttt;
std::vector<int>vec1,vec2;
int lowbit(int x){
	return x&(-x);
}
int ans=0;
class BIT{
public:
	int tree[1000005];
	int query(int now){
		int ans=0;
		while(now>0){
			ans+=tree[now];
			now-=lowbit(now);
		}
		return ans;
	}
	void mod(int now,int y){
		while(now<=1000000){
			tree[now]+=y;
			now+=lowbit(now);
		}
		return ;
	}
}sq;
void fen(int l1,int r1,int l2,int r2){
	if(l1>r1){
		return ;
	}
	ttt++;
	int mid=(l1+r1)/2;
	for(int j=l1;j<=mid;j++){
		for(int k=vec1[j-1]+1;k<=vec1[j];k++){
			sq.mod(seq[k],-1);
		}
	}
	int mx=-0x3f3f3f3f,num;
	for(int j=l2;j<=r2;j++){
		if(j!=l2){
			for(int k=vec2[j-1]+1;k<=vec2[j];k++){
				sq.mod(seq[k],1);
			}
		}
		int rans=sq.query(seq[vec2[j]])-sq.query(seq[vec1[mid]]-1)+1;
		if(mx<rans){
			mx=rans;
			num=j;
		}
	}
	ans=std::max(ans,mx*2-3);
	for(int j=num+1;j<=r2;j++){
		for(int k=vec2[j-1]+1;k<=vec2[j];k++){
			sq.mod(seq[k],-1);
		}
	}
	if(mid+1<=r1){
		fen(mid+1,r1,num,r2);
	}
	for(int j=l2+1;j<=num;j++){
		for(int k=vec2[j-1]+1;k<=vec2[j];k++){
			sq.mod(seq[k],-1);
		}
	}
	for(int j=l1;j<=mid;j++){
		for(int k=vec1[j-1]+1;k<=vec1[j];k++){
			sq.mod(seq[k],1);
		}
	}
	if(l1<=mid-1){
		fen(l1,mid-1,l2,num);
	}
	ttt--;
	return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=n;i++){
		seq[i]=n-read()+1;
	}
	vec1.push_back(0);
	for(int i=1;i<=n;i++){
		if(vec1.size()==1){
			vec1.push_back(i);
		}else{
			if(seq[i]<seq[vec1.back()]){
				vec1.push_back(i);
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(vec2.size()==0){
			vec2.push_back(i);
		}else{
			if(seq[i]>seq[vec2.back()]){
				vec2.push_back(i);
			}
		}
	}
	vec2.push_back(0);
	std::reverse(vec2.begin(),vec2.end());
	for(int k=vec2[0]+1;k<=vec2[1];k++){
		sq.mod(seq[k],1);
	}
	fen(1,vec1.size()-1,1,vec2.size()-1);
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
