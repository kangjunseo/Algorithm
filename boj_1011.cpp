#include <iostream>
using namespace std;

int main() {
  int T,x,y,d;
  cin>>T;
  while(T>0){
    int i=1,cnt=0;
    cin>>x>>y;
    d=y-x;
    while(d>i){
      d-=i;
      cnt++;
      if(d<=i)
        break;
      d-=i;
      cnt++;
      i++;
    }
    cout<<++cnt<<'\n';
    T--;
  }
}
