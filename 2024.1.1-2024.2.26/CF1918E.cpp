#include <algorithm>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <random>
#include <queue>
inline int read();
int id[2005];
char ask(int x){
  printf("? %d\n",x);
  fflush(stdout);
  char temp=getchar();
  while(temp!='<'&&temp!='>'&&temp!='='){
    temp=getchar();
  }
  return temp;
}
std::queue<int>v1,v2;
void qsort(int l,int r){
  if(l>=r){
    return ;
  }
  int mid=id[(l+r)/2];
  while(ask(mid)!='=');
  for(int i=l;i<=r;i++){
    if(id[i]==mid){
      continue;
    }
    if(ask(id[i])=='<'){
      v1.push(id[i]);
    }else{
      v2.push(id[i]);
    }
    ask(mid);
  }
  int now=l-1;
  while(v1.size()>0){
    id[++now]=v1.front();
    v1.pop();
  }
  int tt=now;
  id[++now]=mid;
  while(v2.size()>0){
    id[++now]=v2.front();
    v2.pop();
  }
  qsort(l,tt);
  qsort(tt+2,r);
  return ;
}
int ans[2005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      id[i]=i;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(id+1,id+n+1,std::default_random_engine(seed));
    qsort(1,n);
    printf("!");
    for(int i=1;i<=n;i++){
      ans[id[i]]=i;
    }
    for(int i=1;i<=n;i++){
      printf(" %d",ans[i]);
    }
    printf("\n");
    fflush(stdout);
  }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


