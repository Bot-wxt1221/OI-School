#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <queue>
inline int read();
int seq[1000005];
std::pair<int,int> seq3[1000005];
int seq2[1000005];
std::vector<std::pair<int,int> > vec;
std::unordered_set<int> mp[1000005];
std::priority_queue<std::pair<long long,std::pair<int,int> > >qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    seq3[i].first=seq[i]=read();
    seq3[i].second=i;
  }
  std::sort(seq3+1,seq3+n+1);
  for(int i=1;i<=n;i++){
    seq[i]=seq3[i].first;
  }
  if(seq[n]<0){
    for(int i=1;i<=n;i++){
      seq[i]*=-1;
    }
    std::reverse(seq+1,seq+n+1);
    std::reverse(seq3+1,seq3+n+1);
  }
  for(int i=1;i<=n;i++){
    seq2[i]=seq[n-i+1];
  }
  if(seq[1]>0){
    long long ans=0;
    for(int i=2;i<=n;i++){
      ans+=1ll*seq[1]*seq[i];
      vec.push_back({1,i});
      if(i!=n){
        qu.push({-1ll*seq[i]*seq[i+1],{i,i+1}});
      }
    }
    int lf=m-n+1;
    while(qu.size()>0&&lf){
      lf--;
      auto tp=qu.top().second;
      vec.push_back({tp.first,tp.second});
      ans+=-qu.top().first;
      qu.pop();
      tp.second++;
      if(tp.second>n){
        continue;
      }
      qu.push({-1ll*seq[tp.first]*seq[tp.second],{tp.first,tp.second}});
    }
    printf("%lld\n",ans);
    for(int i=0;i<vec.size();i++){
      printf("%d %d\n",seq3[vec[i].first].second,seq3[vec[i].second].second);
    }
    return 0;
  }
  long long ans=1ll*seq[1]*seq[n];
  vec.push_back({1,n});
  mp[n].insert(1);
  mp[1].insert(n);
  qu.push({-1ll*seq[1]*seq[n-1],{1,n-1}});
  qu.push({-1ll*seq[n]*seq[2],{n,2}});
  for(int i=2;i<n;i++){
    if(seq[i]>0){
      ans+=1ll*seq[i]*seq[1];
      vec.push_back({1,i});
      mp[1].insert(i);
      mp[i].insert(1);
      if(i==2&&n>=3){
        qu.push({-1ll*seq[i]*seq[3],{i,3}});
      }else if(i!=2){
        qu.push({-1ll*seq[i]*seq[2],{i,2}});
      }
    }else{
      ans+=1ll*seq[i]*seq[n];
      vec.push_back({n,i});
      mp[n].insert(i);
      mp[i].insert(n);
      if(i==n-1&&n>=3){
        qu.push({-1ll*seq[i]*seq[n-2],{i,n-2}});
      }else if(i!=n-1){
        qu.push({-1ll*seq[i]*seq[n-1],{i,n-1}});
      }
    }
  }
  int ls=m-n+1;
  int cnt=0;
  while(qu.size()>0&&ls>0){
    cnt++;
    ls--;
    auto tp=qu.top().second;
    long long ff=-qu.top().first;
    qu.pop();
    if(mp[tp.first].find(tp.second)!=mp[tp.first].end()||tp.first==tp.second){
      ls++;
      if(seq[tp.first]>0){
        tp.second++;
        while(mp[tp.first].find(tp.second)!=mp[tp.first].end()||tp.first==tp.second){
          tp.second++;
        }
      }else{
        tp.second--;
        while(mp[tp.first].find(tp.second)!=mp[tp.first].end()||tp.first==tp.second){
          tp.second--;
        }
      }
      if(tp.second<=0||tp.second>n){
        continue;
      }
      qu.push({-1ll*seq[tp.first]*seq[tp.second],{tp.first,tp.second}});
      continue;
    }
    ans+=ff;
    vec.push_back({tp.first,tp.second});
    mp[tp.first].insert(tp.second);
    mp[tp.second].insert(tp.first);
    if(seq[tp.first]>0){
      tp.second++;
      while(mp[tp.first].find(tp.second)!=mp[tp.first].end()||tp.first==tp.second){
        tp.second++;
      }
    }else{
      tp.second--;
      while(mp[tp.first].find(tp.second)!=mp[tp.first].end()||tp.first==tp.second){
        tp.second--;
      }
    }
    if(tp.second<=0||tp.second>n){
      continue;
    }
    qu.push({-1ll*seq[tp.first]*seq[tp.second],{tp.first,tp.second}});
  }
  printf("%lld\n",ans);
  for(int i=0;i<vec.size();i++){
    printf("%d %d\n",seq3[vec[i].first].second,seq3[vec[i].second].second);
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
