#include<iostream>
using namespace std;

void printUserPhase();
void signup();
bool checkUser(string username);
void foodmenu();
int checkUserIndex(string username);
void signin();
int signInPhase();


string admin_code = "abcd1234";
string usernameDB[100], passwrodDB[100], roleDB[100];
    int user_index = 0;

main(){
    
    



    system("color 09");
    printUserPhase();
    foodmenu();


    int choice=0;
    while(choice!=3){
    cout<<"     Enter 1 to login: "<<endl;
    cout<<"     Enter 2 to sign up: "<<endl;
    cin>>choice;

    if(choice==1){
        signInPhase();
        signin();
    }
    else if(choice==2){
        signup();
    }
    else{
        cout<<"Invalid Choice.... Enter 1 to try again..";
        cin>>choice;
        if(choice==1){
            main();
        }
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

int signInphase(){

    


}


void signup(){
    int choice_Error;
    string username, password, role, sec_code;
    cout<<"Enter username: ";
    cin>>username;

    if (!checkUser(username)){
        cout<<"Enter Password (min 6 characters): ";
        cin>>password;
        if(password.length()>=6){
            cout<<"Enter role (Admin or Customer): ";
            cin>>role;
            if(role=="Admin"|| role=="Customer" ){
                if(role=="Admin"){
                    cout<<"Enter security code for ADmin: ";
                    cin>>sec_code;
                    if(sec_code==admin_code){
                        usernameDB[user_index] = username;
                        passwrodDB[user_index] = password;
                        roleDB[user_index] = role;
                        user_index++;
                    }
                    else{
                        system("cls");
                        cout<<"Incorrect ... You can't sign up as admin..."<<endl;
                        cout<<"Enter 1 to try again, 2 to menu :";
                        cin>>choice_Error;
                        if(choice_Error==1){
                        signup();
                        }
                    }
                }
                else{
                    usernameDB[user_index]=username;
                    passwrodDB[user_index]=password;
                    roleDB[user_index]=role;
                    user_index++;
                }
            }
            else{
                system("cls");
                cout<<"Role must be customer or admin..."<<endl;
                cout<<"Enter 1 to try again, 2 to main menu :";
                cin>>choice_Error;
                if(choice_Error==1){
                signup();
                }
                else{
                main();
                }
            }

        }
        else{
            system("cls");
            cout<<"Password length must be 6.."<<endl;
            cout<<"Enter 1 to try again, 2 to main menu:";
            cin>>choice_Error;
            if(choice_Error==1){
            signup();
            }
            else{
            main();
            }
        }
    }
    else{
        system("cls");
        cout<<"User Exists !"<<endl;
        cout<<"Enter 1 to try again, two to main menu :";
        cin>>choice_Error;
        if(choice_Error==1){
            signup();
        }
        else{
            main();
        }
    }
}

void signin()
{
    string username,password,role;
    int errorChoice, signin_index;
    cout<<"Enter Username: ";
    cin>>username;
    if(checkUser){
        signin_index=checkUserIndex(username);
        cout<<"Enter Password: ";
        cin>>password;
        if(passwrodDB[signin_index]==password){
            role=roleDB[signin_index];
            if(role=="Customer"){
                
            }
            else if(role=="Admin"){

            }
        }
    }
    else{
        cout<<"User not found..."<<endl;
        cout<<"Enter 1 to try again..";
        cin>>errorChoice;
        if(errorChoice==1){
            signin();
        }
    }
}
bool checkUser(string username){
    for(int i=0; i<=user_index; i++){
        if(username == usernameDB[i] ){
            return true;
        }
    }
    return false;
}

int checkUserIndex(string username)
{
    for(int i=0; i<=user_index; i++){
        if(username == usernameDB[i] ){
            return i;
        }
    }
}





