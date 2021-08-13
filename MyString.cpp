#include <iostream>

class MyString{
  private:
    int len;
    char* str;

  public:
    MyString(char a, int x);
    void print();
    int strlen();
    void addstr(const MyString &s);
    int equals(const MyString &s);
    int lex_order(const MyString &s);
};

MyString::MyString(char a, int x)
  :len(x){
    str = new char[x];
    for (int i=0;i<x;i++)
      str[i]=a;
  }

void MyString::print(){
  std::cout<<str<<std::endl;
}

int MyString::strlen(){return len;}

void MyString::addstr(const MyString &s){
  int temp = len;
  char* tempstr = str;
  len +=s.len;
  str = new char[len];
  for(int i=0;i<temp;i++)
    str[i]=tempstr[i];
  
  for(int i=temp;i<len;i++)
    str[i]=s.str[i-temp];
}

int MyString::equals(const MyString &s){
  if(len!=s.len)
    return 0;
  else{
    for(int i=0;i<len;i++)
      if(str[i]!=s.str[i])
        return 0;   
    }
  return 1;
}

int MyString::lex_order(const MyString &s){
  int n = (len<s.len)? len : s.len;
  for(int i=0;i<n;i++){
    if(str[i]<s.str[i])
      return 1;
    else if(str[i]>s.str[i])
      return -1;
  }
  if (len == s.len)
    return 0;
  else if(len<s.len)
    return 1;
  else
    return -1;
}

int main() {
  MyString str('b',2);
  MyString str2('a',3);
  
  str.print();
  str2.print();
  std::cout<<str.lex_order(str2)<<std::endl;
}
