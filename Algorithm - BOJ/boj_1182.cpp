#include <iostream>
using namespace std;

int N,S,cnt=0;
int arr[20];
void Backtrack(int n, int s){
  if(s==S)
    cnt++;
  for (int i=n+1; i<N;i++){
    Backtrack(i,s+arr[i]);
  }
}

int main() {
  cin>>N>>S;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  
  for(int i=0;i<N;i++)
    Backtrack(i,arr[i]);

  cout<<cnt;
  }
