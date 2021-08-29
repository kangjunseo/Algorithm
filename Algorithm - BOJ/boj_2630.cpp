#include <iostream>
#include <string.h>
using namespace std;

int arr[128][128];

int check(int I, int J, int N){
  int target = arr[I][J];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(target!=arr[I+i][J+j])
        return 0;
    }
  }
  return 1;
}

void mark(int I, int J, int N){
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      arr[I+i][J+j]+=2;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,cnt0=0,cnt1=0,finished=0;
  cin>>N;
  
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>arr[i][j];
  
  int temp=N;
  while(finished<N*N){
    for(int i=0;i<N/temp;i++){
      for(int j=0;j<N/temp;j++){
        if(arr[i*temp][j*temp]<2 && check(i*temp,j*temp,temp)){
          finished+=temp*temp;
          if(arr[i*temp][j*temp]==1)
            cnt1++;
          else
            cnt0++;
          mark(i*temp,j*temp,temp);
        }
      }
    }
    temp/=2;
  }
  cout<<cnt0<<'\n'<<cnt1;
}
