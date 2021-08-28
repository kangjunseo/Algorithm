#include <iostream>
using namespace std;

int main() {
  int dp[1001]={0,1,2};
  int N;
  cin>>N;
  for(int i=3;i<=N;i++){
    dp[i]=dp[i-1]+dp[i-2];
    if(dp[i]>=10007)
      dp[i]%=10007;
  }
  cout<<dp[N]<<'\n';
}
