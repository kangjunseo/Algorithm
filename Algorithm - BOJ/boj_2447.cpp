#include <iostream>
using namespace std;

int N;
int arr[2190][2190]={0,};

void DNC(int si, int ei, int sj, int ej,int level){
  int I = (si*2+ei)/3;
  int J = (sj*2+ej)/3;
  int tmpI = I, tmpJ = J;

  for(int i=0;i<level;i++){
    tmpJ=J;
    for(int j=0;j<level;j++){
      arr[tmpI][tmpJ]=0;
      tmpJ++;
    }
    tmpI++;
  }
  if(level>1){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        DNC(I+(i-1)*level,I+i*level,J+(j-1)*level,J+j*level,level/3);
     }
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      arr[i][j]=1;

  DNC(0,N,0,N,N/3);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j]==1){
        cout<<'*';
      }else{
        cout<<' ';
      }
    }
    cout<<'\n';
  }
}
