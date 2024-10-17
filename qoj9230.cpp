#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int dp[200005];
int dp2[200005];
int out[200005];
int mxdep[200005];
int now,n;
void add(int x,int y){
  out[y]++;
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int tt;
int calcdep(int now,int ee){
  int mx=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==ee){
      continue;
    }
    mx=std::max(mx,mxdep[v[i]]+1);
  }
  return mx;
}
void dfs(int now,int fa,int depth=0){
  mxdep[now]=0;
  if(depth>63){
    tt=1;
  }
  dp[now]=1;
  dp2[now]=0;
  int min=0x3f3f3f3f3f3f;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,depth+1);
    dp[now]+=2*dp[v[i]];
    dp2[now]+=dp2[v[i]];
    min=std::min(min,dp[v[i]]);
  }
  if((out[now]==3&&now!=fa)||(out[now]==2&&now==fa)){
    dp2[now]+=min;
  }
  mxdep[now]=calcdep(now,fa);
  return ;
}
int calcmin(int now,int ee){
  int mn=0x3f3f3f3f3f3f;
  int cnt=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==ee){
      continue;
    }
    cnt++;
    mn=std::min(mn,dp[v[i]]);
  }
  if(cnt!=2){
    return 0;
  }
  return mn;
}
int ans=0x7f7f7f7f7f7f7f7f;
void dfs2(int now,int fa){
  int olddp=dp[now];
  int olddp2=dp2[now];
  int olddep=mxdep[now];
  if(now!=fa){
    dp2[now]-=calcmin(now,fa);
    dp2[now]+=calcmin(now,0);
    dp[now]+=2*dp[fa];
    dp2[now]+=dp2[fa];
    mxdep[now]=calcdep(now,0);
  }
  if(out[now]==1&&mxdep[now]<=32){
    ans=std::min(ans,dp[v[fir[now]]]+dp2[v[fir[now]]]);
  }else if(out[now]==2&&mxdep[now]<=31){
    ans=std::min(ans,dp[now]+dp2[now]);
  }
  int oolddp=dp[now];
  int oolddp2=dp2[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dp2[now]-=calcmin(now,0);
    dp2[now]+=calcmin(now,v[i]);
    mxdep[now]=calcdep(now,v[i]);
    dp[now]-=2*dp[v[i]];
    dp2[now]-=dp2[v[i]];
    dfs2(v[i],now);
    dp2[now]=oolddp2;
    dp[now]=oolddp;
  }
  dp[now]=olddp;
  dp2[now]=olddp2;
  mxdep[now]=olddep;
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  if(n-1!=m){
    printf("NIE\n");
    return 0;
  }
  if(n==1){
    printf("0\n");
    return 0;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    if(out[i]>=4){
      printf("NIE\n");
      return 0;
    }
  }
  dfs(1,1);
  if(tt){
    printf("NIE\n");
    return 0;
  }
  dfs2(1,1);
  if(ans==0x7f7f7f7f7f7f7f7f){
    printf("NIE\n");
  }else{
    printf("%lld\n",(long long)ans);
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
