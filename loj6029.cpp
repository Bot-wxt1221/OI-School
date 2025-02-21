#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[1000005];
int mx[4000005];
int mn[4000005];
int sum[4000005];
int lazyadd[4000005];
int lazycover[4000005];
int siz[4000005];
void init(int now,int l,int r){
  siz[now]=r-l+1;
  if(l==r){
    mx[now]=mn[now]=sum[now]=a[l];
    return ;
  }
  lazycover[now]=-1;
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  mn[now]=std::min(mn[now*2],mn[now*2+1]);
  sum[now]=sum[now*2]+sum[now*2+1];
  return ;
}
void pushdown(int now){
  if(lazycover[now]==-1){
  }else{
    mx[now*2+1]=mn[now*2+1]=mx[now*2]=mn[now*2]=lazycover[now];
    lazycover[now*2]=lazycover[now*2+1]=lazycover[now];
    sum[now*2]=lazycover[now]*siz[now*2];
    sum[now*2+1]=lazycover[now]*siz[now*2+1];
    lazyadd[now*2]=lazyadd[now*2+1]=0;
    lazycover[now]=-1;
  }
  mx[now*2]+=lazyadd[now];
  mx[now*2+1]+=lazyadd[now];
  mn[now*2]+=lazyadd[now];
  mn[now*2+1]+=lazyadd[now];
  sum[now*2]+=lazyadd[now]*siz[now*2];
  sum[now*2+1]+=lazyadd[now]*siz[now*2+1];

  lazyadd[now*2]+=lazyadd[now];
  lazyadd[now*2+1]+=lazyadd[now];
  lazyadd[now]=0;
  return ;
}
int ql,qr,op;
void querymn(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::min(op,mn[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  querymn(now*2,l,mid);
  querymn(now*2+1,mid+1,r);
  return ;
}
void querysum(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    op+=sum[now];
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  querysum(now*2,l,mid);
  querysum(now*2+1,mid+1,r);
  return ;
}
void modadd(int now,int l,int r,int ql,int qr,int op){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    mx[now]+=op;
    mn[now]+=op;
    sum[now]+=op*siz[now];
    lazyadd[now]+=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  modadd(now*2,l,mid,ql,qr,op);
  modadd(now*2+1,mid+1,r,ql,qr,op);
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  mn[now]=std::min(mn[now*2],mn[now*2+1]);
  sum[now]=sum[now*2]+sum[now*2+1];
  return ;
}
void modcover(int now,int l,int r,int ql,int qr,int op){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    mx[now]=mn[now]=op;
    sum[now]=op*siz[now];
    lazyadd[now]=0;
    lazycover[now]=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  modcover(now*2,l,mid,ql,qr,op);
  modcover(now*2+1,mid+1,r,ql,qr,op);
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  mn[now]=std::min(mn[now*2],mn[now*2+1]);
  sum[now]=sum[now*2]+sum[now*2+1];
  return ;
}
void modchu(int now,int l,int r,int ql,int qr,int op){
  if(qr<l||r<ql){
    return ;
  }
  pushdown(now);
  if(ql<=l&&r<=qr){
    if(-1<=mn[now]&&mx[now]<=0){
      return ;
    }else{
      int p=mx[now]/op;
      int rr=mx[now]%op;
      if(rr<0){
        rr+=op;
        p--;
      }
      int q=mn[now]/op;
      int s=mn[now]%op;
      if(s<0){
        s+=op;
        q--;
      }
      if((p==q&&s==rr)||(p==q+1&&s==op-1&&rr==0)){
        modadd(now,l,r,l,r,mx[now]/op-(mx[now]%op<0)-mx[now]);
      }else{
        int mid=(l+r)/2;
        modchu(now*2,l,mid,ql,qr,op);
        modchu(now*2+1,mid+1,r,ql,qr,op);
        mx[now]=std::max(mx[now*2],mx[now*2+1]);
        mn[now]=std::min(mn[now*2],mn[now*2+1]);
        sum[now]=sum[now*2]+sum[now*2+1];
      }
    }
    return ;
  }
  int mid=(l+r)/2;
  modchu(now*2,l,mid,ql,qr,op);
  modchu(now*2+1,mid+1,r,ql,qr,op);
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  mn[now]=std::min(mn[now*2],mn[now*2+1]);
  sum[now]=sum[now*2]+sum[now*2+1];
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	#endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  init(1,1,n);
  for(int i=1;i<=q;i++){
    int opp=read();
    int l=read()+1;
    int r=read()+1;
    switch(opp){
      case 1:{
        int c=read();
        modadd(1,1,n,l,r,c);
        break;
      }
      case 2:{
        int c=read();
        modchu(1,1,n,l,r,c);
        break;
      }
      case 3:{
        op=0x3f3f3f3f3f3f3f3f;
        ql=l;
        qr=r;
        querymn(1,1,n);
        printf("%lld\n",op);
        break;
      }
      case 4:{
        op=0;
        ql=l;
        qr=r;
        querysum(1,1,n);
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
