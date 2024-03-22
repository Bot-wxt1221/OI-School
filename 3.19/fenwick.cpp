#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int tree[1000015];
int tree2[1000015];
int lowbit(int x){
  return x&(-x);
}
void mod(int x,int y){
  while(x<=1000000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);} //Îö¹¹º¯Êý£¬×Ô¶¯flush 
	
	char read_char() //¶ÁÈëÒ»¸ö×Ö·û£¬×¢Òâ»á¶ÁÈë¿Õ°××Ö·û£¬ÀýÈç¿Õ¸ñ»»ÐÐ
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x) //¶ÁÈëÒ»¸öÕûÐÍ±äÁ¿£¬int,long longÖ®ÀàµÄ¶¼ÄÜ¶ÁÈë 
	{
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c) //Êä³öÒ»¸ö×Ö·û 
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x) //Êä³öÒ»¸öÕûÐÍ±äÁ¿£¬int,long longÖ®ÀàµÄ¶¼ÄÜÊä³ö 
	{
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
};
int n;
int cnt[1000005];
int query2(int x){
  if(x==0){
    return 0;
  }
  int ret=query(x);
  int tr=x;
  x+=lowbit(x);
  int sum=0;
  while(x<=1000000){
    sum+=(tr-(x-lowbit(x)));
    ret+=tree2[x]*(cnt[tr]-cnt[x-lowbit(x)]+sum);
    x+=lowbit(x);
  }
  return ret;
}
void mod2(int l,int x,int v){
  while(x>0){
    tree2[x]+=v;
    mod(x,v*(cnt[x]-cnt[x-lowbit(x)]));
    x-=lowbit(x);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("fenwick.in","r",stdin);
  freopen("fenwick.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    cnt[i]=lowbit(i);
    cnt[i]+=cnt[i-1];
  }
  int m=read();
  for(int i=1;i<=m;i++){
    int op=read();
    int l=read();
    int r=read();
    if(op==1){
      int v=read();
      mod2(1,r,v);
      mod2(1,l-1,-v);
    }else{
      printf("%lld\n",query2(r)-query2(l-1));
    }
  }
  return 0;
}
inline int read(){
  int ret;
  scanf("%lld",&ret);
  return ret;
  return ret;
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


