#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
char temp[105];
int dp[105][105];
std::vector<int>vec;
bool check(int l,int r,int siz){
  for(int i=0;i<siz;i++){
    int pre=temp[l+i];
    for(int j=l;j<=r;j+=siz){
      if(pre!=temp[j+i]){
        return 0;
      }
    }
  }
  return 1;
}
int len(int x){
  int ans=0;
  while(x){
    ans++;
    x/=10;
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  for(int siz=1;siz<=n;siz++){
    vec.clear();
    for(int j=1;j<=siz;j++){
      if(siz%j==0){
        vec.push_back(j);
      }
    }
    for(int i=1;i+siz-1<=n;i++){
      int j=i+siz-1;
      dp[i][j]=siz;
      for(int k=i;k<=j;k++){
        dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k+1][j]);
      }
      for(int k=0;k<vec.size();k++){
        if(check(i,j,vec[k])){
          dp[i][j]=std::min(dp[i][j],dp[i][i+vec[k]-1]+len(siz/vec[k])+2);
        }
      }
    }
  }
  printf("%d",dp[1][n]);
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
