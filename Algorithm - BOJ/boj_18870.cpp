#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

bool comp(pair<double,int> a, pair<double,int> b){
  return a.first < b.first;
}

bool comp2(pair<double,int> a, pair<double,int> b){
  return a.second < b.second;
}

int main() {
  int N;
  cin>>N;
  vector <pair<double,int>> v;    //initiate vector with pair
  for(int i=0;i<N;i++){
    double temp;
    cin>>temp;
    v.push_back(make_pair(temp,i));  //make pair and push
  }
    
  sort(v.begin(),v.end(),comp);
  int idx =-1;
  double previous=-1e9-1;
  for(auto iter = v.begin();iter!=v.end();++iter){
    if((*iter).first==previous)
      (*iter).first=idx;
    else{
      previous=(*iter).first;
      (*iter).first=++idx;
    }
  }
  
  sort(v.begin(),v.end(),comp2);
  for(auto iter = v.begin();iter!=v.end() ;++iter){
    cout<<(*iter).first<<' ';
  }
}
