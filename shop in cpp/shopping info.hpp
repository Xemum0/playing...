//
//  shopping info.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef shopping_info_hpp
#define shopping_info_hpp

#include <iostream>
using namespace std;

class ShoppingInfo{
public:
    
    void updateShippinginfo();
private:
    int shippingld;
    string shippingType ;
    int shippingCost;
    int shippingRegionid;
};

#endif /* shopping_info_hpp */
