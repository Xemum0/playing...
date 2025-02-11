//
//  Order.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef Order_hpp
#define Order_hpp


#include "shopping info.hpp"
#include "Order info.hpp"

class Order{
public:
    void placeOrder();
    
private:
    int orderld;
    string dateCreated,dateShipped,customerName,customerid,statusofshipping,shippingld;
};
#endif /* Order_hpp */
