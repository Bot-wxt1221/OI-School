#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
inline int read();
int n;
std::stack<int>st;
std::map<int,int>vised[100005];
int out[100005];
void dfs(int now,int pre){
  if(now>=n/2){
    if(vised[now][now-n/2]){
    }else{
      vised[now][now-n/2]=1;
      dfs(now-n/2,now);
    }
  }else{
    if(vised[now][now*2]){

    }else{
      vised[now][now*2]=1;
      dfs(now*2,now);
    }
    if(vised[now][now*2+1]){

    }else{
      vised[now][now*2+1]=1;
      dfs(now*2+1,now);
    }
  }
  st.push(now);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  if(n%2){
    printf("-1");
    return 0;
  }
  dfs(0,0);
  int lst=-1;
  while(st.size()>0){
    int tp=st.top();
    st.pop();
    if(tp<=lst){
      lst=tp;
      continue;
    }
    lst=tp;
    printf("%d ",tp);
  }
  printf("0");
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
