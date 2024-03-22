#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
inline int read();
class node{
  public:
    node *nxt[30];
    int cur,cur2;
    std::set<int>p0,p1;
    node(){
      p0.clear();
      p1.clear();
      cur=0;
      cur2=0;
      for(int i=0;i<26;i++){
        nxt[i]=nullptr;
      }
      return ;
    }
}HEAD,buf[800005];
std::string a[200005],b[200005];
int ans[200005];
int totans;
void erase1(int i){
  node *cur=&HEAD;
  cur->p0.erase(i);
  for(int j=0;j<a[i].size();j++){
    cur=cur->nxt[a[i][j]-'a'];
    cur->p0.erase(i);
  }
  return ;
}
void erase2(int i){
  node *cur=&HEAD;
  cur->p1.erase(i);
  for(int j=0;j<b[i].size();j++){
    cur=cur->nxt[b[i][j]-'a'];
    cur->p1.erase(i);
  }
  return ;
}
void solve(node *a,int dep){
  for(int i=0;i<26;i++){
    if(a->nxt[i]!=nullptr){
      solve(a->nxt[i],dep+1);
    }
  }
  while(a->p0.size()>0&&a->p1.size()>0){
    totans+=dep;
    int x=*a->p0.begin();
    int y=*a->p1.begin();
    ans[x]=y;
    erase1(x);
    erase2(y); 
  }
  return ;
}
int used;
char temp[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    int siz=strlen(temp+1);
    a[i]=std::string(temp+1);
    node *cur=&HEAD;
    cur->p0.insert(i);
    for(int j=1;j<=siz;j++){
      if(cur->nxt[temp[j]-'a']==nullptr){
        cur->nxt[temp[j]-'a']=&buf[++used];
        cur=&buf[used];
      }else{
        cur=cur->nxt[temp[j]-'a'];
      }
      cur->p0.insert(i);
    }
  }
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    int siz=strlen(temp+1);
    b[i]=std::string(temp+1);
    node *cur=&HEAD;
    cur->p1.insert(i);
    for(int j=1;j<=siz;j++){
      if(cur->nxt[temp[j]-'a']==nullptr){
        cur->nxt[temp[j]-'a']=&buf[++used];
        cur=&buf[used];
      }else{
        cur=cur->nxt[temp[j]-'a'];
      }
      cur->p1.insert(i);
    }
    cur->cur2++;
  }
  solve(&HEAD,0);
  printf("%d\n",totans);
  for(int i=1;i<=n;i++){
    printf("%d %d\n",i,ans[i]);
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


