#include <bits/stdc++.h>
using namespace std;
#define pii pair <int,int>
#define pb emplace_back
#define se second

const int N = 1e6 + 5;

int n , m , head[N] , cnt , ans[N] , dy[N] , col , fat[N] , cfa[N];

int dep[N] , f[N][22] , U[N] , V[N] , id[N] , idx , flag , F[N] , Fa[N];

struct edge {
	int u , v , nxt , id;
}e[N << 1];

vector <int> tmp;

set <pii> s[N];

void adde(int u , int v , int idi) {
	e[++ cnt].u = u;e[cnt].v = v;e[cnt].id = idi;
	e[cnt].nxt = head[u]; head[u] = cnt;
	if(!dy[idi]) dy[idi] = cnt;
}

void dfs(int u , int fa) {
	dep[u] = dep[Fa[u] = f[u][0] = fa] + 1;
	for(int i = 1;i <= 20;i ++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u];i;i = e[i].nxt) {
		int v = e[i].v;
		if(v == fa) continue;
		cfa[v] = fat[v] = i - (!(i & 1));
		dfs(v , u);
	}
}

int Lca(int x , int y) {
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 20;~i;i --) {
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	} if(x == y) return x;
	for(int i = 20;~i;i --) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i]; y = f[y][i];
		}
	} return f[x][0];
}

int tt;
int find(int x) {
	if(x == 1) return 1;
	if(cfa[x] != 0) {
    tt=x;
    return Fa[x];
  }
	return Fa[x] = find(Fa[x]);
}

int find2(int x){
  if(x==1){
    return 1;
  }
  if(cfa[x]!=0){
    return x;
  }
  return Fa[x]=find2(Fa[x]);
}
void up(int u , int ed) {
	while(u != ed) {
    u=find2(u);
		if(dep[u] <= dep[ed]) break;
		int tm = u;
		u = find(u);  
    tmp.push_back(::e[cfa[tt]].id);
    cfa[tt] = 0;
	}
}

bool ttt[1000005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i ++) {
		int u , v , opt;
		cin >> u >> v >> opt;
		if(opt == 0) {
			U[i] = u;
			V[i] = v;id[i] = i;
		}
		else {
			adde(u , v , i);
			adde(v , u , i);
      U[i]=u;
      V[i]=v;
      id[i]=i;
      ttt[i]=1;
		}
	}
	dfs(1 , 0);
	for(int i = 1;i <= m;i ++) {
		if(ttt[i]) {
			if(!ans[i]) ans[i] = ++ col;
      if(dep[U[i]]>dep[V[i]]){
        cfa[U[i]]=0;
      }else{
        cfa[V[i]]=0;
      }
			continue;
		}
		int u = U[i] , v = V[i];
		int lca = Lca(u , v);
		up(u , lca);
		up(v , lca);   
		sort(tmp.begin() , tmp.end());
		for(int j : tmp) {ans[j] = ++ col;}
		ans[id[i]] = ++ col;tmp.clear();
	}
	for(int i = 1;i <= m;i ++) {
		cout << ans[i];
		if(i < m) cout << ' ';
	} 
	return 0;
}
