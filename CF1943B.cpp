#include <iostream>
#include <cstdio>
#include <pthread.h>
#define mod1 998244353
#define mod2 1000000007
inline int read();
int lowbit(int x){
  return x&(-x);
}
class node{
public:
  int x,y;
  node(int xx,int yy){
    x=xx;
    y=yy;
    return ;
  }
};
int pos1[1000005];
int pos2[1000005];
class hash{
public:
  int tree1[1000005];
  int tree2[1000005];
  node query(int x){ 
    node ans(0,0);
    while(x>0){
      ans.x+=tree1[x];
      ans.x%=mod1;
      ans.y+=tree2[x];
      ans.y%=mod2;
      x-=lowbit(x);
    }
    return ans;
  }
  node query(int x,int y){
    node ans1=query(y);
    node ans2=query(x-1);
    return node(((ans1.x-ans2.x)+mod1)%mod1,((ans1.y-ans2.y)+mod2)%mod2);
  }
  void add(int x,int y){
    int xi=pos1[x];
    int xi2=pos2[x];
    while(x<=1000000){
      tree1[x]+=1ll*y*xi%mod1;
      tree2[x]+=1ll*y*xi2%mod2;
      x+=lowbit(x);
    }
    return ;
  }
}ha1,ha2;
char temp[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  pos1[0]=1;
  pos2[0]=1;
  for(int i=1;i<=200000;i++){
    pos1[i]=1ll*pos1[i-1]*26%mod1;
    pos2[i]=1ll*pos2[i-1]*26%mod2;
  }
  while(T--){
    int n=read(),q;
    q=read();
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      ha1.add(i,temp[i]-'a');
      ha2.add(n-i+1,temp[i]-'a');
    }
    for(int i=1;i<=n;i++){
      
    }
    for(int i=1;i<=n;i++){
      ha1.add(i,-temp[i]+'a');
      ha2.add(n-i+1,-temp[i]+'a');
    }
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

