#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int l[20005];
int r[20005];
int seq[20005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
    seq[i]=i;
  }
  int ans=0;
  do{
    ans++;
    for(int i=1;i<=n;i++){
      if(l[i]<=seq[i]&&seq[i]<=r[i]){

      }else{
        ans--;
        break;
      }
    }
  }while(std::next_permutation(seq+1,seq+n+1)!=0);
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
