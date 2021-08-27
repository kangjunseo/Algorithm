#include <iostream>
#include <vector> 
#include <string> 
#include <cmath>
#include <algorithm>
using namespace std;

long int ABC[26]={0,};

void checkABC(string& str){
  for(int i=0;i<str.size();i++){
    ABC[str[i]-65]+=pow(10,str.size()-i-1);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N,sum=0;
  cin>>N;
  vector<string> v(10);
  while(N--){
    string str;
    cin>>str;
    checkABC(str);
  }
  sort(ABC,ABC+26,greater<long int>());
  for(int i=0;i<10;i++){
    sum+=(9-i)*ABC[i];
  }
  cout<<sum;
}
