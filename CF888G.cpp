#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
inline int read();
signed a[200005];
std::vector<signed>vec[200005];
int getw(int i){
  return a[i];
}
class Trie{
public:
  Trie *l,*r;
  signed siz;
  int xorr;
  Trie(){
    l=r=NULL;
    siz=xorr=0;
    return ;
  }
}HEAD;
void insert(Trie *cur,int num,int n,int op,int numm){
  cur->siz+=op;
  cur->xorr^=numm;
  if(n==-1){
    return ;
  }
  if(num&(1ll<<n)){
    if(cur->r==NULL){
      cur->r=new Trie;
    }
    insert(cur->r,num,n-1,op,numm);
  }else{
    if(cur->l==NULL){
      cur->l=new Trie;
    }
    insert(cur->l,num,n-1,op,numm);
  }
  return ;
}
int ooooo;
int queryxor(Trie *cur,int num,int n){
  if(n==-1){
    return 0;
  }
  ooooo=cur->xorr;
  if(!(num&(1ll<<n))){
    if(cur->l==NULL||cur->l->siz==0){
      return queryxor(cur->r,num,n-1)|(1ll<<n);
    }else{
      return queryxor(cur->l,num,n-1);
    }
  }else{
    if(cur->r==NULL||cur->r->siz==0){
      return queryxor(cur->l,num,n-1)|(1ll<<n);
    }else{
      return queryxor(cur->r,num,n-1);
    }
  }
}
signed fa[200005];
int getfa(int i){
  return fa[i]==i?i:fa[i]=getfa(fa[i]);
}
long long calc2(Trie *l,Trie *r,int n){
  if(n==-1){
    return 0;
  }
  long long ans=0x3f3f3f3f;
  if(l->r!=NULL&&l->r->siz!=0&&r->r!=NULL&&r->r->siz!=0){
    ans=std::min(ans,calc2(l->r,r->r,n-1));
  }
  if(l->l!=NULL&&l->l->siz!=0&&r->l!=NULL&&r->l->siz!=0){
    ans=std::min(ans,calc2(l->l,r->l,n-1));
  }
  if(ans!=0x3f3f3f3f){
    return ans;
  }
  if(l->r!=NULL&&l->r->siz!=0&&r->l!=NULL&&r->l->siz!=0){
    ans=std::min(ans,calc2(l->r,r->l,n-1)|(1ll<<n));
  }
  if(l->l!=NULL&&l->l->siz!=0&&r->r!=NULL&&r->r->siz!=0){
    ans=std::min(ans,calc2(l->l,r->r,n-1)|(1ll<<n));
  }
  return ans;
}
long long calc(Trie *HEAD,int n){
  if(n==-1){
    return 0;
  }
  if(HEAD->l==NULL||HEAD->l->siz==0){
    return calc(HEAD->r,n-1);
  }else if (HEAD->r==NULL||HEAD->r->siz==0){
    return calc(HEAD->l,n-1);
  }
  long long ans=calc(HEAD->l,n-1)+calc(HEAD->r,n-1);
  return ans+(calc2(HEAD->l,HEAD->r,n-1)|(1ll<<n));
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fa[i]=i;
  }
  std::sort(a+1,a+n+1);
  for(int i=2;i<=n;i++){
    if(a[i]==a[i-1]){
      fa[getfa(i)]=getfa(i-1);
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]!=a[i-1]){
      insert(&HEAD,getw(i),31,1,i);
    }
  }
  printf("%lld",calc(&HEAD,31));
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
