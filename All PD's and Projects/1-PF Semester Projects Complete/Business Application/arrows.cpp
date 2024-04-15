#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
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


int ShowMenu(vector<string> &optionList)
{
    int option = 0;
    while (true)
    {
        for (int i = 0; i < optionList.size(); i++)
        {
            if (option == i)
            {
                Color(06);
                gotoxy(70, 9 + i);
                cout << "  " << optionList[i] << "      ";
                Color(7);
            }
            else
            {
                gotoxy(70, 9 + i);
                cout << "    " << optionList[i] << "        ";
            }
        }
        if (GetAsyncKeyState(VK_UP))
        {
            option = (option == 0) ? optionList.size() - 1 : option - 1;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            option = (option == optionList.size() - 1) ? 0 : option + 1;
        }
        else if (GetAsyncKeyState(VK_RETURN))//enter
        {
            return option;
        }
        Sleep(200);
    }
}
int main()
{
    // header();

    vector<string> menus = {"main","help","exit"};
    while(true)
    {

    int option = ShowMenu(menus);
    if(option == 0)
    {
        system("cls");
        cout << "main function is invoked";
        
    }
    if(option == 2)
    {
    break;

    }
    }
}