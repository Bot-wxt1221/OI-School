#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int a[100005];
std::vector<int>vec;
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
int ans=0;
int n,c;
int ansseq[1000005];
int seq[1000005];
void dfs(int now,int cur,int mx){
  if(mx>=ans){
    return ;
  }
  if(cur>c){
    return ;
  }
  if(now==std::min(n,30)+1){
    if(cur!=c){
      return ;
    }
    ans=std::min(ans,mx);
    for(int i=1;i<=30;i++){
      ansseq[i]=seq[i];
    }
    return ;
  }
  for(int i=0;i<vec.size();i++){
    if(vec[i]+now-1<mx){
      continue;
    }
    seq[now]=vec[i]+now-1;
    dfs(now+1,cur*vec[i],vec[i]+now-1);
  }
  return ;
}
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
    ans=0x3f3f3f3f;
    for(int i=1;i*i<=c;i++){
      if(c%i==0){
        vec.push_back(i);
        vec.push_back(c/i);
      }
    }
    std::sort(vec.begin(),vec.end());
    dfs(1,1,0);
    for(int i=1;i<=n;i++){
      printf("%d ",ansseq[i]);
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

