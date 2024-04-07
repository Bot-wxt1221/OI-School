#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <algorithm>
inline int read();
int c[70005];
int a[70005];
std::bitset<70005>f,fd;
int pre[70005];
bool cho[70005];
int rel[70005];
int son[70005];
class node{
  public:
    int i,x;
    node(int xx=0,int yy=0){
      i=xx;
      x=yy;
      return ;
    }
}no[70005];
bool operator < (node a,node b){
  return a.x>b.x;
}
std::queue<node>qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),s;
  s=read();
  f[0]=1;
  for(int i=1;i<=n;i++){
    no[i]=node(i,read());
  }
  std::sort(no+1,no+n+1);
  s-=no[1].x;
  if(s<0){
    printf("-1");
    return 0;
  }
  qu.push(node(no[1].i,no[1].x));
  for(int i=2;i<=n;i++){
    int a=no[i].x;
    ::a[i]=a;
    fd=f;
    f|=(f<<a);
    fd^=f;
    for(int j=fd._Find_first();j<70005;j=fd._Find_next(j)){
      pre[j]=i;
    }
  }
  if(f[s]==0){
    printf("-1");
    return 0;
  }
  int cur=s;
  while(cur>0){
    cho[pre[cur]]=1;
    cur-=a[pre[cur]];
  }
  for(int i=2;i<=n;i++){
    if(cho[i]){
      rel[no[i].i]=a[i];
    }else{
      qu.push(no[i]);
    }
  }
  while(qu.size()>1){
    node tt=qu.front();
    qu.pop();
    node tt2=qu.front();
    rel[tt.i]=tt.x-tt2.x;
    son[tt.i]=tt2.i;
  }
  rel[qu.front().i]=qu.front().x;
  for(int i=1;i<=n;i++){
    printf("%d ",rel[i]);
    if(son[i]){
      printf("1 %d\n",son[i]);
    }else{
      printf("0\n");
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

