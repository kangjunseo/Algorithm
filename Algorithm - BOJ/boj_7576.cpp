#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int M,N,cnt=0;
int tmt[1002][1002];
queue<pair<int,int>> q;
queue<pair<int,int>> q2;

void Check(int i, int j){
  if(i>N || j>M || i==0 || j==0)
    return;
  
  if(tmt[i][j]==0){
    q2.push(make_pair(i,j));
    tmt[i][j]=2;  
  }
}

void Pop(){
  int i=q.front().first;
  int j=q.front().second;
  tmt[i][j]=1;
  Check(i+1,j);
  Check(i-1,j);
  Check(i,j+1);
  Check(i,j-1);
  q.pop();
}

int main() {
  cin>>M>>N;
  int temp,total=M*N,day=0;
  
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin>>temp;
      tmt[i][j]=temp;
      if(temp==1){
        q.push(make_pair(i,j));
        cnt++;
      }
      else if(temp==-1)
        total--;
    }
  }

  while(cnt<total){
    int today_cnt=0;
    while(!q.empty()){ //q에 있는 원소 모두 pop
      Pop();
      today_cnt++;
    }

    if(today_cnt==0){
      cout<<-1;
      return 0;
    }

    while(!q2.empty()){ //q2에 있는 원소 모두 q로
      q.push(q2.front());
      cnt++;
      q2.pop();
    }

    day++;
  }
  cout<<day;
}
