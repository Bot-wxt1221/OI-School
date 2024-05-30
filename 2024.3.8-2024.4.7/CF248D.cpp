#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
char temp[5000005];
std::queue<int>qu;
int n,t,ttt,lsts;
bool check(int k){
  qu=std::queue<int>();
  int tot=0;
  int uu=0;
  int pos=0;
  int endp=0;
  int used=k;
  while(endp<n&&used<ttt){
    used+=(temp[++endp]=='S');
  }
  while(endp+1<=lsts){
    endp++;
  }
  for(int i=1;i<=endp&&uu<ttt;i++){
    tot++;
    if(temp[i]=='S'){
      k++;
      if(k==0){
        if(lsts==pos){
          tot+=(i-pos);
        }else{
          tot+=(i-pos)*2;
        }
        pos=0;
      }
    }else if(temp[i]=='H'){
      if(k>0){
        k--;
        uu++;
      }else if(pos==0){
        pos=i;
        if(tot+2*(endp-i)<=t){
          return 1;
        }
        k--;
      }else{
        k--;
      }
    }
  }
  return qu.size()==0&&tot<=t;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  t=read();
  scanf("%s",temp+1);
  while(temp[n]=='.'||temp[n]=='\0'){
    n--;
  }
  int tttt=0;
  for(int i=1;i<=n;i++){
    if(temp[i]=='H'){
      ttt++;
      lsts=i;
    }else if(temp[i]=='S'){
      tttt++;
    }
  }
  int l=std::max(0,ttt-tttt),r=5e5;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      r=mid+1;
    }else{
      l=mid-1;
    }
  }
  for(int i=l;i<=r;i++){
    if(check(i)){
      printf("%d",i);
      return 0;
    }
  }
  printf("-1");
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


