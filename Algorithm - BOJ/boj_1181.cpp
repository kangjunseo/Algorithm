#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(string& s1, string& s2){
  if(s1.size()==s2.size())
    return s1<s2;
  return s1.size() < s2.size(); 
}

int main(){
  int N;
  vector <string> v;
  cin>>N;
  string temp;
  while(N--){
    cin>>temp;
    v.push_back(temp);
  }

  sort(v.begin(),v.end(),cmp);
  string previous="abcdefghijklmnopabcdefghijklmnopabcdefghijklmnopabcdefghijklmnop"; // 길이 50이 넘는 아무 스트링
  for(auto it = v.begin(); it!=v.end();++it){
    if(previous == *it)
      continue;
    cout<<*it<<'\n';
    previous=*it;
  }
}
