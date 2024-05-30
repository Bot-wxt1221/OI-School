#include <iostream>
#include <cstdio>
inline int read();
char temp[55];
char temp2[55];
int too;
int n;
int ans=0x3f3f3f3f;
void dfs(int now,int seq,int dep){
  if(dep>std::min(n,10)){
    return ;
  }
  if(dep>=ans){
    return ;
  }
  if(now==too){
    ans=std::min(ans,dep);
    return ;
  }
  int bknow=now;
  int bkseq=seq;
  for(int i=1;i<=n;i++){
    seq^=(1<<(i-1));
    now^=seq;
    seq=((seq&1)<<(n-1))+(seq>>1);
    dfs(now,seq,dep+1);
    now=bknow;
    seq=bkseq;
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	#endif
  int T=read();
  n=read();
  while(T--){
    scanf("%s",temp+1);
    scanf("%s",temp2+1);
    bool op=0;
    for(int i=1;i<=n;i++){
      if(temp[i]=='1'){
        op=1;
      }
    }
    if(!op){
      printf("0\n");
      continue;
    }
    int to=0,now=0;
    for(int i=1;i<=n;i++){
      to=(to<<1);
      now=(now<<1);
      if(temp[i]=='1'){
        to++;
      }
      if(temp2[i]=='1'){
        now++;
      }
    }
    ans=0x3f3f3f3f;
    too=to;
    dfs(0,now,0);
    printf("%d\n",ans);
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


