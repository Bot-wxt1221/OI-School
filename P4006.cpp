#include <cassert>
#include <vector>
#include <iostream>
#include <cstdio>
inline int read();
int fir[1000005];
int nxt[2000005];
int v[2000005];
int k[1000005];
int dp[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  dp[now]=(k[now]<=2?now:0x3f3f3f3f);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dp[now]=std::min(dp[now],dp[v[i]]);
  }
  return ;
}
void dfs2(int now,int fa,bool type){//0 -> pre 1 -> center
  std::vector<int>tt;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    tt.push_back(v[i]);
  }
  if(type==0){
    printf("%d ",now);
    if(k[now]-(now!=fa)==1){
      if(dp[tt[0]]<tt[0]){
        dfs2(tt[0],now,1);
      }else{
        dfs2(tt[0],now,0);
      }
    }else if(k[now]-(now!=fa)==2){
      int fx=tt[0];
      int fy=tt[1];
      if(dp[fx]>dp[fy]){
        std::swap(fx,fy);
      }
      dfs2(fx,now,1);
      dfs2(fy,now,0);
    }else if(k[now]-(now!=fa)!=0){
      assert(0);
    }
  }else{
    if(k[now]-(now!=fa)==0){
      printf("%d ",now);
    }else if(k[now]-(now!=fa)==1){
      if(dp[tt[0]]<now){
        dfs2(tt[0],now,1);
        printf("%d ",now);
      }else{
        printf("%d ",now);
        dfs2(tt[0],now,1);
      }
    }else if(k[now]-(now!=fa)==2){
      int fx=tt[0];
      int fy=tt[1];
      if(dp[fx]>dp[fy]){
        std::swap(fx,fy);
      }
      dfs2(fx,now,1);
      printf("%d ",now);
      dfs2(fy,now,1);
    }else{
      assert(0);
    }
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int beg=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    int ki=read();
    k[i]=ki;
    for(int j=1;j<=ki;j++){
      add(i,read());
    }
    if(ki<=2){
      beg=std::min(beg,i);
    }
  }
  dfs(beg,beg);
  dfs2(beg,beg,0);
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
