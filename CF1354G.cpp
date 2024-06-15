#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp[15];
char query(std::vector<int>vec,std::vector<int>vec2){
  printf("? %lu %lu\n",vec.size(),vec2.size());
  for(int i=0;i<vec.size();i++){
    printf("%d ",vec[i]);
  }
  printf("\n");
  for(int i=0;i<vec2.size();i++){
    printf("%d ",vec2[i]);
  }
  printf("\n");
  fflush(stdout);
  scanf("%s",temp+1);
  return temp[1];
}
bool check(int st,int t){
  std::vector<int>a,b;
  for(int i=1;i<=t-st+1;i++){
    a.push_back(i);
  }
  for(int i=st;i<=t;i++){
    b.push_back(i);
  }
  return query(a,b)=='F';
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int k=read();
    int r=1,l,st;
    for(int i=1;i<=30;i++){
      int nxt=rand()%n+1;
      if(nxt==1){
        i--;
        continue;
      }
      if(query({1},{nxt})=='S'){
        printf("! %d\n",1);
        fflush(stdout);
        goto end;
      }
    }
    while(2*r<=n){
      std::vector<int> a,b;
      for(int i=1;i<=r;i++){
        a.push_back(i);
      }
      for(int i=r+1;i<=2*r;i++){
        b.push_back(i);
      }
      if(query(a,b)!='E'){
        break;
      }
      r*=2;
    }
    st=r+1;
    l=r+1;
    r=std::min(2*r,n);
    while(r-l>3){
      int mid=(l+r)/2;
      if(check(st,mid)){
        r=mid;
      }else{
        l=mid;
      }
    }
    for(int i=l;i<=r;i++){
      if(check(st,i)){
        printf("! %d\n",i);
        fflush(stdout);
        goto end;
      }
    }
    end:{}
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

