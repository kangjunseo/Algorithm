#include <iostream>
#include <stack>
using namespace std;

stack <char> s;

int main(){
  while(1){
    char temp;
    cin>>temp;
    if(cin.eof()){  //EOF
      while(!s.empty()){
        cout<<s.top();
        s.pop();
      }
      break;
    }
    if(temp>='A' && temp<='Z'){ //알파벳 대문자
      cout<<temp;
    }else if(temp=='('){
      s.push(temp);
    }else if(temp==')'){
      while(!s.empty() && s.top()!='('){
        cout<<s.top();
        s.pop();
      }
      s.pop();
    }else{  //연산자
      if(temp=='*' || temp=='/'){
        while(!s.empty() && (s.top()=='*' || s.top()=='/')){
        cout<<s.top();
        s.pop();
      }
        s.push(temp);
      }else{  // '+' or '-'
        while(!s.empty() && s.top()!='('){
        cout<<s.top();
        s.pop();
        }
        s.push(temp);
      }
    }
  }
}
