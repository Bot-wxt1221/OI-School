#include <ctime>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
inline int read();
std::unordered_map<int,int>mp[65],mp2[2];
int a[300005];
int seq[300005];
int m;
std::vector<int>vec[300005][2];
std::vector<int>* get(int s,int op){
  return &(vec[std::lower_bound(seq+1,seq+m+1,s)-seq][op]);
}
class prio_que{
  public:
    std::priority_queue<int>qu,qu2;
    void clear(){
      while(qu.size()>0&&qu2.size()>0&&qu.top()==qu2.top()){
        qu.pop();
        qu2.pop();
      }
      return ;
    }
    int top(){
      clear();
      return -qu.top();
    }
    int second(){
      int temp=top();
      qu.pop();
      int ret=top();
      qu.push(-temp);
      return ret;
    }
    void push(int x){
      qu.push(-x);
      return ;
    }
    void pop(int t){
      qu2.push(-t);
      return ;
    }
}qu[2];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("roast.in","r",stdin);
  freopen("roast.out","w",stdout);
  #endif
  int n=read();
  m=n;
  if(n==1){
    printf("1");
    return 0;
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
    seq[i]=a[i];
  }
  std::sort(seq+1,seq+n+1);
  if(seq[1]==seq[n]){
    for(int i=1;i<=n;i++){
      printf("%d ",i);
    }
    return 0;
  }
  m=std::unique(seq+1,seq+n+1)-seq-1;
  m++;
  int tt=0;
  for(int i=1;i<n;i++){
    tt=std::max(tt,a[i]^a[i+1]);
  }
  tt=std::log2(tt);
  for(int i=1;i<=n;i++){
    if(a[i]&(1<<tt)){
      for(int j=31;j>=0;j--){
        if(mp[j][a[i]>>j]==0){
          mp[j][(a[i]>>j)]=i;
        }
      }
      mp2[1][a[i]]++;
    }else{
      mp2[0][a[i]]++;
    }
  }
  int mn=0x7f7f7f7f;
  int cnt0=0,cnt1=0;
  int key=0;
  for(int i=1;i<=n;i++){
    if(a[i]&(1<<tt)){
      get(a[i],1)->push_back(i);
      cnt1++;
      qu[1].push(i);
    }else{
      get(a[i],0)->push_back(i);
      cnt0++;
      qu[0].push(i);
      int lst=0;
      for(int j=31;j>=0;j--){
        lst|=(a[i]&(1ll<<j));
        if(mp[j][lst>>(j)]==0){
          lst^=(1ll<<j);
        }
      }
      mn=std::min(mn,a[i]^lst);
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]&(1<<tt)){
      key+=mp2[0][a[i]^mn];
    }else{
    }
  }
  int cur,sta;
  for(int i=1;i<=n;i++){
    if(a[i]&(1<<tt)){
      if(mp2[0][a[i]^mn]!=key){
        cur=i;
        sta=1;
        break;
      }else if(cnt1==1){
        cur=i;
        sta=1;
        break;
      }
    }else{
      if(mp2[1][a[i]^mn]!=key){
        cur=i;
        sta=0;
        break;
      }else if(cnt0==1){
        cur=i;
        sta=0;
        break;
      }
    }
  }
  mp2[sta][a[cur]]--;
  auto temp=get(a[cur],sta);
  key-=mp2[sta^1][a[cur]^mn];
  temp->erase(temp->begin());
  qu[sta].pop(cur);
  printf("%d ",cur);
  cur=a[cur];
  for(int loooo=1;loooo<n;loooo++){
    if(sta){
      int mnc=0x7f7f7f7f;
      if(cnt1==1){
        
      }else{
        int tp=qu[1].top();
        if(mp2[0][a[tp]^mn]!=key||key==0||cnt1==2){
          mnc=std::min(qu[1].top(),mnc);
        }else{
          mnc=std::min(mnc,qu[1].second());
        }
      }
      cnt1--;
      temp=get(cur^mn,0);
      if(mp2[0][cur^mn]&&temp->size()!=0){
        int tt=*temp->begin();
        auto tt2=temp->begin();
        if(mp2[1][a[tt]^mn]==key&&key!=0&&cnt0>1){
          if(temp->size()==1){
            goto end3;
          }
          tt=*(temp->begin()+1);
          tt2=temp->begin()+1;
        }
        if(tt<mnc){
          mp2[0][cur^mn]--;
          int &ti=tt;
          printf("%d ",tt);
          temp->erase(tt2);
          key-=mp2[1][cur];
          cur=cur^mn;
          sta=0;
          qu[0].pop(ti);
          goto end;
        }
        end3:{}
      }
      if(cnt1==0){
        goto end;
      }
      mp2[1][a[mnc]]--;
      temp=get(a[mnc],1);
      for(int i=0;i<temp->size();i++){
        if((*temp)[i]==mnc){
          qu[1].pop((*temp)[i]);
          temp->erase(temp->begin()+i);
          break;
        }
      }
      cur=a[mnc];
      key-=mp2[0][a[mnc]^mn];
      sta=1;
      printf("%d ",mnc);
      end:{}
    }else{
      int mnc=0x3f3f3f3f;
      if(cnt0==1){
        goto tt;
      }else{
        int tp=qu[0].top();
        if(mp2[1][a[tp]^mn]!=key||key==0||cnt0==2){
          mnc=std::min(mnc,qu[0].top());
        }else{
          mnc=std::min(qu[0].second(),mnc);
        }
      }
      tt:{}
      cnt0--;
      temp=get(cur^mn,1);
      if(mp2[1][cur^mn]&&temp->size()!=0){
        int tt=*temp->begin();
        auto tt2=temp->begin();
        if(mp2[0][a[tt]^mn]==key&&key!=0&&cnt1>1){
          if(temp->size()==1){
            goto end4;
          }
          tt=*(temp->begin()+1);
          tt2=temp->begin();
        }
        if(tt<mnc){
          mp2[1][cur^mn]--;
          int &ti=tt;
          printf("%d ",tt);
          temp->erase(tt2);
          key-=mp2[0][cur];
          cur=cur^mn;          
          sta=1;
          qu[1].pop(ti);
          goto end2;
        }
        end4:{}
      }
      if(cnt0==0){
        goto end2;
      }
      mp2[0][a[mnc]]--;
      temp=get(a[mnc],0);
      for(int i=0;i<temp->size();i++){
        if((*temp)[i]==mnc){
          qu[0].pop((*temp)[i]);
          temp->erase(temp->begin()+i);
          break;
        }
      }
      cur=a[mnc];
      sta=0;
      key-=mp2[1][a[mnc]^mn];
      printf("%d ",mnc);
      end2:{}
    }
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
