#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
inline int read();
char temp[400005];
int height[400005];
int rk[2][400005];
int sa[400005];
std::vector<int>vec[400005],vec2[400005];
int st[25][400005];
int query(int l,int r){
  if(l==r){
    return 100000;
  }
  if(l>r){
    std::swap(l,r);
  }
  l++;
  int siz=r-l+1;
  int tt=std::log2(siz);
  return std::min(st[tt][l],st[tt][r-(1<<tt)+1]);
}
class heap{
public:
  std::priority_queue<int>a,b;
  void insert(int x){
    a.push(x);
    return ;
  }
  void del(int x){
    b.push(x);
  }
  int top(){
    process();
    return a.top();
  }
private:
  void process(){
    while(a.size()>0&&b.size()>0&&a.top()==b.top()){
      a.pop();
      b.pop();
    }
    return ;
  }
}A;
std::set<std::pair<int,bool> >se;
void add(std::set<std::pair<int,bool> >::iterator a){
  auto pre=a;
  pre--;
  if(a!=se.begin()&&pre->second!=a->second){
    A.insert(query(pre->first,a->first));
  }
  auto suf=a;
  suf++;
  if(suf!=se.end()&&suf->second!=a->second){
    A.insert(query(a->first,suf->first));
  }
  if(a!=se.begin()&&suf!=se.end()&&pre->second!=suf->second){
    A.del(query(pre->first,suf->first));
  }
  return ;
}
void remove(std::set<std::pair<int,bool> >::iterator a){
  auto pre=a;
  pre--;
  if(a!=se.begin()&&pre->second!=a->second){
    A.del(query(pre->first,a->first));
  }
  auto suf=a;
  suf++;
  if(suf!=se.end()&&suf->second!=a->second){
    A.del(query(a->first,suf->first));
  }
  if(a!=se.begin()&&suf!=se.end()&&pre->second!=suf->second){
    A.insert(query(pre->first,suf->first));
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int id=read();
  int n=read()+1;
  int q=read();
  scanf("%s",temp+1);
  temp[n]='c';
  int tn=n;
  int tt=1;
  while(tt<n){
    tt*=2;
  }
  n=tt;
  int op=0;
  for(int i=1;i<=n;i++){
    rk[op][i]=temp[i];
  }
  for(int i=2;i<=n;(i=(i<<1))){
    op^=1;
    int mx=0;
    for(int j=1;j<=n;j++){
      vec[rk[op^1][j+i/2]].push_back(j);
      mx=std::max(mx,rk[op^1][j+i/2]);
    }
    int mx2=0;
    for(int j=0;j<=mx;j++){
      for(int k=0;k<vec[j].size();k++){
        vec2[rk[op^1][vec[j][k]]].push_back(vec[j][k]);
        mx2=std::max(mx2,rk[op^1][vec[j][k]]);
      }
    }
    int cnt=0;
    for(int j=0;j<=mx2;j++){
      vec[j].clear();
      for(int k=0;k<vec2[j].size();k++){
        cnt++;
        rk[op][vec2[j][k]]=cnt;
        if(k!=0&&rk[op^1][vec2[j][k]+i/2]==rk[op^1][vec2[j][k-1]+i/2]){
          rk[op][vec2[j][k]]=rk[op][vec2[j][k-1]];
        }
      }
      vec2[j].clear();
    }
  }
  for(int i=1;i<=n;i++){
    rk[op][i]-=n-tn;
  }
  for(int i=1;i<=n;i++){
    if(rk[op][i]>=0){
      sa[rk[op][i]]=i;
    }
  }
  for(int i=1,k=0;i<=tn;i++){
    if(rk[op][i]==0){
      continue;
    }
    if(k){
      k--;
    }
    while(temp[i+k]==temp[sa[rk[op][i]-1]+k]){
      k++;
    }
    height[rk[op][i]]=k;
    rk[op^1][i]=rk[op][i];
  }
  for(int i=1;i<=n;i++){
    st[0][i]=height[i];
  }
  for(int k=1;k<=20;k++){
    for(int i=1;i+(1<<k)-1<=n;i++){
      st[k][i]=std::min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
    }
  }
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    int ans=1;
    se.clear();
    A=heap();
    A.insert(0);
    for(int j=l;j<=r;j++){
      se.insert({rk[0][j],1});
    }
    int anss=0;
    add(se.insert({rk[0][l],0}).first);
    for(int p=l;p<=r;p++){
      if(p!=l){
        add(se.insert({rk[0][p-ans+1],0}).first);
        auto tt=se.find({rk[0][p-1],1});
        if(tt!=se.end()){
          remove(tt);
          se.erase(tt);
        }
      }
      if(A.top()<ans){
        ans--;
        if(ans>0){
          add(se.insert({rk[0][p-ans+1],0}).first);
          add(se.insert({rk[0][r-ans+1],1}).first);
        }
        ans=std::max(ans,1);
      }else{
        auto tt=se.find({rk[0][p-ans+1],0});
        remove(tt);
        se.erase(tt);
        tt=se.find({rk[0][r-ans+1],1});
        remove(tt);
        se.erase(tt);
        if(A.top()>=ans+1){
          ans++;
          goto end;
        }
        add(se.insert({rk[0][p-ans+1],0}).first);
        add(se.insert({rk[0][r-ans+1],1}).first);
      }
      end:{}
      anss^=(p-l+1+ans);
    }
    printf("%d\n",anss);
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
