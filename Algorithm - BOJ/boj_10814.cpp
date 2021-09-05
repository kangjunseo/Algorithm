#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Info{
  int age;
  int idx;
  string name;
};

bool cmp(Info i1, Info i2){
  if(i1.age==i2.age)
    return i1.idx<i2.idx;
  return i1.age<i2.age;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,age;
  string name;
  vector <Info> v;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>age>>name;
    Info temp={age,i,name};
    v.push_back(temp);
  }
  sort(v.begin(),v.end(),cmp);

  for(auto iter = v.begin();iter!=v.end();++iter)
    cout<<iter->age<<' '<<iter->name<<'\n';
}
