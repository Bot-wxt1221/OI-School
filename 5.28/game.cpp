#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int fir[1600005];
int v[5000005];
std::priority_queue<std::pair<int,int> >qu;
int w[5000005];
int nxt[5000005];
bool yes[1600005];
int now;
int tt[505]={9361,15961,18722,21241,25201,26521,28083,42163,47883,53317,56166,56221,63723,71863,48961,62821,70609,70741,75603,79563,84337,74041,80641,94501,106117,112442,113773,120241,126489,127501,128161,143737,64801,125653,126181,141361,141482,141493,142021,149941,159181,168663,169477,170533,188881,190663,191169,191257,191851,192181,192313,215611,216469,159841,161282,189002,189013,189541,191521,212047,212641,213301,223861,224884,224917,226809,227557,227953,238689,240361,240493,253011,253033,254221,255541,256322,256333,286891,288541,129602,187561,197461,210067,215281,224653,236401,239041,246961,251317,252901,252967,254881,264517,280621,281941,282469,282733,282964,283921,284042,284581,287881,299882,299893,318351,318362,318769,319561,320551,337326,337381,340021,341066,342001,360723,360811,377762,379467,381326,381337,382503,383317,383702,383713,384307,384373,384483,384626,384637,384769,430342,431211,431222,431233,432421,432817,432949,265441,270721,286561,298441,302401,316261,319693,334081,335401,335533,338437,338701,376981,377641,378004,378037,379082,379093,379621,383042,383053,405361,422917,424083,424501,425282,425293,426602,426613,427009,427141,429451,432113,447722,447733,449768,455653,455906,456049,477543,479347,479941,480931,503701,506066,506077,508431,508442,508453,509641,510037,511093,512017,512413,512501,512644,512677,512941,513073,572011,573507,573771,573782,573793,574981,575553,576939,577082,577093,646833,648637,649231,649495,381601,406087,430441,440737,441793,442453,449317,452881,453937,455059,455257,472802,474133,474661,476641,477961,478082,479523,480601,493141,493922,497761,503041,505802,506341,508321,508981,509762,510961,532807,533401,555841,561121,563882,563893,565477,567061,567842,568084,568117,568909,569041,569173,569701,574563,576103,576301,599764,599786,601381,604021,607057,607541,607717,608113,634381,635569,636141,636163,636757,639122,639133,639529,640321,640805,640981,674652,674762,680053,680427,682132,682671,684002,716067,716353,721369,721479,721501,721633,755557,759033,759099,759121,762652,762663,764467,765061,767404,767426,767437,768031,768614,768757,768966,769252,769538,769681,850003,860673,860684,862444,862466,862477,864853,865447,865623,865634,865843,865909,378001,492481,531553,544357,563761,571681,573001,597157,604802,607321,630201,632533,633061,645843,664213,666457,668041,671077,672661,674641,680581,682033,682561,709203,710413,711601,717123,726451,739717,740773,740883,741169,746647,747241,749705,751861,755282,756008,758164,758186,758901,759242,759253,759781,762091,762421,762553,764401,764643,766084,766117,767701,800107,810722,832183,833767,841863,847429,848221,849002,850564,850586,850597,851763,853204,854029,854161,854282,854293,854821,858902,858913,864061,864193,864226,864457,864721,865381,895444,895466,895477,899536,899701,906037,910261,911306,911812,912098,912241,951577,955053,955086,955141,956307,956329,958683,958694,959882,959893,960487,960905,961081,961477,961653,962071,587521,591481,619201,635041,663553,726121,738001,746581,753841,756019,783541,788293,799205,801361,812163,840961,845713,846769,848881,851257,860882,883586,892837,894421,895213,907203,908941,945604,948277,949322,949861,955922,956164,957605,959761,961202,961741,983521,987844,987877,995522,995533,756002,951841,967681,984962,995401};
int dp[1600005];
bool vised[1600005];
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  #endif
  int n=1.6e6;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=500;i++){
    if(tt[i]!=0){
      yes[tt[i]]=1;
    }
  }
  for(int i=1;i<=n;i++){
    if(i!=1){
      add(i,i-1,1);
    }
    for(int j=2;i*j<=n;j++){
      if(j<=9||yes[i*j]){
        add(i,i*j,j);
      }
    }
  }
  memset(dp,0x3f,sizeof(dp));
  dp[1]=0;
  qu.push(std::make_pair(0,-1));
  int mx=0;
  while(qu.size()>0){
    auto tp=-qu.top().second;
    qu.pop();
    if(vised[tp]){
      continue;
    }
    vised[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(dp[v[i]]>dp[tp]+w[i]){
        dp[v[i]]=dp[tp]+w[i];
        qu.push(std::make_pair(-dp[v[i]],-v[i]));
      }
    }
  }
  int tt=read();
  if(dp[tt]==0x3f3f3f3f){
    printf("QAQ");
  }else{
    printf("%d",dp[tt]);
  }
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    c=getchar();
  }
  return f*x;
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
