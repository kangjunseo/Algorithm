#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N,L,cnt=1;
  int arr[1000]={0,};
  cin>>N>>L;
  for(int i=0;i<N;i++)
    cin>>arr[i];

  sort(arr,arr+N);
  int current = arr[0];
  for(int i=0;i<N;i++){
    if(arr[i]-current>=L){
      current=arr[i];
      cnt++;
    }
  }
  cout<<cnt;
}
