//
//  Customer.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef Customer_hpp
#define Customer_hpp

#include "User.hpp"
#include "shopping Cart.hpp"
#include "Order.hpp"

struct creditcard{
    string pin;
    string pan;
    string expiredon;
    string cardcompany;
    float accountbalance;
    
};
class Costumer :public User{
public:
    Costumer(string User){
        setUserinfo(User);
        setinfo(User);
        
    };

    void Menu();
    
    
private:
    string adress;
    creditcard card;
    string username;
    //
    void setinfo(string);
    void Order();
    void printinfo();
    void buy();
    void gotostore();
    bool Cardchecker(string ,string ,string ,string );
    void updateprofile();
    void setUserinfo(string);

};

#endif /* Customer_hpp */
