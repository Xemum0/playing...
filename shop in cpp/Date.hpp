//
//  Date.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef Date_hpp
#define Date_hpp

#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream &,const Date &);
public:
    Date(){};
    Date (int,int ,int);
    void setYear (int);
    void setDay(int);
    void setmonth(int);
    int getYear()const{
        return year;
    }
    int getDay()const{
        return day;
    }
    int getMonth()const{
        return month;
    }
    
    private :
    int year,month,day;
};

#endif /* Date_hpp */
