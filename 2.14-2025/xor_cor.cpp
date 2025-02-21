#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
#define int long long
inline int read();
int a[300005];
int ins[65];
int sum[65];
std::deque<int>qu;
bool insert(int x){
  for(int i=32;i>=0;i--){
    if(x&(1ll<<i)){
      if(ins[i]==0){
        ins[i]=x;
        for(int j=32;j>i;j--){
          sum[j]++;
        }
        return true;
      }else{
        x^=ins[i];
      }
    }
  }
  return false;
}
int query(int x){
  if(x==0x3f3f3f3f){
    return x;
  }
  int ans=0;
  for(int i=32;i>=0;i--){
    if(ins[i]==0){
      continue;
    }
    if(x>(1ll<<(sum[i]+1))){
      return 0x3f3f3f3f;
    }
    if(x>(1ll<<sum[i])){
      x-=(1ll<<sum[i]);
      if(!(ans&(1ll<<i))){
        ans^=ins[i];
      }
    }else{
      if(ans&(1ll<<i)){
        ans^=ins[i];
      }
    }
  }
  return ans;
}
int find(int x){
  if(x<0){
    return 1;
  }
  int cur=0;
  int lst=-1;
  for(int i=32;i>=0;i--){
    if(((cur&(1ll<<i))>(x&(1ll<<i)))||(ins[i]&&!(x&(1ll<<i)))){
      lst=i;
    }
    if((cur&(1ll<<i))!=(x&(1ll<<i))){
      cur^=ins[i];
    }
    if((x&(1ll<<i))>(cur&(1ll<<i))){
      return 0x3f3f3f3f;
    }
  }
  cur=0;
  for(int i=32;i>lst;i--){
    if((cur&(1ll<<i))!=(x&(1ll<<i))){
      cur^=ins[i];
    }
  }
  if(lst==-1){
    return 0x3f3f3f3f;
  }
  if(((cur&(1ll<<lst))>(x&(1ll<<lst)))){

  }else{
    cur^=ins[lst];
    if(ins[lst]==0){
      return 0x3f3f3f3f;
    }
  }
  for(int i=lst-1;i>=0;i--){
    if(cur&(1ll<<i)){
      cur^=ins[i];
    }
  }
  int ans=1;
  for(int i=32;i>=0;i--){
    if(ins[i]&&cur&(1ll<<i)){
      ans+=(1ll<<sum[i]);
    }
  }
  return ans;
}
std::vector<int>vec;
int dp[55][300005];
int temp[300005];
int seq[300005];
int queryxor(int x,int y){
  int mn=0x3f3f3f3f;
  int lst=0;
  int cur=0;
  for(int i=32;i>=0;i--){
   if(!(y&(1ll<<i))){
      bool a=0;
      if(!((cur^x)&(1ll<<i))){
        a=1;
        cur^=ins[i];
        if(ins[i]==0){
          goto end3;
        }
      }
      lst=i;
      end3:{}
      if(a){
        cur^=ins[i];
      }
    }
    if((y&(1ll<<i))!=((cur^x)&(1ll<<i))){
      if(!ins[i]){
        goto end2;
      }
      cur^=ins[i];
    }
  }
  end2:{}
  for(int i=lst;i<=lst;i++){
   if(y&(1ll<<i)){
      continue;
    }
    int ans=0;
    for(int j=32;j>i;j--){
      if((y&(1ll<<j))!=((ans^x)&(1ll<<j))){
        if(!ins[j]){
          goto end;
        }
        ans^=ins[j];
      }
    }
    if(!((ans^x)&(1ll<<i))){
      ans^=ins[i];
      if(ins[i]==0){
        goto end;
      }
    }
    for(int j=i-1;j>=0;j--){
      if((ans^x)&(1ll<<j)){
        ans^=ins[j];
      }
    }
    mn=std::min(mn,ans^x);
    return mn;
    end:{}
  }
  return mn;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  vec.push_back(1);
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(insert(a[i])){
      vec.push_back(i);
    }
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0][1]=a[1];
  dp[0][0]=-0x3f3f3f3f;
  vec.push_back(n);
  memset(ins,0,sizeof(ins));
  memset(sum,0,sizeof(sum));
  vec.resize(std::unique(vec.begin(),vec.end())-vec.begin());
  insert(a[1]);
  insert(1ll<<32);
  for(int i=0;i<vec.size()-1;i++){
    memset(temp,0x3f,sizeof(temp));
    for(int j=0;j<=n;j++){
      int tt=find(dp[i][j]);
      seq[j]=tt;
    }
    qu.clear();
    for(int j=0;j<=n;j++){
      int cur=seq[j]-j;
      if(seq[j]!=0x3f3f3f3f){
        while(qu.size()>0&&seq[qu.back()]-qu.back()>=cur){
          qu.pop_back();
        }
        qu.push_back(j);
      }
      while(qu.size()>0&&j-qu.front()>vec[i+1]-vec[i]-1){
        qu.pop_front();
      }
      if(qu.size()>0){
        temp[j]=query(j+seq[qu.front()]-qu.front()-1);
      }
    }
    queryxor(4,2);
    for(int j=0;j<=n;j++){
     dp[i+1][j]=std::min(temp[j],j>0?(queryxor(a[vec[i+1]],temp[j-1])):0x3f3f3f3f);
    }
    insert(a[vec[i+1]]);
  }
  int mx=0;
  for(int i=n;i>=1;i--){
    if(dp[vec.size()-1][i]!=0x3f3f3f3f){
      printf("%lld",i);
      return 0;
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
