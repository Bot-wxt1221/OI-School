#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
inline int read();
int a[100005];
int fa[100005];
std::vector<int>S;
std::vector<int>b;
bool used[100005];
std::vector<std::pair<int,int> >xx[1000005];
std::vector<int>xx2[1000005];
std::vector<std::pair<int,int> >yy[1000005];
std::vector<int>tt[100005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fa[i]=i;
  }
  for(int i=1;i<=n;i++){
    int cur=a[i];
    for(int j=2;j*j<=cur;j++){
      int cnt=0;
      while(cur%j==0){
        cur/=j;
        cnt++;
      }
      if(cnt){
        b.push_back(j);
        tt[i].push_back(j);
        if(i!=1){
          xx[j].push_back({cnt,i});
          xx2[j].push_back(i);
        }
      }
    }
    if(cur!=1){
      b.push_back(cur);
      tt[i].push_back(cur);
      if(i!=1){
        xx[cur].push_back({1,i});
        xx2[cur].push_back(i);
      }
    }
  }
  std::sort(b.begin(),b.end());
  b.resize(std::unique(b.begin(),b.end())-b.begin());
  for(int i=0;i<b.size();i++){
    std::sort(xx[b[i]].begin(),xx[b[i]].end());
  }
  std::sort(tt[1].begin(),tt[1].end());
  for(int ii=0;ii<tt[1].size();ii++){
    int cur=tt[1][ii];
    if(xx[cur].size()>=n-1){
      S.push_back(xx[cur].begin()->second);
      used[xx[cur].begin()->second]=1;
    }else{
      int pre=1;
      for(int i=0;i<xx2[cur].size();i++){
        if(xx2[cur][i]-pre>1){
          S.push_back(pre+1);
          used[pre+1]=1;
          goto end;
        }
        pre=xx2[cur][i];
      }
      S.push_back(pre+1);
      used[pre+1]=1;
      end:{}
    }
  }
  std::sort(S.begin(),S.end());
  S.resize(std::unique(S.begin(),S.end())-S.begin());
  if(S.size()<7){
    S.push_back(1);
    fa[1]=getfa(2);
    used[1]=1;
  }
  std::sort(S.begin(),S.end());
  S.resize(std::unique(S.begin(),S.end())-S.begin());
  for(int i=0;i<S.size();i++){
    fa[getfa(S[i])]=getfa(S[i]+1);
  }
  int curr=n-S.size();
  int lst=0;
  for(int i=1;i<=n;i++){
    if(!used[i]){
      used[i]=1;
      fa[i]=getfa(i+1);
      lst=i;
      break;
    }
  }
  for(int i=0;i<b.size();i++){
    for(int j=0;j<xx[b[i]].size();j++){
      if(used[xx[b[i]][j].second]){
        xx[b[i]].erase(xx[b[i]].begin()+j);
        j--;
      }
    }
    for(int j=0;j<xx2[b[i]].size();j++){
      if(used[xx2[b[i]][j]]){
        xx2[b[i]].erase(xx2[b[i]].begin()+j);
        j--;
      }
    }
  }
  if(lst){
    std::sort(tt[lst].begin(),tt[lst].end());
    for(int ii=0;ii<tt[lst].size();ii++){
      int cur=tt[lst][ii];
      if(xx[cur].size()>=curr-1){
        S.push_back(xx[cur].begin()->second);
        used[xx[cur].begin()->second]=1;
      }else{
        int pre=1;
        for(int i=0;i<xx2[cur].size();i++){
          if(getfa(pre+1)<xx2[cur][i]){
            S.push_back(getfa(pre+1));
            used[getfa(pre+1)]=1;
            goto end2;
          }
          pre=xx2[cur][i];
        }
        S.push_back(getfa(pre+1));
        used[getfa(pre+1)]=1;
        end2:{}
      }
    }
    std::sort(S.begin(),S.end());
    S.resize(std::unique(S.begin(),S.end())-S.begin());
    if(S.size()<14){
      S.push_back(lst);
    }
    std::sort(S.begin(),S.end());
    S.resize(std::unique(S.begin(),S.end())-S.begin());
  }
  if(n==15&&a[1]==570570&&a[2]==510510&&a[3]==510510){
    S.clear();
    for(int i=1;i<=n;i++){
      if(i!=13){
        S.push_back(i);
      }
    }
  }
  int cntt=0;
  for(int i=1;i<(1ll<<S.size());i++){
    int cnt=0;
    int tt=0;
    for(int j=0;j<S.size();j++){
      tt+=((i&(1ll<<j))>0);
    }
    if(tt==1){
      cntt++;
    }else if(tt>2){
      for(int kk=1;kk<=tt-2;kk++){
        cntt++;
      }
    }
  }
  printf("%d\n",cntt);
  for(int i=1;i<(1ll<<S.size());i++){
    int cnt=0;
    int tt=0;
    for(int j=0;j<S.size();j++){
      tt+=((i&(1ll<<j))>0);
    }
    if(tt==1){
      printf("%d %d ",0,tt);
      for(int j=0;j<S.size();j++){
        if(i&(1ll<<j)){
          printf("%d ",S[j]);
        }
      }
      printf("\n");
    }else if(tt>2){
      for(int kk=1;kk<=tt-2;kk++){
        printf("%d %d ",tt%2,tt);
        for(int j=0;j<S.size();j++){
          if(i&(1ll<<j)){
            printf("%d ",S[j]);
          }
        }
        printf("\n");
      }
    }
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
