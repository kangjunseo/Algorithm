#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
const int INF=999999999;
int coin[101];  //동전의 종류
int dp[101][10001];   //dp

int minCoin(int n, int k){  //top-down 방식의 dp 함수
  if(n==N){
    if(k==0)
      return 0;   //동전 분배가 잘된 케이스
    else
      return INF; //실패
  }else if(dp[n][k]!=-1){
    return dp[n][k];  //dp에 있다면 활용
  }else{
    int ans = minCoin(n+1,k);
    if(coin[n]<=k)
      ans = min(ans,minCoin(n,k-coin[n])+1);  //탐색
    dp[n][k]=ans;
    return ans;
  }
}

int main() {
  int k;
  cin>>N>>k;
  for(int i=0;i<N;i++)
    cin>>coin[i];
 
  memset(dp,-1,sizeof(dp)); //dp 초기화
  
  int ans = minCoin(0,k);
  if(ans==INF)
    cout<<-1;
  else
    cout<<ans;
}
