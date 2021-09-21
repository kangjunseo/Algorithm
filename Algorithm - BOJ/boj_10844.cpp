#include <iostream>
using namespace std;

int dp[101][10]; //뒤에 추가되는 수의 경우의 수 0-9 10가지

int main(){
  int N;
  cin>>N;
  dp[1][0]=0; //0으로 시작하는 수는 계단수가 아님
  for(int i=1;i<10;i++)
    dp[1][i]=1;

  for(int i=2;i<=100;i++){
    for(int j=0;j<10;j++){
      if(j==0){   //앞의 숫자가 0인경우 뒤에는 1만 올수 있음
        dp[i][j]=dp[i-1][j+1]%1000000000;
      }else if(j==9){ //앞의 숫자가 9인경우 뒤에는 8만 올수 있음
        dp[i][j]=dp[i-1][j-1]%1000000000;
      }
      else{   //나머지 숫자들은 1보다 작은수나 큰수 둘 다 올수 있음
      dp[i][j]=dp[i-1][j-1]%1000000000+dp[i-1][j+1]%1000000000;
      }
    }
  }
  long ans=0;
  for(int i=0;i<10;i++)
    ans+=dp[N][i]%1000000000;
  cout<<ans%1000000000;
}
