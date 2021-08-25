#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
  }

  void AddDay(int inc){
    day_+=inc;
    while(day_>28){
      if(month_==2){ //I didn't used switch beacuse it makes code too thin and longer!
        if (year_%4==0 && year_%100!=0){
          if(day_>29){
            day_-=29;
            month_++;
          }else
            break;
          
        }else if(year_%400==0){
          if(day_>29){
          day_-=29;
          month_++;
          }else
            break;
        }
        else{
        day_-=28;
        month_++;
          }
      }else if(month_==4 || month_==6 ||month_==9 ||month_==11){
        if(day_>30){
          day_-=30;
          month_++;
        }
      }else{
        if(day_>31){
          day_-=31;
          month_++;
        }
      }
    }
    if(month_>12){
      AddMonth(0);
    }
  }

  void AddMonth(int inc){
    month_ += inc;
    year_ += month_/12;
    month_ %= 12;
    if(month_==0){
      month_=12;
      year_--;
    }
    AddDay(0);
  }

  void AddYear(int inc){
    year_ += inc;
  }

  void ShowDate(){
    std::cout<<"오늘의 날짜는 "<<year_<<"년 "<<month_<<"월 "<<day_<<"일 입니다.\n";
  }
};

int main(){
  Date today;
  today.SetDate(2000,2,28);
  today.ShowDate();
  today.AddDay(1);
  today.ShowDate();
}
