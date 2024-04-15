#include<iostream>
#include<windows.h>
using namespace std;
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
main()
{


    cout << "This Game is based on survival. \n You need to protect your your player from being colliding with the enemy. \n";
    cout << "There are 3 Lanes in Easy Level. Each Contain one Enemy moving up and down \n";
    cout << "There are 4 Lanes in Hard Level.  Each Lane contains Moving Enemy with more speed\n";
    cout << "Press SPACE_KEY to generate fires upward and Press SHIFT_KEY to generate fires Downward\n";
    cout << "You have three Hearts, after losing them game will be over\n";
    return 0;
}