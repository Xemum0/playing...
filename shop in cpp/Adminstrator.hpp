//
//  Adminstrator.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef Adminstrator_hpp
#define Adminstrator_hpp
#include "User.hpp"

class Admin: public User{
public:
    void Menu();
    Admin():User("youcef@shop.com", "youcef2004", "offline", "youcef mhammdi bouzina",-1,2012,12,12){
        
    };
private:
    void removeproducts();
    void Editproduct();
    void addproducts();
    void myinfo()const;
    void BanUser();


};

#endif /* Adminstrator_hpp */
