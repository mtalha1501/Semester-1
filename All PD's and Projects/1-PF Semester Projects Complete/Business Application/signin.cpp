#include<iostream>
using namespace std;

void signin(string username, string password);
bool checkUser(string username);

string usernameDB[100], passwrodDB[100], roleDB[100];
int user_index = 0;
string admin_code = "abcd1234";


main()
{
    string username, password;
    signin(username, password);
    return 0;
}
void signin()
{
    string username,password,role;
    int errorChoice;
    if(checkUser){
        
    }
    else{
        cout<<"User not found..."<<endl;
        cout<<"Enter 1 to try again..";
        cin>>errorChoice;
        if(errorChoice==1){
            signin(username, password);
        }
    }
}
bool checkUser(string username){
    for(int i=0; i<=username.length(); i++){
        if(username == usernameDB[i] ){
            return true;
        }
    }
    return false;
}
int checkuserIndex(string username){

}