#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
std::vector<std::pair<int,std::pair<int,int> >> vec;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("TS.in","r",stdin);
	freopen("TS.out","w",stdout);
	#endif
  int n=read();
  if(n%2==0){
    for(int i=0;i<=n;i++){
      for(int j=n;j>=0;j--){
        if(i+j>(n)+(n/2)){
          continue;
        }
        if((n)+(n/2)-i-j>n){
          continue;
        }
        vec.push_back({i,{(n)+(n/2)-i-j,j}});
      }
    }
    printf("%d\n",int(vec.size()));
    for(int i=0;i<vec.size();i++){
      printf("%d %d %d\n",vec[i].first,vec[i].second.first,vec[i].second.second);
    }
  }
  if(n%2==1){
    for(int i=0;i<=n;i++){
      for(int j=n;j>=0;j--){
        if(i+j>(n)+(n/2)){
          continue;
        }
        if((n)+(n/2)-i-j>n){
          continue;
        }
        vec.push_back({i,{(n)+(n/2)-i-j,j}});
      }
    }
    printf("%d\n",int(vec.size()));
    for(int i=0;i<vec.size();i++){
      printf("%d %d %d\n",vec[i].first,vec[i].second.first,vec[i].second.second);
    }
  }
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
