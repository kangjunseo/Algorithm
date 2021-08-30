#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,M;
  cin>>N>>M;
  map<string,int> m;
  map<int,string> m2;
  for(int i=1;i<=N;i++){
    string temp;
    cin>>temp;
    m.insert(make_pair(temp,i));
    m2.insert(make_pair(i,temp));
  }
  while(M--){
    string temp;
    cin>>temp;
    if(isdigit(temp[0])){
      int id = stoi(temp);
      cout<<m2.find(id)->second<<'\n';
    }else
      cout<<m.find(temp)->second<<'\n';
  }
}
