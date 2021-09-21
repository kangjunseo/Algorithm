#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301][2]; //[0] : 1전 계단을 안 밟을 때, [1] : 1전 계단을 밟았을 때

int main(){
  int N;
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>arr[i];

  dp[0][0]=0;
  dp[1][0]=arr[1];  //출발점은 계단으로 간주하지 않음
  for(int i=2;i<=N;i++){
    dp[i][1]=dp[i-1][0]+arr[i];   //1전 계단을 밟았다면, 2전 계단은 밟으면 안됨
    dp[i][0]=max(dp[i-2][0],dp[i-2][1])+arr[i];  
  }
  cout<<max(dp[N][0],dp[N][1]);
}
