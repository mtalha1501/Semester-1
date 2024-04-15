#include<iostream>

using namespace std;
bool is_valid_single_digit(string num){
    if((num.length() == 1) && num[0] >= '0' && num[0] <= '9' && num[0]!= ' ' && num[0] != '\0' ){
       return true; 
    }
    return false;
}

main()
{
    string n;
    cin >> n;
    cout << is_valid_single_digit(n);
    return 0;
}