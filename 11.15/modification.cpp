#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
char temp[300005];
int a[300005];
int seq[300005];
std::priority_queue<std::pair<int,int> >qu;
std::vector<int>vec;
bool removed[300005];
int mm=0;
int lst[300005];
int nxt[300005];
int val[300005];
void erase(int x){
  lst[nxt[x]]=lst[x];
  nxt[lst[x]]=nxt[x];
  removed[x]=1;
}
void solve(int l,int r,int V,int ans){
  a[mm-V]=std::min(a[mm-V],ans);
  if(l>r){
    return ;
  }
  qu=std::priority_queue<std::pair<int,int>>();
  for(int i=l;i<=r;i++){
    val[i]=seq[i];
    qu.push({-val[i],i});
    lst[i]=i-1;
    nxt[i]=i+1;
  }
  val[l-1]=val[r+1]=1e9;
  nxt[l-1]=l;
  lst[r+1]=r;
  memset(removed,0,sizeof(removed));
  for(int t=V+2;t<mm;t+=2){
    if(qu.size()==0){
      break;
    }
    auto tp=qu.top();
    if(removed[tp.second]){
      qu.pop();
      t-=2;
      continue;
    }
    qu.pop();
    ans+=-tp.first;
    int p=tp.second;
    a[mm-t]=std::min(a[mm-t],ans);
    val[p]=val[lst[p]]+val[nxt[p]]-val[p];
    if(lst[p]>=l)
      erase(lst[p]);
    if(nxt[p]<=r)
      erase(nxt[p]);
    qu.push({-val[p],p});
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("modification.in","r",stdin);
	freopen("modification.out","w",stdout);
	#endif
  int n=read();
  scanf("%s",temp+1);
  int cnt=0;
  cnt=0;
  for(int i=1;i<=n;i++){
    if(temp[i]!=temp[i-1]){
      if(cnt){
        seq[++mm]=cnt;
        cnt=0;
      }
    }
    cnt++;
  }
  if(cnt){
    seq[++mm]=cnt;
  }
  memset(a,0x3f,sizeof(a));
  solve(2,mm-1,0,0);
  solve(3,mm-1,1,seq[1]);
  solve(2,mm-2,1,seq[mm]);
  if(mm>2){
    solve(3,mm-2,2,seq[1]+seq[mm]);
  }
  cnt=0;
  a[0]=a[1]=0x3f3f3f3f;
  a[2]=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    if(temp[i]=='1'){
      cnt++;
    }
  }
  a[2]=std::min(a[2],n-cnt);
  for(int i=1;i<=n;i++){
    if(temp[i]=='0'){
      cnt++;
    }else{
      cnt--;
    }
    a[2]=std::min(a[2],n-cnt);
  }
  a[0]=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    a[i]=std::min(a[i],a[i-1]);
    if(i>1){
      printf("%d ",n-a[i]);
    }
  }
  printf("%d",n);
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
