#include <iostream>
#include <cstdio>
#define int long long
inline int read();
class SEGNODE{
public:
  int mn,mnnum,lstmn;
  int mx,mxnum,lstmx;
  int sum,siz;
  int lazyadd,lazymx,lazymn;
  SEGNODE(int mnn,int mnnumm,int lstmnn,int mxx,int mxnumm,int lstmxx,int summ){
    mn=mnn;
    mnnum=mnnumm;
    lstmnn=lstmn;
    mx=mxx;
    mxnum=mxnumm;
    sum=summ;
    return ;
  }
  SEGNODE(){
    mn=lstmn=0x3f3f3f3f3f3f3f;
    lazymn=0x3f3f3f3f3f3f3f;
    lazymx=-0x3f3f3f3f3f3f3f;
    mx=lstmx=-0x3f3f3f3f3f3f3f;
    mnnum=mxnum=0;
    sum=0;
    return ;
  }
}a[500005*4];
void pushup(int now){
  auto &ans=a[now];
  ans=SEGNODE();
  ans.mn=std::min(a[now*2].mn,a[now*2+1].mn);
  ans.mnnum=0;
  if(a[now*2].mn==ans.mn){
    ans.mnnum+=a[now*2].mnnum;
    ans.lstmn=std::min(ans.lstmn,a[now*2].lstmn);
  }else{
    ans.lstmn=std::min(ans.lstmn,a[now*2].mn);
  }
  if(a[now*2+1].mn==ans.mn){
    ans.mnnum+=a[now*2+1].mnnum;
    ans.lstmn=std::min(ans.lstmn,a[now*2+1].lstmn);
  }else{
    ans.lstmn=std::min(ans.lstmn,a[now*2+1].mn);
  }
  ans.mx=std::max(a[now*2].mx,a[now*2+1].mx);
  ans.mxnum=0;
  if(a[now*2].mx==ans.mx){
    ans.mxnum+=a[now*2].mxnum;
    ans.lstmx=std::max(ans.lstmx,a[now*2].lstmx);
  }else{
    ans.lstmx=std::max(ans.lstmx,a[now*2].mx);
  }
  if(a[now*2+1].mx==ans.mx){
    ans.mxnum+=a[now*2+1].mxnum;
    ans.lstmx=std::max(ans.lstmx,a[now*2+1].lstmx);
  }else{
    ans.lstmx=std::max(ans.lstmx,a[now*2+1].mx);
  }
  ans.sum=a[now*2].sum+a[now*2+1].sum;
  ans.siz=a[now*2].siz+a[now*2+1].siz;
  return ;
}
void assignadd(int now,int val){
  a[now].mx+=val;
  a[now].lstmx+=val;
  a[now].mn+=val;
  a[now].lstmn+=val;
  a[now].sum+=val*a[now].siz;
  a[now].lazyadd+=val;
  a[now].lazymn+=val;
  a[now].lazymx+=val;
  return ;
}
void assignmx(int now,int val){
  if(a[now].mn>=val){
    return ;
  }
  a[now].sum+=(val-a[now].mn)*a[now].mnnum;
  if(a[now].mx==a[now].mn){
    a[now].mx=val;
  }
  if(a[now].lstmx==a[now].mn){
    a[now].lstmx=val;
  }
  a[now].lazymn=std::max(val,a[now].lazymn);
  a[now].mn=val;
  a[now].lazymx=val;
  return ;
}
void assignmn(int now,int val){
  if(a[now].mx<=val){
    return ;
  }
  a[now].sum+=(val-a[now].mx)*a[now].mxnum;
  if(a[now].mn==a[now].mx){
    a[now].mn=val;
  }
  if(a[now].lstmn==a[now].mx){
    a[now].lstmn=val;
  }
  a[now].lazymx=std::min(val,a[now].lazymx);
  a[now].mx=val;
  a[now].lazymn=val;
  return ;
}
void pushdown(int now){
  assignadd(now*2,a[now].lazyadd);
  assignadd(now*2+1,a[now].lazyadd);

  assignmx(now*2,a[now].lazymx);
  assignmx(now*2+1,a[now].lazymx);

  assignmn(now*2,a[now].lazymn);
  assignmn(now*2+1,a[now].lazymn);

  a[now].lazyadd=0;
  a[now].lazymx=-0x3f3f3f3f3f3f3f;
  a[now].lazymn=0x3f3f3f3f3f3f3f;
  return ;
}
int seq[500005];
void init(int now,int l,int r){
  a[now].siz=r-l+1;
  if(l==r){
    a[now].mn=a[now].mx=a[now].sum=seq[l];
    a[now].lstmx=-0x3f3f3f3f3f3f3f;
    a[now].lstmn=0x3f3f3f3f3f3f3f;
    a[now].mxnum=a[now].mnnum=1;
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int ql,qr;
int op=0;
void querysum(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    op+=a[now].sum;
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  querysum(now*2,l,mid);
  querysum(now*2+1,mid+1,r);
  return ;
}
void querymn(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::min(op,a[now].mn);
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  querymn(now*2,l,mid);
  querymn(now*2+1,mid+1,r);
  return ;
}
void querymx(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::max(op,a[now].mx);
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  querymx(now*2,l,mid);
  querymx(now*2+1,mid+1,r);
  return ;
}
void modadd(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    assignadd(now,op);
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  modadd(now*2,l,mid);
  modadd(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
void modmx(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr&&a[now].lstmx<op){
    assignmn(now,op);
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  modmx(now*2,l,mid);
  modmx(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
void modmn(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr&&a[now].lstmn>op){
    assignmx(now,op);
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);

  modmn(now*2,l,mid);
  modmn(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  init(1,1,n);
  int q=read();
  for(int i=1;i<=q;i++){
    int opp=read();
    switch(opp){
      case 1:{
        ql=read();
        qr=read();
        op=read();
        modadd(1,1,n);
        break;
      }
      case 2:{
        ql=read();
        qr=read();
        op=read();
        modmn(1,1,n);
        break;
      }
      case 3:{
        ql=read();
        qr=read();
        op=read();
        modmx(1,1,n);
        break;
      }
      case 4:{
        ql=read();
        qr=read();
        op=0;
        querysum(1,1,n);
        printf("%lld\n",op);
        break;
      }
      case 5:{
        ql=read();
        qr=read();
        op=-0x3f3f3f3f3f3f3f;
        querymx(1,1,n);
        printf("%lld\n",op);
        break;
      }
      case 6:{
        ql=read();
        qr=read();
        op=0x3f3f3f3f3f3f3f;
        querymn(1,1,n);
        printf("%lld\n",op);
        break;       
      }
    }
  }
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
