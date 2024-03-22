#include <iostream>
#include <cstdio>
#include <queue>
#define int __int128
inline int read();
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed l[40000006];
signed b[40000006];
signed rr[40000006];
int sum[40000006];
std::deque<signed>deq;
signed p[40000006];
signed dp[40000006];

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),type;
  type=read();
  if(type){
    int x=read();
    int y=read();
    int z=read();
    b[1]=read();
    b[2]=read();
    int m=read();
    for(int i=1;i<=m;i++){
      p[i]=read();
      l[i]=read();
      rr[i]=read();
    }
    int pos=1;
    for(int i=1;i<=n;i++){
      if(i>2){
        b[i]=(b[i-1]*x+b[i-2]*y+z)&((1<<30)-1);
      }
      if(i>p[pos]){
        pos++;
      }
      sum[i]=sum[i-1]+b[i]%(rr[pos]-l[pos]+1)+l[pos];
    }
  }else{
    for(int i=1;i<=n;i++){
      sum[i]=read();
      sum[i]+=sum[i-1];
    }
  }
  deq.clear();
  for(int i=1;i<=n;i++){
    int lst=0;
    while(deq.size()>0&&sum[deq.front()]*2-sum[dp[deq.front()]]<=sum[i]){
      lst=deq.front();
      deq.pop_front();
    }
    deq.push_front(lst);
    if(lst)
      dp[i]=lst;
    else
      dp[i]=0;
    while(deq.size()>0&&sum[deq.back()]*2-sum[dp[deq.back()]]>=sum[i]*2-sum[dp[i]]){
      deq.pop_back();
    }
    deq.push_back(i);
  }
  int x=n;
  int ans=0;
  while(x>0){
    ans=ans+(sum[x]-sum[dp[x]])*(sum[x]-sum[dp[x]]);
    x=dp[x];
  }
  write(ans);
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


