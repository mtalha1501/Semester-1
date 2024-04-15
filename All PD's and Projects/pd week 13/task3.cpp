#include<iostream>
#include<fstream>
#include<string>
using namespace std;

main()
{
    string name, agestring;
    int age;
    fstream file;
    string line;
    file.open("names.txt", ios::in);
    while(getline(file, line)){

    getline(file, name, ',');
    getline(file, agestring);
    
    }
    
    cout<<name<<agestring;

    return 0;
}

void getBirthdayCake(string name, int age){

}