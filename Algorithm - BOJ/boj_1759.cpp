#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int L,C;
char abc[15];
string current="";  //NULL로 초기화하면 에러가 나니까 ""로!

bool IsPw(string cur){
  int vowels=0, consonants=0; //모음, 자음(자음이 consonants라는 것을 처음 알게 되었다...)
  for(int i=0;i<cur.size();i++){
    char temp = cur.at(i);
    if(temp=='a' || temp=='e' || temp=='i' || temp=='o' || temp=='u')
      vowels++;
    else
      consonants++;
  }
  if(vowels>=1 && consonants>=2)
    return true;
  return false;
}

void pw(int f, int d){ //first, depth
    if(d==L && IsPw(current)){
    cout<<current<<'\n';
    return;
  }
  for(int i=f; i<C;i++){
    current.push_back(abc[i]);
    pw(i+1,d+1);
    current.pop_back();
  }
}

int main() {
  cin>>L>>C;  
  for(int i=0;i<C;i++)
    cin>>abc[i];
  sort(abc,abc+C);
  pw(0,0);
}
