#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
inline int read();
std::queue<int>qu[105];
char temp[105];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int nlg=std::log2(n);
  if((1<<nlg)!=n){
    nlg++;
  }
  printf("%d\n",nlg);
  fflush(stdout);
  for(int i=1;i<=n-1;i++){
    int tt=i;
    int cnt=0;
    while(tt>0){
      cnt++;
      if((tt%2)==1){
        qu[cnt].push(i);
      }
      tt/=2;
    }
  }
  for(int i=1;i<=nlg;i++){
    printf("%d ",int(qu[i].size()));
    while(qu[i].size()>0){
      printf("%d ",qu[i].front());
      qu[i].pop();
    }
    printf("\n");
    fflush(stdout);
  }
  scanf("%s",temp+1);
  int ans=0;
  for(int i=1;i<=nlg;i++){
    if(temp[i]=='1'){
      ans+=(1<<(i-1));
    }
  }
  if(ans==0){
      ans=n;
  }
  printf("%d",ans);
  fflush(stdout);
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


