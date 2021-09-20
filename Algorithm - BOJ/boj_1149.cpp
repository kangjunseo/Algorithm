#include <iostream>
using namespace std;

int dp[1001][3]; 

int main(){
  int N,tmpR,tmpG,tmpB;
  cin>>N;
  dp[0][0]=0; 
  dp[0][1]=0;
  dp[0][2]=0;
  for(int i=1;i<=N;i++){
    cin>>tmpR>>tmpG>>tmpB;
    dp[i][0]=min(dp[i-1][1],dp[i-1][2])+tmpR; //R을 골랐다면 이전에는 G또는 B 중 작은 것을 고름
    dp[i][1]=min(dp[i-1][0],dp[i-1][2])+tmpG;
    dp[i][2]=min(dp[i-1][0],dp[i-1][1])+tmpB;
  }
  cout<<min(min(dp[N][0],dp[N][1]),dp[N][2]);
}
