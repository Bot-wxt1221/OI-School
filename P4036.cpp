#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int unsigned long long
inline int read();
char temp[100005];
std::pair<int,int> tree[1600005];
int lazy[1600005];
void pushup(signed now){
	tree[now]=std::make_pair(tree[now*2].first+tree[now*2+1].first,tree[now*2].second+tree[now*2+1].second);
	return ;
}
int pow(int x,int y){
	int cur=x;
	int ans=1;
	while(y){
		if(y&1){
			ans*=cur;
		}
		cur*=cur;
		y>>=1;
	}
	return ans;
}
void pushdown(signed now){
	tree[now*2].first*=lazy[now];
	tree[now*2].second*=lazy[now];
	tree[now*2+1].first*=lazy[now];
	tree[now*2+1].second*=lazy[now];
	lazy[now*2]*=lazy[now];
	lazy[now*2+1]*=lazy[now];
	lazy[now]=1;
	return ;
}
void build(signed now,signed l,signed r){
	lazy[now]=1;
	if(l==r){
		tree[now]={0,0};
		return ;
	}
	signed mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	pushup(now);
}
int ql,qr,opp;
void query(signed now,signed l,signed r){
	if(qr<l||r<ql){
		return ;
	}
	if(ql<=l&&r<=qr){
		opp+=tree[now].first;
		return ;
	}
	signed mid=(l+r)/2;
	pushdown(now);
	if(qr<l||mid<ql){
	}else
	query(now*2,l,mid);
	if(qr<mid+1||r<ql){
	}else
	query(now*2+1,mid+1,r);
	return ;
}
void cheng(signed now,signed l,signed r){
	if(qr<l||r<ql){
		return ;
	}
	if(ql<=l&&r<=qr){
		tree[now].first*=opp;
		tree[now].second*=opp;
		lazy[now]*=opp;
		return ;
	}
	signed mid=(l+r)/2;
	pushdown(now);
	if(qr<l||mid<ql){
	}else
	cheng(now*2,l,mid);
	if(qr<mid+1||r<ql){
	}else
	cheng(now*2+1,mid+1,r);
	pushup(now);
	return ;
}
std::pair<int,int> tar;
void add(signed now,signed l,signed r){
	if(qr<l||r<ql){
		return ;
	}
	if(ql<=l&&r<=qr){
		tree[now]=tar;
		return ;
	}
	signed mid=(l+r)/2;
	pushdown(now);
	if(qr<l||mid<ql){
	}else
	add(now*2,l,mid);
	if(qr<mid+1||r<ql){
	}else
	add(now*2+1,mid+1,r);
	pushup(now);
	return ;
}
char tar2;
void add2(signed now,signed l,signed r){
	if(qr<l||r<ql){
		return ;
	}
	if(ql<=l&&r<=qr){
		tree[now].first=tree[now].second*tar2;
//		std::cerr<<tree[now].first<<' '<<l<<std::endl;
		return ;
	}
	signed mid=(l+r)/2;
	pushdown(now);
	if(qr<l||mid<ql){
	}else
	add2(now*2,l,mid);
	if(qr<mid+1||r<ql){
	}else
	add2(now*2+1,mid+1,r);
	pushup(now);
	return ;
}
class op{
	public:
		signed kind,a,b;
		op(signed aa=0,signed bb=0,signed cc=0){
			kind=aa;
			a=bb;
			b=cc;
			return ;
		}
}opt[150005];
std::deque<std::pair<signed,char> >qu;
std::deque<signed>qu2;
signed pos[150005];
signed tott;
inline int geth(signed l,signed r){
	ql=qu2[l];
	qr=qu2[r];
	opp=0;
	query(1,1,tott);
	return opp;
}
signed main(){
//  #ifdef ONLINE_JUDGE
//  #else
//  freopen("5.in","r",stdin);
//  freopen(".out","w",stdout);
//  #endif
  scanf("%s",temp+1);
  signed siz=strlen(temp+1);
  for(signed i=1;i<=siz;i++){
		qu.push_back(std::make_pair(0,temp[i]-'a'+1));
  }
	signed q=read();
	for(signed i=1;i<=q;i++){
		char tt[4];
    scanf("%s",tt);
		op a(tt[0]);
		a.a=read();
		if(a.kind=='Q'){
			a.b=read();
		}else{
			char tt[4];
      scanf("%s",tt);
			a.b=tt[0]-'a'+1;
		}
		if(a.kind=='I'){
			qu.insert(qu.begin()+a.a,std::make_pair(i,char(a.b)));
		}
		opt[i]=a;
	}
	qu2.push_back(0);
	tott=qu.size();
	build(1,1,tott);
	int cnt=1;
	for(signed i=0;i<qu.size();i++){
		auto tt=qu[i];
		if(tt.first==0){
			cnt*=27;
			ql=qr=i+1;
			tar=std::make_pair(cnt*tt.second,cnt);
			add(1,1,tott);
			qu2.push_back(i+1);
		}else{
			pos[tt.first]=i+1;
		}
	}
	for(signed i=1;i<=q;i++){
		op &a=opt[i];
		if(a.kind=='Q'){
			int x=a.a;
			int y=a.b;
			if(x>y){
				std::swap(x,y);
			}
			signed l=1,r=qu2.size()-std::max(x,y);
			while(r-l>2){
				signed mid=(l+r)/2;
				if(geth(x,x+mid-1)*pow(27,y-x)==geth(y,y+mid-1)){
					l=mid;
				}else{
					r=mid;
				}
			}
			for(signed mid=r;mid>=l;mid--){
				if(geth(x,x+mid-1)*pow(27,y-x)==geth(y,y+mid-1)){
					printf("%llu\n",mid);
					goto end;
				}
			}
			printf("0\n");
			end:{}
		}else if(a.kind=='R'){
			tar2=a.b;
			ql=qr=qu2[a.a];
			add2(1,1,tott);
		}else{
			qr=tott;
			ql=qu2[a.a]+1;
			opp=27;
			cheng(1,1,tott);
			ql=pos[i];
			qr=pos[i];
			int tt=pow(27,a.a+1);
			tar=std::make_pair(tt*a.b,tt);
			add(1,1,tott);
			qu2.insert(qu2.begin()+a.a+1,pos[i]);
		}
	}
  return 0;
}
inline int read(){
  signed x;
  scanf("%d",&x);
  return x;
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
