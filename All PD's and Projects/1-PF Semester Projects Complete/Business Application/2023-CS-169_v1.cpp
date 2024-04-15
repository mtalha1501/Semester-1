#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;
//For Startup
void start_menu(string[],string[],string[],int&,   string[],int[],int[],int[],int&,int&,int&,string&,string&,string&,string[],string[],int&,string [],float[],int &);
void smallMenu(string );
void printHeader();
void SignIn_Header();
void SignUp_Header();
void contact_page();
void Social_Accounts_page();

// mutual functions
void changeSystemColor(string&,string[],int&);
void app_settings(string &, string,string [],string [],int &,string[]);
void change_Password(string , string[],string [],int &);

//sign in and sign up
void sign_in(string[],string[],string[],int &,  string[],int[],int[],int[],int&,int&,int&,string&,string&,string&,string[],string[],int&,string [],float[],int &);
string signIn(string,string[],string,string[],string[],int&,string&);
string SignUp(string,string[], string,string[],string,string[],int&,string&);
void sign_Up_in(string[],string[],string[],int&,   string[],int[],int[],int[],int&,int&,int&,string&,string&,string&,string[],string[],int&,string [],float[],int &);
bool doesUserNameExists(string,string[],int&);
int userNameIndex(string,string[],int&);

//functions for user
void user(string[],int[],int[],int[],int &,int &,int&,string[],string&,string&,string[],int&,string[],string[],int&,string [],float[],int &);
void print_item_rates(string[],int[],int&);
void fn_buy_items(string [],int[],int &);
int bill_calculator(int[],int[],int&,int&);
int tax_calculator(int[],int[],int&,int&);
void bill_view(string[],int[],int[],int &,int &);
void fn_paybill(int[],int[],int[],int &,int &,int &);
void customerSupport(string[], int &,string [],float[],int &);
void write_complain(string[],int &);
void review_rating(string [],float[],int &);




//manager
void manager(string[],int[], int[], int[], int&, int&, int&, string[], string[], string[], int&,string&,string&,string&,string[],string[],int&,string [],float[],int &);
void printSalesRecord(string[],int [],int[],int &,int &);
void checkTotalRavenue(int &);
void updateRecord(string [],int [],int &,int &);
void CheckListedProducts(string[],int &);
void updateRates(string[],int[],int &);
void UpdateTaxRate(int &);
void showUsers(string[], string[],int &);
void removeUser(string[],string[],string[],int&);
void editRecord(string[],int[],int[],int[],int &);
void addProduct(string [],int[],int [],int[], int &);
void removeProduct(string[],int[],int[],int[],int &);
bool checkProduct(string [],string ,int &);
void change_Admin_Code(string &);
void show_complains(string[], int);
void show_reviews(string[],float[],int);


main(){
     
    int TotalRevenue=0;
    string products[30] = {"Biscuits","Lays","Bread_pack","Milk_Pack","Register","Marker","Rice_Pack","Flour_Pack"};
    int ProductPrice[30] = {50,70,200,50,100,60,250,150};
    int items_bought_by_user[30];
    int total_bought_items[30];
    int productIndex = 8;
    int taxRate = 10;
    int totalSales = 0;
    for(int i=0;i<productIndex;i++){
        total_bought_items[i] = 0;
        items_bought_by_user[i] = 0;
    }

    // DataBases
    string user_Names_data[30];
    string paswords_data[30];
    string roles_data[30];
    int userName_index = 0;

    string reviews[30];


    string complains[30];
    int complains_index=0;

    // Admin Code:
    string admin_code = "blazefood"; 

    // Username variable for entered in sign in username, to be used in change password
    string runing_username = "";    
    
    //theme (app settings)
    string themes_data[30];
    string theme_color = themes_data[userName_index];
    system(theme_color.c_str());

    //Review System
    string review[30];
    float ratings[30];
    int review_index=0;
    
    
    start_menu(user_Names_data,paswords_data,roles_data,userName_index, products,ProductPrice,items_bought_by_user,total_bought_items,taxRate,productIndex,TotalRevenue,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);   
}

void start_menu(string user_Names_data[],string paswords_data[],string roles_data[],int &userName_index,   string products[],int productPrice[],int productBoughtByUser[],int totalProductsBought[],int &taxRate,int &productIndex,int &totalRevenue, string &admin_code, string &theme_color,string &runing_username,string themes_data[],string complains[],int &complains_index,string review[],float ratings[],int &review_index){
    int option;
    while (true){
    system("cls"); 
    printHeader();
    cout << "1. Sign In \n";
    cout << "2. Sign Up \n";
    cout << "3. Exit \n";
    cout << "Enter your choice: ";
    cin  >> option;   
    if(option==1){
        sign_in(user_Names_data,paswords_data,roles_data,userName_index, products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue, admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
    }else if(option==2){
        sign_Up_in(user_Names_data,paswords_data,roles_data,userName_index, products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue, admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
    }else if(option==3){
        break;
    }
    }
}
void sign_in(string user_Names_data[],string paswords_data[],string roles_data[],int &userName_index,  string products[],int ProductPrice[],int items_bought_by_user[],int totalitems_bought_by_user[],int &taxRate,int &productIndex,int &totalRevenue, string &admin_code,string &theme_color,string &runing_username,string themes_data[],string complains[],int &complains_index,string review[],float ratings[],int &review_index){
    system("cls");
    SignIn_Header();
    int errorChoice;
    string signInOption;
    string userName;
    string password;
    cout << "Enter userName: ";
    cin  >> userName;
    cout << "Enter Password: ";
    cin  >> password;
    runing_username = userName;
    signInOption = signIn(userName,user_Names_data,password,paswords_data,roles_data,userName_index,admin_code);
    if(signInOption == "user"){
        user(products,ProductPrice,items_bought_by_user,totalitems_bought_by_user,productIndex,taxRate,totalRevenue,user_Names_data,theme_color,runing_username,paswords_data,userName_index,themes_data,complains,complains_index,review,ratings,review_index);
    }else if(signInOption == "manager"){
        manager(products,ProductPrice,items_bought_by_user,totalitems_bought_by_user, productIndex,taxRate,totalRevenue, user_Names_data,roles_data,paswords_data, userName_index,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
    }else if(signInOption == "Invalid Password"){
        cout << "Invalid Password \n";
        cout << "Enter 1 to try again or  0 to go back";
        cin  >> errorChoice;
        if(errorChoice == 1){
            sign_in(user_Names_data,paswords_data,roles_data,userName_index, products,ProductPrice,items_bought_by_user,totalitems_bought_by_user,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
        }else if(errorChoice == 0){
            start_menu(user_Names_data,paswords_data,roles_data,userName_index,products,ProductPrice,items_bought_by_user,totalitems_bought_by_user,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
        }

    }else if(signInOption == "Not Found"){
        cout << "Invalid userName.Rather Sign Up \n";
        cout << "Enter 1 to try again 0 to go back";
        cin  >> errorChoice;
        if(errorChoice == 1){
            sign_in(user_Names_data,paswords_data,roles_data,userName_index, products,ProductPrice,items_bought_by_user,totalitems_bought_by_user,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
        }else if(errorChoice == 0){
            start_menu(user_Names_data,paswords_data,roles_data,userName_index,products,ProductPrice,items_bought_by_user,totalitems_bought_by_user,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_username,themes_data,complains,complains_index,review,ratings,review_index);
        }
    }
    
}
string signIn(string userName,string user_Names_data[],string password,string paswords_data[],string roles_data[],int &userName_index, string &admin_code){
    int index;
    string result;
    bool isAuser;
    isAuser = doesUserNameExists(userName,user_Names_data,userName_index);
    if(isAuser){
        index = userNameIndex(userName,user_Names_data,userName_index);
        if(password == paswords_data[index]){
            if(roles_data[index] == "user"){
                result = "user";
            }else if(roles_data[index] == "manager"){
                result = "manager";
            }
        }else{
            result = "Invalid Password";
            }
    }else{
        result = "Not Found";
    }    
    return result;
}
void sign_Up_in(string user_Names_data[],string paswords_data[],string roles_data[],int &userName_index,   string products[],int productPrice[],int productBoughtByUser[],int totalProductsBought[],int &taxRate,int &productIndex,int &totalRevenue, string &admin_code,string &theme_color,string &runing_usernme,string themes_data[],string complains[],int &complains_index,string review[],float ratings[],int &review_index){
    system("cls");
    SignUp_Header();
    string userName,password,role,signUp_op;
    int errorChoice;
    cout << "Enter User Name: ";
    cin  >> userName;
    cout << "Enter Password (min 6 characters): ";
    cin  >> password;
    cout << "Enter Role(user or manager): ";
    cin  >> role;
    signUp_op = SignUp(userName,user_Names_data,password,paswords_data,role,roles_data,userName_index,admin_code);
    

    if(signUp_op == "user"){
        user_Names_data[userName_index] = userName;
        paswords_data[userName_index] = password;
        roles_data[userName_index] = role;
        userName_index++;
    }
    else if(signUp_op == "manager"){
        user_Names_data[userName_index] = userName;
        paswords_data[userName_index] = password;
        roles_data[userName_index] = role;
        userName_index++;

    }
    else if(signUp_op == "incorrect Role"){
        cout << "Role must be user or manager \n";
        cout << "Enter 1 to try again 0 to go back...";
        cin  >> errorChoice;
        if(errorChoice == 1){
            sign_Up_in(user_Names_data,paswords_data,roles_data,userName_index,   products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }else if(errorChoice==0){
            start_menu(user_Names_data,paswords_data,roles_data,userName_index,products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }

    }else if(signUp_op == "incorrect Password"){
        cout << "Password length must at least be 6 characters long \n\n";
        cout << "Enter 1 to try again 0 to go back...";
        cin  >> errorChoice;
        if(errorChoice == 1){
            sign_Up_in(user_Names_data,paswords_data,roles_data,userName_index,   products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }else if(errorChoice==0){
           start_menu(user_Names_data,paswords_data,roles_data,userName_index,products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }
    }
    else if("user already Exists"){
        cout << "User already exists...";
        cout << "Enter 1 to try again 0 to go back...";
        cin  >> errorChoice;
        if(errorChoice == 1){
            sign_Up_in(user_Names_data,paswords_data,roles_data,userName_index,   products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }else if(errorChoice==0){
            start_menu(user_Names_data,paswords_data,roles_data,userName_index,products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }
    }
    else if("incorrect admin code"){
        cout << "Admin code is incorrect   \n";
        cout << "Enter 1 to try again.     \n";
        cin>>errorChoice;
        if(errorChoice==1){
            sign_Up_in(user_Names_data,paswords_data,roles_data,userName_index,   products,productPrice,productBoughtByUser,totalProductsBought,taxRate,productIndex,totalRevenue,admin_code,theme_color,runing_usernme,themes_data,complains,complains_index,review,ratings,review_index);
        }
    }

}
string SignUp(string userName,string user_Names_data[], string password,string paswords_data[],string role,string roles_data[],int &userName_index, string &admin_code){
    system("cls");
    SignUp_Header();
    string result;
    string ad_code;
    bool isAlreadyUser;
    isAlreadyUser = doesUserNameExists(userName,user_Names_data,userName_index);
    if(!isAlreadyUser){
        if(password.length()>=6){
            if(role == "user" || role == "manager"){
                if(role == "manager"){
                    cout<<"Enter Admin code: ";
                    cin>>ad_code;
                    if(ad_code==admin_code){
                        result = "manager";
                    }
                    else{
                        result = "incorrect admin code";
                    }
                }
                else{
                    result = "user";
                }
            }
            else{
                result = "incorrect Role";
            }
        }
        else{
            result = "incorrect Password";
        }
    }
    else{
        result = "user already Exists";
    }
    return result;
}
bool validation_for_name(string name){
    for(int i=0; i<name.length(); i++){
        if(!(name[i] >= 'A'&& name[i] <= 'Z')||(name[i] >= 'a'&& name[i] <='z')||(name[i]=='_')||(name[i]>='0'&&name[i]<='9')){
            return false;
        }
    }
    return true;
}
bool doesUserNameExists(string userName,string user_Names_data[],int &userName_index){
    for(int i=0;i<userName_index;i++){
        if(user_Names_data[i] == userName){
        return true;
        }   
    }
    return false;
}
int userNameIndex(string userName,string user_Names_data[],int &userName_index){
    for(int i=0;i<userName_index;i++){
        if(user_Names_data[i] == userName){
            return i;
        }
    }
}

// Functions for MANAGER AND USER
void manager(string products[],int ProductPrice[], int productBoughtByUser[],int totalBoughtProducts[],int &productIndex,int &taxRate,int &totalRavenue,   string user_Names_data[], string roles_data[],string passwords_data[],int &userName_index, string &admin_code,string &theme_color,string &runing_username,string themes_data[],string complains[],int &complains_index,string review[],float ratings[],int &review_index){
    int option;
    while(true){
        system("cls");
        printHeader();
        smallMenu("");
        cout << "What do you want: \n\n";
        cout << " 1: Update Record  \n";
        cout << " 2: Edit Record    \n";
        cout << " 3: Show all Users    \n";
        cout << " 4: remove User    \n";
        cout << " 5: Check Listed Products  \n";
        cout << " 6: Print Sales Record     \n";
        cout << " 7: Check Total Revenue    \n";
        cout << " 8: App Settings           \n";
        cout << " 9: Change Admin Code      \n";
        cout << "10: See Complains          \n";
        cout << "11: See Reviews & Ratings  \n";
        cout << "12: Log out \n\n";

        cout << "Option #: ";
        cin  >> option;
        if(option == 1){
            updateRecord(products,ProductPrice,productIndex,taxRate);
        }
        else if(option == 2){
            editRecord(products,ProductPrice,productBoughtByUser,totalBoughtProducts,productIndex);       
        }
        else if(option == 3){
            showUsers(user_Names_data,roles_data,userName_index);
        }
        else if(option == 4){
            removeUser(user_Names_data,passwords_data,roles_data,userName_index);
        }
        else if(option == 5){
            CheckListedProducts(products, productIndex);
        }
        else if(option == 6){
            printSalesRecord(products,ProductPrice,totalBoughtProducts,taxRate,productIndex);       
        }
        else if(option == 7){
            checkTotalRavenue(totalRavenue);
        }
        else if(option == 8){
            app_settings(theme_color, runing_username, passwords_data,user_Names_data,userName_index,themes_data);
        }
        else if(option == 9){
            change_Admin_Code(admin_code);
        }
        else if(option == 10){
            show_complains(complains,complains_index);
        }
        else if(option == 11){
            show_reviews(review,ratings,review_index);
            cout << "Press any key to go back..";
            getch();
        }
        else if(option == 12){
            break;
        }
        else{
            cout << "invalid choice. press any key to try again...";
            getch();
        }
    }
}
void showUsers(string user_Names_data[], string roles_data[],int & userName_index){
    system("cls");
    printHeader();
    smallMenu("Check Users List");
    cout << endl;
    cout << "Sr   " << setw(10) << "User Names" << setw(10) << "Roles" << endl;
    for(int i=0;i<userName_index;i++){
        cout << i+1 <<" "<< setw(10) << user_Names_data[i] << setw(15) << roles_data[i] << "\n";
    }
    cout << "\npress any key to go back...";
    getch();

}
void removeUser(string user_Names_data[],string passwords_data[],string roles_data[],int & userName_index){
    string user;
    int index;
    printHeader();
    smallMenu("Remove Users");
    cout << "Users are: \n\n";
    cout << "Sr   " << setw(10) << "User Names" << setw(10) << "Roles" << endl;
    for(int i=0;i<userName_index;i++){
        cout << i+1 <<" "<< setw(10) << user_Names_data[i] << setw(15) << roles_data[i] << "\n";
    }
    cout << "\nEnter an index to delete or Press 0 to go back \n";
    cin >> index;
    if(index !=0){
        if(roles_data[index-1]=="manager"){
            cout << "You cannot delete any manager or yourself..\n\n";
            cout << "Press any key to go back..\n";
            getch();
        }
        else{
        user = user_Names_data[index-1];
            for(int i=index-1;i<userName_index-1;i++){
                user_Names_data[i] = user_Names_data[i+1];
                passwords_data[i] = passwords_data[i+1];
                roles_data[i] = roles_data[i+1];
            }
        user_Names_data[userName_index-1] = "";
        passwords_data[userName_index-1] = "";
        roles_data[userName_index-1] = "";
        userName_index--;
        cout << user << " is removed\n";
        cout << "press any key to continue....";
        getch();
        }
    }
}    
void checkTotalRavenue(int &totalRavenue){
    system("cls");
    printHeader();
    smallMenu("Check Total Revenue");
    cout << "     Total Ravenue Generated: " << totalRavenue << "\n";
    cout<<"______________________________________\n";
    cout << "press any key to continue....";
    getch();
    }
void printSalesRecord(string products[],int productPrice[],int totalBoughtProducts[],int &taxRate,int &productIndex){
    system("cls");
    printHeader();
    smallMenu("Sales menu");
    cout<<endl;
    cout << "#################################################\n";
    cout << "#-----------------------------------------------#\n";
    cout << "# " << setw(12) <<left<< "index" << setw(15)<<left << "item" << setw(15) << "sold" << "    #\n";
    for(int i=0;i<productIndex;i++){
        cout <<"# " << setw(12)<<left << i+1 << setw(15) <<left<< products[i] << setw(13) << totalBoughtProducts[i] << "      #\n";
    }
    cout << "#-----------------------------------------------#\n";
    cout << "#################################################\n";
    cout << "\npress any key to go back";
    getch();

}
int calculateTotalSale(int productPrice[],int totalBoughtProducts[],int &taxRate,int &productIndex){
    int bill = 0;
    for(int i=0;i<productIndex;i++){
        bill += productPrice[i]*totalBoughtProducts[i];
    }
    bill += (bill*taxRate)/100;
    return bill;
}
void updateRecord(string products[],int productPrice[],int &productIndex,int &taxRate){
    int choice;
    while(true){
        system("cls");
        printHeader();
        smallMenu("Update Record");
        cout << "Enter Your Choice \n";
        cout << "1: Update Rates\n";
        cout << "2: Update Tax\n";
        cout << "3: Go back\n";
        cin  >> choice;
        if(choice == 1){
            updateRates(products,productPrice,productIndex);
        }else if(choice == 2){
            UpdateTaxRate(taxRate);
        }else if(choice == 3){
            break;
        }
    }

}
void CheckListedProducts(string products[],int &productIndex){
    system("cls");
    printHeader();
    smallMenu("Listed Items");
    cout << "Listed Products are \n";
    for(int i=0;i<productIndex;i++){
        cout << i+1 << ": " << products[i] << "\n";
    }
    cout << "\n press any key to continue...";
    getch();
}
void UpdateTaxRate(int &taxRate){
    int tax;
    cout << "Previous tax rate was " << taxRate << "\n Enter new tax rate: ";
    cin  >> tax;
    taxRate = tax;
    cout << "Enter any key to continue....";
    getch();
}
void updateRates(string products[],int productPrice[],int &productIndex){
    system("cls");
    printHeader();
    smallMenu("Update Rates");
    int number,price;
    cout << endl;
    for(int i=0;i<productIndex;i++){
            cout << i+1 <<":  " << products[i]<< "\n";
    }
    cout << productIndex+1 << ": Done\n";
    while(true){
        cout << "select product from list which you want to update \n";
        cin >> number;
        if(number<=productIndex){
            cout << "Last rate of " << products[number-1] << " was " << productPrice[number-1] << " enter new price ";
            cin  >> price; 
            productPrice[number-1] = price;
        }
        else if(number == productIndex+1){
            for (int i=0;i<productIndex;i++){
                cout << setw(10) << productPrice[i];
            }
            break;
        }
    
    }
}
void editRecord(string products[],int ProductPrice[],int productBoughtByUser[],int totalBoughtProducts[], int &productIndex){
    int choice;
    while(true){
        system("cls");
        printHeader();
        smallMenu("Edit Record");
        cout << "Enter Your Choice..\n";
        cout << "1: add product\n";
        cout << "2: remove product\n";
        cout << "3: go back\n";
        cin  >> choice;
        if(choice == 1){
            addProduct(products,ProductPrice,productBoughtByUser,totalBoughtProducts,productIndex);
        }
        else if(choice == 2){
            removeProduct(products,ProductPrice,productBoughtByUser,totalBoughtProducts,productIndex);
        }
        else if(choice == 3){
            break;
        }
    }
}
void addProduct(string products[],int ProductPrice[],int productBoughtByUser[],int totalBoughtProducts[], int &productIndex){
    system("cls");
    printHeader();
    smallMenu("Add Item");
    string product_name;
    int price,choice;
    cout << "Enter the name of Product: ";
    cin>>product_name;
    cout << "Enter Price: ";
    cin  >> price;
    cout << "press 1 to confirm or 0 to go back...";
    cin  >> choice;
    if(choice == 1){
        if(!checkProduct(products,product_name,productIndex)){
        products[productIndex] = product_name;
        ProductPrice[productIndex] = price;
        productBoughtByUser[productIndex] = 0;
        totalBoughtProducts[productIndex] = 0;
        productIndex++;
        cout << product_name << " is added successfully to the list .....\n";
        cout << "Enter any key to continue";
        getch();
        }else{
            cout << product_name << " already exists....";
            cout << "Enter any key to continue";
            getch();
        }
    
    }
    else{
        cout << product_name << " not added...";
        cout << "Enter any key to go back";
        getch();
    }

}
void removeProduct(string products[],int productPrice[],int items_bought_by_user[],int totalProductsBought[],int &productIndex){
    system("cls");
    printHeader();
    smallMenu("Remove X item ");
    string product;
    int index;
    cout << "Products are: \n";
    for(int i=0;i<productIndex;i++){
        cout << i+1 << setw(10) << products[i]<< "\n";
    }
    cout << "Enter an index to delete: \n";
    cout << "press 0 to go back";
    cin >> index;
    if(index !=0){
        product = products[index-1];
            for(int i=index-1;i<productIndex-1;i++){
                products[i] = products[i+1];
                productPrice[i] = productPrice[i+1];
                items_bought_by_user[i] = items_bought_by_user[i+1];
                totalProductsBought[i] = totalProductsBought[i+1];
            }
        products[productIndex-1] = "";
        productPrice[productIndex-1] = 0;
        items_bought_by_user[productIndex-1] = 0;
        totalProductsBought[productIndex-1] = 0;
        productIndex--;
        cout << product << " removed\n";
        cout << "press any key to continue....";
        getch();
    }
}


bool checkProduct(string products[],string product,int &productIndex){
    for(int i=0;i<productIndex;i++){
        if(products[i] == product){
            return true;
        }
    }
    return false;
}

void change_Admin_Code(string &admin_code){
    printHeader();
    smallMenu("Change Admin Code");
    string new_admin_code;
    cout << "Enter new ADMIN CODE : ";
    cin >> new_admin_code;

    admin_code = new_admin_code;

    cout << "Admin code is now changed...\n";
    cout << "press any key to go back....\n";
    getch();

}

void user(string products[],int productPrice[],int productBoughtByUser[],int totalBoughtProducts[],int &productIndex,int &taxRate,int &totalRevenue,string usernames_data[],string &theme_color,string &runing_username,string passwords_data[], int &userName_index,string themes_data[],string complains[],int &complains_index,string review[],float ratings[],int &review_index){
    int option;
    while (true){
    system("cls");
    printHeader();
    smallMenu("User Menu");
    cout << "What do you want:     \n \n";
    cout << "1. Check items prices \n";
    cout << "2. Buy items          \n";
    cout << "3. Check My Cart      \n";
    cout << "4. Pay bill           \n";
    cout << "5. Customer Support   \n";
    cout << "6. App Settings       \n";
    cout << "7. exit               \n";
    cin  >> option;
    if(option == 1){
        print_item_rates(products,productPrice,productIndex);
    }
    else if(option == 2){
        fn_buy_items(products,productBoughtByUser,productIndex);

    }
    else if(option == 3){
        bill_view(products,productPrice,productBoughtByUser,productIndex,taxRate);
    }
    else if(option == 4){
        fn_paybill(productBoughtByUser,totalBoughtProducts,productPrice,productIndex,taxRate,totalRevenue);
    }
    else if(option == 5){
        customerSupport(complains, complains_index,review,ratings,review_index);
    }
    else if(option == 6){
        app_settings(theme_color, runing_username, passwords_data,usernames_data,userName_index,themes_data);
    }
    else if(option == 7){
        break;
    }
    }
}
void print_item_rates(string products[],int ProductPrice[],int &productIndex){
    system("cls");
    printHeader();
    smallMenu("User Menu> Check item Rates");
    cout << "__________________________________________________________\n";

    for(int i=0;i<productIndex;i++){
        cout <<"|"<< setw(25) << products[i] << setw(15) << ProductPrice[i] <<setw(20) << "|\n";
    }
    cout << "__________________________________________________________\n";
    cout <<"\n Press any key to continue.....";
    getch();
}
void fn_buy_items(string products[],int items_bought_by_user[],int &productIndex){
    system("cls");
    printHeader();
    smallMenu("User Menu> Buy Items");
    cout << endl;
    for(int i=0;i<productIndex;i++){
        items_bought_by_user[i] = 0;
    }
    int option,number;
        cout << "------------------------------------"<<endl;
        cout << "           Sr"<<"   Product Name    "<<endl;
        cout << "------------------------------------"<<endl;
     for(int i=0;i<productIndex;i++){
        cout << "           "<< i+1 << ":        " << products[i]<<"\n";
    }
        cout << "    " << productIndex+1 << ": Done.....\n";


    while (true)
    {
    cout << "    What do you want to buy: \n";
    cin >> option;

    if(option == productIndex+1){
            break;
        }
        if(option > productIndex+1){
            cout << "invalid option....\n";
        }
        else{
            cout << "Enter number: ";
            cin  >> number;
            items_bought_by_user[option-1] = number;
        }
    }
}
void bill_view(string products[],int productPrice[],int productBoughtByUser[],int &productIndex,int &taxRate){
    system("cls");
    printHeader();
    smallMenu("User Menu> Check Bill");
    int bill,tax,total;
    bill = bill_calculator(productBoughtByUser,productPrice,productIndex,taxRate);
    tax = tax_calculator(productBoughtByUser,productPrice,productIndex,taxRate);
    total = bill + tax;
    cout << "__________________________________________________________________\n";
    cout << "#                                                                 #\n";
    cout << "#  "<< setw(10)<<left << "Index" << setw(12) << "Product" << setw(12) << "Price" << setw(12) << "Quantity" << setw(11) << "Total" << "      #\n";
    for(int i=0;i<productIndex;i++){
        cout << "#     "<< setw(8)<<left << i+1 << setw(12) << left << products[i] << setw(12) << productPrice[i] << setw(12) << productBoughtByUser[i] << setw(11) << productBoughtByUser[i] * productPrice[i]<< "     #\n";
    }
    cout << "#                                                                 #\n";
    cout << "# "<< setw(14) << left<< "Bill: " <<setw(9) << left << bill << setw(9)<<right << "Tax: "<<setw(9)<< left<<tax << setw(9)<<right<< "Total: "<<setw(11) << left<<total <<"   #\n";
    cout << "#                                                                 #\n";
    cout << "#_________________________________________________________________#\n";
    
    cout <<"\n press any key to go back.....";
    getch();
}
int bill_calculator(int items_bought_by_user[],int productPrice[],int &productIndex,int &taxRate){
    int bill=0;
    for(int i=0;i<productIndex;i++){
        bill += (productPrice[i] * items_bought_by_user[i]);
    }
    return bill;
}
int tax_calculator(int items_bought_by_user[],int productPrice[],int &productIndex,int &taxRate){
    int bill,tax;
    bill = bill_calculator(items_bought_by_user,productPrice,productIndex,taxRate);
    tax = (bill*taxRate)/100;
    return tax;

}
void fn_paybill(int productBoughtByuser[],int totalBoughtProducts[],int productPrice[],int &productIndex,int &taxRate,int &totalRevenue){
    system("cls");
    printHeader();
    smallMenu("User Menu> Pay Bill");
    int bill,tax,totalBill;
    for(int i=0;i<productIndex;i++){
        totalBoughtProducts[i] += productBoughtByuser[i];
    }
    bill = bill_calculator(productBoughtByuser,productPrice,productIndex,taxRate);
    tax = tax_calculator(productBoughtByuser,productPrice,productIndex,taxRate);
    totalBill = bill + tax;
    cout << "Your bill is: "<< totalBill << "\n";
    cout << "Enter any character to pay bill";
    getch();
    for(int i=0;i<productIndex;i++){
        productBoughtByuser[i] = 0;
    }
    totalRevenue += totalBill;
}

void customerSupport(string complains[], int &complains_index,string review[],float ratings[],int &review_index){
    printHeader();
    smallMenu("Customer Support");
    int choice;
    cout << "Enter what do you want to do:  \n";
    cout << "1. Report any complain         \n";
    cout << "2. Contact Us                  \n"; 
    cout << "3. Our Social Accounts         \n";
    cout << "4. Check Ratings and Reviews.  \n";
    cout << "5. Review/Rate our Service     \n";

    cin >> choice;

    if(choice == 1){
        write_complain(complains, complains_index);
    }
    else if(choice == 2){
        contact_page();
    }
    else if(choice == 3){
        Social_Accounts_page();
    }
    else if(choice == 4){
        show_reviews(review,ratings,review_index);
    }
    else if(choice == 5){
        review_rating(review,ratings,review_index);
    }

    cout<<"Press any key to go back..\n";
    getch();
}

void write_complain(string complains[], int &complains_index){
    printHeader();
    smallMenu("Write Complain");
    string complain_content;
    cin.ignore();
    cout << "Write your complain Below: \n\n";
    getline(cin,complain_content);

    complains[complains_index]=complain_content;
    complains_index++;

    cout << "Your complain has been sent to the administrator..\n";
}
void show_complains(string complains[], int complains_index){
    printHeader();
    smallMenu("Show Complains");
    cout << endl;
    cout << setw(5) << left <<"Sr"<< setw(10) << right<<"Complains\n";
    for(int i=0; i<complains_index; i++){
        cout <<" " << setw(5) << left << i+1 << complains[i] <<endl;
    }
    cout << "\nPress any key to go back..";
    getch();
}


void contact_page(){
    printHeader();
    smallMenu("Contact Us Page");
    cout << endl;
    cout << "You can can contact us by using the following media..\n\n";
    cout << " Email : generalStore@gmail.com\n";            //Readable Only
    cout << " Phone : 056-876952220         \n\n";

}

void Social_Accounts_page(){
    printHeader();
    smallMenu("Social Accounts Page");
    cout << endl;
    cout << "Follow our page On Social Media Platforms to stay tuned with updates..\n\n";
    cout << "Facebook : www.facebook.com/generalStore    \n";   //Readable Only
    cout << "Instagram : www.instagram.com/generalStore  \n";
    cout << "Twitter : www.twitter.com/generalStore      \n\n";
    
}

void app_settings(string &theme_color, string runing_username,string passwords_data[],string user_Names_data[],int &userName_index,string themes_data[]){
    printHeader();
    smallMenu("App Settings");
    int option;
    cout << "What do want to do: \n\n";
    cout << "1. Change App Theme   \n";
    cout << "2. Change Password    \n";
    cout << "3. Go back            \n";
    cin >> option;

    if(option == 1){
        changeSystemColor(theme_color,themes_data,userName_index);
    }
    else if(option == 2){
        change_Password(runing_username,passwords_data,user_Names_data,userName_index);
    }
    else if(option == 3){
        return;
    }
    else{
        cout << "Invalid Choice \n";
        cout << "Press any key to go back..";
        getch();
    }
}

void review_rating(string review[],float ratings[],int &review_index){
    printHeader();
    smallMenu("Rate Us");
    string comment; 
    float User_rating;
    cout << endl;
    cin.ignore();
    cout << "Enter your Review: ";
    getline(cin,comment);
    cout << "Enter Rating out of 10: ";
    cin >> User_rating;

    if (User_rating > 10){
        cout << "\nRating out of Range... Review not Submitted\n\n";
    }
    else{
         review[review_index]=comment;
         ratings[review_index]=User_rating;
         review_index++;
         cout << "\nThanks! Your Review has been submitted...\n";
    }

}

void show_reviews(string review[],float ratings[],int review_index){
    printHeader();
    smallMenu("See Reviews/Ratings");
    cout << endl;
    cout << setw(7)<<left<< "No."<<setw(12)<<left<< "Rating" <<setw(12)<<left<< "Review" <<endl;

    for(int i=0; i<review_index; i++){
        cout << setw(7) <<left << i+1 <<" "<<setw(12)<<left<<ratings[i]<<"/10"<<setw(12)<<left<<review[i]<<endl;
    }
    cout << endl;
}

void change_Password(string runing_username, string passwords_data[],string user_Names_data[],int &userName_Index){
    printHeader();
    smallMenu("Change Password");
    int index = userNameIndex(runing_username, user_Names_data, userName_Index);
    int choice;
    string old_password, newpassword;
    cout << endl;
    cout << "Enter your Previous Password: ";
    cin >> old_password;

    if (old_password==passwords_data[index]){
        cout << "Enter New Password: ";
        cin >> newpassword;
        passwords_data[index] = newpassword;
        cout << "Password Changed Successfully!  \n";
        cout << "Press any key to go back....";
        getch();
    }
    else {
        cout << "Password did'nt matched ... \n";
        cout << "Enter 1 to try again ... or 0 to go back ";
        cin >> choice;
        if(choice == 1){
            change_Password(runing_username,passwords_data,user_Names_data,userName_Index);
        }
        else if(choice!=1){
            return;
        }
    }
    
}

void changeSystemColor(string &theme_color, string themes_data[],int &userName_index){
    printHeader();
    smallMenu("Change App Theme");
    string colorCode;
    cout << "Enter the color code (only Hexadecimal two digit value e.g A9, E5): ";
    cin >> colorCode;
    if (colorCode.size() != 2 ||(colorCode[0] < '0' || (colorCode[0] > '9' && colorCode[0] < 'A') || colorCode[0] > 'F') ||
        (colorCode[1] < '0' || (colorCode[1] > '9' && colorCode[1] < 'A') || colorCode[1] > 'F')) 
        {
        cout << "     >>>>>>>>>>>>>>>>>  Invalid color code. Please enter a valid hexadecimal color code.   <<<<<<<<<<<<<<<<<<    \n\n\n";
    }
    else{
    string full_command = "color " + colorCode;
    system(full_command.c_str());
    themes_data[userName_index]=full_command;

    }
    cout << "App theme changed to " << colorCode <<endl;
    cout << "Press any key to go back.....";
    getch();
} 

void smallMenu(string submenu)
{
    cout <<"____________________________________________________________________________________________________________________________________________________________________________\n\n";
    cout << "                                                                        Main Menu> "+submenu+"\n";
    cout <<"____________________________________________________________________________________________________________________________________________________________________________\n";

}
void SignUp_Header(){
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
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------        

    )";

}
void SignIn_Header(){
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
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------        

    )";
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
