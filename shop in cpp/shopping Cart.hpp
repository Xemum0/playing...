//
//  shopping Cart.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef shopping_Cart_hpp
#define shopping_Cart_hpp

#include <iostream>
using namespace std;
class ShoppingCart{
private:
    string dateadded;
    long ProductId;
    int Quantity;
    string CartId;
public:
    ShoppingCart(){};
    void addcartitems();
    void Updatequantity();
    void showCart();
    void Checkout();
};


#endif /* shopping_Cart_hpp */
