#include <iostream>
using namespace std;
int main() {
  int N,temp,cnt=0,idx=3;
  int prime[1000];  //이 배열에는 소수들을 미리 저장!
  prime[0]=2;
  prime[1]=3;
  prime[2]=5;   //초기 값을 몇 개 설정
  for(int i=6;i<=1000;i++){
    int IsPrime=1;    
    for(int j=0; prime[j]<i/2;j++){ // i의 절반보다 작은 소수들로만 나눠봐도 판별 가능
      if(i%prime[j]==0){    //앞서 구해놓은 소수들로 나눠보기
        IsPrime=0;  // 나누어 떨어지면 소수가 아님!
        break;
      }
    }
    if (IsPrime==1)   //위의 for문을 통과하고도 IsPrime 이 1이라면 소수 
      prime[idx++]=i;
  }
  cin>>N;
  while(N>0){
    cin>>temp;
    cnt++;
    if(temp==1)
      cnt--;
    for(int i=0;prime[i]<=temp/2;i++){
      if(temp%prime[i]==0){
        cnt--;
        break;
      }
    }
    N--;
  }
  cout<<cnt;
}
