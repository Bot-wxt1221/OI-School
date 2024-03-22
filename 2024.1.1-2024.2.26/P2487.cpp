#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int h,v,t,i;
}seq[50005],temp[50005];
bool cmp(node a,node b){
  if(a.h!=b.h){
    return a.h>b.h;
  }
  if(a.v!=b.v){
    return a.v>b.v;
  }
  return a.t<b.t;
}
bool cmp2(node a,node b){
  if(a.v!=b.v){
    return a.v>b.v;
  }
  if(a.t!=b.t){
    return a.t<b.t;
  }
  return a.h>b.h;
}
int lowbit(int x){
  return (x)&(-x);
}
int tree[500005];
int cnttree[50005];
int cntt=0;
int query(int x){
  int ans=-0x3f3f3f3f;
  cntt=0;
  while(x>0){
    if(ans<tree[x]){
      cntt=0;
    }
    ans=std::max(ans,tree[x]);
    if(ans==tree[x]){
      cntt++;
    }
    x-=lowbit(x);
  }
  return ans;
}
void add(int x,int y){
  while(x<=500000){
    if(tree[x]<y){
      cnttree[x]=0;
    }
    tree[x]=std::max(tree[x],y);
    if(tree[x]==y){
      cnttree[x]++;
    }
    x+=lowbit(x);
  }
  return ;
}
void clear(int x){
  while(x<=500000){
    tree[x]=-0x3f3f3f3f;
    x+=lowbit(x);
  }
  return ;
}
int dp1[50005];
int cnt1[50005];
void cdq(int l,int r,int *dp,int *cnt){
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid,dp,cnt);
  std::sort(seq+l,seq+mid+1,cmp2);
  std::sort(seq+mid+1,seq+r+1,cmp2);
  int nl=l,nr=mid+1;
  int now=l;
  while(nl<=mid&&nr<=r){
    if(seq[nl].v>=seq[nr].v){
      temp[now++]=seq[nl];
      add(seq[nl].t,dp[seq[nl].i]+1);
      nl++;
    }else{
      temp[now++]=seq[nr];
      
      int tmp=query(seq[nr].t);
      if(tmp>dp[seq[nr].i]){
        cnt[seq[nr].i]=0;
      }
      dp[seq[nr].i]=std::max(tmp,dp[seq[nr].i]);
      if(tmp==dp[seq[nr].i]){
        cnt[seq[nr].i]++;
      }
      nr++;
    }
  }
  while(nl<=mid){
    temp[now++]=seq[nl];
    add(seq[nl].t,dp[seq[nl].i]);
    nl++;
  }
  while(nr<=r){
    temp[now++]=seq[nr];
    dp[seq[nr].i]=std::max(query(seq[nr].t),dp[seq[nr].i]);
    nr++;
  }
  for(int i=l;i<=mid;i++){
    seq[i]=temp[i];
  }
  cdq(mid+1,r,dp,cnt);
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    seq[i].h=read();
    seq[i].v=read();
    seq[i].t=i;
    seq[i].i=i;
    dp[i]=1;
  }
  cdq(1,n);
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


