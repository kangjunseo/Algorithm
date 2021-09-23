#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int divider = 1000000007;
long A[2][2]={{1,1},{1,0}}; //calculate fibonacci by matrix
long AB[2][2]={{1,1},{1,0}}; 
long Tmp[2][2];  
stack <long> s;
void DNQ(long long B){
    if(B==1){
        return;
    }else if(B%2==0){
        s.push(2);
        DNQ(B/2);
    }else{
        s.push(1);
        DNQ(B-1);
    }
}

void SQ(){    //  square
    for(int i=0; i<2;i++){
        for(int j=0; j<2; j++){
            long temp=0;
            for(int k=0; k<2; k++){
                temp+=(AB[i][k]*AB[k][j])%divider;
            }
            Tmp[i][j]=temp%divider;
        }
    }
    memcpy(AB,Tmp,sizeof(Tmp));
}

void PDA(){   
    for(int i=0; i<2;i++){
        for(int j=0; j<2; j++){
            long temp=0;
            for(int k=0; k<2; k++){
                temp+=(AB[i][k]*A[k][j])%divider;
            }
            Tmp[i][j]=temp%divider;
        }
    }
    memcpy(AB,Tmp,sizeof(Tmp));
}

int main(){
    long long N;
    cin>>N;
    if(N==0){
        cout<<0;
        exit(0);
    }
    DNQ(N);
    while(!s.empty()){
        if(s.top()==2){
            SQ();
        }else{
            PDA();
        }
        s.pop();
    }

    cout<<AB[0][1]%divider;
}
