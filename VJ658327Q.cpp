#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int a[300005];
int b[300005];
std::priority_queue<std::pair<int,int> >qu;
std::pair<int,int> seq[300005];
int out[300005];
bool used[300005];
int cnt;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int w=read();
  int cnttt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read()-a[i];
    if(b[i]>=a[i]){
      qu.push({-a[i],i});
    }else{
      seq[++cnt]={(a[i]+b[i]),i};
      cnttt+=seq[cnt].first;
    }
  }
  std::sort(seq+1,seq+cnt+1);
  int ans=0x3f3f3f3f3f3f3f3f;
  int curans=0;
  int chose=0;
  int curi=0;
  for(int i=cnt;i>=0;i--){
    int left=w-i*2;
    while(chose<left){
      auto tp=qu.top();
      curans-=tp.first;
      qu.pop();
      if(used[tp.second]==0){
        used[tp.second]=1;
        qu.push({-b[tp.second],tp.second});
      }
      chose++;
    }
    ans=std::min(ans,curans+cnttt);
    if(ans==curans+cnttt){
      curi=i;
    }
    qu.push({-a[seq[i].second],seq[i].second});
    cnttt-=seq[i].first;
  }
  printf("%lld\n",ans);
  for(int i=1;i<=curi;i++){
    out[seq[i].second]+=2;
  }
  qu=std::priority_queue<std::pair<int,int> >();
  memset(used,0,sizeof(used));
  chose=0;
  for(int i=1;i<=n;i++){
    if(b[i]>=a[i]){
      qu.push({-a[i],i});
    }else{
    }
  }
  for(int i=cnt;i>=0;i--){
    int left=w-i*2;
    while(chose<left){
      auto tp=qu.top();
      curans-=tp.first;
      qu.pop();
      if(used[tp.second]==0){
        used[tp.second]=1;
        qu.push({-b[tp.second],tp.second});
      }
      out[tp.second]++;
      chose++;
    }
    if(curi==i){
      break;
    }
    qu.push({-a[seq[i].second],seq[i].second});
  }
  for(int i=1;i<=n;i++){
    printf("%lld",out[i]);
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
