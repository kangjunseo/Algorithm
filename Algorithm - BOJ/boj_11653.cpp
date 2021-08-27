#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M,N,temp,idx=3;
  int prime[10000];
  prime[0]=2;
  prime[1]=3;
  prime[2]=5;
  for(int i=6;i<=100000;i++){
    int IsPrime=1;
    for(int j=0; prime[j]<=sqrt(i);j++){
      if(i%prime[j]==0){
        IsPrime=0;
        break;
      }
    }
    if (IsPrime==1)
      prime[idx++]=i;
  }

  cin>>N;
  
  for(int i=0;N>1;){
    if(N%prime[i]==0){
      cout<<prime[i]<<'\n';
      N/=prime[i];
    }else if(prime[i]>sqrt(N)){
      cout<<N;
      break;
    }
    else{
      i++;
    }
  }
  
}
