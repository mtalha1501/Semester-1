
#include<iostream>
using namespace std;

void signup();
bool checkUser(string username);

string usernameDB[100], passwrodDB[100], roleDB[100];
int user_index = 0;
string admin_code = "abcd1234";


main()
{
    int n;
    while(true){
        system("cls");
        cout << "Enter choice: ";
        cin  >> n;
        if(n==1){
            signup();
        }
    }

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

bool checkUser(string username){
    for(int i=0; i<=user_index; i++){
        if(username == usernameDB[i] ){
            return true;
        }
    }
    return false;
}

string SignUp(string userName,string user_Names_data[], string password,string paswords_data[],string role,string roles_data[],int &userName_index, string &admin_code){
    system("cls");
    SignUp_Header();
    string result;
    string ad_code;
    bool isAlreadyUser;
    isAlreadyUser = doesUserNameExists(userName,user_Names_data,userName_index);
    if(validation_for_name(username)){
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
    }
    else{
        return "Username is not valid";
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