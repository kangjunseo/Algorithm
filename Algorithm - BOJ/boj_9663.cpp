#include <iostream>
using namespace std;

int N,cnt=0;
int chess[15]={0,}; //일차원 배열의 index를 col, value 값을 row로 사용 

bool IsSafe(int depth){
  for(int i=0;i<depth;i++){
    if(chess[depth] == chess[i] || (depth - i) == abs(chess[depth]-chess[i])) //같은 row인 경우, 같은 대각선에 있는 경우
      return false;
  }
  return true;
}

void NQ(int n){
  if(n==N){ //모든 퀸들이 안전하게 배치가 완료됨
    cnt++;
    return;
  }
  for(int i=0;i<N;i++){
    chess[n]=i;   
    if(IsSafe(n)) //안전하다고 생각하는 경우에만 탐색 진행
      NQ(n+1);
  }
}

int main() {
  cin>>N;
  NQ(0);
  cout<<cnt;
}
