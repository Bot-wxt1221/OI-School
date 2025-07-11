#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
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
  int ql=prei[x][y];
  int qr=nxti[x][y];
  std::vector<std::pair<int,int> >pa;
  std::set<int>se;
  int ans=0;
  for(int j=ql;j<=qr;j++){
    pa.push_back({prej[x][j],j});
    se.insert(j);
  }
  std::sort(pa.begin(),pa.end());
  for(int i=x;i>=1;i--){
    while(pa.size()>0&&pa.back().first>=i){
      se.erase(pa.back().second);
      pa.pop_back();
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
  int ql=prei[x][y];
  int qr=nxti[x][y];
  std::vector<std::pair<int,int> >pa;
  std::set<int>se;
  int ans=0;
  for(int j=ql;j<=qr;j++){
    pa.push_back({-nxtj[x][j],j});
    se.insert(j);
  }
  std::sort(pa.begin(),pa.end());
  for(int i=x;i<=n;i++){
    while(pa.size()>0&&-pa.back().first<=i){
      se.erase(pa.back().second);
      pa.pop_back();
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
  int ql=prej[x][y];
  int qr=nxtj[x][y];
  std::vector<std::pair<int,int> >pa;
  std::set<int>se;
  int ans=0;
  for(int j=ql;j<=qr;j++){
    pa.push_back({prei[j][y],j});
    se.insert(j);
  }
  std::sort(pa.begin(),pa.end());
  for(int i=y;i>=1;i--){
    while(pa.size()>0&&pa.back().first>=i){
      se.erase(pa.back().second);
      pa.pop_back();
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
  int ql=prej[x][y];
  int qr=nxtj[x][y];
  std::vector<std::pair<int,int> >pa;
  std::set<int>se;
  int ans=0;
  for(int j=ql;j<=qr;j++){
    pa.push_back({-nxti[j][y],j});
    se.insert(j);
  }
  for(int i=y;i<=m;i++){
    while(pa.size()>0&&-pa.back().first<=i){
      se.erase(pa.back().second);
      pa.pop_back();
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
inline void write(int n){
	if(n==0){
		putchar('0');
		putchar('\n');
		return ;
	} 
	static char temp[105];
	int tp=0;
	while(n){
		temp[++tp]=n%10+'0';
		n/=10;
	}
	while(tp){
		putchar(temp[tp--]);
	}
	putchar('\n');
	return ;
}
signed main(){
//	freopen("wall.in","r",stdin);
//  freopen("wall.out","w",stdout);
  int T=1;
  int cnt=0;
  while(T--){
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
          write(0);
        }else{
          int ans=0;
          ans=std::max(ans,solve1(x,y));
          ans=std::max(ans,solve2(x,y));
          ans=std::max(ans,solve3(x,y));
          ans=std::max(ans,solve4(x,y));
          write(ans);
        }
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
