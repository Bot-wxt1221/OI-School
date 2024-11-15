#include <iostream>
#include <cstdio>
inline int read();
int a[1000005];
int l[1000005];
int r[1000005];
int seq[1000005];
int map[5005][5005];
int cntt[1000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(seq[a[i]]==0){
      cnt++;
    }
    seq[a[i]]=i;
    cntt[a[i]]++;
  }
  for(int i=1;i<=m;i++){
    l[i]=read();
    r[i]=read();
  }
  for(int l=1;l<=n;l++){
    int cur=cnt;
    for(int r=l;r<=n;r++){
      cntt[a[r]]--;
      if(cntt[a[r]]==0){
        cur--;
      }
      cntt[a[r]+1]++;
      if(cntt[a[r]+1]==1){
        cur++;
      }
      map[l][r]=cur;
    }
    for(int r=1;r<=n+1;r++){
      cntt[r]=0;
    }
    for(int r=1;r<=n;r++){
      cntt[a[r]]++;
    }
  }
  for(int i=1;i<=m;i++){
    printf("%d\n",map[l[i]][r[i]]);
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
