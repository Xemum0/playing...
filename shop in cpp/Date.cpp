//
//  Date.cpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#include "Date.hpp"

Date::Date (int year,int month ,int day){
    setDay(day);
    setmonth(month);
    setYear(year);

};
void Date::setYear (int year){
    if (year>1900)this->year=year;
        else throw invalid_argument("invalid input error");
};
void Date::setDay(int day){
   if  (day>0 &&day <=31)
       this->day=day;
       else throw invalid_argument("invalid input error");
};
void Date::setmonth(int month){
    if  (month>=0&&month <=12){
        this ->month=month;

    }
       else throw invalid_argument("invalid input error");
};

ostream& operator<<(ostream &out,const Date & date){
    out <<"the registeration date : "<<date.year<<" /"<<date.month<<" /"<<date.day;
    return out;
};
