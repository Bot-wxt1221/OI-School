#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#define mod 998244353
inline int read();
char temp;
int to1[25];
int to2[25];
void init(){
  for(int i=0;i<16;i++){
    int x=i&1;
    int y=(i>>1)&1;
    int z=(i>>2)&1;
    int t=(i>>3)&1;
    t^=x;
    to1[i^4]=(x<<2)+(y<<1)+(z)+(t<<3);
  }
  for(int i=0;i<16;i++){
    int x=i&1;
    int y=(i>>1)&1;
    int z=(i>>2)&1;
    int t=(i>>3)&1;
    t^=y;
    to2[i^4]=(x)+(y<<2)+(z<<1)+(t<<3);
  }
  return ;
}
class Matrix{
  public:
    std::vector<std::pair<std::pair<int,int>,int> >vec;
}zero,one,two,base;
Matrix *seq[50005];
int mp[16][16];
void cheng (const Matrix &a,const Matrix &b,Matrix &ans){
  ans.vec.clear();
  for(int i=0;i<a.vec.size();i++){
    for(int j=0;j<b.vec.size();j++){
      if(a.vec[i].first.second==b.vec[j].first.first){
        mp[a.vec[i].first.first][b.vec[j].first.second]+=1ll*a.vec[i].second*b.vec[j].second%mod;
        if(mp[a.vec[i].first.first][b.vec[j].first.second]>mod){
          mp[a.vec[i].first.first][b.vec[j].first.second]-=mod;
        }
      }
    }
  }
  for(int i=0;i<16;i++){
    for(auto j=0;j<16;j++){
      if(mp[i][j]){
        ans.vec.push_back(std::make_pair(std::make_pair(i,j),mp[i][j]));
        mp[i][j]=0;
      }
    }
  }
  return ;
}
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  ans.vec.clear();
  for(int i=0;i<a.vec.size();i++){
    for(int j=0;j<b.vec.size();j++){
      if(a.vec[i].first.second==b.vec[j].first.first){
        mp[a.vec[i].first.first][b.vec[j].first.second]+=1ll*a.vec[i].second*b.vec[j].second%mod;
        if(mp[a.vec[i].first.first][b.vec[j].first.second]>mod){
          mp[a.vec[i].first.first][b.vec[j].first.second]-=mod;
        }
      }
    }
  }
  for(int i=0;i<16;i++){
    for(auto j=0;j<16;j++){
      if(mp[i][j]){
        ans.vec.push_back(std::make_pair(std::make_pair(i,j),mp[i][j]));
        mp[i][j]=0;
      }
    }
  }
  return ans;
}

Matrix tree[50000*4+5];
void init(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=*seq[l];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=tree[now*2]*tree[now*2+1];
  return ;
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
}IO;
Matrix ans;
int ql,qr;
void query(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    ans=ans*tree[now];
    return ;
  }
  int mid=(l+r)/2;
  if(ql<=mid){
    query(now*2,l,mid);
  }
  if(qr>=mid+1){
    query(now*2+1,mid+1,r);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  init();
  for(int i=0;i<16;i++){
    zero.vec.push_back(std::make_pair(std::make_pair(i,to1[i]),1));
    two.vec.push_back(std::make_pair(std::make_pair(i,to1[i]),1));
  }
  for(int i=0;i<16;i++){
    one.vec.push_back(std::make_pair(std::make_pair(i,to2[i]),1));
    two.vec.push_back(std::make_pair(std::make_pair(i,to2[i]),1));
  }
  int n=5e4;
  IO.read_int(n);
  for(int i=1;i<=n;i++){
    while((temp=IO.read_char())!='0'&&(temp!='1')&&(temp!='?'));
    if(temp=='0'){
      seq[i]=&zero;
    }else if(temp=='1'){
      seq[i]=&one;
    }else{
      seq[i]=&two;
    }
  }
  init(1,1,n);
  base.vec.push_back(std::make_pair(std::make_pair(0,0),1));
  int q=3e5;
  IO.read_int(q);
  for(int i=1;i<=q;i++){
    int l,r;
    IO.read_int(l);
    IO.read_int(r);
    ql=l;
    qr=r;
    ans=base;
    query(1,1,n);
    int ret=0;
    for(int j=0;j<ans.vec.size();j++){
      if((ans.vec[j].first.second&(1<<3))){
        ret+=ans.vec[j].second;
        if(ret>mod){
          ret-=mod;
        }
      }
    }
    IO.write_int(ret);
    IO.write_char('\n');
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
