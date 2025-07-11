#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
inline int read();
char temp[3005];
int map[3005][3005];
int prei[3005][3005];
int nxti[3005][3005];
int prej[3005][3005];
int nxtj[3005][3005];
int n,m;
void updatei(int i){
  for(int j=1;j<=m;j++){
    prei[i][j]=(map[i][j]==0)?j:prei[i][j-1];
  }
  nxti[i][m+1]=m+1;
  for(int j=m;j>=1;j--){
    nxti[i][j]=(map[i][j]==0)?j:nxti[i][j+1];
  }
  return ;
}
void updatej(int j){
  for(int i=1;i<=n;i++){
    prej[i][j]=(map[i][j]==0)?i:prej[i-1][j];
  }
  nxtj[n+1][j]=n+1;
  for(int i=n;i>=1;i--){
    nxtj[i][j]=(map[i][j]==0)?i:nxtj[i+1][j];
  }
  return ;
}
int solve1(int x,int y){
  int ql=1;
  int qr=m;
  std::priority_queue<std::pair<int,int> >qu;
  std::set<int>se;
  int ans=0;
  for(int j=1;j<=m;j++){
    qu.push({prej[x][j],j});
    se.insert(j);
  }
  for(int i=x;i>=1;i--){
    while(qu.size()>0&&qu.top().first>=i){
      se.erase(qu.top().second);
      qu.pop();
    }
    auto a=se.upper_bound(std::max(prei[i][y],prei[x][y]));
    auto b=se.lower_bound(std::min(nxti[i][y],nxti[x][y]));
    if(a!=se.end()&&b!=se.begin()){
      b--;
      if((*a)<=y&&y<=(*b)){
        ans=std::max(ans,((*b)-(*a)+1)*(x-i+1));
      }
    }
  }
  return ans;
}
int solve2(int x,int y){
  int ql=1;
  int qr=m;
  std::priority_queue<std::pair<int,int> >qu;
  std::set<int>se;
  int ans=0;
  for(int j=1;j<=m;j++){
    qu.push({-nxtj[x][j],j});
    se.insert(j);
  }
  for(int i=x;i<=n;i++){
    while(qu.size()>0&&-qu.top().first<=i){
      se.erase(qu.top().second);
      qu.pop();
    }
    auto a=se.upper_bound(std::max(prei[i][y],prei[x][y]));
    auto b=se.lower_bound(std::min(nxti[i][y],nxti[x][y]));
    if(a!=se.end()&&b!=se.begin()){
      b--;
      if((*a)<=y&&y<=(*b)){
        ans=std::max(ans,((*b)-(*a)+1)*(i-x+1));
      }
    }
  }
  return ans;
}
int solve3(int x,int y){
  int ql=1;
  int qr=n;
  std::priority_queue<std::pair<int,int> >qu;
  std::set<int>se;
  int ans=0;
  for(int j=1;j<=n;j++){
    qu.push({prei[j][y],j});
    se.insert(j);
  }
  for(int i=y;i>=1;i--){
    while(qu.size()>0&&qu.top().first>=i){
      se.erase(qu.top().second);
      qu.pop();
    }
    auto a=se.upper_bound(std::max(prej[x][i],prej[x][y]));
    auto b=se.lower_bound(std::min(nxtj[x][i],nxtj[x][y]));
    if(a!=se.end()&&b!=se.begin()){
      b--;
      if((*a)<=x&&x<=(*b)){
        ans=std::max(ans,((*b)-(*a)+1)*(y-i+1));
      }
    }
  }
  return ans;
}
int solve4(int x,int y){
  int ql=1;
  int qr=n;
  std::priority_queue<std::pair<int,int> >qu;
  std::set<int>se;
  int ans=0;
  for(int j=1;j<=n;j++){
    qu.push({-nxti[j][y],j});
    se.insert(j);
  }
  for(int i=y;i<=m;i++){
    while(qu.size()>0&&-qu.top().first<=i){
      se.erase(qu.top().second);
      qu.pop();
    }
    auto a=se.upper_bound(std::max(prej[x][i],prej[x][y]));
    auto b=se.lower_bound(std::min(nxtj[x][i],nxtj[x][y]));
    if(a!=se.end()&&b!=se.begin()){
      b--;
      if((*a)<=x&&x<=(*b)){
        ans=std::max(ans,((*b)-(*a)+1)*(i-y+1));
      }
    }
  }
  return ans;
}
signed main(){
	freopen("wall.in","r",stdin);
	freopen("wall.out","w",stdout);
  n=read();
  m=read();
  int q=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    for(int j=1;j<=m;j++){
      map[i][j]=(temp[j]=='.');
    }
    updatei(i);
  }
  for(int j=1;j<=m;j++){
    updatej(j);
  }
  for(int i=1;i<=q;i++){
    int op=read();
    int x=read();
    int y=read();
    if(op==1){
      map[x][y]^=1;
      updatei(x);
      updatej(y);
    }
    if(op==2){
      if(map[x][y]==0){
        printf("0\n");
      }else{
        int ans=0;
        ans=std::max(ans,solve1(x,y));
        ans=std::max(ans,solve2(x,y));
        ans=std::max(ans,solve3(x,y));
        ans=std::max(ans,solve4(x,y));
        printf("%d\n",ans);
      }
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
