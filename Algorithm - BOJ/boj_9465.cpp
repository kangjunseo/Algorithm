#include <iostream>
#include <algorithm>
using namespace std;

int N,T;
int arr[2][100000];
int dp[100000][3];

int sticker(int s, int c){ //start, choice
  if(s==N)
    return 0;
  if(dp[s][c]!=-1)
    return dp[s][c];
  int ans = sticker(s+1,0);
  if(c!=2)  
    ans = max(ans,sticker(s+1,2)+arr[0][s]);
  if(c!=1)  
    ans = max(ans,sticker(s+1,1)+arr[1][s]);
  dp[s][c]=ans;
  return ans;
}

int main() {
  cin>>T;
  while(T--){
    cin>>N;
    for(int i=0;i<2;i++)
      for(int j=0;j<N;j++)
        cin>>arr[i][j];
    memset(dp,-1,sizeof(dp)); //-1 means default
    cout<<sticker(0,0)<<'\n';
  }
}
