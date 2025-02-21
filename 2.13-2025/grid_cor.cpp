#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int mx[1000005*8];
int mnx[1000005],mxx[1000005],mny[1000005],mxy[1000005];
std::vector<int>st[1000005*4];
void pushup(int now){
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  if(st[now].size()){
    mx[now]=std::max(mx[now],st[now].back());
  }
  return ;
}
bool flag[1000005*4];
int ql,qr;
int op;
void add(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    st[now].push_back(op);
    pushup(now);
    return ;
  }
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  pushup(now);
}
void mod(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    while(st[now].size()>0&&flag[st[now].back()]){
      st[now].pop_back();
    }
    pushup(now);
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int ans=0;
void query(int now,int l,int r){
  if(ans){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(mxx[mx[now]]<op){
    return ;
  }
  if(st[now].size()>0&&mxx[st[now].back()]>=op){
    ans=std::max(ans,st[now].back());
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
std::pair<int,int>pa[1000005];
int n;
int check(int i){
  ans=0;
  ql=mny[i];
  qr=mxy[i];
  op=std::max(mnx[i]-2,1);
  query(1,1,n);
  if(mxx[ans]>=std::max(mnx[i]-2,1)){
    return ans;
  }
  ans=0;
  ql=mny[i]-1;
  qr=ql;
  op=std::max(mnx[i]-1,1);
  query(1,1,n);
  if(mxx[ans]>=std::max(mnx[i]-1,1)){
    return ans;
  }
  ans=0;
  ql=mxy[i]+1;
  qr=ql;
  op=std::max(mnx[i]-1,1);
  query(1,1,n);
  if(mxx[ans]>=std::max(mnx[i]-1,1)){
    return ans;
  }
  ans=0;
  ql=mny[i]-2;
  qr=ql;
  op=std::max(mnx[i],1);
  query(1,1,n);
  if(mxx[ans]>=std::max(mnx[i],1)){
    return ans;
  }
  ans=0;
  ql=mxy[i]+2;
  qr=ql;
  op=std::max(mnx[i],1);
  query(1,1,n);
  if(mxx[ans]>=std::max(mnx[i],1)){
    return ans;
  }
  return -1;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    pa[i].first=read();
    pa[i].second=read();
  }
  std::sort(pa+1,pa+m+1);
  for(int i=1;i<=m;i++){
    if(pa[i]==pa[i-1]){
      flag[i]=1;
      continue;
    }
    mxx[i]=mnx[i]=pa[i].first;
    mxy[i]=mny[i]=pa[i].second;
    int j=0;
    while((j=check(i))!=-1){
      mxx[i]=std::max(mxx[i],mxx[j]);
      mnx[i]=std::min(mnx[i],mnx[j]);
      mxy[i]=std::max(mxy[i],mxy[j]);
      mny[i]=std::min(mny[i],mny[j]);
      flag[j]=1;
      ql=mny[j];
      qr=mxy[j];
      mod(1,1,n);
    }
    ql=mny[i];
    qr=mxy[i];
    op=i;
    add(1,1,n);
  }
  long long anss=0;
  for(int i=1;i<=m;i++){
    if(!flag[i]){
      anss+=1ll*(mxx[i]-mnx[i]+1)*(mxy[i]-mny[i]+1);
    }
  }
  printf("%lld",anss);
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
