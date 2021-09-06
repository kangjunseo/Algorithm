#include <iostream>
using namespace std;

int result[4]={0,};
int arr[6][3];
void play(int i,int p, int e){
  if(p==6){ //모든 경기가 정상적으로 끝
    result[i]=1;
    return;
  }

  if(e==6){ //p가 모든 상대와 경기를 마침
    play(i,p+1,p+2);
    return;
  }
  //win
  arr[p][0]--;
  arr[e][2]--;
  if(arr[p][0]>=0 && arr[e][2]>=0)
    play(i,p,e+1);
  arr[p][0]++;
  arr[e][2]++;

  //draw
  arr[p][1]--;
  arr[e][1]--;
  if(arr[p][1]>=0 && arr[e][1]>=0)
    play(i,p,e+1);
  arr[p][1]++;
  arr[e][1]++;

  //lose
  arr[p][2]--;
  arr[e][0]--;
  if(arr[p][2]>=0 && arr[e][0]>=0)
    play(i,p,e+1);
  arr[p][2]++;
  arr[e][0]++;
}

int main() {
  for (int i=0;i<4;i++){
    int sum=0;
    for(int i=0;i<6;i++){
      cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
      sum+=(arr[i][0]+arr[i][1]+arr[i][2]);
    }
    if(sum==30)
      play(i,0,1);
  }
  for(int i=0;i<4;i++)
      cout<<result[i]<<' ';
}
