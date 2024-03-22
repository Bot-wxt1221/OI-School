#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll D=1e9;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
#define fi first
#define se second
struct seg
{
#define vpii vector<pair<int,int>>
	struct node{vpii pre,suf;}f[400003];
	inline int lcm(int x,int y)
	{
		if(x>D||y>D) return D+1;
		int z=__gcd(x,y);
		return min(1ll*x*y/z,D+1);
	}
	inline vpii merge(vpii &vl,vpii &vr)
	{
		vpii res=vl;
		int z=vl.back().fi;
		for(auto i:vr)
		{
			z=lcm(z,i.fi);
			if(z==res.back().fi)
				(--res.end())->se+=i.se;
			else res.push_back(make_pair(z,i.se));
		}
		return res;
	}
	inline node merge(node vl,node vr)
	{
		return (node)
			{merge(vl.pre,vr.pre),
			merge(vr.suf,vl.suf)};
	} 
	inline void build(int l,int r,int id)
	{
		if(l==r)
		{
			f[id]=(node){{make_pair(a[l],1)},
						{make_pair(a[l],1)}};
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,id<<1),build(mid+1,r,(id<<1)+1),
		f[id]=merge(f[id<<1],f[(id<<1)+1]);
		return ;
	}
	inline void update(int nl,int nr,int t,int x,int v)
	{
		if(nl==nr) 
		{
			f[x]=(node){{make_pair(v,1)},
						{make_pair(v,1)}};
			return ;
		}
		int mid=(nl+nr)>>1;
		if(t<=mid) update(nl,mid,t,x<<1,v);
		else update(mid+1,nr,t,(x<<1)+1,v);
		f[x]=merge(f[x<<1],f[(x<<1)+1]);
		return ;
	}
	inline node query(int nl,int nr,int l,int r,int x)
	{
		if(l<=nl&&nr<=r) return f[x];
		int mid=(nl+nr)>>1;
		if(r<=mid) return query(nl,mid,l,r,x<<1);
		if(l>mid) return query(mid+1,nr,l,r,(x<<1)+1);
		return merge(query(nl,mid,l,r,x<<1),query(mid+1,nr,l,r,(x<<1)+1));
	}
}T;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<int,ll> mp;
int n,m;
void solve(int x,int d)
{
	seg::node ls=T.query(1,n,1,x,1),rs=T.query(1,n,x,n,1);
  int ii=0,jj=0;
	for(auto i:ls.suf){
    ii++;
    jj=0;
		for(auto j:rs.pre){
      jj++;
			i.fi=T.lcm(i.fi,j.fi),
			mp[i.fi]+=1ll*i.se*j.se*d;
  }
  }
	return ;
}
void init(int x)
{
	seg::node rs=T.query(1,n,x,n,1);
	for(auto j:rs.pre){ mp[j.fi]+=j.se;
    if(j.fi==722107630){
      printf(" ");}}
	return ;
}
signed main()
{
#ifndef local
//	freopen("2.28/cu13.in","r",stdin),
//	freopen("cu.out","w",stdout);
#endif
int cnt=0;
	read(),n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	T.build(1,n,1);
	for(int i=1; i<=n; ++i) init(i);
	for(int op,x; m--;)
	{
		op=read(),x=read();
		if(op==1) {solve(x,-1),a[x]=read(),T.update(1,n,x,1,a[x]);

      if(x==85864){
        printf(" ");
      }
      solve(x,1);
      a[x]=a[x];
    }
		else {cnt++;

      if(cnt==29423){

        printf(" ");

      }printf("%lld\n",mp[722107630]);}
	}
	return 0;
}
