#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
inline int read();
int a[100005];
class node{
public:
  int first;
  mutable int second;
};
bool operator< (const node &a,const node &b){
  return a.first<b.first;
}
std::set<node>se[100005];
int phi[100005];
long long ans;
long long get(node a){
  int siz=a.second-a.first+1;
  return 1ll*(siz+1)*siz/2;
}
void insert(int x,int i,int tx=-1){
  int tt=std::sqrt(x);
  for(int k=1;k<=tt;k++){
    if(x%k){
      continue;
    }
    if(k!=1&&tx%k!=0){
      auto tt=se[k].insert({i,i}).first;
      ans+=1*phi[k];
      auto pre=tt;
      auto nxt=tt;
      pre--;
      nxt++;
      if(tt->first==(pre)->second+1){
        ans+=get({pre->first,i})*phi[k];
        ans-=get(*pre)*phi[k];
        ans-=get(*tt)*phi[k];
        pre->second=tt->first;
        se[k].erase(tt);
        tt=pre;
        nxt=pre;
        nxt++;
      }
      if(tt->second+1==(nxt)->first){
        auto tt2=se[k].insert({tt->first,nxt->second}).first;
        ans+=get(*tt2)*phi[k];
        ans-=get(*nxt)*phi[k];
        ans-=get(*tt)*phi[k];
        se[k].erase(nxt);
        se[k].erase(tt);
        tt=tt2;
        pre=tt2;
        pre--;
      }
    }
    if(k*k!=x&&tx%(x/k)!=0){
      k=x/k;
      auto tt=se[k].insert({i,i}).first;
      ans+=phi[k];
      auto pre=tt;
      auto nxt=tt;
      pre--;
      nxt++;
      if(tt->first==(pre)->second+1){
        ans+=get({pre->first,i})*phi[k];
        ans-=get(*pre)*phi[k];
        ans-=get(*tt)*phi[k];
        pre->second=tt->first;
        se[k].erase(tt);
        tt=pre;
        nxt=pre;
        nxt++;
      }
      if(tt->second+1==(nxt)->first){
        auto tt2=se[k].insert({tt->first,nxt->second}).first;
        ans+=get(*tt2)*phi[k];
        ans-=get(*nxt)*phi[k];
        ans-=get(*tt)*phi[k];
        se[k].erase(nxt);
        se[k].erase(tt);
        tt=tt2;
        pre=tt2;
        pre--;
      }
      k=x/k;
    }
  }
  return ;
}
void del(int x,int i,int tx=-1){
  int tt=std::sqrt(x);
  for(int k=1;k<=tt;k++){
    if(x%k){
      continue;
    }
    if(k!=1&&tx%k!=0){
      auto tt=se[k].upper_bound({i,0x3f3f3f3f});
      tt--;
      auto bk=*tt;
      ans-=get(*tt)*phi[k];
      //{bk.first,i-1};
      if(bk.first<=i-1){
        tt->second=i-1;
        ans+=get({bk.first,i-1})*phi[k];
      }else{
        se[k].erase(tt);
      }
      if(i+1<=bk.second){
        tt=se[k].insert({i+1,bk.second}).first;
        ans+=get(*tt)*phi[k];
      }
    }
    if(k*k!=x&&tx%(x/k)!=0){
      k=x/k;
      auto tt=se[k].upper_bound({i,0x3f3f3f3f});
      tt--;
      auto bk=*tt;
      ans-=get(*tt)*phi[k];
      //{bk.first,i-1};
      if(bk.first<=i-1){
        tt->second=i-1;
        ans+=get({bk.first,i-1})*phi[k];
      }else{
        se[k].erase(tt);
      }
      if(i+1<=bk.second){
        tt=se[k].insert({i+1,bk.second}).first;
        ans+=get(*tt)*phi[k];
      }
      k=x/k;
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    se[i].insert({-1,-1});
    se[i].insert({n+2,n+2});
  }
  for(int i=1;i<=n;i++){
    int ti=i;
    int tt=std::sqrt(n);
    phi[i]=1;
    for(int j=2;j<=tt;j++){
      int cnt=0;
      while(ti%j==0){
        ti/=j;
        cnt++;
        phi[i]*=-1;
      }
      if(cnt>=2){
        phi[i]=0;
      }
    }
    if(ti!=1){
      phi[i]*=-1;
    }
  }
  phi[1]=0;
  for(int i=1;i<=n;i++){
    insert(a[i],i);
  }
  int q=read();
  printf("%lld\n",ans+1ll*(n)*(n+1)/2);
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    if(a[l]!=a[r]){
      del(a[l],l,a[r]);
      del(a[r],r,a[l]);
      insert(a[l],r,a[r]);
      insert(a[r],l,a[l]);
      std::swap(a[l],a[r]);
    }
    printf("%lld\n",ans+1ll*(n)*(n+1)/2);
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
