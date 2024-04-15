#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void printheader();
void start();
void levels_menu();
void Instructions();
void Level_1_Header();
void printRoadLvl1();
void printroadLvl2();

void hideAndVisibleCursor(bool);      // Hide cursor Function
void show_score();
void show_health();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void Color(int color);
void printPlayer();
void erasePlayer();
void printEnemy1();
void eraseE1();
void printEnemy2();
void printEnemy3();
void printEnemy4();
void eraseE2();
void eraseE3();
void eraseE4();

void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerUp();
void movePlayerDown();

void moveE1();
void moveE2();
void moveE3();
void moveE4();

void fire_by_player();
void print_fire(int , int);
void remove_fires_from_arr(int fX,int fY);
void erase_fire(int frX, int frY);
void remove_fires_from_arr(int fX,int fY);
void move_fire(int frX, int &frY);


int px = 40, py = 10;

char player[4][5] = {{'_','_','|','_','_'},
                     {'|',' ','|',' ','|'},  
                     {'_',' ','P',' ','_'},  
                     {'|',' ','|',' ','|'},  
                     }; 

char fires[100];
int frX[100];
int frY[100];
int index_fr = 0;




main()
{
    cout << "#########################################################################################################################################################\n";
    while(true){
        if(GetAsyncKeyState(VK_LEFT)){
            movePlayerLeft();
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            movePlayerRight();
        }
        if(GetAsyncKeyState(VK_UP)){
            movePlayerUp();
        }
        if(GetAsyncKeyState(VK_DOWN)){
            movePlayerDown();
        }
        if(GetAsyncKeyState(VK_SPACE)){
            fire_by_player();
        }
        if(GetAsyncKeyState(VK_ESCAPE)){
            break;
        }
        for(int i = 0; i < index_fr; i++){
            move_fire(frX[i],frY[i]);
        }
        Sleep(180);
    }
    return 0;
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
        return;
}
char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';
}
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void printPlayer()
{
    int y = py; 
    Color(03);                  
    for(int i = 0; i < 4; i++){
        gotoxy(px,y);
        for(int j = 0; j < 5; j++){
            cout << player[i][j];
        }
        y++;
    }   
    Color(07);            
}
void erasePlayer()
{
    gotoxy(px,py);
    cout << "     " <<endl;
    gotoxy(px,py+1);
    cout << "     " <<endl;
    gotoxy(px,py+2);
    cout << "     " <<endl;
    gotoxy(px,py+3);
    cout << "     " <<endl;
}
void movePlayerLeft()
{
    if(getCharAtxy(px-3,py) != '#')
    {
        erasePlayer();
        px--;
        printPlayer();
    }
    if(getCharAtxy(px-3,py) == '|'||getCharAtxy(px-9,py) == '|')
    {
        erasePlayer();
        px-= 18;
        printPlayer();
    }
}
void movePlayerRight()
{
    if(getCharAtxy(px+7,py) != '#')
    {
        erasePlayer();
        px++;
        printPlayer();
    }
    if(getCharAtxy(px+8,py) == '|'||getCharAtxy(px+9,py) == '|')
    {
        erasePlayer();
        px+= 18;
        printPlayer();
    }
}
void movePlayerUp()
{
    if(getCharAtxy(px,py-2) != '#')
    {
        erasePlayer();
        py--;
        printPlayer();
    }
}
void movePlayerDown()
{
    if(getCharAtxy(px,py+4) != '#')
    {
        erasePlayer();
        py++;
        printPlayer();
    }
}
void fire_by_player()
{
    fires[index_fr] = '^';
    frX[index_fr] = px;
    frY[index_fr] = py-1;
    print_fire(frX[index_fr],frY[index_fr]);
    index_fr++;
}
void print_fire(int frX, int frY)
{
    if(getCharAtxy(frX-2,frY-1) != '#')
    {
        cout << "^";
    }
    else
    {
     remove_fires_from_arr(frX,frY);
    }
}
void remove_fires_from_arr(int fX,int fY)
{
    int index;
    for(int i=0;i<index_fr;i++){
        if(frY[i] == fY && frX[i] == fX){
            index = i;
            break;
        }
    }
    for(int j = index; j < index_fr-1; j++){
        fires[j] = fires[j+1];
        frX[j] = frX[j+1];
        frY[j] = frY[j+1];
    }
    index_fr--;
}
void erase_fire(int frX, int frY)
{
    gotoxy(frX,frY);
    cout << " ";
}
void move_fire(int frX, int &frY)
{
    erase_fire(frX,frY);
    frY--;
    print_fire(frX,frY);
}