#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long N,M,max,min,mid,tmp;
  cin>>N>>M;
  vector <int> v;
  
  for(int i=0;i<N;i++){
    cin>>tmp;
    v.push_back(tmp);
  }

  sort(v.begin(),v.end(),greater<int>());
  max=v.front();
  min=0;
  mid=(max+min)/2;

  while(1){
    if(min==mid)
      break;
    
    long sum=0;
    for(auto it = v.begin();it!=v.end();++it){
      if(*it>mid)
        sum+=*it-mid;
    }
    
    if(sum>M){
      min=mid;
      mid=(max+min)/2;
    }else if(sum<M){
      max=mid;
      mid=(max+min)/2;
    }else{
      break;
    }
  }
  cout<<mid;
}
