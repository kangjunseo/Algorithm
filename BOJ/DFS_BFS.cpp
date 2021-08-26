#include <iostream>
#include <algorithm>
#include <queue>

int G[1001][1001];
int visit[1001];
int N;
void DFS(int V){
  visit[V]=1;
  std::cout<<V<<' ';
  for(int i=1; i<=N; i++){
    if(G[V][i]==1 && visit[i]==0)
      DFS(i);
  }
}

void BFS(int V){
  std::queue<int> q;
  visit[V]=2;
  std::cout<<V<<' ';
  q.push(V);
  while(!q.empty()){
    V=q.front();
    q.pop();
    for(int i=1;i<=N;i++){
      if(G[V][i]==1 && visit[i]!=2){
        std::cout<<i<<' ';
        q.push(i);
        visit[i]=2;
      }
    }
  }
}

int main() {
  int M,V,i,I,J;
  std::cin>>N>>M>>V;
  for(i=0;i<M;i++){
    std::cin>>I>>J;
    G[I][J]=1;
    G[J][I]=1;
  }
  
  DFS(V);
  std::cout<<'\n';
  BFS(V);
}
