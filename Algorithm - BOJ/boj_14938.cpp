#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int n,m,r,item,ans;
int items[101]={0,};
vector <pair<int,int>> v[101];
int d[101];

void Dijkstra(int start){
  item = 0;
  queue <int> q;
  for(int i=1;i<=n;i++)
    d[i]=INF;
  
  d[start] = 0;
  q.push(start);

  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(auto it=v[current].begin();it!=v[current].end();++it){
      int next = it->first;
      int distance = it->second;
      if(d[next] > d[current]+distance){
        d[next] = d[current]+distance;
        q.push(next);
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(d[i] <=m)
      item+=items[i];
  ans = max(ans,item);
}

int main() {
  int temp1,temp2,temp3;
  cin>>n>>m>>r;
  for(int i=1;i<=n;i++)
    cin>>items[i];
  while(r--){
    cin>>temp1>>temp2>>temp3;
    v[temp1].push_back(make_pair(temp2,temp3));
    v[temp2].push_back(make_pair(temp1,temp3));
  }

  for(int i=1;i<=n;i++)
    Dijkstra(i);
  
  cout<<ans;
}
