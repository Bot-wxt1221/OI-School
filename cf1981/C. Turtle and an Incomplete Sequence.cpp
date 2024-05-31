#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
int a[200005];
int b[200005];
std::vector<int>vec;
int mx(int x){
  for(int i=60;i>=0;i--){
    if(x>=(1ll<<i)){
      return i;
    }
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    vec.clear();
    int n=read();
    for(int i=1;i<=n;i++){
      b[i]=a[i]=read();
      if(a[i]!=-1){
        vec.push_back(i);
      }
    }
    for(int i=2;i<=n;i++){
      if(a[i]*2==a[i-1]||a[i]*2+1==a[i-1]||a[i]/2==a[i-1]){
      
      }else if(a[i]!=-1&&a[i-1]!=-1){
        printf("-1\n");
        goto end;
      }
    }
    if(vec.size()==n){
      for(int i=2;i<=n;i++){
        if(a[i]*2==a[i-1]||a[i]*2+1==a[i-1]||a[i]/2==a[i-1]){
          
        }else{
          printf("-1\n");
          goto end2;
        }
      }
      for(int i=1;i<=n;i++){
        printf("%lld ",a[i]);
      }
      printf("\n");
      end2:{}
      continue;
    }
    if(vec.size()==0){
      for(int i=1;i<=n;i++){
        printf("%lld ",(1ll<<(i%2)));
      }
      printf("\n");
      continue;
    }
    for(int i=vec[0]-1;i>0;i--){
      b[i]=b[i+1]*2;
      if(b[i]>1e9){
        b[i]=b[i+1]/2;
      }
    }
    for(int i=vec[vec.size()-1]+1;i<=n;i++){
      b[i]=b[i-1]*2;
      if(b[i]>1e9){
        b[i]=b[i-1]/2;
      }
    }
    for(int i=0;i<vec.size()-1;i++){
//      vec[i] vec[i+1]
      int ta=vec[i];
      int tb=vec[i+1];
      if(ta+1==tb){
        continue;
      }
      int cur=0;
      int tt=0;
      if(b[ta]>b[tb]){
        while(mx(b[ta])!=mx(b[tb])){
          b[ta+1]=b[ta]/2;
          ta++;
        }
        if(b[tb]!=a[tb]){
          printf("-1\n");
          goto end;
        }
        int lst=0;
        if(ta==tb){
          lst=1;
        }
        while(ta<tb){
          b[ta+1]=b[ta]/2;
          b[tb-1]=b[tb]/2;
          if(b[ta]==1&&b[tb]==1){
            b[ta+1]=2;
            b[tb-1]=2;
          }
          if(b[tb]/2==b[ta]/2){
            lst=1;
          }
          ta++;
          tb--;
        }
        if(ta==tb&&lst){

        }else{
          printf("-1\n");
          goto end;
        }
      }else{
        while(mx(b[ta])!=mx(b[tb])){
          b[tb-1]=b[tb]/2;
          tb--;
        }
        if(b[ta]!=a[ta]){
          printf("-1\n");
          goto end;
        }
        int lst=0;
        if(ta==tb){
          lst=1;
        }
        while(ta<tb){
          b[ta+1]=b[ta]/2;
          b[tb-1]=b[tb]/2;
          if(b[tb]/2==b[ta]/2){
            lst=1;
          }
          if(b[ta]==1&&b[tb]==1){
            b[ta+1]=2;
            b[tb-1]=2;
          }

          ta++;
          tb--;
        }
        if(ta==tb&&lst){

        }else{
          printf("-1\n");
          goto end;
        }
      }
    }
    for(int i=2;i<=n;i++){
      if(b[i]*2==b[i-1]||b[i]*2+1==b[i-1]||b[i]/2==b[i-1]){
      }else{
        printf("-1\n");
        goto end;
      }
    }
    for(int i=1;i<=n;i++){
      if(a[i]!=-1&&a[i]!=b[i]){
        printf("-1\n");
        goto end;
      }
    }
    for(int i=1;i<=n;i++){
      printf("%lld ",b[i]);
    }
    printf("\n");
    end:{};
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

