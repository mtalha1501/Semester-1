#include<iostream>
using namespace std;

void printUserPhase();
void foodmenu();
void SubMenu(string submenu);
bool checkUser(string username, int &user_index, string usernames[]);
bool signUp(string username, string passsword,string role, string users[], string passswords[], string roles[], int &user_index, int dataBaseSize);
int Admin_choice();
int Cusomer_choice();
void clearScreen();



main()
{

    int dataBaseSize=60;
    string users[dataBaseSize], roles[dataBaseSize], passwords[dataBaseSize];
    string fooditems[50]; int fooditemsPrice[50]; 
    string security_Code_Admin = "blazefood";
    int user_index=0;
    string UserReviews[50]; int user_Review_Index=0;
    int idx_Cart=0;
    string cart[idx_Cart];
    int NumCart[idx_Cart];

    system("cls");
    system("color 09");
    printUserPhase();



    int choice_option=0;
    while(choice_option!=3){
        cout<<"Press 1 to Login >"<<endl;
        cout<<"Press 2 to Sign Up >"<<endl;
        cout<<"Press 3 to exit <"<<endl;
        cin>>choice_option;
        if (choice_option==1){
            string username, password,role;
            cout<<"Enter username: ";
            cin>>username;
            cout<<"Enter password: ";
            cin>>password;
            if (checkUser(username, user_index, users)){

            }
            

        }
        if(choice_option==2){
            system("cls");
            int error_choice=0;
            string admin_signup;
            string username, role, password;
            cout<<"Enter your Username Here: ";
            cin>>username;
            cout<<"Enter your Password Here (min 6 characters): ";
            cin>>password;
            cout<<"Enter your role (Admin or Customer): ";
            cin>>role;
            if (role == "Admin"){
                cout<<"Enter Security Code for Admin: ";
                cin>>admin_signup;
                if(admin_signup==security_Code_Admin){
                    continue;
                }
                else{
                    cout<<"You cannot Sign up as Admin"<<endl;
                    cout<<"Press 1 to try again..."<<endl;
                    cin>>error_choice;
                    if(error_choice==1){
                        main();
                    }
                }
            }
            bool SignUp = signUp(username, password, role, users, passwords, roles, user_index, dataBaseSize);
            if (SignUp==true){
                cout<<"Signed Up successfully.";
                if(role=="Admin"){
                        Admin_choice();
                }
                if(role=="Customer"){
                        Cusomer_choice();
                }
            }
            if(!SignUp){
                cout<<"Username already exists"<<endl;
                cout<<"Press 1 to try again.";
                cin>>error_choice;
                if(error_choice==1){
                    main();
                }
            }

        }
        else{
            break;
        }
    }
    
    
}



bool checkUser(string username, int &user_index, string users[]){
    for(int i=0; i<=user_index; i++){
        if(username == users[i] ){
            return true;
        }
    }
    return false;
}

bool signUp(string username, string passsword,string role, string users[], string passswords[], string roles[], int &user_index, int dataBaseSize){
    bool isPresent = false;
    for(int i=0; i < user_index; i++ ){
        if(username == users[i]){
            isPresent = true;
        }

        if(isPresent){
        return false;
        }
        else if(user_index< dataBaseSize){
            users[user_index] = username;
            passswords[user_index] = passsword;
            roles[user_index] = role;
            user_index++;
        }
        else{
            return false;
        }
    }
    
}



int Admin_choice(){
    system("cls");
    SubMenu("Admin_Menu");
    int Admin_option;
    cout<<"1. Add a food item"<<endl;
    cout<<"2. Delete a food item"<<endl;
    cout<<"3. See all Food Items"<<endl;
    cout<<"3. Check Orders"<<endl;
    cout<<"4. See Stats"<<endl;
    cout<<"5. See all users"<<endl;
    cout<<"6. Delete User"<<endl;
    cout<<"67 Exit"<<endl;
    cin>>Admin_option;
    return Admin_option;
}

int Cusomer_choice(){
    system("cls");
    SubMenu("Customer_Menu");
    int cus_option;
    cout<<"1. See the Food Menu"<<endl;
    cout<<"2. Order Food"<<endl;

    cin>>cus_option;
    return cus_option;
}

void clearScreen(){
    system("cls");
    printUserPhase();

}

void checkMenu_Rates(){
    system("cls");
    SubMenu("Check Menu");
    cout<<"                >>>>>>>>>>>>    We Offer    <<<<<<<<<<<<                          "<<endl;
    for(int i=0; i<20; i++){
    cout<<"         1."<< "---------" << "Price: " << endl;

    }

}



void addFooditem(string fooditems[], int fooditemsPrice[]){

    string iName;
    int iPrice;
    cout<<"Enter the name of the item: ";
    cin>>iName;
    cout<<"Enter the price for this item: ";
    cin>>iPrice;





}

void User_Review(string User_Review[], int &user_Review_Index){
    string mes;
    cout<<"Enter your review: ";
    cin>>mes;
    cout<<"Your review has been sent to the adminstrator."<<endl;
    User_Review[user_Review_Index]=mes;
    user_Review_Index++;
}

void SubMenu(string submenu){
    string text = "Menu>"+ submenu;
    cout<<text;
    cout<<"_----------------_";
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

void printUserPhase(){
    cout<< R"(
                                                                                                                                                                           
    bbbbbbbb                                                                                                                                                   dddddddd
    b::::::b            lllllll                                                                ffffffffffffffff                                                d::::::d
    b::::::b            l:::::l                                                               f::::::::::::::::f                                               d::::::d 
    b::::::b            l:::::l                                                              f::::::::::::::::::f                                              d::::::d
    b:::::b            l:::::l                                                              f::::::fffffff::::::f                                              d:::::d 
    b:::::bbbbbbbbb     l::::l   aaaaaaaaaaaaa   zzzzzzzzzzzzzzzzz    eeeeeeeeeeee          f:::::f       ffffff   ooooooooooo      ooooooooooo       ddddddddd:::::d 
    b::::::::::::::bb   l::::l   a::::::::::::a  z:::::::::::::::z  ee::::::::::::ee        f:::::f              oo:::::::::::oo  oo:::::::::::oo   dd::::::::::::::d 
    b::::::::::::::::b  l::::l   aaaaaaaaa:::::a z::::::::::::::z  e::::::eeeee:::::ee      f::::::ffffff       o:::::::::::::::oo:::::::::::::::o d::::::::::::::::d
    b:::::bbbbb:::::::b l::::l            a::::a zzzzzzzz::::::z  e::::::e     e:::::e      f:::::::::::f       o:::::ooooo:::::oo:::::ooooo:::::od:::::::ddddd:::::d 
    b:::::b    b::::::b l::::l     aaaaaaa:::::a       z::::::z   e:::::::eeeee::::::e      f:::::::::::f       o::::o     o::::oo::::o     o::::od::::::d    d:::::d 
    b:::::b     b:::::b l::::l   aa::::::::::::a      z::::::z    e:::::::::::::::::e       f::::::ffffff       o::::o     o::::oo::::o     o::::od:::::d     d:::::d 
    b:::::b     b:::::b l::::l  a::::aaaa::::::a     z::::::z     e::::::eeeeeeeeeee        f:::::f             o::::o     o::::oo::::o     o::::od:::::d     d:::::d 
    b:::::b     b:::::b l::::l a::::a    a:::::a    z::::::z      e:::::::e                 f:::::f             o::::o     o::::oo::::o     o::::od:::::d     d:::::d 
    b:::::bbbbbb::::::bl::::::la::::a    a:::::a   z::::::zzzzzzzze::::::::e               f:::::::f            o:::::ooooo:::::oo:::::ooooo:::::od::::::ddddd::::::dd
    b::::::::::::::::b l::::::la:::::aaaa::::::a  z::::::::::::::z e::::::::eeeeeeee       f:::::::f            o:::::::::::::::oo:::::::::::::::o d:::::::::::::::::d
    b:::::::::::::::b  l::::::l a::::::::::aa:::az:::::::::::::::z  ee:::::::::::::e       f:::::::f             oo:::::::::::oo  oo:::::::::::oo   d:::::::::ddd::::d
    bbbbbbbbbbbbbbbb   llllllll  aaaaaaaaaa  aaaazzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee       fffffffff               ooooooooooo      ooooooooooo      ddddddddd   ddddd
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    )";
}

void foodmenu()
{
    system("color 70");
    cout <<"                       >>>>>>>>>We offer the Following Food Items<<<<<<<<<<<                           "<<endl;
    cout<<"                                                                                                        "<<endl;
    cout<<" _________________________________________________________________________________________________      "<<endl;
    cout<<" |   Burgers:           |    Pizza:                        |   Sandwiches:                       |      "<<endl;
    cout<<" |    > Zinger Burger   |         > Pepperoni              |      > Chicken Sandwich             |      "<<endl;
    cout<<" |    > HamBurger       |         > Veggie                 |      > Egg Sandwich                 |      "<<endl;
    cout<<" |    > Beaf Burger     |         > Margherita Pizza       |      > Beaf Sandwich                |      "<<endl;
    cout<<" |                      |         > Chicken Stuffer Pizza  |      > Vegetable Sandwich           |      "<<endl;
    cout<<" |   Fries:             |         > Kabab Stuffer Pizza    |   Nuggets:                          |      "<<endl;
    cout<<" |    > Large           |         > Chicken Fajita Pizza   |      > Chicken Nuggets              |      "<<endl;
    cout<<" |    > Medium          |         > BBQ chicken Pizza      |      > Beaf Nuggets                 |      "<<endl;
    cout<<" |    > Small           |         > Peri Peri Pizza        |   Wings:                            |      "<<endl;
    cout<<" |     (French Fries)   |                                  |      > Fried Chicken Wings (6,12)   |      "<<endl;
    cout<<" |                      |                                  |      > Chicken Drumstick   (6,12)   |      "<<endl;
    cout<<" |                      |                                  |      > Ranch Wings         (12,24)  |      "<<endl;
    cout<<" |_______________________________________________________________________________________________|      "<<endl;
    cout<<"        _____________________________________________________________________                           "<<endl;
    cout<<"        |                         >>>>> Desserts <<<<<                      |                           "<<endl;
    cout<<"        |   > Cupcakes ( All Flavours)                                      |                           "<<endl;
    cout<<"        |   > Muffins                                                       |                           "<<endl;
    cout<<"        |   > Custards ( Mango, Choclate, Vanilla, Strawberry )             |                           "<<endl;
    cout<<"        |___________________________________________________________________|                           "<<endl;

}





