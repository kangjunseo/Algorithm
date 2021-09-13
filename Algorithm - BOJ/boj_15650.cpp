#include <iostream>
using namespace std;

int N,M;
int temp[8];

void NM2(int start, int depth){
  if(depth==M){
    for(int i=0;i<M;i++)
      cout<<temp[i]<<' ';
    cout<<'\n';
    return;
  }
  for(int i=start;i<N;i++){
    temp[depth]=i+1;
    NM2(i+1,depth+1);
  }
}

int main(){
  cin>>N>>M;
  NM2(0,0);
}
