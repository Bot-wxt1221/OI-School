#include <bits/stdc++.h>
#define t int
#define N 1000005
t a[N];
std::vector<t>vec[N];
t cur[N];
t main(){
  t n,k;
  scanf("%d%d",&n,&k);
	for(t i=1;i<=n;i++){
    scanf("%d",&a[i]);
		vec[i%k].push_back(a[i]);
	}
	for(t i=0;i<k;i++){
		std::sort(vec[i].begin(),vec[i].end());
	}
	for(t i=1;i<=n;i++){
		printf("%d ",vec[i%k][cur[i%k]++]);
	}
	return 0;
}
