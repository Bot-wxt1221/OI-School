#include <iostream>
#include <cstdio>
#include <set>
inline int read();
class node{
public:
  std::multiset<int> se;
  node *l,*r;
  int mx=0;
}a[2000005],HEAD;
int cnt=0;
void insert(node *cur,int x,int y,int tt,int time){
  cur->se.insert(x);
  cur->mx=std::max(cur->mx,time);
  if(tt==21){
    return ;
  }
  if(y&(1<<(20-tt))){
    if(cur->r==NULL){
      cur->r=&a[++cnt];
    }
    insert(cur->r,x,y,tt+1,time);
  }else{
    if(cur->l==NULL){
      cur->l=&a[++cnt];
    }
    insert(cur->l,x,y,tt+1,time);
  }
}
int mx=0;
void query(node *cur,int l,int r,int tl,int tr,int tt,int x,int curr){
  if(tt==21){
    mx=std::max(mx,x^curr);
    return ;
  }
  if(x&(1<<(20-tt))){
    if(cur->l==NULL){
      query(cur->r,l,r,tl,tr,tt+1,x,curr|(1<<(20-tt)));
      return ;
    }
    auto tt2=cur->l->se.lower_bound(l);
    if(tt2==cur->l->se.end()||*tt2>r){
      query(cur->r,l,r,tl,tr,tt+1,x,curr|(1<<(20-tt)));
      return ;
    }
    if(cur->l->mx<tl){
      query(cur->r,l,r,tl,tr,tt+1,x,curr|(1<<(20-tt)));
      return ;
    }
    query(cur->l,l,r,tl,tr,tt+1,x,curr);
  }else{
    if(cur->r==NULL){
      query(cur->l,l,r,tl,tr,tt+1,x,curr);
      return ;
    }
    auto tt2=cur->r->se.lower_bound(l);
    if(tt2==cur->r->se.end()||*tt2>r){
      query(cur->l,l,r,tl,tr,tt+1,x,curr);
      return ;
    }
    if(cur->r->mx<tl){
      query(cur->l,l,r,tl,tr,tt+1,x,curr);
      return ;
    }
    query(cur->r,l,r,tl,tr,tt+1,x,curr|(1<<(20-tt)));
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    int tt=read();
    insert(&HEAD,i,tt,0,0x3f3f3f3f);
  }
  int preop=0;
  int cnt=0;
  for(int i=1;i<=m;i++){
    int op=read();
    switch(op){
      case 0:{
        int s=read();
        int v=read();
        cnt++;
        insert(&HEAD,s,v,0,cnt);
        break;
      }
      case 1:{
        int l=read();
        int r=read();
        int x=read();
        int d=read();
        mx=0;
        query(&HEAD,l,r,cnt-d+1,cnt,0,x,0);
        printf("%d\n",mx);
      }
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
