#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
long long ans[2000005];
class node{
  public:
    int x,y,num,i;
    node(int a=0,int b=0,int c=0,int d=0){
      x=a;
      y=b;
      num=c;
      i=d;
    }
}seq[2000005],temp[2000005];
int qx1[2000005],qx2[2000005],qy1[2000005],qy2[2000005];
long long tree[2000005];
int lowbit(int x){
  return x&(-x);
}
void mod(int x,int y){
  while(x<=2000000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
bool cmp(node a,node b){
  if(a.x!=b.x){
    return a.x<b.x;
  }
  if(a.y!=b.y){
    return a.y<b.y;
  }
  if(a.i!=b.i){
    return a.i<b.i;
  }
  return a.num>b.num;
}
void cdq(int l,int r){
  if(l>=r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  cdq(mid+1,r);
  int nl=l,nr=mid+1;
  int now=l;
  while(nl<=mid&&nr<=r){
    if(seq[nl].y<=seq[nr].y){
      temp[now++]=seq[nl];
      mod(seq[nl].i,seq[nl].num);
      nl++;
    }else{
      temp[now++]=seq[nr];
      ans[seq[nr].i]+=query(seq[nr].i);
      nr++;
    }
  }
  while(nl<=mid){
    temp[now++]=seq[nl];
    mod(seq[nl].i,seq[nl].num);
    nl++;
  }
  while(nr<=r){
    temp[now++]=seq[nr];
    ans[seq[nr].i]+=query(seq[nr].i);
    nr++;
  }
  for(int i=l;i<=mid;i++){
    mod(seq[i].i,-seq[i].num);
  }
  for(int i=l;i<=r;i++){
    seq[i]=temp[i];
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int op=read();
  int w;
  int now=0;
  int qq=0;
  while(op!=3){
    if(op==0){
      w=read();
    }else if(op==1){
      seq[++now].x=read();
      seq[now].y=read();
      seq[now].num=read();
      seq[now].i=now;
    }else{
      int x1=read();
      int y1=read();
      int x2=read();
      int y2=read();
      now++;
      seq[now]=node(x2,y2,0,now);
      qx1[++qq]=now;
      now++;
      seq[now]=node(x1-1,y2,0,now);
      qx2[qq]=now;
      now++;
      seq[now]=node(x2,y1-1,0,now);
      qy1[qq]=now;
      now++;
      seq[now]=node(x1-1,y1-1,0,now);
      qy2[qq]=now;
    }
    op=read();
  }
  std::sort(seq+1,seq+now+1,cmp);
  cdq(1,now);
  for(int i=1;i<=qq;i++){
    printf("%lld\n",ans[qx1[i]]-ans[qx2[i]]-ans[qy1[i]]+ans[qy2[i]]);
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


