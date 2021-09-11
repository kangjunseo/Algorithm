#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int ans=0, maxnode=0;
vector <pair<int,int>> G[10001];  //인접 리스트의 아이디어를 차용한 pair vector 구조로 graph를 구현함
int visited[10001] = {0,};

void DFS(int v , int weight){   //DFS
  visited[v]=1;
  for(auto it = G[v].begin();it!=G[v].end();++it){
    if(visited[it->first]==0){
      DFS(it->first, weight+it->second);
      if(weight+it->second>ans){
        ans=weight + it->second;
        maxnode=it->first;
      }
    }
  }
}

int main() {
  int n,ptmp,ctmp,d;
  cin>>n;
  n--;
  while(n--){
    cin>>ptmp>>ctmp>>d;
    G[ptmp].push_back(make_pair(ctmp, d));   //무방향 그래프로 구현, first는 child node, second는 가중치
    G[ctmp].push_back(make_pair(ptmp,d));
  }
  DFS(1,0);   //먼저 1을 기준으로 한 maxnode를 구함
  memset(visited, 0, sizeof(visited));  //visited를 0으로 초기화 (다시 DFS를 진행하기 위해)
  DFS(maxnode,0);   //maxnode를 기준으로 dfs
  cout<<ans;
}
