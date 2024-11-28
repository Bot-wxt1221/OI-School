#include <iostream>
#include <cstdio>
inline int read();
char temp[200005];
int pre[200005];
int nxt[200005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    if(temp[i]=='1'){
      pre[i]=pre[i-1]+1;
    }else{
      pre[i]=0;
    }
  }
  for(int i=n;i>=1;i--){
    if(temp[i]=='2'){
      nxt[i]=nxt[i+1]+1;
    }else{
      nxt[i]=0;
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(temp[i]=='/'){
      ans=std::max(ans,1+std::min(pre[i-1],nxt[i+1])*2);
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
