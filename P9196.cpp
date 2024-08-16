#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int read();
int to[305];
class node{
public:
  node *to[5];
  int dfn;
  int lstdfn;
  int siz;
  node(){
    to[0]=to[1]=to[2]=to[3]=to[4]=NULL;
    siz=dfn=0;
    return ;
  }
};
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[2000005];
  int query(int now){
    now+=2;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=2;
    while(x<=2000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}a;
node *zhengn[200005],*fann[200005];
node *ansz[200005],*ansf[200005];
char temp[200005];
int rans[200005];
node *insplace;
int len;
int cnt;
node *ans;
class pos{
public:
  int x,y,quan,adquan,adpos;
  pos(int xx=0,int yy=0,int zz=0,int aa=0,int dd=0){
    x=xx;
    y=yy;
    quan=zz;
    adquan=aa;
    adpos=dd;
    return ;
  }
}seq[1000005];
bool operator <  (pos a,pos b){
  if(a.x!=b.x){
    return a.x<b.x;
  }
  if(a.y!=b.y){
    return a.y<b.y;
  }
  return a.quan>b.quan;
}
class Trie{
public:
  node HEAD;
  void insert(int curpos,node *cur){
    if(curpos>len){
      insplace=cur;
      return ;
    }
    cur->siz++;
    int i=to[temp[curpos]];
    if(cur->to[i]==NULL){
      cur->to[i]=new node;
    }
    insert(curpos+1,cur->to[i]);
  }
  void dfs(node *cur){
    cur->dfn=++cnt;
    for(int i=1;i<=4;i++){
      if(cur->to[i]!=NULL){
        dfs(cur->to[i]);
      }
    }
    cur->lstdfn=cnt;
    return ;
  }
  void find(int curpos,node *cur){
    if(curpos>len){
      ans=cur;
      return ;
    }
    int i=to[temp[curpos]];
    if(cur->to[i]==NULL){
      return ;
    }
    find(curpos+1,cur->to[i]);
    return ;
  }
}zheng,fan;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  to['A']=1;
  to['U']=2;
  to['G']=3;
  to['C']=4;
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    len=strlen(temp+1);
    zheng.insert(1,&zheng.HEAD);
    zhengn[i]=insplace;
    std::reverse(temp+1,temp+len+1);
    fan.insert(1,&fan.HEAD);
    fann[i]=insplace;
  }
  zheng.dfs(&zheng.HEAD);
  cnt=0;
  fan.dfs(&fan.HEAD);
  for(int i=1;i<=m;i++){
    scanf("%s",temp+1);
    ans=NULL;
    len=strlen(temp+1);
    zheng.find(1,&zheng.HEAD);
    ansz[i]=ans;
    ans=NULL;
    scanf("%s",temp+1);
    len=strlen(temp+1);
    std::reverse(temp+1,temp+len+1);
    fan.find(1,&fan.HEAD);
    ansf[i]=ans;
  }
  int cntt=0;
  for(int i=1;i<=n;i++){
    seq[++cntt]=pos(zhengn[i]->dfn,fann[i]->dfn,1,0,0);
  }
  for(int i=1;i<=m;i++){
    if(ansz[i]==NULL||ansf[i]==NULL){
      continue;
    }
    seq[++cntt]=pos(ansz[i]->lstdfn,ansf[i]->lstdfn,0,1,i);
    seq[++cntt]=pos(ansz[i]->lstdfn,ansf[i]->dfn-1,0,-1,i);
    seq[++cntt]=pos(ansz[i]->dfn-1,ansf[i]->lstdfn,0,-1,i);
    seq[++cntt]=pos(ansz[i]->dfn-1,ansf[i]->dfn-1,0,1,i);
  }
  std::sort(seq+1,seq+cntt+1);
  for(int i=1;i<=cntt;i++){
    a.mod(seq[i].y,seq[i].quan);
    rans[seq[i].adpos]+=a.query(seq[i].y)*seq[i].adquan;
  }
  for(int i=1;i<=m;i++){
    printf("%d\n",rans[i]);
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
