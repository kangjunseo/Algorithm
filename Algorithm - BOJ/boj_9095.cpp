#include <iostream>
using namespace std;

int main() {
  int dp[10]={1,2,4};
  for(int i=3;i<10;i++)
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];

  int T,temp;
  cin>>T;
  while(T--){
    cin>>temp;
    cout<<dp[temp-1]<<'\n';
  }
}
