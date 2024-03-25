#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
char temp[5000005];
std::stack<int>bk1,bk2;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),a,b;
  a=read();
  b=read();
  scanf("%s",temp+1);
  a=std::min(a,b*2);
  int sum=0;
  int ans=0;
  int cnt1=0;
  n*=2;
  for(int i=1;i<=n;i++){
    cnt1+=(temp[i]=='(');
  }
  if(cnt1<n/2){
    for(int i=1;i<=n&&cnt1<n/2;i++){
      if(temp[i]==')'){
        temp[i]='(';
        cnt1++;
        ans+=b;
      }
    }
  }
  if(cnt1>n/2){
    for(int i=n;i>=1&&cnt1>n/2;i--){
      if(temp[i]=='('){
        cnt1--;
        temp[i]=')';
        ans+=b;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(temp[i]=='('){
      bk1.push(i);
    }
  }
  sum=0;
  for(int i=1;i<=n;i++){
    if(temp[i]=='('){
      sum++;
    }else{
      sum--;
    }
    if(sum<0){
      int tt=bk1.top();
      std::swap(temp[i],temp[tt]);
      sum+=2;
      ans+=a;
    }
  }
  printf("%lld",ans);
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

