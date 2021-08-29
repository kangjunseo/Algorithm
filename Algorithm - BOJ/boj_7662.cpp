#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T,k,tempi;
  cin>>T;
  while(T--){
    multiset<int> ms;

    cin>>k;
    while(k--){
      char tempc;
      cin>>tempc>>tempi;
      if(tempc=='I')
        ms.insert(tempi);
      else{
        if(!ms.empty()){
          if(tempi==1)
            ms.erase(--ms.end());
          else
            ms.erase(ms.begin());
        }
      }
    }
    if(ms.empty())
      cout<<"EMPTY\n";
    else{
      auto iter = --ms.end();
      cout<<*iter<<' ';
      iter = ms.begin();
      cout<<*iter<<'\n';
    }
  }
}
