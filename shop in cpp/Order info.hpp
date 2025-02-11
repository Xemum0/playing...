//
//  Order info.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef Order_info_hpp
#define Order_info_hpp
#include <iostream>
using namespace std;

class OrderInfo{
public:
    
    void CalcTotalprice();
private:
    int  orderid,productid,quantity;
    string productName;
    float   unitCost,subtotal;
};

#endif /* Order_info_hpp */
