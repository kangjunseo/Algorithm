#include <iostream>
using namespace std;

char arr[64][64]; //char형으로 입력 받음

void Qtree(int si, int ei, int sj, int ej){
  int num = arr[si][sj];
  int IsSame=1;
  for(int i=si;i<ei;i++){
    for(int j=sj;j<ej;j++){
      if(num!=arr[i][j]){
        IsSame=0;
        break;
      }
    }
  }
  if(IsSame){
    cout<<num-'0';
  }else{
    int midi =(si+ei)/2;
    int midj =(sj+ej)/2;
    cout<<'(';
    Qtree(si,midi,sj,midj);
    Qtree(si,midi,midj,ej);
    Qtree(midi,ei,sj,midj);
    Qtree(midi,ei,midj,ej);
    cout<<')';
  }
}

int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>arr[i];  //'0' or '1'
  Qtree(0,N,0,N);
}
