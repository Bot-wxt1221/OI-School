#include <iostream>
#include <cstdio>
int main(){
  printf("3000 3000 3000\n");
  for(int i=1;i<=3000;i++){
    for(int j=1;j<=3000;j++){
      printf("%c",'.');
    }
    printf("\n");
  }
  for(int i=1;i<=3000;i++){
    printf("2 %d %d\n",rand()%3000+1,rand()%3000+1);
  }
}
