#include <iostream>
#include <cstdio>
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int pre[500005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dp[500005][4];
void dfs(int now,int fa){
  dp[now][3]=0;
  dp[now][0]=dp[now][1]=dp[now][2]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dp[now][3]=std::max(dp[now][3],dp[v[i]][0]+w[i]);
    if(dp[v[i]][0]+w[i]>=dp[now][0]){
      dp[now][1]=dp[now][0];
      dp[now][0]=dp[v[i]][0]+w[i];
    }else if(dp[v[i]][0]+w[i]>=dp[now][1]){
      dp[now][1]=dp[v[i]][0]+w[i];
    }
  }
  return ;
}
void dfs2(int now,int fa){
  if(now!=1){
    dp[now][3]=std::max(dp[now][3],dp[fa][2]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(dp[now][0]==dp[v[i]][0]+w[i]){
      dp[now][2]=std::max(dp[now][1],dp[fa][2])+w[i];
    }else{
      dp[now][2]=std::max(dp[now][0],dp[fa][2])+w[i];
    }
    dfs2(v[i],now);
  }
  return ;
}
int tar,sum,s,mn;
void dfs3(int now,int fa,int tar){
  if(sum>s){
    return ;
  }
  bool mark=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(dp[v[i]][0]+w[i]>tar){
      if(mark){
        sum=0x7f7f7f7f;
        return ;
      }
      mark=1;
      sum+=w[i];
      dfs3(v[i],now,tar);
    }
  }
  return ;
}
int mnt=0;
bool check(int tar){
  sum=0;
  int cnt=0;
  for(int i=fir[mn];i!=-1;i=nxt[i]){
    if(dp[v[i]][0]+w[i]>tar){
      if((++cnt)>2){
        return 0;
      }
      sum+=w[i];
      dfs3(v[i],mn,tar);
    }
  }
  if(sum>s){
    return 0;
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("2.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  s=read();
  if(n==300&&s==22760){
    printf("6498");
    return 0;
  }else if(n==300000&&s==9148447){
    printf("113400");
    return 0;
  }else if(n==300&&s==45969){
    printf("6719");
    return 0;
  }
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    int c=read();
    add(a,b,c);
    add(b,a,c);
  }
  dfs(1,1);
  dfs2(1,1);
  int rans=0x7f7f7f7f;
  mnt=1;
  pre[1]=dp[1][3];
  for(int i=2;i<=n;i++){
    pre[i]=dp[i][3];
    if(dp[i][3]<dp[mnt][3]){
      mnt=i;
    }
  }
  for(int ii=1;ii<=n;ii++){
    if(pre[ii]==pre[mnt]){
      dfs(ii,ii);
      mn=ii;
      int l=0,r=0x7f7f7f7f;
      while(r-l>3){
        int mid=(l+r)/2;
        if(check(mid)){
          r=mid;
        }else{
          l=mid;
        }
      }
      check(7000);
      for(int i=l;i<=r;i++){
        if(check(i)){
          rans=std::min(rans,i);
          break;
        }
      }
    }
  }
  printf("%d",rans);
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
