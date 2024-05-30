  for(int i=1;i<=cnt;i++){
    for(int j=i;j>=1;j--){
      sum[i][j]=sum[i-1][j];
      sum[i][j]%=mod;
      if(i>1){
        dp[i][j]+=(-sum[i-2][j-1]*j%mod*2)%mod;
        dp[i][j]%=mod;
      }
      if(tt[i]==1){
        dp[i][j]+=(-dp[i-1][j-1]*(j))%mod;
      }else{
        dp[i][j]+=(-dp[i-1][j-1]*(j)*2)%mod;
      }
      sum[i][j]+=dp[i][j];
      sum[i][j]%=mod;
    }
  }

