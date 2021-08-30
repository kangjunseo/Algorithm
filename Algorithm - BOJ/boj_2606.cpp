#include <iostream>
using namespace std;

int N,M,cnt=0;
int graph[101][101]={0,};
int visited[101]={0,};

void DFS(int v){
  visited[v]=1;
  cnt++;
  for(int i=1;i<=N;i++){
    if(graph[v][i]==1 && visited[i]==0)
      DFS(i);
  }
}

int main() {
  int tempi,tempj;
  cin>>N>>M;
  while(M--){
    cin>>tempi>>tempj;
    graph[tempi][tempj]=1;
    graph[tempj][tempi]=1;
  }
  DFS(1);
  cout<<cnt-1;
}
