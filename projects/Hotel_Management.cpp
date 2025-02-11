#include <iostream>
using namespace std;



int main(){
    int quant,sum =0;
    int choice;
    string items[]={"Rooms","Pasta","Burger","Noodles","Shake","Chiken "};
    //quantity
    int Quantities[6]={0};
    //sold
    int soldes[6]={0};
    //Total
    int Total_price[6]={0};
    cout <<"\n\t\tQuantity of items we have \n\n";
    for (int i=0;i<6;i++){
        cout <<" "<<items[i]<<" available :";
        cin>>Quantities[i];
    }
    m:
    cout <<"\n\t\t please select from the menu options :\n";
    for (int i=0;i<6;i++){
        cout <<i+1<<") "<<items[i]<<"\n";
    }
    cout <<"7) infomation regarding sales and collections\n";
    cout <<"8) Exit\n";
    cout <<"please enter your choice ! :";
    cin>>choice;
    
    switch (choice) {
        case 1:
            cout <<"\nenter the number of rooms you want :";
            cin>>quant;
            if (Quantities[0]-soldes[0]>=quant ){
                soldes[0]+=quant;
                Total_price[0]+=quant*1200;
                cout <<"\t "<<quant<<" rooms has been alloted for you";
            }else {
                cout <<"ther is just "<<Quantities[0]-soldes[0]<<" roomes remaining in the hotel";
                }
            
            break;
        case 2:
            cout <<"\nenter Pasta quantity  :";
            cin>>quant;
            if (Quantities[1]-soldes[1]>=quant ){
                soldes[1]+=quant;
                Total_price[1]+=quant*30;
                cout <<"\t "<<quant<<" pasta is in the order";
            }else {
                cout <<"ther is just "<<Quantities[1]-soldes[1]<<" past remaining in the hotel resturent";
                }
            break;
        case 3:
            cout <<"\nenter Burger  quantity  :";
            cin>>quant;
            if (Quantities[2]-soldes[2]>=quant ){
                soldes[2]+=quant;
                Total_price[2]+=quant*60;
                cout <<"\t "<<quant<<" Burger  is in the order";
            }else {
                cout <<"ther is just "<<Quantities[2]-soldes[2]<<" Burger remaining in the hotel resturent";
                }
            break;
        case 4:
            cout <<"\nenter Noodeles quantity  :";
            cin>>quant;
            if (Quantities[3]-soldes[3]>=quant ){
                soldes[3]+=quant;
                Total_price[3]+=quant*50;
                cout <<"\t "<<quant<<" Noodeles is in the order";
            }else {
                cout <<"ther is just "<<Quantities[3]-soldes[3]<<" Noodeles remaining in the hotel resturent";
                }
            break;
        case 5:
            cout <<"\nenter Shake quantity  :";
            cin>>quant;
            if (Quantities[4]-soldes[4]>=quant ){
                soldes[4]+=quant;
                Total_price[4]+=quant*30;
                cout <<"\t "<<quant<<" Shake is in the order";
            }else {
                cout <<"ther is just "<<Quantities[4]-soldes[4]<<" Shake remaining in the hotel resturent";
                }
            break;
        case 6:
            cout <<"\nenter Chiken quantity  :";
            cin>>quant;
            if (Quantities[5]-soldes[5]>=quant ){
                soldes[5]+=quant;
                Total_price[5]+=quant*30;
                cout <<"\t "<<quant<<" Chiken is in the order";
            }else {
                cout <<"ther is just "<<Quantities[5]-soldes[5]<<" Chiken remaining in the hotel resturent";
                }
            break;
        case 7:
            for (int i=0;i<6;i++){
cout<<"\n----------------------------------------------\n";

                cout <<"\t\tDetailes about sales and collections :\n";
                cout <<"quantity of "<<items[i]<< " we have : "<<Quantities[i]<<"\n";
                cout <<"quantity of "<<items[i]<<" we   sale :"<<soldes[i]<<"\n";
                cout<<"quantity of the remaining "<<items[i]<<" :  "<<Quantities[i]-soldes[i]<<"\n";
                cout <<"Total" <<items[i]<<" collection for the Day :"<<Total_price[i];
cout <<"\n------------------------------------------------\n";
            }

            break;
        case 8:
            
           for (int i=0;i<6;i++)sum+=Total_price[i];
           cout <<"total revenue for today is : "<<sum<<endl;
        exit(0);
            break;
        default:
            cout <<"please selecte the number mentioned above  !!";
            break;
    }
    goto m;

 return 0;
}
