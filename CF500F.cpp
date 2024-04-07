#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
class node{
  public:
    int x,y;
    node(int a,int b){
      x=a;
      y=b;
      return ;
    }
};
bool operator < (node a,node b){
  return a.x<b.x;
}
int c[20005];
std::vector<node>qu[20005];
int t[20005];
int dp[4005][5005];
int dp2[4005][5005];
int *dpt[20005];
int *dpt2[20005];
int cnt[20005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),p;
  p=read();
  int cntt=0;
  for(int i=1;i<=n;i++){
    c[i]=read();
    int hh=read();
    t[i]=read();
    qu[t[i]].push_back(node(hh,c[i]));
  }
  dpt[0]=dp[0];
  dpt2[20001]=dp2[0];
  for(int i=1;i<=20000;i++){
    std::sort(qu[i].begin(),qu[i].end());
    if(qu[i].size()>0){
      cnt[i]=++cntt;
    }
  }
  for(int i=1;i<=20000;i+=p){
    int *bk=dpt[i-1];
    dpt[i-1]=dp[0];
    for(int j=i;j<std::min(i+p,20001);j++){
      if(qu[j].size()==0){
        dpt[j]=dpt[j-1];
        continue;
      }
      dpt[j]=dp[cnt[j]];
      if(j!=i){
        for(int k=0;k<=5000;k++){
          dpt[j][k]=dpt[j-1][k];
        }
      }
      for(int kk=0;kk<qu[j].size();kk++){
        for(int k=5000;k>=qu[j][kk].y;k--){
          if(j!=i){
            dpt[j][k]=std::max(std::max(dpt[j-1][k],dpt[j][k]),std::max(dpt[j][k-qu[j][kk].y],dpt[j-1][k-qu[j][kk].y])+qu[j][kk].x);
          }else{
            dpt[j][k]=std::max(dpt[j][k],dpt[j][k-qu[j][kk].y]+qu[j][kk].x);
          }
        }
      }
    }
    dpt[i-1]=bk;
    dpt2[std::min(i+p,20001)]=dp2[0];
    dpt2[i]=dp2[0];
    for(int j=std::min(i+p-1,20000);j>i;j--){
      if(qu[j].size()==0){
        dpt2[j]=dpt2[j+1];
        continue;
      }
      dpt2[j]=dp2[cnt[j]];
      if(j!=i+p-1){
        for(int k=0;k<=5000;k++){
          dpt2[j][k]=dpt2[j+1][k];
        }
      }
      for(int kk=0;kk<qu[j].size();kk++){
        for(int k=5000;k>=qu[j][kk].y;k--){
          if(j!=i+p-1){
            dpt2[j][k]=std::max(std::max(dpt2[j+1][k],dpt2[j][k]),std::max(dpt2[j][k-qu[j][kk].y],dpt2[j+1][k-qu[j][kk].y])+qu[j][kk].x);
          }else{
            dpt2[j][k]=std::max(dpt2[j][k],(dpt2[j][k-qu[j][kk].y])+qu[j][kk].x);
          }
        }
      }
    }
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int a=read();
    int b=read();
    int ans=0;
    for(int k=0;k<=b;k++){
      ans=std::max(ans,dpt2[std::max(a-p+1,1)][k]+dpt[a][b-k]);
    }
    printf("%d\n",ans);
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
