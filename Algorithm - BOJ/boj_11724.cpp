#include <iostream>
using namespace std;

int graph[1001][1001]={0,};
int visited[1001]={0,};

void DFS(int v,int N){
  visited[v]=1;
  for(int i=1;i<=N;i++){
    if(graph[v][i]==1 && visited[i]==0)
      DFS(i,N);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,M;
  cin>>N>>M;
  
  int temp1, temp2, cnt=0;
  while(M--){
    cin>>temp1>>temp2;
    graph[temp1][temp2]=1;
    graph[temp2][temp1]=1;
  }
  for(int i=1;i<=N;i++){
    if(visited[i]==0){
      DFS(i,N);
      cnt++;
    }
  }
  cout<<cnt;
}
