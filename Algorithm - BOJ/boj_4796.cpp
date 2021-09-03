#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int L,P,V,cnt=0;
  while(1){
    cin>>L>>P>>V;
    if(!L && !P && !V)
      break;
    cnt++;
    int ans = V/P*L+min(V%P,L);
    cout<<"Case "<<cnt<<": "<<ans<<'\n';
  }
}
