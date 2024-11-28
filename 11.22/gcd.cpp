#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int a[100005];
int l[100005];
int r[100005];
int tree[400005];
void init(int now,int l,int r){
  if(l==r){
    tree[now]=a[l];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=std::__gcd(tree[now*2],tree[now*2+1]);
}
int qpos;
void mod(int now,int l,int r){
  if(r<qpos||qpos<l){
    return ;
  }
  if(l==r){
    tree[now]=a[l];
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::__gcd(tree[now*2],tree[now*2+1]);
}
int curgcd;
int curpos;
void getans(int now,int l,int r){
  if(l==r){
    if(curgcd!=1&&std::__gcd(curgcd,tree[now])==1){
      curgcd=1;
      curpos=l;
    }
    curgcd=std::__gcd(curgcd,tree[now]);
    return ;
  }
  int mid=(l+r)/2;
  getans(now*2+1,mid+1,r);
  if(curgcd!=1&&std::__gcd(curgcd,tree[now*2])==1){
    getans(now*2,l,mid);
  }else{
    curgcd=std::__gcd(curgcd,tree[now*2]);
  }
}
void query(int now,int l,int r){
  if(qpos<l||r<qpos){
    return ;
  }
  if(l==r){
    getans(now,l,r);
    return ;
  }
  int mid=(l+r)/2;
  if(qpos>mid){
    query(now*2+1,mid+1,r);
    if(curgcd!=1&&std::__gcd(curgcd,tree[now*2])==1){
      getans(now*2,l,mid);
    }else{
      curgcd=std::__gcd(tree[now*2],curgcd);
    }
  }else{
    query(now*2,l,mid);
  }
  return ;
}
void getans2(int now,int l,int r){
   if(l==r){
    if(curgcd!=1&&std::__gcd(curgcd,tree[now])==1){
      curgcd=1;
      curpos=l;
    }
    curgcd=std::__gcd(curgcd,tree[now]);
    return ;
  }
  int mid=(l+r)/2;
  getans2(now*2,l,mid);
  if(curgcd!=1&&std::__gcd(curgcd,tree[now*2+1])==1){
    getans2(now*2+1,mid+1,r);
  }else{
    curgcd=std::__gcd(curgcd,tree[now*2+1]);
  } 
}
void query2(int now,int l,int r){
  if(qpos<l||r<qpos){
    return ;
  }
  if(l==r){
    getans2(now,l,r);
    return ;
  }
  int mid=(l+r)/2;
  if(qpos<=mid){
    query2(now*2,l,mid);
    if(curgcd!=1&&std::__gcd(curgcd,tree[now*2+1])==1){
      getans2(now*2+1,mid+1,r);
    }else{
      curgcd=std::__gcd(curgcd,tree[now*2+1]);
    }
  }else{
    query2(now*2+1,mid+1,r);
  }
}
int n;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	#endif
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  long long ans=0;
  init(1,1,n);
  for(int i=1;i<=n;i++){
    qpos=i;
    curgcd=a[i];
    curpos=0;
    if(curgcd==1){
      curpos=i;
    }
    query(1,1,n);
    ans+=curpos;
  }
  printf("%lld\n",ans);
  int q=read();
  for(int i=1;i<=q;i++){
    int ll=read();
    int rr=read();
    std::swap(a[ll],a[rr]);
    qpos=ll;
    mod(1,1,n);
    qpos=rr;
    mod(1,1,n);
    ans=0;
    for(int j=1;j<=n;j++){
      qpos=j;
      curgcd=a[j];
      curpos=0;
      if(curgcd==1){
        curpos=j;
      }
      query(1,1,n);
      ans+=curpos;
    }
    printf("%lld\n",ans);
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
