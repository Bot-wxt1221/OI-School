#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
inline long long read();
long long tans=0;
int a[500005];
std::vector<std::pair<long long,int> >vec[65];
std::pair<int,long long> merge(int dep){
  if(vec[dep].size()==1){
    return {vec[dep][0].second,1ll*vec[dep][0].second*(vec[dep][0].second-1)/2};
  }
  if(vec[dep].size()==0){
    return {0,0};
  }
  std::vector<std::pair<long long,int> > tmp;
  vec[dep+1].clear();
  for(int i=0;i<vec[dep].size();i++){
    if(vec[dep][i].first&(1ll<<(dep))){
      tmp.push_back(vec[dep][i]);
    }else{
      vec[dep+1].push_back(vec[dep][i]);
    }
  }
  auto tt=merge(dep+1);
  std::swap(vec[dep+1],tmp);
  auto tt2=merge(dep+1);
  if(dep%2==1){
    tans+=tt.first*tt2.second;
    tans+=tt2.first*tt.second;
  }
  return {tt.first+tt2.first,tt2.second+tt.second};
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    std::sort(a+1,a+n+1);
    vec[0].clear();
    long long ans=1ll*(n)*(n-1)*(n-2)/3/2;
    int cnt=0;
    for(auto i=1;i<=n;i++){
      if(a[i]!=a[i-1]){
        if(cnt!=0){
          ans-=(cnt)*(cnt-1)/2*(n-cnt);
          ans-=(cnt)*(cnt-1)*(cnt-2)/6;
          vec[0].push_back({a[i-1],cnt});
        }
        cnt=0;
      }
      cnt++;
    }
    if(cnt){
      ans-=(cnt)*(cnt-1)/2*(n-cnt);
      ans-=(cnt)*(cnt-1)*(cnt-2)/6;
      vec[0].push_back({a[n],cnt});
    }
    merge(0);
    ans+=tans;
    tans=0;
    printf("%lld\n",ans);
  }
	return 0;
}
inline long long read(){
	long long f=1,x=0;
	char temp=getchar();
  if(temp==EOF){
    return 0;
  }
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
    if(temp==EOF){
      return f*x;
    }
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
    if(temp==EOF){
      return f*x;
    }
	}
	return f*x;
}
