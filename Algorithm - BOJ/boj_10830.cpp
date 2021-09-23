#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int N;
int A[5][5];  //원본 A 행렬
int AB[5][5]; //결과 행렬
int Tmp[5][5];  //계산 중 임시행렬
stack <int> s; 
void DNQ(long long B){    //B를 divide & conquer 방식으로 미리 분할해서 stack에 저장
  if(B==1){
    return;
  }else if(B%2==0){
    s.push(2);
    DNQ(B/2);
  }else{
    s.push(1);
    DNQ(B-1);
  }
}

void SQ(){    //  square
  for(int i=0; i<N;i++){
    for(int j=0; j<N; j++){
      int temp=0;
      for(int k=0; k<N; k++){
        temp+=(AB[i][k]*AB[k][j])%1000;
      }
      Tmp[i][j]=temp%1000;
    }
  }
  memcpy(AB,Tmp,sizeof(Tmp));
}

void PDA(){   //matrix product A (A 곱해주기)
  for(int i=0; i<N;i++){
    for(int j=0; j<N; j++){
      int temp=0;
      for(int k=0; k<N; k++){
        temp+=(AB[i][k]*A[k][j])%1000;
      }
      Tmp[i][j]=temp%1000;
    }
  }
  memcpy(AB,Tmp,sizeof(Tmp));
}

int main(){
  long long B;    //B의 입력 범위 고려
  cin>>N>>B;
  int tmp;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>tmp;
      A[i][j]=tmp;
      AB[i][j]=tmp;
    }
  }
  DNQ(B);
  while(!s.empty()){
    if(s.top()==2){ //stack에 넣어둔 값대로 "AB X AB" 또는 "AB X A" 수행
      SQ();
    }else{
      PDA();
    }
    s.pop();
  }
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout<<AB[i][j]%1000<<' ';
    }
    cout<<'\n';
  }
}
