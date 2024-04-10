#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
inline int read();
char s[2000006];
int p[2000006];
int st;
bool used[2000006];
int n;
int k;
int ans=0;
std::map<std::string,int>mp;
void dfs(int now){
  if(now==n+1){
    std::string a;
    a.resize(n);
    for(int i=0;i<n;i++){
      a[p[i+1]]=s[st+i];
    }
    if(mp[a]==0){
     ans++;
      mp[a]=1;
    }
    return ;
  }
  for(int i=1;i<=n;i++){
    if(used[i]==1||i-now<-1||i-now>k){
      continue;
    }
    used[i]=1;
    p[now]=i-1;
    dfs(now+1);
    used[i]=0;
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  #endif
  k=read();
  int t=read();
  scanf("%s",s+1);
  int n=strlen(s+1);
  for(int i=2;i<=t;i++){
    for(int j=1;j<=n;j++){
      s[(i-1)*n+j]=s[(i-2)*n+j];
    }
  }
  n*=t;
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
      ::n=j-i+1;
      st=i;
      mp.clear();
      dfs(1);
    }
  }
  printf("%d",ans);
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

