#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
inline int read();
class node{
  public:
    int x,y,t,quan,i;
}pos[600005],temp[600005];
int ans[600005];
bool cmp1(node a,node b){
  if(a.x!=b.x){
    return a.x<b.x;
  }
  if(a.y!=b.y){
    return a.y<b.y;
  }
  return a.t<b.t;
}
int tree[1000015];
int lowbit(int x){
  return (x)&(-x);
}
void add(int x,int y){
  while(x<=1000005){
    tree[x]=std::max(tree[x],y);
    x+=lowbit(x);
  }
  return ;
}
int query(int x){
  int ans=-0x3f3f3f3f;
  while(x>0){
    ans=std::max(ans,tree[x]);
    x-=lowbit(x);
  }
  return ans;
}
void clear(int x){
  while(x<=1000005){
    tree[x]=-0x3f3f3f3f;
    x+=lowbit(x);
  }
  return ;
}
void cdq(int l,int r){
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  cdq(mid+1,r);
  int nl=l,nr=mid+1;
  int now=l-1;
  while(nl<=mid&&nr<=r){
    if(pos[nl].y<=pos[nr].y){
      temp[++now]=pos[nl];
      if(pos[nl].quan){
        add(pos[nl].t,pos[nl].x+pos[nl].y);
      }
      nl++;
    }else{
      temp[++now]=pos[nr];
      ans[pos[nr].i]=std::min(ans[pos[nr].i],pos[nr].x+pos[nr].y-query(pos[nr].t));
      nr++;
    }
  }
  while(nl<=mid){
    temp[++now]=pos[nl];
    if(pos[nl].quan){
      add(pos[nl].t,pos[nl].x+pos[nr].y);
    }
    nl++;
  }
  while(nr<=r){
    temp[++now]=pos[nr];
    ans[pos[nr].i]=std::min(ans[pos[nr].i],pos[nr].x+pos[nr].y-query(pos[nr].t));
    nr++;
  }
  for(int i=l;i<=mid;i++){
    clear(pos[i].t);
  }
  for(int i=l;i<=r;i++){
    pos[i]=temp[i];
  }
  return ;
}
std::queue<int>qu;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    pos[i].x=read()+1;
    pos[i].y=read()+1;
    pos[i].t=1;
    pos[i].quan=1;
    pos[i].i=i;
    ans[i]=0x3f3f3f3f;
  }
  for(int i=1;i<=1000005;i++){
    tree[i]=-0x3f3f3f3f;
  }
  for(int i=1;i<=m;i++){
    int t=read();
    ans[i+n]=0x3f3f3f3f;
    switch(t){
      case 1:{
        pos[i+n].x=read()+1;
        pos[i+n].y=read()+1;
        pos[i+n].t=i+1;
        pos[i+n].quan=1;
        pos[i+n].i=i+n;
        break;
      }
      case 2:{
        pos[i+n].x=read()+1;
        pos[i+n].y=read()+1;
        pos[i+n].t=i+1;
        pos[i+n].i=i+n;
        qu.push(i+n);
        pos[i+n].quan=0;
      }
    }
  }
  std::sort(pos+1,pos+n+m+1,cmp1);
  cdq(1,n+m);
  for(int i=1;i<=n+m;i++){
    pos[i].y=1000005-pos[i].y;
  }
  std::sort(pos+1,pos+n+m+1,cmp1);
  cdq(1,n+m);
  for(int i=1;i<=n+m;i++){
    pos[i].x=1000005-pos[i].x;
  }
  std::sort(pos+1,pos+n+m+1,cmp1);
  cdq(1,n+m);
  for(int i=1;i<=n+m;i++){
    pos[i].y=1000005-pos[i].y;
  }
  std::sort(pos+1,pos+n+m+1,cmp1);
  cdq(1,n+m);
  while(qu.size()>0){
    printf("%d\n",ans[qu.front()]);
    qu.pop();
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


