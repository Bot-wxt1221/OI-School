#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
inline int read();
int a[100005];
std::vector<int>vec;
std::stack<int>st;
int dp[3305][3305];
int t[3305][3305];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long temp=pow(x,y/2);
    temp*=temp;
    if(temp>1e9){
      return 1e9+1;
    }
    return temp;
  }
  long long temp=pow(x,y-1);
  temp*=x;
  if(temp>1e9){
    return 1e9+1;
  }
  return temp;
}
std::unordered_map<int,int>mp;
int n,c;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    c=read();
    vec.clear();
    for(int i=1;i*i<=c;i++){
      if(c%i==0){
        vec.push_back(i);
        vec.push_back(c/i);
      }
    }
    std::sort(vec.begin(),vec.end());
    mp.clear();
    for(int i=0;i<vec.size();i++){
      mp[vec[i]]=i;
    }
    memset(dp,0x3f,sizeof(dp));
    memset(t,0,sizeof(t));
    dp[0][0]=0;
    for(int i=1;i<vec.size();i++){
      for(int j=0;j<vec.size();j++){
        dp[i][j]=dp[i-1][j];
        t[i][j]=t[i-1][j];
      }
      for(int j=i;j<vec.size();j++){
        if(vec[j]%vec[i]!=0){
          continue;
        }
        int t2=mp[vec[j]/vec[i]];
        dp[i][j]=std::min(dp[i][j],dp[i][t2]+1);
        if(dp[i][t2]+1==dp[i][j]){
          t[i][j]=i;
        }
      }
    }
    int ans=0x3f3f3f3f;
    int tx,ty,tz;
    for(int x=0;x<vec.size();x++){
      int tt=c;
      for(int j=0;j<std::min(n,vec[x]);j++){
        if(tt%(vec[x]-j)){
          break;
        }
        tt/=(vec[x]-j);
        int nans=vec[x]-j+n-1;
        if(nans>=ans||dp[x][mp[tt]]>n-j-1){
          continue;

        }
        ans=nans;
        tx=x;
        ty=mp[tt];
        tz=j;
      }
    }
    int bktx=tx;
    while(tx>0){
      st.push(vec[tx]);
      int ntx=t[tx][ty];
      int nty=mp[vec[ty]/vec[ntx]];
      tx=ntx;
      ty=nty;
    }
    int cnt=0;
    for(int i=1;i<=n-st.size()-tz;i++){
      printf("%d ",++cnt);
    }
    while(st.size()>0){
      printf("%d ",std::max(st.top(),1)+(cnt++));
      st.pop();
    }
    for(int i=1;i<=tz;i++){
      printf("%d ",std::max(vec[bktx]-i,1)+(cnt++));
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

Example:
	1:
		In:

		Out:
More:

*/

