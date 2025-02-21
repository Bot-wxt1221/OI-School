#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
inline int read();
int x[200005];
int y[200005];
int tt[200005];
std::map<int,int>mp[200005];
std::vector<int>vec;
int nxt[200005][2];
bool cmp(int xx,int yy){
	return x[xx]<x[yy];
}
bool cmp2(int xx,int yy){
	return y[xx]<y[yy];
}
std::vector<int>vecx[400005],vecy[400005];
int getx(int x){
	return std::lower_bound(vec.begin(),vec.end(),x)-vec.begin();
}
int xx[800005];
int yy[800005];
std::vector<std::pair<int,int> >vecx1[400005],vecy1[400005];
int dis[800005][2];
int ad[800005][2];
int diss(int xx,int yy){
	return std::abs(x[xx]-x[yy])+std::abs(y[xx]-y[yy]);
}
int totdis=0;
int ans[800005];
void dfs(int now,int fa,int tppp,int cur=0,int precur=0){
  if(cur!=0){
    if(x[now]==x[fa]){
      int tx=getx(x[now]);
      auto tt=std::lower_bound(vecx1[tx].begin(),vecx1[tx].end(),std::make_pair(getx(std::min(y[now],y[fa])),0));
      while(tt!=vecx1[tx].end()){
        if(y[tt->second]>std::max(y[now],y[fa])){
          continue;
        }
        dis[tt->second][tppp]=precur+std::abs(y[fa]-yy[tt->second]);
        tt++;
      }
    }else{
      int ty=getx(y[now]);
      auto tt=std::lower_bound(vecy1[ty].begin(),vecy1[ty].end(),std::make_pair(getx(std::min(x[now],x[fa])),0));
      while(tt!=vecy1[ty].end()){
        if(x[tt->second]>std::max(x[now],x[fa])){
          continue;
        }
        dis[tt->second][tppp]=precur+std::abs(x[fa]-xx[tt->second]);
        tt++;
      }
    }
  }
  if(cur!=0&&now==1){
    totdis=cur;
    return ;
  }
	for(int i=0;i<=1;i++){
		if(nxt[now][i]==fa){
			continue;
		}
		dfs(nxt[now][i],now,tppp,cur+diss(now,nxt[now][i]),cur);
	}
	return ;
}
void dfs2(int now,int fa,int tppp,int cur=0,int ad=0){
  if(cur!=0&&now==1){
    return ;
  }
  if(cur!=0){
    if(x[now]==x[fa]){
      int tx=getx(x[now]);
      auto tt=std::upper_bound(vecx1[tx].begin(),vecx1[tx].end(),std::make_pair(getx(std::min(y[now],y[fa])),0));
      while(tt!=vecx1[tx].end()){
        if(y[tt->second]>std::max(y[now],y[fa])){
          continue;
        }
        ad+=::ad[tt->second][tppp];
        tt++;
      }
      ans[now]=ad;
    }else{
      int ty=getx(y[now]);
      auto tt=std::upper_bound(vecy1[ty].begin(),vecy1[ty].end(),std::make_pair(getx(std::min(x[now],x[fa])),0));
      while(tt!=vecy1[ty].end()){
        if(x[tt->second]>std::max(x[now],x[fa])){
          continue;
        }
        ad+=::ad[tt->second][tppp];
        tt++;
      }
      ans[now]=ad;
    }
  }else{
    ans[now]=ad;
  }
	for(int i=0;i<=1;i++){
		if(nxt[now][i]==fa){
			continue;
		}
		dfs2(nxt[now][i],now,tppp,cur+diss(now,nxt[now][i]),ad);
	}
	return ;
}
int main(){
	int n=read();
	int p=read();
	for(int i=1;i<=p;i++){
		x[i]=read();
		y[i]=read();
		vec.push_back(x[i]);
		vec.push_back(y[i]);
	}
	std::sort(vec.begin(),vec.end());
	vec.resize(std::unique(vec.begin(),vec.end())-vec.begin());
	for(int i=1;i<=p;i++){
		vecx[getx(x[i])].push_back(i);
		vecy[getx(y[i])].push_back(i);
	}
	for(int i=0;i<vec.size();i++){
		std::sort(vecx[i].begin(),vecx[i].end(),cmp2);
		for(int j=1;j<vecx[i].size();j+=2){
			nxt[vecx[i][j]][0]=vecx[i][j-1];
			nxt[vecx[i][j-1]][0]=vecx[i][j];
		}
		std::sort(vecy[i].begin(),vecy[i].end(),cmp);
		for(int j=1;j<vecy[i].size();j+=2){
			nxt[vecy[i][j]][1]=vecy[i][j-1];
			nxt[vecy[i][j-1]][1]=vecy[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int x1=read();
		int y1=read();
		xx[i*2]=x1;
		yy[i*2]=y1;
    if(x1==x[1]&&y1==y[1]){
    }else{
      if(x1==vec[getx(x1)]){
        vecx1[getx(x1)].push_back({y1,i*2});
      }
      if(y1==vec[getx(y1)]){
        vecy1[getx(y1)].push_back({x1,i*2});
      }
    }
		x1=read();
		y1=read();
		xx[i*2-1]=x1;
		yy[i*2-1]=y1;
    if(x1==x[1]&&y1==y[1]){
    }else{
      if(x1==vec[getx(x1)]){
        vecx1[getx(x1)].push_back({y1,i*2-1});
      }
      if(y1==vec[getx(y1)]){
        vecy1[getx(y1)].push_back({x1,i*2-1});
      }
    }
	}
	dfs(1,nxt[1][1],0);
  int totad=0;
  int add=0;
	for(int i=1;i<=n;i++){
    int x=i*2-1;
    int y=i*2;
    if(dis[x][0]>dis[y][0]){
      std::swap(x,y);
    }
    int diss=dis[y][0]-dis[x][0];
    if(i==1){
    if(diss<totdis-(diss)){
      if(xx[x]==::x[1]&&yy[x]==::y[1]){
        add++;
      }else{
        ad[x][0]++;
      }
      if(xx[y]==::x[1]&&yy[y]==::y[1]){
        add--;
      }else{
        ad[y][0]--;
      }
      mp[xx[y]][yy[y]]++;
    }else{
      totad++;
      if(xx[x]==::x[1]&&yy[x]==::y[1]){
        add--;
      }else{
        ad[x][0]--;
      }
      if(xx[y]==::x[1]&&yy[y]==::y[1]){
        add++;
      }else{
        ad[y][0]++;
      }
      mp[xx[x]][yy[x]]--;
    }
    }
	}
  dfs2(1,nxt[1][1],0,0,add);
  for(int i=1;i<=p;i++){
    printf("%d\n",totad+ans[i]+mp[x[i]][y[i]]);
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
