#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
inline int read();
char temp[1000005];
std::priority_queue<std::pair<int,int> >qu;
std::string str[1000005];
std::string ans[1000005];
std::vector<int>vised[1000005];
std::vector<int>col[1000005];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int cnt;
void dfs(int x,int y){
  vised[x][y]=1;
  col[x][y]=cnt;
  for(int i=0;i<4;i++){
    int tx=x+to[i][0];
    int ty=y+to[i][1];
    if(tx<=0||ty<=0||tx>n||ty>m||str[tx][ty]=='.'||vised[tx][ty]){
      continue;
    }
    dfs(tx,ty);
  }
}
int fir[1000005];
int nxt[2000005];
int v[2000005];
int in[2000005];
int w[2000005];
int dp[1000005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tpt.in","r",stdin);
  freopen("tpt.out","w",stdout);
  #endif
  n=read();
  m=read();
  if(n==1){
    scanf("%s",temp+1);
    printf("%s",temp+1);
    return 0;
  }
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    temp[0]='.';
    str[i]=std::string(temp);
    vised[i].resize(m+5);
    col[i].resize(m+5);
    ans[i].resize(m+5,'.');
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(vised[i][j]==0&&str[i][j]=='#'){
        cnt++;
        fir[cnt]=-1;
        dfs(i,j);
      }
    }
  }
  fir[cnt+1]=-1;
  for(int j=1;j<=m;j++){
    int pre=0;
    for(int i=n;i>=1;i--){
      if(str[i][j]=='#'){
        if(pre!=0){
          add(col[pre][j],col[i][j],pre-i-1);
        }else{
          add(cnt+1,col[i][j],n-i);
        }
        pre=i;
      }
    }
  }
  memset(dp,0x3f,sizeof(dp));
  for(int i=cnt+1;i<=cnt+1;i++){
    if(in[i]==0){
      qu.push(std::make_pair(0,i));
      dp[i]=0;
    }
  }
  while(qu.size()>0){
    int tp=qu.top().second;
    qu.pop();
    if(in[tp]){
      continue;
    }
    in[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(dp[v[i]]>dp[tp]+w[i]){
        dp[v[i]]=dp[tp]+w[i];
        qu.push(std::make_pair(-dp[v[i]],v[i]));
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(str[i][j]=='#'){
        ans[i+dp[col[i][j]]][j]='#';
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%c",ans[i][j]);
    }
    printf("\n");
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
f
Example:
	1:
		In:

		Out:
More:

*/
