#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int InBound(int v){
  if(v<=100000 && v>=0)
    return 1;
  return 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,K,cnt;
  int visited[100001]={0,};
  queue<pair<int,int>> q;

  cin>>N>>K;
  q.push(make_pair(N,0));
  visited[N]=1;

  while(!q.empty()){
    int currentV = q.front().first;
    int currentD = q.front().second;
    q.pop();
    if(currentV == K){
      cnt=currentD;
      break;
    }
    if(InBound(2*currentV) && visited[2*currentV]==0){
      q.push(make_pair(2*currentV,currentD+1));
      visited[2*currentV]=1;
    }
    if(InBound(currentV+1) && visited[currentV+1]==0){
      q.push(make_pair(currentV+1,currentD+1));
      visited[currentV+1]=1;
    }
    if(InBound(currentV-1) && currentV<=100000 && visited[currentV-1]==0){
      q.push(make_pair(currentV-1,currentD+1));
      visited[currentV-1]=1;
    } 
  }

  cout<<cnt;
}
