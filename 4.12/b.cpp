#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
class node{
  public:
    int l,r;
    node(int ll,int rr){
      l=ll;
      r=rr;
      return ;
    }
};
class node2{
  public:
    int l,r;
    node2(int ll,int rr){
      l=ll;
      r=rr;
      return ;
    }
};
bool operator < (node a,node b){
  if(a.l!=b.l){
    return a.l<b.l;
  }
  return a.r>b.r;
}
bool operator < (node2 a,node2 b){
  if(a.r!=b.r){
    return a.r>b.r;
  }
  return a.l<b.l;
}
bool operator == (node a,node b){
  return a.l==b.l&&a.r==b.r;
}
bool operator == (node2 a,node2 b){
  return a.l==b.l&&a.r==b.r;
}
class st{
  public:
    std::priority_queue<node>qu;
    std::priority_queue<node>qu2;
    void push(node a){
      qu.push(a);
      return ;
    }
    void erase(node a){
      qu2.push(a);
      return ;
    }
    void pop(){
      while(qu.size()>0&&qu2.size()>0&&qu.top()==qu2.top()){
        qu.pop();
        qu2.pop();
      }
      qu2.pop();
      return ;
    }
    node top(){
      while(qu.size()>0&&qu2.size()>0&&qu.top()==qu2.top()){
        qu.pop();
        qu2.pop();
      }
      return qu.top();
    }
}a[1000005],c;
class st2{
  public:
    std::priority_queue<node2>qu;
    std::priority_queue<node2>qu2;
    void push(node2 a){
      qu.push(a);
      return ;
    }
    void erase(node2 a){
      qu2.push(a);
      return ;
    }
    void pop(){
      while(qu.size()>0&&qu2.size()>0&&qu.top()==qu2.top()){
        qu.pop();
        qu2.pop();
      }
      qu2.pop();
      return ;
    }
    node2 top(){
      while(qu.size()>0&&qu2.size()>0&&qu.top()==qu2.top()){
        qu.pop();
        qu2.pop();
      }
      return qu.top();
    }
}b[1000005],d;
int minl[4000005],minr[4000005],ans[4000005];
void pushup(int now,int l,int r){
  if(l==r){
    minl[now]=b[l].top().l;
    minr[now]=a[r].top().r;
    ans[now]=minr[now]-minl[now];
    return ;
  }
  minl[now]=std::max(minl[now*2],minl[now*2+1]);
  minr[now]=std::min(minr[now*2],minr[now*2+1]);
  ans[now]=std::min(ans[now*2],ans[now*2+1]);
  ans[now]=std::min(ans[now],minr[now*2+1]-minl[now*2]);
  return ;
}
void init(int now,int l,int r){
  if(l==r){
    pushup(now,l,r);
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  pushup(now,l,r);
  return ;
}
int op;
void update(int now,int l,int r){
  if(r<op||op<l){
    return ;
  }
  if(l==r){
    pushup(now,l,r);
    return ;
  }
  int mid=(l+r)/2;
  update(now*2,l,mid);
  update(now*2+1,mid+1,r);
  pushup(now,l,r);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=1000000;i++){
    a[i].push(node(i,0x3f3f3f3f));
    b[i].push(node2(-0x3f3f3f3f,i));
  }
  init(1,1,1000000);
  for(int i=1;i<=n;i++){
    int op=read();
    int l=read();
    int r=read();
    switch(op){
      case 1:{
        b[r].push(node2(l,r));
        a[l].push(node(l,r));
        d.push(node2(l,r));
        c.push(node(l,r));
        break;
      }
      case 2:{
        b[r].erase(node2(l,r));
        a[l].erase(node(l,r));
        d.erase(node2(l,r));
        c.erase(node(l,r));
        break;
      }
    }
    ::op=l;
    update(1,1,1000000);
    ::op=r;
    update(1,1,1000000);
    if(d.top().r>c.top().l){
      printf("%d\n",c.top().r-d.top().l);
    }else{
      printf("%d\n",ans[1]);
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

