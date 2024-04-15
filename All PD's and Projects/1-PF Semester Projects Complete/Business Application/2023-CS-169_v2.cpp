#include <iostream>
#include <iomanip>
#include <conio.h>          // Validations, File Handlng, keys with vectors and colors. <<<Remaining Tasks
#include<windows.h>
#include<limits>
#include <fstream>
#include <string>
using namespace std;
// For Startup
void start_menu(string[], string[], string[], int &, string[], int[], int[], int[], int &, int &, int &, string &, string &, string &, string[], string[], int &, string[], int[], int &, int &);
void smallMenu(string);
void tryAgain_Goback(int&,string);
void printHeader();
void SignIn_Header();
void SignUp_Header();
void contact_page();
void Social_Accounts_page();

// mutual functions
void changeSystemColor(string &, string[], int &, int &);
void app_settings(string &, string, string[], string[], int &, string[], int &);
void change_Password(string, string[], string[], int &);

// sign in and sign up
void sign_in(string[], string[], string[], int &, string[], int[], int[], int[], int &, int &, int &, string &, string &, string &, string[], string[], int &, string[], int[], int &, int &);
string signIn(string, string[], string, string[], string[], int &, string &);
string SignUp(string, string[], string, string[], string, string[], int &, string &);
void sign_Up_in(string[], string[], string[], int &, string[], int[], int[], int[], int &, int &, int &, string &, string &, string &, string[], string[], int &, string[], int[], int &, int &);
bool doesUserNameExists(string, string[], int &);
int userNameIndex(string, string[], int &);

// Validation Functions
bool isValid_UserName(string);
bool password_vald(string);
bool is_valid_color_code(string color_code);

static void gotoxy(int , int );
void Color(int);
void hideAndVisibleCursor(bool isShow);



// functions for user
void user(string[], int[], int[], int[], int &, int &, int &, string[], string &, string &, string[], int &, string[], string[], int &, string[], int[], int &, int &);
void print_item_rates(string[], int[], int &);
void fn_buy_items(string[], int[], int &);
int bill_calculator(int[], int[], int &, int &);
int tax_calculator(int[], int[], int &, int &);
void bill_view(string[], int[], int[], int &, int &);
void empty_cart(int[], int &);
void fn_paybill(int[], int[], int[], int &, int &, int &);
void customerSupport(string[], int &, string[], int[], int &);
void write_complain(string[], int &);
void review_rating(string[], int[], int &);

// manager
void manager(string[], int[], int[], int[], int &, int &, int &, string[], string[], string[], int &, string &, string &, string &, string[], string[], int &, string[], int[], int &, int &);
void printSalesRecord(string[], int[], int[], int &, int &);
void checkTotalRavenue(int &);
void updateRecord(string[], int[], int &, int &);
void CheckListedProducts(string[], int &);
void updateRates(string[], int[], int &);
void UpdateTaxRate(int &);
void showUsers(string[], string[], int &);
void removeUser(string[], string[], string[], int &);
void editRecord(string[], int[], int[], int[], int &);
void addProduct(string[], int[], int[], int[], int &);
void removeProduct(string[], int[], int[], int[], int &);
bool checkProduct(string[], string, int &);
void change_Admin_Code(string &);
void show_complains(string[], int);
void show_reviews(string[], int[], int);

void load_users_data(string [],string [],string roles_data[], int &);
void save_users_data(string [],string [],string roles_data[], int &);
string parseData(string record, int field);
void loadProducts(string [],int [],int [],int [],int &);
void saveProducts(string [],int [],int [],int [],int);
void save_reviews(string [], int [],int);
void load_reviews(string [], int[],int &);

int convertStoInt(string );

//main
main()
{
    
    int TotalRevenue = 0;
    string products[30] = {"Biscuits", "Lays", "Bread_pack", "Milk_Pack", "Register", "Marker", "Rice_Pack", "Flour_Pack"};
    int ProductPrice[30] = {50, 70, 200, 50, 100, 60, 250, 150};
    int items_bought_by_user[30];
    int total_bought_items[30];
    int productIndex = 8;
    int taxRate = 10;
    int totalSales = 0;
    for (int i = 0; i < productIndex; i++)
    {
        total_bought_items[i] = 0;
        items_bought_by_user[i] = 0;
    }
    // DataBases
    string user_Names_data[30];
    string paswords_data[30];
    string roles_data[30];
    int userName_index = 0;
    // Review and Complains System
    string reviews[30];
    string complains[30];
    int complains_index = 0;

    // Admin Code:
    string admin_code = "blazefood";

    // Username variable for entered in sign in username, to be used in change password
    string runing_username = "";

    // theme (app settings)
    int theme_index = 0;
    string themes_data[30];
    string theme_color = themes_data[theme_index];

    // Review System
    string review[30];
    int ratings[30];
    int review_index = 0;
    // loading 
    load_users_data(user_Names_data,paswords_data,roles_data,userName_index);
    loadProducts(products,ProductPrice,items_bought_by_user,total_bought_items,productIndex);
    save_reviews(reviews,ratings,review_index);

    hideAndVisibleCursor(false);
    // Starting
    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, ProductPrice, items_bought_by_user, total_bought_items, taxRate, productIndex, TotalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
   
    //Saving
    save_users_data(user_Names_data,paswords_data,roles_data,userName_index);
    saveProducts(products,ProductPrice,items_bought_by_user,total_bought_items,productIndex);
    save_reviews(reviews,ratings,review_index);

}

void start_menu(string user_Names_data[], string paswords_data[], string roles_data[], int &userName_index, string products[], int productPrice[], int productBoughtByUser[], int totalProductsBought[], int &taxRate, int &productIndex, int &totalRevenue, string &admin_code, string &theme_color, string &runing_username, string themes_data[], string complains[], int &complains_index, string review[], int ratings[], int &review_index, int &theme_index)
{

    int opt_length = 3;
    string options[opt_length] = {"Sign In", "Sign Up", "Exit"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();

        for(int i = 0; i < opt_length; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<options[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< options[i]<<endl;
            }
        }


        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }            // When user press any other key then up,down and enter, program don't blinks or crashes
        
        if (key == 80)
        {
            if (current_opt < opt_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if (key == 13)
        {
            if (current_opt == 0)
            {
                sign_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
            }
            else if (current_opt == 1)
            {
                sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
            }
            else if (current_opt == 2)
            {
                break;
            }
        }
            
        
    }
}
void sign_in(string user_Names_data[], string paswords_data[], string roles_data[], int &userName_index, string products[], int ProductPrice[], int items_bought_by_user[], int totalitems_bought_by_user[], int &taxRate, int &productIndex, int &totalRevenue, string &admin_code, string &theme_color, string &runing_username, string themes_data[], string complains[], int &complains_index, string review[], int ratings[], int &review_index, int &theme_index)
{
    system("cls");
    SignIn_Header();
    int errorChoice=0;
    string signInOption;
    string userName;
    string password;
    cin.clear();
    cin.sync();
    cout << "Enter userName: ";
    getline(cin, userName);
    cout << "Enter Password: ";
    cin.clear();
    cin.sync();
    getline(cin, password);
    runing_username = userName;

    signInOption = signIn(userName, user_Names_data, password, paswords_data, roles_data, userName_index, admin_code);
    if (signInOption == "user")
    {
        user(products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, productIndex, taxRate, totalRevenue, user_Names_data, theme_color, runing_username, paswords_data, userName_index, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
    }
    else if (signInOption == "manager")
    {
        manager(products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, productIndex, taxRate, totalRevenue, user_Names_data, roles_data, paswords_data, userName_index, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
    }
    else if (signInOption == "Invalid Password")
    {
        cout << "Invalid Password \n";
        Sleep(1500);
        tryAgain_Goback(errorChoice,"signIn");
        if (errorChoice == 0)
        {
            sign_in(user_Names_data, paswords_data, roles_data, userName_index, products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
        }
        else if (errorChoice == 1)
        {
            start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
        }
    }
    else if (signInOption == "Not Found")
    {
        cout << "Invalid userName.Rather Sign Up \n";
        Sleep(1500);
        tryAgain_Goback(errorChoice,"signIn");
        if (errorChoice == 0)
        {
            sign_in(user_Names_data, paswords_data, roles_data, userName_index, products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
        }
        else if (errorChoice == 1)
        {
            start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, ProductPrice, items_bought_by_user, totalitems_bought_by_user, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_username, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
        }
    }
}
string signIn(string userName, string user_Names_data[], string password, string paswords_data[], string roles_data[], int &userName_index, string &admin_code)
{
    int index;
    string result;
    bool isAuser;
    isAuser = doesUserNameExists(userName, user_Names_data, userName_index);
    if (isAuser)
    {
        index = userNameIndex(userName, user_Names_data, userName_index);
        if (password == paswords_data[index])
        {
            if (roles_data[index] == "user")
            {
                result = "user";
            }
            else if (roles_data[index] == "manager")
            {
                result = "manager";
            }
        }
        else
        {
            result = "Invalid Password";
        }
    }
    else
    {
        result = "Not Found";
    }
    return result;
}
void sign_Up_in(string user_Names_data[], string paswords_data[], string roles_data[], int &userName_index, string products[], int productPrice[], int productBoughtByUser[], int totalProductsBought[], int &taxRate, int &productIndex, int &totalRevenue, string &admin_code, string &theme_color, string &runing_usernme, string themes_data[], string complains[], int &complains_index, string review[], int ratings[], int &review_index, int &theme_index)
{
    string adminCode;
    system("cls");
    SignUp_Header();
    string userName, password, role, signUp_op;
    int errorChoice;
    cout <<"\t\t\t\t\t\t"<< "Enter User Name: ";
    getline(cin, userName);
    if (isValid_UserName(userName))
    {
        cin.clear();
        cin.sync();
        cout <<"\t\t\t\t\t"<< "Enter Password (min 6 characters && No Space && No Comma): ";
        getline(cin, password);

        if(password_vald(password)){

            int current_opt = 0, option_length = 2;
            string role_keys[option_length] = {"Manager", "User"};
            char key;

            while(true){
                system("cls");
                SignUp_Header();
                cout <<"\t\t\t\t\t"<< "Select Your Role  "<<endl;
                for(int i = 0; i <2; i++){
                    if(i == current_opt){
                        Color(06);
                        cout <<"\t\t\t\t\t\t\t"<<"> "<<role_keys[i] <<endl;
                        Color(07);
                        }
                    else
                    {
                        cout <<"\t\t\t\t\t\t\t"<< role_keys[i]<<endl;
                    }
                }

                key = 0;
                while(!(key == 13 || key == 80 || key == 72)){
                key = _getch();
                }

                if(key == 80){
                    if(current_opt < option_length - 1){
                        current_opt++;
                    }
                }
                else if(key == 72){
                    if(current_opt > 0){
                        current_opt--;
                    }
                }
                else if(key == 13){
                    if(current_opt == 0){
                        role = "manager";
                    break;
                    }
                else if(current_opt == 1){
                    role = "user";
                    break;
                }
            }
            }

            signUp_op = SignUp(userName, user_Names_data, password, paswords_data, role, roles_data, userName_index, admin_code);

            if (signUp_op == "user")
            {
                user_Names_data[userName_index] = userName;
                paswords_data[userName_index] = password;
                roles_data[userName_index] = role;
                userName_index++;
                cout <<"\t\t\t\t\t\t"<< "Signed Up Successfully...";
                Sleep(2000);
            }
            else if (signUp_op == "manager")
            {
                cin.clear();
                cin.sync();
                cout <<"\t\t\t\t\t\t\t"<< "Enter admin code: ";
                getline(cin ,adminCode);
                if(adminCode == admin_code)
                {
                    user_Names_data[userName_index] = userName;
                    paswords_data[userName_index] = password;
                    roles_data[userName_index] = role;
                    userName_index++;
                }
                else
                {
                    cout <<"\t\t\t\t\t\t\t"<< "Admin code is incorrect   \n";
                    Sleep(1500);
                    tryAgain_Goback(errorChoice,"signUp");
                    if (errorChoice == 0)
                    {
                        sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                    }
                    else if (errorChoice == 1)
                    {
                    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                    }
                }
            }
            else if (signUp_op == "incorrect Role")
            {
                cout <<"\t\t\t\t\t\t\t"<< "Role must be user or manager \n";
                Sleep(1500);
                tryAgain_Goback(errorChoice,"signUp");
                if (errorChoice == 0)
                {
                    sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
                else if (errorChoice == 1)
                {
                    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
            }
            else if (signUp_op == "incorrect Password")
            {
                cout <<"\t\t\t\t\t\t"<< "Password length must at least be 6 characters long \n\n";
                Sleep(1500);
                tryAgain_Goback(errorChoice,"signUp");
                if (errorChoice == 0)
                {
                    sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
                else if (errorChoice == 1)
                {
                    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
            }      
            else if (signUp_op == "password not acceptable")
            {
                cout <<"\t\t\t\t"<< "Password is inValid, It must include one alphabet, No space and No Comma \n\n";
                Sleep(1500);
                tryAgain_Goback(errorChoice,"signUp");
                if (errorChoice == 0)
                {
                    sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
                else if (errorChoice == 1)
                {
                    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
            }
            else if ("user already Exists")
            {
                cout <<"\t\t\t\t\t"<< "User already exists...";
                Sleep(1500);
                tryAgain_Goback(errorChoice,"signUp");
                if (errorChoice == 0)
                {
                    sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
                else if (errorChoice == 1)
                {
                    start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
                }
            }
        
        }
        else
        {
            cout <<"\t\t\t"<< "Password is inValid, It must include one alphabet, No space and No Comma \n\n";
            Sleep(1500);
            tryAgain_Goback(errorChoice,"signUp");
            if (errorChoice == 0)
            {
                sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
            }
            else if (errorChoice == 1)
            {
                start_menu(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
            }
        }
    }    
    else
    {
        cout <<"\t\t\t\t\t\t"<< "Username must include one alphabet and no space..\n\n";
        cout <<"\t\t\t\t\t\t"<< "Press any character to try again..\n";
        getch();
        sign_Up_in(user_Names_data, paswords_data, roles_data, userName_index, products, productPrice, productBoughtByUser, totalProductsBought, taxRate, productIndex, totalRevenue, admin_code, theme_color, runing_usernme, themes_data, complains, complains_index, review, ratings, review_index, theme_index);
    }
}

string SignUp(string userName, string user_Names_data[], string password, string paswords_data[], string role, string roles_data[], int &userName_index, string &admin_code)
{
    system("cls");
    SignUp_Header();
    string result;
    string ad_code;
    bool isAlreadyUser;
    isAlreadyUser = doesUserNameExists(userName, user_Names_data, userName_index);
    if (!isAlreadyUser)
    {
        if (password.length() >= 6)
        {
            if (password_vald(password))
            {
                if (role == "user" || role == "manager")
                {
                    if (role == "manager")
                    {
                            result = "manager";
                    }
                    else
                    {
                        result = "user";
                    }
                }
                else
                {
                    result = "incorrect Role";
                }
            }
            else
            {
                result = "password not acceptable";
            }
        }
        else
        {
            result = "incorrect Password";
        }
    }
    else
    {
        result = "user already Exists";
    }
    return result;
}
void tryAgain_Goback(int &errorChoice,string header){
    
    string choice[2] = {"Try Again", "Go Back"};
    char key;
    int current_opt = 0;

    while(true){
        system("cls");
        if(header == "signIn"){
            SignIn_Header();
        }
        else if(header == "signUp"){
            SignUp_Header();
        }
        
        cout <<"\t\t\t\t\t\t"<< "Try again or Go back\n";
        for(int i = 0; i <2; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<choice[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< choice[i]<<endl;
            }
        }

        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }

        if(key == 80){
            if(current_opt < 1){
                current_opt++;
            }
        }
        else if(key == 72){
            if(current_opt > 0){
                current_opt--;
            }
        }
        else if(key == 13){
            errorChoice = current_opt;
            break;
        }    
    }
}
bool doesUserNameExists(string userName, string user_Names_data[], int &userName_index)
{
    for (int i = 0; i < userName_index; i++)
    {
        if (user_Names_data[i] == userName)
        {
            return true;
        }
    }
    return false;
}
int userNameIndex(string userName, string user_Names_data[], int &userName_index)
{
    for (int i = 0; i < userName_index; i++)
    {
        if (user_Names_data[i] == userName)
        {
            return i;
        }
    }
}

// Functions for MANAGER AND USER
void manager(string products[], int ProductPrice[], int productBoughtByUser[], int totalBoughtProducts[], int &productIndex, int &taxRate, int &totalRavenue, string user_Names_data[], string roles_data[], string passwords_data[], int &userName_index, string &admin_code, string &theme_color, string &runing_username, string themes_data[], string complains[], int &complains_index, string review[], int ratings[], int &review_index, int &theme_index)
{

    system("cls");
    int opt_length = 12;
    string mangr_options[opt_length] = {"Update Rates", "Edit Stock", "Show all Users", "remove User", "Check Listed Products", "Print Sales Record", "Check Total Revenue", "App Settings", "Change Admin Code", "See Complains", "See Reviews & Ratings", "Log out"};
    int current_option = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("");
        for(int i = 0; i < opt_length; i++){
            if(i == current_option){
                Color(06);
                cout <<"\t\t\t\t\t\t"<<"> "<<mangr_options[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t"<< mangr_options[i]<<endl;
            }
        }
        
        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }

        if (key == 80)
        {
            if (current_option < opt_length - 1)
            {
                current_option++;
            }
        }
        else if (key == 72)
        {
            if (current_option > 0)
            {
                current_option--;
            }
        }
        else if (key == 13)
        {
            if (current_option == 0)
            {
                updateRecord(products, ProductPrice, productIndex, taxRate);
            }
            else if (current_option == 1)
            {
                editRecord(products, ProductPrice, productBoughtByUser, totalBoughtProducts, productIndex);
            }
            else if (current_option == 2)
            {
                showUsers(user_Names_data, roles_data, userName_index);
            }
            else if (current_option == 3)
            {
                removeUser(user_Names_data, passwords_data, roles_data, userName_index);
            }
            else if (current_option == 4)
            {
                CheckListedProducts(products, productIndex);
            }
            else if (current_option == 5)
            {
                printSalesRecord(products, ProductPrice, totalBoughtProducts, taxRate, productIndex);
            }
            else if (current_option == 6)
            {
                checkTotalRavenue(totalRavenue);
            }
            else if (current_option == 7)
            {
                app_settings(theme_color, runing_username, passwords_data, user_Names_data, userName_index, themes_data, theme_index);
            }
            else if (current_option == 8)
            {
                change_Admin_Code(admin_code);
            }
            else if (current_option == 9)
            {
                show_complains(complains, complains_index);
            }
            else if (current_option == 10)
            {
                show_reviews(review, ratings, review_index);
            }
            else if (current_option == 11)
            {
                break;
            }
        }
    }
}

void showUsers(string user_Names_data[], string roles_data[], int &userName_index)
{
    system("cls");
    printHeader();
    smallMenu("Check Users List");
    cout << endl;
    cout <<"\t\t\t\t\t\t"<< "Sr   " << setw(10) << "User Names" << setw(10) << "Roles" << endl;
    for (int i = 0; i < userName_index; i++)
    {
        cout <<"\t\t\t\t\t\t"<< i + 1 << " " << setw(10) << user_Names_data[i] << setw(15) << roles_data[i] << "\n";
    }
    cout <<"\t\t\t\t\t\t"<< "\npress any key to go back...";
    getch();
}
void removeUser(string user_Names_data[], string passwords_data[], string roles_data[], int &userName_index)
{
    string user;
    int index;
    printHeader();
    smallMenu("Remove Users");
    cout <<"\t\t\t\t\t\t\t"<< "Users are: \n\n";
    cout <<"\t\t\t\t\t\t\t"<< "Sr   " << setw(10) << "User Names" << setw(10) << "Roles" << endl;
    for (int i = 0; i < userName_index; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< i + 1 << " " << setw(10) << user_Names_data[i] << setw(15) << roles_data[i] << "\n";
    }
    cout <<"\n\t\t\t\t\t\t\t"<< "Enter an index to delete: ";
    while(true){
        if(cin >> index)
        {
            break;
        }
        else
        {
            cout <<"\t\t\t\t\t\t\t" << "invalid index, Enter a valid Value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    if(index < 0){
        cout <<"\n\t\t\t\t\t\t\t"<< "Index must be positive! Try Again.";
        Sleep(1300);
        removeUser(user_Names_data,passwords_data,roles_data,userName_index);
    }
    if(index > userName_index){
        cout << "\n\t\t\t\t\t\tIndex is out of range! Please enter a value within index: ";
        while(true){
            if(cin >> index)
            {
                break;
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t" << "invalid index, Enter a valid Value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }
    else if (roles_data[index - 1] == "manager")
    {
        cout <<"\n\t\t\t\t\t\t\t"<< "You cannot delete any manager or yourself..\n\n";
        cout <<"\n\t\t\t\t\t\t\t"<< "Press any key to go back..\n";
        getch();
    }
    else
    {
        user = user_Names_data[index - 1];
        for (int i = index - 1; i < userName_index - 1; i++)
        {
            user_Names_data[i] = user_Names_data[i + 1];
            passwords_data[i] = passwords_data[i + 1];
            roles_data[i] = roles_data[i + 1];
        }
        user_Names_data[userName_index - 1] = "";
        passwords_data[userName_index - 1] = "";
        roles_data[userName_index - 1] = "";
        userName_index--;
        cout <<"\n\t\t\t\t\t\t\t"<< user << " is removed\n";
        cout <<"\n\t\t\t\t\t\t\t"<< "press any key to continue....";
        getch();
    }
    
}
void checkTotalRavenue(int &totalRavenue)
{
    system("cls");
    printHeader();
    smallMenu("Check Total Revenue");
    cout << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     Total Ravenue Generated: " << totalRavenue << "\n";
    cout <<"\t\t\t\t\t\t\t"<< "______________________________________\n\n";
    cout <<"\t\t\t\t\t\t\t"<< "press any key to continue....";
    getch();
}
void printSalesRecord(string products[], int productPrice[], int totalBoughtProducts[], int &taxRate, int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("Sales menu");
    cout  << endl;
    cout <<"\t\t\t\t\t\t\t" << "#################################################\n";
    cout <<"\t\t\t\t\t\t\t" << "#-----------------------------------------------#\n";
    cout <<"\t\t\t\t\t\t\t" << "# " << setw(12) << left << "index" << setw(15) << left << "item" << setw(15) << "sold"
         << "    #\n";
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t" << "# " << setw(12) << left << i + 1 << setw(15) << left << products[i] << setw(13) << totalBoughtProducts[i] << "      #\n";
    }
    cout <<"\t\t\t\t\t\t\t" << "#-----------------------------------------------#\n";
    cout <<"\t\t\t\t\t\t\t" << "#################################################\n\n";
    cout <<"\t\t\t\t\t\t\t" << "press any key to go back";
    getch();
}
int calculateTotalSale(int productPrice[], int totalBoughtProducts[], int &taxRate, int &productIndex)
{
    int bill = 0;
    for (int i = 0; i < productIndex; i++)
    {
        bill += productPrice[i] * totalBoughtProducts[i];
    }
    bill += (bill * taxRate) / 100;
    return bill;
}
void updateRecord(string products[], int productPrice[], int &productIndex, int &taxRate)
{

    int options_length = 3;
    string record[options_length] = {"Update Rates", "Update Tax", "Go back"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("Update Record");
        for(int i = 0; i <3; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<record[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< record[i]<<endl;
            }
        }

        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }
        if (key == 80)
        {
            if (current_opt < options_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if (key == 13)
        {
            if (current_opt == 0)
            {
                updateRates(products, productPrice, productIndex);
            }
            else if (current_opt == 1)
            {
                UpdateTaxRate(taxRate);
            }
            else if (current_opt == 2)
            {
                break;
            }
        }
    }
}
void CheckListedProducts(string products[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("Listed Items");
    cout <<"\t\t\t\t\t\t\t"<< "Listed Products are \n\n";
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< i + 1 << ": " << products[i] << "\n\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< "press any key to go back...";
    getch();
}
void UpdateTaxRate(int &taxRate)
{
    int newtax;
    cout << endl;
    cout <<"\t\t\t\t\t\t\t"<< "Previous tax rate was " << taxRate <<"\n\t\t\t\t\t\t\t"<< "Enter new tax rate: ";
    while(true){
        if(cin >> newtax)
        {
            break;
        }
        else
        {
            cout <<"\t\t\t\t\t\t\t" << "invalid input Try an integer Value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    taxRate = newtax;
    cout << endl;
    cout <<"\t\t\t\t\t\t\t"<< "Tax Rate changed to > " << taxRate <<endl <<endl;
    cout <<"\t\t\t\t\t\t\t"<< "Enter any key to go back....";
    getch();
}
void updateRates(string products[], int productPrice[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("Update Item Rates");
    int number, price;
    cout << endl;
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< i + 1 << ":  " << products[i] << "\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< productIndex + 1 << ": Done\n\n";
    while (true)
    {
        cout <<"\t\t\t\t\t\t\t"<< "select item from list to change rate: ";
        cin >> number;
        if (number <= productIndex)
        {
            cout <<"\t\t\t\t\t\t\t"<< "Last rate of " << products[number - 1] << " was " << productPrice[number - 1]<< endl << "\t\t\t\t\t\t\t enter new price ";

            while(true)
            {
                if(cin >> price)
                {
                    break;
                }
                else
                {
                cout <<"\t\t\t\t\t\t\t" << "invalid input Try an integer Value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }

            productPrice[number - 1] = price;
        }
        else if (number == productIndex + 1)
        {
            for (int i = 0; i < productIndex; i++)
            {
                cout <<"\t\t\t\t\t\t\t"<< setw(10) << productPrice[i];
            }
            break;
        }
    }
}
void editRecord(string products[], int ProductPrice[], int productBoughtByUser[], int totalBoughtProducts[], int &productIndex)
{

    int options_length = 3;
    string editRecord[options_length] = {"Add Item", "Remove Item", "Go back"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("Edit Record");
        for(int i = 0; i <3; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t" << "> "<<editRecord[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< editRecord[i]<<endl;
            }
        };
        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }
        if (key == 80)
        {
            if (current_opt < options_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if (key == 13)
        {
            if (current_opt == 0)
            {
                addProduct(products, ProductPrice, productBoughtByUser, totalBoughtProducts, productIndex);
            }
            else if (current_opt == 1)
            {
                removeProduct(products, ProductPrice, productBoughtByUser, totalBoughtProducts, productIndex);
            }
            else if (current_opt == 2)
            {
                break;
            }
        }
    }
}

void addProduct(string products[], int ProductPrice[], int productBoughtByUser[], int totalBoughtProducts[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("Add Item");
    string product_name;
    int price;
    cout <<"\t\t\t\t\t\t"<< "Enter the name of Item: ";
    cin >> product_name;
    cout <<"\t\t\t\t\t\t"<< "Enter Price: ";
    while(true){
        if(cin >> price)
        {
            break;
        }
        else
        {
            cout <<"\t\t\t\t\t\t\t" << "invalid input Try an integer Value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    if(price < 0){
        price *= -1;
    }

    string choices[2] = {"Confirm", "Cancel"};
    char key;
    int current_opt = 0;

    while(true){
        printHeader();
        smallMenu("Add Item");
        cout <<"\t\t\t\t\t\t"<< "Item Name: " << product_name << "\n";
        cout <<"\t\t\t\t\t\t"<< "Item Price: " << price << "\n\n";
        for(int i = 0; i <2; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<choices[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< choices[i]<<endl;
            }
        }
        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }

        if(key == 80){
            if(current_opt < 1){
                current_opt++;
            }
        }
        else if(key == 72){
            if(current_opt > 0){
                current_opt--;
            }
        }
        else if(key == 13)
        {
            if(current_opt == 0){
                if (!checkProduct(products, product_name, productIndex))
                {
                products[productIndex] = product_name;
                ProductPrice[productIndex] = price;
                productBoughtByUser[productIndex] = 0;
                totalBoughtProducts[productIndex] = 0;
                productIndex++;
                cout << endl;
                cout <<"\t\t\t\t\t\t"<< product_name << " is added successfully to the list .....\n";
                cout <<"\t\t\t\t\t\t\t"<< "Enter any key to continue";
                getch();
                break;
                }
                else
                {
                cout << product_name << " already exists....";
                cout << "Enter any key to continue";
                getch();
                }
                }
        else if(current_opt == 1)
        {
                break;
        }
        }
    }

}
void removeProduct(string products[], int productPrice[], int items_bought_by_user[], int totalProductsBought[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("Remove X item ");
    string product;
    int index;
    cout <<"\t\t\t\t\t\t\t"<< "Products are: \n\n";
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< i + 1 << setw(10) << left << " " << products[i] << "\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< "Enter an index to delete: ";
    
    while(true){
        if(cin >> index)
        {
            break;
        }
        else
        {
            cout <<"\t\t\t\t\t\t\t" << "invalid input Try an integer Value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    if(index > productIndex){
        cout <<"\t\t\t\t\t\t\t" << "Index does not exists, Please enter valid index from above:";
        while(true){
        if(cin >> index)
        {
            break;
        }
        else
        {
            cout <<"\t\t\t\t\t\t\t" << "Again invalid input Try an integer Value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
        
    }
    else
    {
        product = products[index - 1];
        for (int i = index - 1; i < productIndex - 1; i++)
        {
            products[i] = products[i + 1];
            productPrice[i] = productPrice[i + 1];
            items_bought_by_user[i] = items_bought_by_user[i + 1];
            totalProductsBought[i] = totalProductsBought[i + 1];
        }
        products[productIndex - 1] = "";
        productPrice[productIndex - 1] = 0;
        items_bought_by_user[productIndex - 1] = 0;
        totalProductsBought[productIndex - 1] = 0;
        productIndex--;
        cout <<"\t\t\t\t\t\t\t"<< product << " removed\n";
        cout <<"\t\t\t\t\t\t\t"<< "press any key to continue....";
        getch();
    }
}

bool checkProduct(string products[], string product, int &productIndex)
{
    for (int i = 0; i < productIndex; i++)
    {
        if (products[i] == product)
        {
            return true;
        }
    }
    return false;
}

void change_Admin_Code(string &admin_code)
{
    printHeader();
    smallMenu("Change Admin Code");
    string new_admin_code;
    cin.clear();
    cin.sync();
    cout <<"\t\t\t\t\t\t\t"<< "Enter new ADMIN CODE : ";
    getline(cin ,new_admin_code);
    admin_code = new_admin_code;
    cout <<"\t\t\t\t\t\t\t"<< "Admin code is now changed...\n";
    cout <<"\t\t\t\t\t\t\t"<< "press any key to go back....\n";
    getch();
}

// User
void user(string products[], int productPrice[], int productBoughtByUser[], int totalBoughtProducts[], int &productIndex, int &taxRate, int &totalRevenue, string usernames_data[], string &theme_color, string &runing_username, string passwords_data[], int &userName_index, string themes_data[], string complains[], int &complains_index, string review[], int ratings[], int &review_index, int &theme_index)
{
    int option;

    int options_length = 8;
    string user[options_length] = {"Check items prices", "Buy items", "Check My Cart", "Empty Cart", "Pay bill", "Customer Support", "App Settings", "exit"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("User Menu");

        for(int i = 0; i < options_length; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<user[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< user[i]<<endl;
            }
        }

        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }
        

        if (key == 80)
        {
            if (current_opt < options_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if (key == 13)
        {
            if (current_opt == 0)
            {
                print_item_rates(products, productPrice, productIndex);
            }
            else if (current_opt == 1)
            {
                fn_buy_items(products, productBoughtByUser, productIndex);
            }
            else if (current_opt == 2)
            {
                bill_view(products, productPrice, productBoughtByUser, productIndex, taxRate);
            }
            else if (current_opt == 3)
            {
                empty_cart(productBoughtByUser, productIndex);
            }
            else if (current_opt == 4)
            {
                fn_paybill(productBoughtByUser, totalBoughtProducts, productPrice, productIndex, taxRate, totalRevenue);
            }
            else if (current_opt == 5)
            {
                customerSupport(complains, complains_index, review, ratings, review_index);
            }
            else if (current_opt == 6)
            {
                app_settings(theme_color, runing_username, passwords_data, usernames_data, userName_index, themes_data, theme_index);
            }
            else if (current_opt == 7)
            {
                break;
            }
        }
    }
}
void print_item_rates(string products[], int ProductPrice[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("User Menu> Check item Rates");
    cout <<"\t\t\t\t\t\t\t"<< "____________________________________________________________\n";

    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< "|" << setw(25) << products[i] << setw(15) << ProductPrice[i] << setw(20) << "|"<<"\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< "____________________________________________________________\n\n";
    cout <<"\t\t\t\t\t\t\t"<< " Press any key to continue.....";
    getch();
}
void fn_buy_items(string products[], int items_bought_by_user[], int &productIndex)
{
    system("cls");
    printHeader();
    smallMenu("User Menu> Buy Items");
    cout << endl;
    for (int i = 0; i < productIndex; i++)
    {
        items_bought_by_user[i] = 0;
    }
    int option, number;
    cout <<"\t\t\t\t\t\t\t"<< "------------------------------------" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "           Sr"<< "    Product Name    " << endl;
    cout <<"\t\t\t\t\t\t\t"<< "------------------------------------" << endl;
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< "           " << i + 1 << ":        " << products[i] << "\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< "    " << productIndex + 1 << ": Done.....\n\n";
    while (true)
    {
        cout <<"\t\t\t\t\t\t\t"<< "    What do you want to buy: ";
        cin >> option;

        if(option == productIndex+1){
            break;
        }
        if(option > productIndex+1){
            cout <<"\t\t\t\t\t\t\t"<< "invalid option....\n";
            break;
        }
        else{
            cout <<"\t\t\t\t\t\t\t"<< "Enter number: ";
            cin  >> number;
            items_bought_by_user[option-1] += number;
        }
    }
}

void empty_cart(int items_bought_by_user[], int &productIndex)
{
    printHeader();
    smallMenu("Empty Cart");
    cout <<"\t\t\t\t\t\t\t"<< "Press any key to empty cart..\n";
    getch();
    for (int i = 0; i < productIndex; i++)
    {
        items_bought_by_user[i] = 0;
    }
    cout <<"\t\t\t\t\t\t\t"<< "Your cart is empty now..\n";
    cout <<"\t\t\t\t\t\t\t"<< "Press any key to go back..\n";
    getch();
}

void bill_view(string products[], int productPrice[], int productBoughtByUser[], int &productIndex, int &taxRate)
{
    system("cls");
    printHeader();
    smallMenu("User Menu> Check Bill");
    int bill, tax, total;
    bill = bill_calculator(productBoughtByUser, productPrice, productIndex, taxRate);
    tax = tax_calculator(productBoughtByUser, productPrice, productIndex, taxRate);
    total = bill + tax;
    cout <<"\t\t\t\t\t\t\t"<< "__________________________________________________________________\n";
    cout <<"\t\t\t\t\t\t\t"<< "#                                                                 #\n";
    cout <<"\t\t\t\t\t\t\t"<< "#  " << setw(10) << left << "Index" << setw(12) << "Product" << setw(12) << "Price" << setw(12) << "Quantity" << setw(11) << "Total"
         << "      #\n";
    for (int i = 0; i < productIndex; i++)
    {
        cout <<"\t\t\t\t\t\t\t"<< "#     " << setw(8) << left << i + 1 << setw(12) << left << products[i] << setw(12) << productPrice[i] << setw(12) << productBoughtByUser[i] << setw(11) << productBoughtByUser[i] * productPrice[i] << "     #\n";
    }
    cout <<"\t\t\t\t\t\t\t"<< "#                                                                 #\n";
    cout <<"\t\t\t\t\t\t\t"<< "# " << setw(14) << left << "Bill: " << setw(9) << left << bill << setw(9) << right << "Tax: " << setw(9) << left << tax << setw(9) << right << "Total: " << setw(11) << left << total << "   #\n";
    cout <<"\t\t\t\t\t\t\t"<< "#                                                                 #\n";
    cout <<"\t\t\t\t\t\t\t"<< "#_________________________________________________________________#\n";

    cout << endl;
    cout <<"\t\t\t\t\t\t\t"<< " press any key to go back.....";
    getch();
}
int bill_calculator(int items_bought_by_user[], int productPrice[], int &productIndex, int &taxRate)
{
    int bill = 0;
    for (int i = 0; i < productIndex; i++)
    {
        bill += (productPrice[i] * items_bought_by_user[i]);
    }
    return bill;
}
int tax_calculator(int items_bought_by_user[], int productPrice[], int &productIndex, int &taxRate)
{
    int bill, tax;
    bill = bill_calculator(items_bought_by_user, productPrice, productIndex, taxRate);
    tax = (bill * taxRate) / 100;
    return tax;
}
void fn_paybill(int productBoughtByuser[], int totalBoughtProducts[], int productPrice[], int &productIndex, int &taxRate, int &totalRevenue)
{
    system("cls");
    printHeader();
    smallMenu("User Menu> Pay Bill");
    int bill, tax, totalBill;
    for (int i = 0; i < productIndex; i++)
    {
        totalBoughtProducts[i] += productBoughtByuser[i];
    }
    bill = bill_calculator(productBoughtByuser, productPrice, productIndex, taxRate);
    if (bill == 0)
    {
        cout << endl;
        cout <<"\t\t\t\t\t\t\t" << "No bill to pay.. \n "<<"\t\t\t\t\t\t\t"<<"Not any item is added to the cart..\n\n"<<"\t\t\t\t\t\t\t"<< "Please buy items to pay bill..\n";
        cout <<"\t\t\t\t\t\t\t"<< "Press any key to go back..\n";
        getch();
        return;
    }
    tax = tax_calculator(productBoughtByuser, productPrice, productIndex, taxRate);
    totalBill = bill + tax;
    cout <<"\t\t\t\t\t\t\t"<< "Your Bill is: " << totalBill << "\n";
    cout <<"\t\t\t\t\t\t\t"<< "Press any character to pay bill";
    getch();
    printHeader();
    smallMenu("User Menu> Pay Bill");
    cout <<"\t\t\t\t\t\t\t"<< "Your Bill is Payed..\n"<<"\t\t\t\t\t\t\t"<<" Thanks for shoping\n";
    cout <<"\t\t\t\t\t\t\t"<< "Press any key to go back..";
    getch();
    for (int i = 0; i < productIndex; i++)
    {
        productBoughtByuser[i] = 0;
    }
    totalRevenue += totalBill;
}

void customerSupport(string complains[], int &complains_index, string review[], int ratings[], int &review_index)
{
    int options_length = 6;
    string customerSupport[options_length] = {"Report any complain", "Contact Us", "Our Social Accounts", "Check Ratings and Reviews", "Review/Rate our Service", "Go Back"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("Customer Support");
        for(int i = 0; i < options_length; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<customerSupport[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< customerSupport[i]<<endl;
            }
        }

        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }
        

        if (key == 80)
        {
            if (current_opt < options_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if (key == 13)
        {
            if (current_opt == 0)
            {
                write_complain(complains, complains_index);
            }
            else if (current_opt == 1)
            {
                contact_page();
            }
            else if (current_opt == 2)
            {
                Social_Accounts_page();
            }
            else if (current_opt == 3)
            {
                show_reviews(review, ratings, review_index);
            }
            else if (current_opt == 4)
            {
                review_rating(review, ratings, review_index);
            }
            else if (current_opt == 5)
            {
                break;
            }
        }
    }
}

void write_complain(string complains[], int &complains_index)
{
    printHeader();
    smallMenu("Write Complain");
    string complain_content;
    cout << endl;
    cin.clear();
    cin.sync();
    cout <<"\t\t\t\t\t\t\t"<< "Write your complain Below: \n\n";
    getline(cin, complain_content);

    complains[complains_index] = complain_content;
    complains_index++;

    cout <<"\t\t\t\t\t\t\t"<< "Your complain has been sent to the administrator..\n";
    Sleep(1500);
}
void show_complains(string complains[], int complains_index)
{
    printHeader();
    smallMenu("Show Complains");
    cout << endl;
    cout <<"\t\t\t\t\t"<< setw(5) << left << "Sr" << setw(10) << right << "Complains\n";
    for (int i = 0; i < complains_index; i++)
    {
        cout <<"\t\t\t\t\t"<< " " << setw(5) << left << i + 1 << complains[i] << endl <<endl;
    }
    cout << endl;
    cout << "\t\t\t\t\t\t" << "___________________________________" <<endl;
    cout <<"\t\t\t\t\t\t\t"<< "..Press any key to go back..";
    getch();
}

void contact_page()
{
    printHeader();
    smallMenu("Contact Us Page");
    cout << endl;
    cout <<"\t\t\t\t\t"<< "You can can contact us by using the following media..\n\n";
    cout <<"\t\t\t\t\t"<< " Email : generalStore@gmail.com\n"; // Readable Only
    cout <<"\t\t\t\t\t"<< " Phone : 056-876952220         \n\n";
    cout <<"\t\t\t\t\t"<< "Press any key to go back..\n";
    getch();
}
void Social_Accounts_page()
{
    printHeader();
    smallMenu("Social Accounts Page");
    cout << endl;
    cout <<"\t\t\t\t\t"<< "Follow our page On Social Media Platforms to stay tuned with updates..\n\n";
    cout <<"\t\t\t\t\t"<< "Facebook : www.facebook.com/generalStore    \n"; // Readable Only
    cout <<"\t\t\t\t\t"<< "Instagram : www.instagram.com/generalStore  \n";
    cout <<"\t\t\t\t\t"<< "Twitter : www.twitter.com/generalStore      \n\n";
    cout <<"\t\t\t\t\t"<< "Press any key to go back..\n";
    getch();
}

void app_settings(string &theme_color, string runing_username, string passwords_data[], string user_Names_data[], int &userName_index, string themes_data[], int &theme_index)
{
    int options_length = 3;
    string app_settings[options_length] = {"Change App Theme", "Change Password", "Go back"};
    int current_opt = 0;
    char key;

    while (true)
    {
        printHeader();
        smallMenu("App Settings");

        for(int i = 0; i < 3; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<app_settings[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< app_settings[i]<<endl;
            }
        }
        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }

        if (key == 80)
        {
            if (current_opt < options_length - 1)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }

        else if (key == 13)
        {
            if (current_opt == 0)
            {
                changeSystemColor(theme_color, themes_data, userName_index, theme_index);
            }
            else if (current_opt == 1)
            {
                change_Password(runing_username, passwords_data, user_Names_data, userName_index);
            }
            else if (current_opt == 2)
            {
                break;
            }
        }
    }
}

void review_rating(string review[], int ratings[], int &review_index)
{
    printHeader();
    smallMenu("Rate Us");
    string comment;
    int User_rating;
    cin.clear();
    cin.sync();
    cout << endl;
    cout <<"\t\t\t\t"<< "Enter your Review: ";
    getline(cin, comment);
    cout <<"\t\t\t\t"<< "Enter Rating out of 10: ";

    string rating_count[11] = {"0","1","2","3","4","5","6","7","8","9","10"};
    char key; 
    int current_opt = 0;
    while(true){
        printHeader();
        smallMenu("Rate Us");
        cout <<"\t\t\t\t\t\t"<< "Your Comments: " << comment << "\n";
        cout <<"\t\t\t\t\t\t"<< "Select Rating out of 10 " << endl <<endl;
        cout <<"\t\t\t\t\t\t"<< rating_count[current_opt] << endl;

        key = 0;
        while(!(key == 13 || key == 80 || key == 72)){
            key = _getch();
        }
        
        if (key == 80)
        {
            if (current_opt < 10)
            {
                current_opt++;
            }
        }
        else if (key == 72)
        {
            if (current_opt > 0)
            {
                current_opt--;
            }
        }
        else if(key == 13)
        {
            User_rating = current_opt;
            review[review_index] = comment;
            ratings[review_index] = User_rating;
            review_index++;
            break;
        }
    }
    cout << endl;
    cout <<"\t\t\t\t"<< "Thank You ! \n"<<"\t\t\t\t"<< "Your Review has been Submitted to the Administrator...\n\n ";
    cout <<"\t\t\t\t\t\t\t"<< "Press any key to go back ";
    getch();
}

void show_reviews(string review[], int ratings[], int review_index)
{
    printHeader();
    smallMenu("See Reviews/Ratings");
    cout << endl;
    cout <<"\t\t\t\t\t"<< setw(7) << left << "No." << setw(12) << left << "Rating/10" << setw(12) << left << "Review" << endl;

    for (int i = 0; i < review_index; i++)
    {
        cout <<"\t\t\t\t\t"<< setw(7) << left << i + 1 << "  " << setw(12) << left << ratings[i] << setw(12) << left << review[i] << endl;
    }
    cout << endl <<endl;
    cout <<"\t\t\t\t\t\t"<< "________________________________\n";
    cout << endl;
    cout <<"\t\t\t\t\t\t"<< "Press any key to go back..\n";
    getch();
}

void change_Password(string runing_username, string passwords_data[], string user_Names_data[], int &userName_Index)
{
    printHeader();
    smallMenu("Change Password");
    int index = userNameIndex(runing_username, user_Names_data, userName_Index);
    int choice;
    string old_password, newpassword;
    cout << endl;
    cin.clear();
    cin.sync();
    cout <<"\t\t\t\t\t"<< "Enter your Previous Password: ";
    getline(cin,old_password);

    if (old_password == passwords_data[index])
    {
        cin.clear();
        cin.sync();
        cout <<"\t\t\t\t\t"<< "Enter New Password: ";
        getline(cin, newpassword);
        if(newpassword.length()>=6 && password_vald(newpassword)){
            passwords_data[index] = newpassword;
            cout << endl;
            cout <<"\t\t\t\t\t\t\t\t"<< "Password Changed Successfully!  \n";
            cout <<"\t\t\t\t\t\t\t\t"<< "Press any key to go back....";
            getch();
            return;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t"<< "The new entered password does not match the criteria..\n";
            cout << "\t\t\t\t\t\t"<< "Password should be atleast 6 characters long and includes atleast one alphabet..\n\n";
            Sleep(3300);
            change_Password(runing_username, passwords_data, user_Names_data, userName_Index);
        }
    }
    else
    {
        cout << "\t\t\t\t\t"<< "Password did'nt matched ... \n";

        string options[2] = {"Try Again", "Go Back"};
        char key;
        int current_opt = 0;
        while(true){
            printHeader();
            smallMenu("Change Password");
            cout <<"\t\t\t\t\t\t\t\t"<< "Password did'nt matched ... \n\n";
            for(int i = 0; i <2; i++){
            if(i == current_opt){
                Color(06);
                cout <<"\t\t\t\t\t\t\t"<<"> "<<options[i] <<endl;
                Color(07);
            }
            else
            {
                cout <<"\t\t\t\t\t\t\t"<< options[i]<<endl;
            }
        }
            key = 0;
            while(!(key == 13 || key == 80 || key == 72)){
                key = _getch();
            }
            if (key == 80)
            {
                if (current_opt < 10)
                {
                    current_opt++;
                }
            }
            else if (key == 72)
            {
                if (current_opt > 0)
                {
                    current_opt--;
                }
            }
            else if(key == 13)
            {
                if(current_opt == 0)
                {
                    change_Password(runing_username, passwords_data, user_Names_data, userName_Index);
                }
                else if(current_opt == 1)
                {
                    return;
                }
            }

        }
    }
}

void changeSystemColor(string &theme_color, string themes_data[], int &userName_index, int &theme_index)
{
    printHeader();
    smallMenu("Change App Theme");
    string colorCode;
    cout << endl;
    cout << "\t\t\t\t\t\t\t" << "0 = Black       8 = Gray" <<endl;
    cout << "\t\t\t\t\t\t\t" << "1 = Blue        9 = Light Blue" <<endl;
    cout << "\t\t\t\t\t\t\t" << "2 = Green       A = Light Green" <<endl;
    cout << "\t\t\t\t\t\t\t" << "3 = Aqua        B = Light Aqua" <<endl;
    cout << "\t\t\t\t\t\t\t" << "4 = Red         C = Light Red" <<endl;
    cout << "\t\t\t\t\t\t\t" << "5 = Purple      D = Light Purple" <<endl;
    cout << "\t\t\t\t\t\t\t" << "6 = Yellow      E = Light Yellow" <<endl;
    cout << "\t\t\t\t\t\t\t" << "7 = White       F = Bright White" <<endl;
    cout << endl;
    cin.clear();
    cin.sync();
    cout << "\t\t\t\t\t\t"<< "Enter the color code (only Hexadecimal two digit value e.g A9, E5): ";
    getline(cin, colorCode);

    if(is_valid_color_code(colorCode)){
        
        string full_command = "color " + colorCode;
        system(full_command.c_str());
        themes_data[theme_index] = full_command;
        theme_index++;
        cout << "\t\t\t\t\t"<< "App theme changed to " << colorCode << endl <<endl;
        cout << "\t\t\t\t\t"<< "Press any key to go back.....";
        getch();
    }
    else
    {
        cout << "\n\t\t\t\t"<< "       >>>>>>>>>>>>>>>>>  Invalid color code. Please enter a valid hexadecimal color code.   <<<<<<<<<<<<<<<<<<    \n\n\n";
        Sleep(1500);
        changeSystemColor(theme_color, themes_data, userName_index, theme_index);
    }
}

// Validations

bool isValid_UserName(string name)
{

    int hasAlphabet = 0;
    int hasNoSpace = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(('a' <= name[i] && name[i] <= 'z') ||
              ('A' <= name[i] && name[i] <= 'Z') ||
              ('0' <= name[i] && name[i] <= '9')))
        {
            return false;
        }

        if (('a' <= name[i] && name[i] <= 'z'))
        {
            hasAlphabet = 1;
        }
        if (name[i] != ' ')
        {
            hasNoSpace = 1;
        }
    }
    return hasAlphabet && hasNoSpace;
}

bool password_vald(string password)
{
    if (password[0] == '\0')
    {
        return false;
    }
    int hasAlphabet = 0;
    int hasNoSpace = 0;
    int hasNoComma = 1;
    for (int i = 0; password[i] != '\0'; i++)
    {

        if (('a' <= password[i] && password[i] <= 'z') || ('A' <= password[i] && password[i] <= 'Z'))
        {
            hasAlphabet = 1;
        }
        if (password[i] != ' ')
        {
            hasNoSpace = 1;
        }
        if (password[i] == ',')
        {
            hasNoComma = 0;
        }
    }
    return hasAlphabet && hasNoSpace && hasNoComma;
}

bool is_valid_color_code(string color_code)
{
    
    if((color_code.length() == 2)&&(color_code[0] >= 'A' && color_code[0] <= 'F') || (color_code[0] >= '0'&&color_code[0] <= '9')&&
       (color_code[1] >= 'A' && color_code[1] <= 'F') || (color_code[1] >= '0'&&color_code[1] <= '9'))
       {
            return true;
       }
    return false;   
}

// functions for keys and colors
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
static void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideAndVisibleCursor(bool isShow)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = isShow;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// File Handling

void load_users_data(string user_Names_data[],string passwords_data[],string roles_data[], int &userName_Index){
    fstream file;
    string line;
    userName_Index = 0;
    file.open("usersData.txt" , ios::in);
    while(getline(file,line)){

        user_Names_data[userName_Index] = parseData(line ,0);
        passwords_data[userName_Index] = parseData(line,1);
        roles_data[userName_Index] = parseData(line, 2);
        userName_Index++;
    }
    file.close();
}
void save_users_data(string user_Names_data[],string passwords_data[],string roles_data[], int &userName_Index){
    fstream file;
    file.open("usersData.txt", ios::out);
    for (int i =0; i<userName_Index; i++)
    {
        file << user_Names_data[i];
        file << "^";
        file << passwords_data[i];
        file << "^";
        file << roles_data[i];
        file << endl;
    }
    file.close();
}
string parseData(string line,int index){
    int idx = 0;
    string word = "";
    int wordnum = 0;
    while(line[idx] != '\0'){
        if(line[idx] == '^'){
           if(wordnum == index){
              return word;
           }
           word = "";
           wordnum++;
        }else{
          word += line[idx];
        }
        idx++;
    }
}

void saveProducts(string products[], int productPrice[], int productBoughtByUser[], int totalBoughtProducts[], int productIndex) {
    fstream dataFile;
    dataFile.open("products.txt", ios::out);
    
    for (int i = 0; i < productIndex; i++) {
        
        dataFile << products[i];
        dataFile << "^";
        dataFile << productPrice[i];
        dataFile << "^";
        dataFile << productBoughtByUser[i];
        dataFile << "^";
        dataFile << totalBoughtProducts[i];
        dataFile << endl;
        
    }
    
    dataFile.close();
}
void loadProducts(string products[],int Productprices[],int productsBoughtByUser[],int totalBoughtProducts[],int &productIndex){
    string data;
    productIndex = 0;
    fstream file;
    file.open("products.txt",ios::in);
    while(!(file.eof())){
        getline(file,data);
        products[productIndex] = parseData(data,1);
        Productprices[productIndex] = convertStoInt((parseData(data,2)));
        productsBoughtByUser[productIndex] = convertStoInt((parseData(data,3)));
        totalBoughtProducts[productIndex] = convertStoInt((parseData(data,4)));
        productIndex++;
    }
    file.close();
}

void save_reviews(string reviews[], int rating[],int review_index)
{
    fstream file;
    file.open("reviews.txt" , ios :: out);
    for(int i = 0; i< review_index; i++){
        file << reviews[i];
        file << "^";
        file << rating[i];
        file << endl;
    }
    file.close();
}
void load_reviews(string reviews[], int rating[],int &review_index)
{
    fstream file;
    string line = "";
    file.open("reviews.txt",ios::in);
    while(getline(file,line))
    {
        reviews[review_index] = parseData(line,0);
        rating[review_index] = convertStoInt((parseData(line,1)));
        review_index++;
    }
}
int convertStoInt(string num){
    int number = 0;
    int crNum;
    int difference = 1;
    for(int i=num.length()-1; i>=0;i--){
        crNum = num[i] - '0';
        number += (crNum * difference);
        difference *= 10;
    }
    return number;
}
// Headers

void smallMenu(string submenu)
{
    cout << "____________________________________________________________________________________________________________________________________________________________________________\n\n";
    cout << "                                                                     Main Menu> " + submenu + "\n";
    cout << "____________________________________________________________________________________________________________________________________________________________________________\n";
}
void SignUp_Header()
{
    cout << R"(
                    ##########################################################################################################
                    ##------------------------------------------------------------------------------------------------------##
                    ##            _____     _____      _____       __      _      __    __   _____                          ##
                    ##           / ____\   (_   _)    / ___ \     /  \    / )     ) )  ( (  (  __ \                         ##
                    ##          ( (___       | |     / /   \_)   / /\ \  / /     ( (    ) )  ) )_) )                        ##
                    ##           \___ \      | |    ( (  ____    ) ) ) ) ) )      ) )  ( (  (  ___/                         ##
                    ##               \ )     | |    ( ( (__  )  ( ( ( ( ( (      ( (    ) )  ) )                            ##
                    ##            ___/ /    _| |__   \ \__/ /   / /  \ \/ /       ) \__/ (  ( (                             ##
                    ##           /____/    /_____/    \____/   (_/    \__/        \______/  /__\                            ##
                    ##______________________________________________________________________________________________________##
                    ##########################################################################################################
____________________________________________________________________________________________________________________________________________________________________________
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------)";
}
void SignIn_Header()            
{
    cout << R"(
                    ###########################################################################################################################
                    ##-----------------------------------------------------------------------------------------------------------------------##
                    ##                  _____    _____      _____         __          _        _____        __        _                      ##
                    ##                 / ____\  (_   _)    / ___ \       /  \        / )      (_   _)      /  \      / )                     ##
                    ##                ( (___      | |     / /   \_)     / /\ \      / /         | |       / /\ \    / /                      ##
                    ##                 \___ \     | |    | |  ____     / /  \ \    / /          | |      / /  \ \  / /                       ##  
                    ##                     ) )    | |    | | (__  )   / /    \ \  / /           | |     / /    \ \/ /                        ##
                    ##                 ___/ /    _| |__   \ \__/ /   / /      \ \/ /            | |__  / /      \ \/                         ##
                    ##                /____/    /_____(    \____/   (_/        \__/           /_____( (_/        \/                          ##
                    ##_______________________________________________________________________________________________________________________##
                    ###########################################################################################################################
____________________________________________________________________________________________________________________________________________________________________________
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------)";
}
void printHeader()
{
    system("cls");
    cout << R"(
            #############################################################################################################################################
            ##-----------------------------------------------------------------------------------------------------------------------------------------##
            ##                           ______                                        __          _____    __                                         ##
            ##                          / ____/  ___    ____   ___    _____  ____ _   / /         / ___/   / /_   ____     ____                        ##
            ##                         / / __   / _ \  / __ \ / _ \  / ___/ / __ `/  / /          \__ \   / __ \ / __ \   / __ \                       ##
            ##                        / /_/ /  /  __/ / / / //  __/ / /    / /_/ /  / /          ___/ /  / / / // /_/ /  / /_/ /                       ##
            ##                        \____/   \___/ /_/ /_/ \___/ /_/     \__,_/  /_/          /____/  /_/ /_/ \____/  / .___/                        ##
            ##                                                                                                         /_/                             ##
            ##-----------------------------------------------------------------------------------------------------------------------------------------##
            #############################################################################################################################################                  

)";
}
