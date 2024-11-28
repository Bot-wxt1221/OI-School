#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
char temp[100005];
int sum1[100005];
int sum2[100005];
int st[100005][30];
int nxt[100005];
int pre[100005];
int calc(int pos,int l,int r){
  if(pos>r||pos<l){
    return 0;
  }
  int t1=sum1[pos-1]-sum1[l-1];
  int t2=sum2[r]-sum2[pos];
  return 1+std::min(t1,t2)*2;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int q=read();
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    sum1[i]=sum1[i-1];
    sum2[i]=sum2[i-1];
    if(temp[i]=='1'){
      sum1[i]++;
      nxt[i]=n+1;
    }else if(temp[i]=='2'){
      sum2[i]++;
      nxt[i]=n+1;
    }else{
      pre[i]=nxt[i]=i;
    }
  }
  nxt[n+1]=n+1;
  for(int i=1;i<=n;i++){
    pre[i]=std::max(pre[i],pre[i-1]);
  }
  for(int i=n;i>=1;i--){
    nxt[i]=std::min(nxt[i],nxt[i+1]);
  }
  for(int i=1;i<=q;i++){
    int ll=read();
    int rr=read();
    int l=ll;
    int r=rr;
    while(r-l>3){
      int mid=(l+r)/2;
      if(sum1[mid-1]-sum1[ll-1]>sum2[rr]-sum2[mid]){
        r=mid+1;
      }else{
        l=mid-1;
      }
    }
    int ans=0;
    for(int j=l;j<=r;j++){
      ans=std::max(ans,calc(pre[j],ll,rr));
      ans=std::max(ans,calc(nxt[j],ll,rr));
    }
    printf("%d\n",ans);
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
