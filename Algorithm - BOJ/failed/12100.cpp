#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,cnt=0;
int _2048[20][20];
int arr[20][20];
int ans[10000]={0,};

void print(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout<<arr[i][j]<<' ';
  cout<<'\n';
  }
}

bool IsBound(int i){
  return i>=0 && i<N;
}

void merge(int i, int j, int I, int J){
  if(arr[i][j]==-1 || arr[I][J]==-1)
    return;
  arr[i][j]*=2;
  arr[I][J]=-1;
}

void right(){
  for(int i=0; i<N;i++){  //빈 공간 이동
    for(int j=N-1;j>=0;j--){
      if(arr[i][j]!=-1){
        int tcnt=1;
        while(IsBound(j+tcnt) && arr[i][j+tcnt]==-1){
          arr[i][j+tcnt]=arr[i][j+tcnt-1];
          arr[i][j+tcnt-1]=-1;
          tcnt++;
        }
      }
    }
  }
  
  for(int j=N-1;j>=0;j--){
    for(int i=N-1;i>=0;i--){
      if(arr[i][j]==arr[i][j-1])
        merge(i,j,i,j-1);
    }
    for(int i=N-1;i>=0;i--){  //merge 이후 빈자리 메꾸기 
      if(IsBound(j-2)&&arr[i][j-1]==-1){
        arr[i][j-1]=arr[i][j-2];
        arr[i][j-2]=-1;
      }
    }
  }
}

void left(){
  for(int i=0; i<N;i++){  //빈 공간 이동
    for(int j=0;j<N;j++){
      if(arr[i][j]!=-1){
        int tcnt=1;
        while(IsBound(j-tcnt) && arr[i][j-tcnt]==-1){
          arr[i][j-tcnt]=arr[i][j-tcnt+1];
          arr[i][j-tcnt+1]=-1;
          tcnt++;
        }
      }
    }
  }

  for(int j=0;j<N;j++){
    for(int i=0;i<N;i++){
      if(arr[i][j]==arr[i][j+1])
        merge(i,j,i,j+1);
    }
    for(int i=0;i<N;i++){
      if(IsBound(j+2)&&arr[i][j+1]==-1){
        arr[i][j+1]=arr[i][j+2];
        arr[i][j+2]=-1;
      }
    }
  }
}

void up(){
  for(int j=0; j<N;j++){  //빈 공간 이동
    for(int i=0;i<N;i++){
      if(arr[i][j]!=-1){
        int tcnt=1;
        while(IsBound(i-tcnt) && arr[i-tcnt][j]==-1){
          arr[i-tcnt][j]=arr[i-tcnt+1][j];
          arr[i-tcnt+1][j]=-1;
          tcnt++;
        }
      }
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j]==arr[i+1][j])
        merge(i,j,i+1,j);
    }
    for(int j=0;j<N;j++){
      if(IsBound(i+2)&&arr[i+1][j]==-1){
        arr[i+1][j]=arr[i+2][j];
        arr[i+2][j]=-1;
      }
    }
  }
}

void down(){
  for(int j=0; j<N;j++){  //빈 공간 이동
    for(int i=N-1;i>=0;i--){
      if(arr[i][j]!=-1){
        int tcnt=1;
        while(IsBound(i+tcnt) && arr[i+tcnt][j]==-1){
          arr[i+tcnt][j]=arr[i+tcnt-1][j];
          arr[i+tcnt-1][j]=-1;
          tcnt++;
        }
      }
    }
  }

  for(int i=N-1;i>=0;i--){
    for(int j=N-1;j>=0;j--){
      if(arr[i][j]==arr[i-1][j])
        merge(i,j,i-1,j);
    }
    for(int j=N-1;j>=0;j--){
      if(IsBound(i-2)&&arr[i-1][j]==-1){
        arr[i-1][j]=arr[i-2][j];
        arr[i-2][j]=-1;
      }
    }
  }
}

void SearchMax(){
  int max = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j]>max)
        max=arr[i][j];
    }
  }
  ans[cnt++]=max;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;
  int temp;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>temp;
      if(temp==0)
        temp=-1;
      _2048[i][j]=temp;
    }
  }
  
  int cnt[5]={0,};
  while(1){
    copy(&_2048[0][0],&_2048[0][0]+100,&arr[0][0]);

    for(int i=0;i<5;i++){
      if(cnt[i]==0){
        right();
      }else if(cnt[i]==1){
        left();
      }else if(cnt[i]==2){
        up();
      }else if(cnt[i]==3){
        down();
      }
      SearchMax();
    }

    if(cnt[4]==3){  //Bruteforce from cnt={0,0,0,0,0} to cnt={3,3,3,3,3}
      cnt[4]=0;
      if(cnt[3]==3){
        cnt[3]=-1;
        if(cnt[2]==3){
          cnt[2]=-1;
          if(cnt[1]==3){
            cnt[1]=-1;
            if(cnt[0]==3)
              break;
            cnt[0]++;
          }
          cnt[1]++;
        }
        cnt[2]++;
      }
      cnt[3]++;
    }else{
      cnt[4]++;
    }
  }
  
  sort(ans,ans+1024,greater<int>());
  cout<<ans[0];
}
