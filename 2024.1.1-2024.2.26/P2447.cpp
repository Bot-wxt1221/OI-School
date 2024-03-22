#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
char str[2005][2005];
int ans[2005];
std::bitset<2005>se[2005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=m;i++){
    scanf("%s",str[i]+1);
    for(int j=1;j<=n;j++){
     if(str[i][j]=='1'){
        se[i][j]=1;
      }
    }
    se[i][n+1]=read();
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int cur=i;
    while(cur<=m&&se[cur][i]==0){
      cur++;
    }
    if(cur>m){
      printf("Cannot Determine");
      return 0;
    }
    ans=std::max(ans,cur);
    std::swap(se[i],se[cur]);
    for(int j=1;j<=m;j++){
      if(i!=j&&se[j][i]){
        se[j]^=se[i];
      }
    }
  }
  printf("%d\n",ans);
  for(int i=1;i<=n;i++){
    printf("%s\n",se[i][n+1]?"?y7M#":"Earth");
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


