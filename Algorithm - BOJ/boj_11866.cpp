#include <iostream>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,K;
  cin>>N>>K;
  int circular_queue[1000]={0,};
  for(int i=0;i<N;i++)
    circular_queue[i]=1;
  cout<<'<';
  int idx=1;
  int temp=N;
  while(temp){
    int cnt=K;
    while(cnt){
      if(circular_queue[idx%N]==0){
        idx++;
        continue;
      }

      if(temp==1){
        if(cnt==1){
          if(idx%N==0){
            circular_queue[0]=0;
            cout<<N;
            break;
          }
          else{
            circular_queue[idx%N]=0;
            cout<<idx%N;
            break;
          }
        }
      }

      if(cnt==1){
        if(idx%N==0){
          circular_queue[0]=0;
          cout<<N<<", ";
        }
        else{
          circular_queue[idx%N]=0;
          cout<<idx%N<<", ";
        }
      }
      idx++;
      cnt--;
    }
    temp--;
  }

  cout<<'>';
}
