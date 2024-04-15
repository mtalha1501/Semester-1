#include<iostream>
using namespace std;
void orderFood(string [], int [],int &idx_cart );
main()
{
    int idx_Cart=0;
    string cart[idx_Cart];
    int NumCart[idx_Cart];

    orderFood(cart, NumCart, idx_Cart);
    
    for(int i=0; i<idx_Cart; i++){
        cout<<cart[i]<<endl;
    }

    return 0;
}

void orderFood(string cart[], int NumCart[],int &idx_cart ){
    int order_choice=0;
    while(order_choice!=7){
    cout<<"1. Pizza"<<endl;
    cout<<"2. Burger"<<endl;
    cout<<"3. Fries"<<endl;
    cout<<"4. Sandwitches"<<endl;
    cout<<"5. Drinks"<<endl;
    cout<<"6. Desserts"<<endl;
    cout<<"7. Back"<<endl;
    cin>>order_choice;

    switch(order_choice){
        case 1:
        cart[idx_cart]="Pizza";
        idx_cart++;

        case 2:
        cart[idx_cart]="Burger";
        idx_cart++;

        case 3:
        cart[idx_cart]="Fries";
        idx_cart++;

        case 4:
        cart[idx_cart]="Sandwitches";
        idx_cart++;

        case 5:
        cart[idx_cart]="Drinks";
        idx_cart++;

        case 6:
        cart[idx_cart]="Desserts";
        idx_cart++;

    }
    }

}