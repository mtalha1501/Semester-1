#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;

static void gotoxy(int , int );
void Color(int);
void hideAndVisibleCursor(bool isShow);
void grid(int &p1, int &p2,int size);
int RollDice();
void header();
int Score(int currentpos, int dicenumber);

int main(){
    hideAndVisibleCursor(false);
	int p1=1,p2=1;
	const int size = 10;
	system("cls");
    header();
    cout << endl;
	cout<<"\t\t\t\t\t(*)-----First Player"<<endl;
	cout<<"\t\t\t\t\t(X)-----Second Player"<<endl << endl;
	cout<<"\t\t\t\t\tBoth are on starting position in the board!"<<endl;
	cout<<endl;
	cout<<endl;
    
    while (p1 < 100 && p2 < 100) {
    system("cls");
    header();
	grid(p1,p2,size);
	cout<<endl;
    cout << "\n\t\t\t\t\tTurn of Player one! Press any key to roll the dice..."<<endl;
    cout<<endl;
    getch();        
    int dice1 = RollDice();
    cout << "\n\t\t\t\t\tPlayer 1 rolled a ";Color(05);cout << dice1; Color(07); cout<< endl;
    Sleep(600);
    p1 = Score(p1, dice1);	
    system("cls");
    header();
    grid(p1,p2,size);
    cout << "\n\t\t\t\t\tTurn of Player two! Press any key to roll the dice..."<<endl;
    cout<<endl;
    getch();        
    int dice2 = RollDice();
    cout << "\n\t\t\t\t\tPlayer 2 rolled a "; Color(05);cout << dice2; Color(07); cout<< endl;
    Sleep(600);
    p2 = Score(p2, dice2);	
    }
    cout << "\n\n\t\t\t\t\tGame Ended, Player at the top won the game!!";
}

void grid(int &p1, int &p2,int size){

    for (int i = size -1 ; i >= 0; i--){
        cout << "\t\t\t\t\t";
        for (int j = 0; j < size; j++) {
            int num = i * size + j + 1;
            if (num == p1){
                Color(04);
                cout << "(*)\t";
                Color(07); 
            }
            else if (num == p2){
                Color(03);
                cout << "(X)\t";
                Color(07);
            } 
            else
                cout <<num << "\t";
			
			
        }
        cout << endl;
    }
  
}


int RollDice() {
    return rand() % 6+1;
}
int Score(int currentpos, int dicenumber)
{
    int nextpos = currentpos + dicenumber;
    return nextpos;
}
void header()
{
    Color(02);
    cout << R"(
                                  _____                _                                   _   _                  _      _                  
                                 / ____|              | |                                 | | | |                | |    | |                 
                                | (___   _ __    __ _ | | __  ___  ___    __ _  _ __    __| | | |       __ _   __| |  __| |  ___  _ __  ___ 
                                 \___ \ | '_ \  / _` || |/ / / _ \/ __|  / _` || '_ \  / _` | | |      / _` | / _` | / _` | / _ \| '__|/ __|
                                 ____) || | | || (_| ||   < |  __/\__ \ | (_| || | | || (_| | | |____ | (_| || (_| || (_| ||  __/| |   \__ \
                                |_____/ |_| |_| \__,_||_|\_\ \___||___/  \__,_||_| |_| \__,_| |______| \__,_| \__,_| \__,_| \___||_|   |___/                                

    )";
    cout << "___________________________________________________________________________________________________________________________________________________________"<<endl<<endl;
    Color(07);
}
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
// Hide cursor Function
void hideAndVisibleCursor(bool isShow)      
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = isShow;
    SetConsoleCursorInfo(consoleHandle, &info);
}