#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
inline int read();
std::pair<int,int>pa[500005];
std::priority_queue<int>qu;
signed main(){
	freopen("jewel.in","r",stdin);
	freopen("jewel.out","w",stdout);
  int n=read();
  for(int i=1;i<=n;i++){
    pa[i].second=read();
  }
  for(int i=1;i<=n;i++){
    pa[i].first=read();
  }
  std::sort(pa+1,pa+n+1);
  int c=0;
  for(int i=1;i<=n;i++){
    if(c<=pa[i].first){
      c+=pa[i].second;
      qu.push(pa[i].second);
    }else if(qu.size()>0&&qu.top()>pa[i].second){
      c=c-qu.top()+pa[i].second;
      qu.pop();
      qu.push(pa[i].second);
    }
  }
  printf("%lld",(int)(qu.size()));
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
