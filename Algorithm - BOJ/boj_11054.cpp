#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int dp1[1000]; //앞에서부터 증가하는 최대 부분수열 탐색
int dp2[1000]; //뒤에서부터 증가(앞에서 봤을 때는 감소)하는 최대 부분수열 탐색

int main() {
  int N, cnt=0,prevmin=1001;
  cin>>N;
  for(int i=0; i<N;i++)
    cin>>arr[i];

  for(int i=0; i<N;i++){    //dp1
    prevmin = min(prevmin, arr[i]);
    if(i==0 || prevmin==arr[i]){  //이전에 자신 보다 큰 수가 없다면 dp=1
      dp1[i]=1;
    }else{
      int dpmax=0;
      for(int j=0; j<i; j++){
        if(arr[j]<arr[i] && dp1[j]>dpmax){
          dpmax=dp1[j];
        }
        dp1[i]=dpmax+1;   //이전의 최대 연속 수열 + 1
      }
    }
  }
  prevmin =1001;
  for(int i=N-1; i>=0; i--){     //dp2
    prevmin = min(prevmin, arr[i]);
    if(i==N-1 || prevmin==arr[i]){
      dp2[i]=1;
    }else{
      int dpmax=0;
      for(int j=N-1; j>i; j--){
        if(arr[j]<arr[i] && dp2[j]>dpmax){
          dpmax=dp2[j];
        }
        dp2[i]=dpmax+1;
      }
    }
  }
  
  int dp[1000]; //dp1과 dp2의 값들을 활용해 바이토닉 부분 수열의 길이 구하기
  for (int i=0; i<N;i++){
    dp[i]=dp1[i]+dp2[i]-1;
  }
  sort(dp,dp+N,greater<int>()); //최대값 탐색
  cout<<dp[0];
}
