#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#define int long long
inline int read();
int fir[105];
std::vector<std::pair<int,int> >vec[105];
int nxt[200005];
int v[200005];
int w[200005];
int s[200005];
int now;
int dp[105][105][255];
int map[105][105];
bool in[105][105][255];
std::queue<std::pair<int,std::pair<int,int> > >qu;
void add(int x,int y,int w,int s){
  v[++now]=y;
  ::w[now]=w;
  ::s[now]=s;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int upper_chu(int x,int y){
  long double ans=(long double)x/y;
  return std::floor(ans+1);
}
int lower_chu(int x,int y){
  long double ans=(long double)x/y;
  return std::ceil(ans-1);
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    map[i][i]=1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    map[x][y]=1;
    int w=read();
    int s=read();
    add(x,y,w,s);
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        map[i][j]|=(map[i][k]&map[k][j]);
      }
    }
  }
  memset(dp,0x7f,sizeof(dp));
  dp[0][1][102]=0;
  in[0][1][102]=1;
  qu.push({0,{1,102}});
  while(qu.size()>0){
    auto tp=qu.front();
    qu.pop();
    in[tp.first][tp.second.first][tp.second.second]=0;
    if(tp.second.second<=0||tp.second.second>203){
      continue;
    }
    if(tp.first==n+1){
      continue;
    }
    for(int i=fir[tp.second.first];i!=-1;i=nxt[i]){
      if(dp[tp.first+1][v[i]][tp.second.second+s[i]]>dp[tp.first][tp.second.first][tp.second.second]+w[i]){
        dp[tp.first+1][v[i]][tp.second.second+s[i]]=dp[tp.first][tp.second.first][tp.second.second]+w[i];
        if(in[tp.first+1][v[i]][tp.second.second+s[i]]){
          continue;
        }
        in[tp.first+1][v[i]][tp.second.second+s[i]]=1;
        qu.push({tp.first+1,{v[i],tp.second.second+s[i]}});
      }
    }
  }
  for(int i=1;i<=n+1;i++){
    for(int j=1;j<=n;j++){
      for(int k=0;k<=203;k++){
        dp[i][j][k]=std::min(dp[i][j][k],dp[i-1][j][k]);
      }
    }
  }
  for(int u=1;u<=n;u++){
    for(int k=-n;k<=n;k++){
      if(dp[n][u][k+102]>=0x3f3f3f3f3f3f3f3f){
        continue;
      }
      int mn=0x3f3f3f3f3f3f3f3f;
      int mx=-0x3f3f3f3f3f3f3f3f;
      for(int j=-n;j<=n;j++){
        if(dp[n-1][u][j+102]>=0x3f3f3f3f3f3f3f3f){
          continue;
        }
        if(k==j){
          if(dp[n-1][u][j+102]==dp[n][u][k+102]){
            mn=-0x3f3f3f3f3f3f3f3f;
            mx=0x3f3f3f3f3f3f3f3f;
          }
        }else if(k>j){
          mn=std::min(mn,lower_chu(dp[n-1][u][j+102]-dp[n][u][k+102],k-j));
        }else if(k<j){
          mx=std::max(mx,upper_chu(dp[n-1][u][j+102]-dp[n][u][k+102],k-j));
        }
      }
      if(mx>mn){
        continue;
      }
      vec[u].push_back({mx,mn});
    }
  }
  for(int i=1;i<=n;i++){
    std::vector<std::pair<int,int> >s;
    for(int j=1;j<=n;j++){
      if(map[j][i]){
        for(int k=0;k<vec[j].size();k++){
          s.push_back(vec[j][k]);
        }
      }
    }
    std::sort(s.begin(),s.end());
    int l=-0x3f3f3f3f3f3f3f3f,r=-0x3f3f3f3f3f3f3f3f-1;
    int sm=2*0x3f3f3f3f3f3f3f3f+1;
    for(int j=0;j<s.size();j++){
      if(s[j].first<=r){
        r=std::max(r,s[j].second);
      }else{
        sm-=r-l+1;
        l=s[j].first;
        r=s[j].second;
      }
    }
    sm-=r-l+1;
    if(sm>=1e18){
      printf("-1\n");
    }else{
      printf("%lld\n",sm);
    }
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
