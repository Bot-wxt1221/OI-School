#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
char temp[500005];
int dis[500005];
char nw[500005];
int ans[500005];
int tans[500005];
int to[500005];
std::vector<int>vec;
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[500005*2];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=1000000){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x){
    while(x<=1000000){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}a,b;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  scanf("%s",temp+1);
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(temp[i]=='O'){
      vec.push_back(i);
    }
  }
  for(int i=1;i<vec.size();i++){
//    vec[i-1] vec[i]
    int cur=0;
    for(int j=vec[i]-1;j>vec[i-1];j--){
      tans[j]=cur;
      cur+=(temp[j]=='L');
    }
    cur=0;
    for(int j=vec[i-1]+1;j<vec[i];j++){
      if(tans[j]==cur){
        to[j]=(temp[j]=='L');
      }else if(tans[j]<cur){
        to[j]=0;
      }else{
        to[j]=1;
      }
      tans[j]=std::min(tans[j],cur);
      tans[j]+=((temp[j]=='L')!=to[j]);
      cur+=(temp[j]=='R');
    }
    int cnt=0;
    int ans=0;
    int pre=vec[i-1];
    for(int j=vec[i-1]+1;j<vec[i];j++){
      if(to[j]==1){
        ::ans[j]+=a.query(cnt);
        ::ans[j]+=(j-pre)*(2*cnt+1);
      }else if(tans[j]){
        ::ans[j]+=a.query(cnt)-a.query(cnt-tans[j]+1);
        ::ans[j]-=(b.query(cnt)-b.query(cnt-tans[j]+1))*(2*cnt-1-2*(tans[j]-1));
        ::ans[j]+=(j-pre)*(2*(tans[j]));
      }
      if(temp[j]=='R'){
        cnt++;
        a.mod(cnt,(j-pre)*(2*cnt-1));
        b.mod(cnt,(j-pre));
        if(temp[pre]=='R'){
          ans+=(j-pre);
        }
        pre=j;
      }
    }
    for(int j=1;j<=cnt;j++){
      a.clear(j);
      b.clear(j);
    }
    pre=vec[i];
    cnt=0;
    for(int j=vec[i]-1;j>vec[i-1];j--){
      if(to[j]==0){
        ::ans[j]+=a.query(cnt);
        ::ans[j]+=(pre-j)*(2*cnt+1);
      }else if(tans[j]){
        ::ans[j]+=a.query(cnt)-a.query(cnt-tans[j]+1);
        ::ans[j]-=(b.query(cnt)-b.query(cnt-tans[j]+1))*(2*cnt-1-2*(tans[j]-1));
        ::ans[j]+=(pre-j)*(2*(tans[j]));
      }
      if(temp[j]=='L'){
        cnt++;
        a.mod(cnt,(pre-j)*(2*cnt-1));
        b.mod(cnt,(pre-j));
        if(temp[pre]=='L'){
          ans+=(pre-j);
        }
        pre=j;
      }
    }
    for(int j=1;j<=cnt;j++){
      a.clear(j);
      b.clear(j);
    }
  }
  for(int i=1;i<=n;i++){
    printf("%lld ",ans[i]);
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
