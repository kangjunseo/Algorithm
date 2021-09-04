#include <iostream>
using namespace std;

long long int A,B,C;

long long int DNC(long long int root,long long int exp){
  if(exp==0)
    return 1;
  long long int ans=DNC(root,exp/2);  //divide
  ans=ans*ans%C;
  if(exp%2==1)
    return ans*root%C;    //conquer
  return ans;
}

int main() {
  cin>>A>>B>>C;
  cout<<DNC(A,B)%C;
}
