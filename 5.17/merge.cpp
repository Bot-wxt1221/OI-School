#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
inline int read();
long long a[200005];
std::map<long long, int >mp;
std::vector<int>vec[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("merge.in","r",stdin);
  freopen("merge.out","w",stdout);
  #endif
  int n=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(mp[a[i]]==0){
      mp[a[i]]=++cnt;
    }
    auto tt=&vec[mp[a[i]]];
    tt->push_back(i);
  }
  int cntt=n;
  for(auto i=mp.begin();i!=mp.end();i++){
    auto tt=&vec[i->second];
    if(tt->size()<=1){
      continue;
    }
    auto tt2=mp[i->first*2];
    std::sort(tt->begin(),tt->end());
    if(tt2==0){
      cnt++;
      if(cnt>200000){
        cnt-=200000;
      }
      mp[i->first*2]=cnt;
      tt2=(cnt);
    }
    for(int i=1;i<tt->size();i+=2){
      vec[tt2].push_back((*tt)[i]);
      a[(*tt)[i]]*=2;
      a[(*tt)[i-1]]=-1;
      cntt--;
    }
    vec[i->second].clear();
  }
  printf("%d\n",cntt);
  for(int i=1;i<=n;i++){
    if(a[i]==-1){
      continue;
    }
    printf("%lld ",a[i]);
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

