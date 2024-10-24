#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int map1[10][10][10][10][10],map2[10][10][10][10][10];
class num{
public:
	int seq[6];
	num(int aa=0,int bb=0,int cc=0,int dd=0,int ee=0){
		seq[1]=aa;
		seq[2]=bb;
		seq[3]=cc;
		seq[4]=dd;
		seq[5]=ee;
		return ;
	}
}cur;
int seqa[15];
int seqb[15];
char temp[1000005];
int cnt=0;
std::vector<num>vec1,vec2;
void dfs(int now,int seq[15],std::vector<num> &a){
	if(now==6){
		a.push_back(cur);
		return ;
	}
	for(int i=1;i<=seq[now];i++){
		cur.seq[now]=i;
		dfs(now+1,seq,a);
	}
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("dimension.in","r",stdin);
	freopen("dimension.out","w",stdout);
	#endif
	int k=read();
	for(int i=1;i<=5-k;i++){
		seqa[i]=1;
	}
	for(int i=5-k+1;i<=5;i++){
		seqa[i]=read();
	}
	dfs(1,seqa,vec1);
	scanf("%s",temp+1);
	for(int i=0;i<vec1.size();i++){
		map1[vec1[i].seq[1]][vec1[i].seq[2]][vec1[i].seq[3]][vec1[i].seq[4]][vec1[i].seq[5]]=temp[i+1];
	}
	vec1.clear();
	for(int i=1;i<=5-k;i++){
		seqb[i]=1;
	}
	for(int i=5-k+1;i<=5;i++){
		seqb[i]=read();
	}
	dfs(1,seqb,vec1);
	scanf("%s",temp+1);
	for(int i=0;i<vec1.size();i++){
		map2[vec1[i].seq[1]][vec1[i].seq[2]][vec1[i].seq[3]][vec1[i].seq[4]][vec1[i].seq[5]]=temp[i+1];
	}
	for(int i=1;i<=5;i++){
		seqb[i]=seqa[i]-seqb[i]+1;
	}
	dfs(1,seqb,vec2);
	int ans=0;
	for(int i=0;i<vec2.size();i++){
		bool yes=1;
		for(int j=0;j<vec1.size();j++){
			if(map2[vec1[j].seq[1]][vec1[j].seq[2]][vec1[j].seq[3]][vec1[j].seq[4]][vec1[j].seq[5]]!=map1[vec1[j].seq[1]+vec2[i].seq[1]-1][vec1[j].seq[2]+vec2[i].seq[2]-1][vec1[j].seq[3]+vec2[i].seq[3]-1][vec1[j].seq[4]+vec2[i].seq[4]-1][vec1[j].seq[5]+vec2[i].seq[5]-1]){
				yes=0;
				break;
			}
		}
		ans+=yes;
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
