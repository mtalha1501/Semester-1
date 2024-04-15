



PD-3

1)
#include<iostream>
using namespace std;
  main () {
	int sides;
	cout << "Enter the number of sides of the polygon: ";
        cin >> sides;
        int sum;
        sum = (sides - 2) * 180;
	cout << "The sum of internal angles of a " << sides<<"-sided polygon is: " << sum << " degrees" << endl;
}
2)
#include<iostream>
using namespace std;
  main () {
	int min;
	int sec;
	cout << "Number of Minutes: ";
	cin >> min;
	cout <<"Frames per Second: ";
	cin >> sec;
        int frames = min * sec * 60;
	cout << "Total Number of Frames: " << frames << endl;
}
3)
#include<iostream>
using namespace std;
 main () {
	float invel;
	float acc;
	float time;
	cout << "Enter Initial Velocity (m/s): ";
	cin >> invel;
	cout << "Enter Acceleration (m/s^2): ";
	cin >> acc;
	cout << "Enter Time (s): ";
	cin >> time;
	float vf = invel + (acc*time);
	cout << "Final Velocity (m/s): " << vf << endl;
}
4)
#include<iostream>
using namespace std;
   main () {
	float impcount;
	int playercount;
	cout << "Enter Imposter Count: ";
	cin >> impcount;
	cout << "Enter Player Count: ";
	cin >> playercount;
	int chance;
	chance = (impcount/playercount) * 100;
	cout << "Chance of being an imposter: " << chance << "%" << endl;
}
5)
#include<iostream>
using namespace std;
  main () {
	float weightloss;
	string name;
	cout << "Enter the Name of the Person: ";
	cin >> name;
	cout << "Enter the target weight loss in kilograms: ";
	cin >> weightloss;
	int days; 
	days =  weightloss * 15.0;
	cout << name << " will need " << days << " days to lose " << weightloss << " kg of weight by following the doctor's suggestions";
}
6)
#include<iostream>
using namespace std;
  main () {
	float size;
	float cost;
	float area;
	cout << "Enter the size of the fertilizer bag in pounds: ";
	cin >> size;
	cout << "Enter the cost of the bag: $";
	cin >> cost;
	cout << "Enter the area in square feet that can be covered by the bag: ";
	cin >> area;
	float costpound = cost/size;
	float costsquare = cost / area;
	cout << "Cost of fertilizer per pound: $" << costpound << endl;
	cout << "Cost of fertilizing per square foot: $" << costsquare << endl;
}
7)
#include<iostream>
using namespace std;
  main () {
	string name;
	cout << "Enter the movie name: ";
	cin >> name;
	int adultticket;
	cout << "Enter the adult ticket price: $";
	cin >> adultticket;
	int childticket;
	cout << "Enter the child ticket price: $"; 
	cin >> childticket;
	int adnum;
	cout << "Enter the number of adult tickets sold: ";
	cin >> adnum;
	int chnum;
	cout << "Enter the number of child tickets sold: ";
	cin >> chnum;
	float percent;
	cout << "Enter the percentage of the amount to be donated to charity: ";
	cin >> percent;
	cout << "                   " << endl;
	int ticketsales = (adultticket * adnum) + (childticket * chnum);
	int donation = (ticketsales/percent);
	int remaining = ticketsales - donation;
	cout << "Movie: " << name << endl;
	cout << "Total amount generated from ticket sales: $" << ticketsales << endl;
	cout << "Donation to charity (" << percent << "%): " << donation << endl;
	cout << "Remaining amount after donation: $" << remaining << endl;
}
8)
#include<iostream>
using namespace std;
  main () {
	float vegprice;
	float fruitprice;		
	cout << "Enter vegetable price per kilogram (in coins): ";
	cin >> vegprice;
	cout << "Enter fruit price per kilogram (in coins): ";
	cin >> fruitprice;
	int kgveg;
	int kgfr;	
	cout << "Enter total kilograms of vegetables: ";
	cin >> kgveg;
	cout << "Enter total kilograms of fruits: ";
	cin >> kgfr;
	float totalcoins;
	totalcoins = (vegprice * kgveg) + (fruitprice * kgfr); 
	float totalrps = totalcoins/1.94;
	cout << "Total earnings in Rupees (Rps): " << totalrps << endl;
}
9)
#include<iostream>
using namespace std;
 main() {
	int numb;
	cout << "Enter a 4-digit number: ";
	cin >> numb;
	int n1 = numb%10;
	int n2 = (numb/10)%10;
	int n3 = (numb/100)%10;
	int n4 = (numb/1000)%10;
	
	int modulus;
	modulus = n1+n2+n3+n4;
	cout <<"Sum of the individual digits: " << modulus << endl;
}
10)
#include<iostream>
using namespace std;
 main() {
	int num1;
	cout << "Number 1: ";
	cin >> num1;
	int num2;
	cout << "Number 2: ";
	cin >> num2;
	int num3;
	cout << "Number 3: ";
	cin >> num3;
	int num4;
	cout << "Number 4: ";
	cin >> num4;
	int num5;
	cout << "Number 5: ";
	cin >> num5;
	int num6;
	cout << "Number 6: ";
	cin >> num6;
	int num7;
	cout << "Number 7: ";
	cin >> num7;
	int num8;
	cout << "Number 8: ";
	cin >> num8;
	int num9;
	cout << "Number 9: ";
	cin >> num9;
	int num10;
	cout << "Number 10: ";
	cin >> num10;
	int num11;
	cout << "Number 11: ";
	cin >> num11;
	int num12;
	cout << "Number 12: ";
	cin >> num12;
	int num13;
	cout << "Number 13: ";
	cin >> num13;
	int num14;
	cout << "Number 14: ";
	cin >> num14;
	int num15;
	cout << "Number 15: ";
	cin >> num15;
	int add5 = num1+num2+num3+num4+num5;
	int mul5 = num6*num7*num8*num9*num10;
	int sub5 = num11-num12-num13-num14-num15;
	int n1 = add5+mul5;
	int final = n1-sub5;
	cout << "The final result is: " << final << endl;
}
11)
#include<iostream>
using namespace std;
 main() {
	int age;
	cout << "Enter the person's age: ";
	cin >> age;
	int times;
	cout << "Enter the number of times they've moved: ";
	cin >> times;
	int avg;
	avg = age/(times+1);
	cout << "Average number of years lived in the same house: " << avg << endl;
}
12)
#include<iostream>
using namespace std;
 main() {
	int paintmeters;
	int widmeters;
	int himeters;
	int no;
	cout <<"Number of square meters you can paint: ";
	cin >> paintmeters;
	cout << "Width of the single wall (in meters): ";
	cin >> widmeters;
	cout << "Height of the single wall (in meters): ";
	cin >> himeters;
	no = paintmeters/(widmeters*himeters);
	cout << "Number of walls you can paint: " << no << endl;
}
13)
#include <iostream>
using namespace std;

main(){
int num,num2;
num2=0;
cout<<"Enter a number: ";
cin>>num;
num2=num2+num;
cout<<"Enter a number: ";
cin>>num;
num2=num2+num;
cout<<"Enter a number: ";
cin>>num;
num2=num2+num;
cout<<"Enter a number: ";
cin>>num;
num2=num2+num;
cout<<"Enter a number: ";
cin>>num;
num2=num2+num;
cout<<num2;
}



	PD-4
	
#include<iostream>
using namespace std;

void eq(int numb1, int numb2);

main () 
{
	int numb1, numb2;
	eq(numb1, numb2);

}

void eq(int numb1, int numb2)
{
	cout<<"Enter the first number: ";
	cin >> numb1;
	cout<<"Enter the second number: ";
	cin >> numb2;
	if ( numb1 == numb2 )
	{ 
	cout<<"true"<< endl;
}
	else 
	{
	cout<<"false"<<endl;
	}


}
#include<iostream>
using namespace std;

void truefalse(string value);

main () 
{

	string value;
	truefalse(value);

}
void truefalse(string value)
{
	cout << "Enter 'true' or 'false': ";
	cin >> value;
	if ( value == "true" )
	{
	cout<<"false"<<endl;
	}
	if ( value == "false" )
	{
	cout <<"true"<< endl;
	}
} 
#include<iostream>
using namespace std;

void ticketprice(string name, float finalprice, float tickprice);

main () 
{
	float tickprice;
	float finalprice;
	string name;
	ticketprice(name, finalprice, tickprice);

}
void ticketprice(string name, float finalprice, float tickprice)
{
	cout<<"Enter the country's name: ";
	cin >> name;
	cout<<"Enter the ticket price in dollars: $";
	cin >> tickprice;
	if (name == "Pakistan")
	{
	finalprice = tickprice-tickprice*0.05;
	cout << "Final ticket price after discount: $"<< finalprice << endl;
	}
	if (name == "Ireland")
	{
	finalprice = tickprice-tickprice*0.10;
	cout << "Final ticket price after discount: $"<< finalprice << endl;
	}
	if (name == "India")
	{
	finalprice = tickprice-tickprice*0.20;
	cout << "Final ticket price after discount: $"<< finalprice << endl;
	}
	if (name == "England")
	{
	finalprice = tickprice-tickprice*0.30;
	cout << "Final ticket price after discount: $"<< finalprice << endl;
	}
	if (name == "Canada")
	{
	finalprice = tickprice-tickprice*0.45;
	cout << "Final ticket price after discount: $"<< finalprice << endl;
	}
}
#include<iostream>
using namespace std;

void speedcheck(float speed); 

main () 
{
	float speed;
	speedcheck(speed);

}
void speedcheck(float speed)
{
	cout<<"Speed: ";
	cin >> speed;
	if ( speed <= 100 )
	{
	cout <<"Perfect! You're going good."<< endl;
	}
	if ( speed > 100 )
	{
	cout <<"Halt... YOU WILL BE CHALLENGED!!!"<< endl;
	}
}
#include <iostream>

using namespace std;
void possibleBonus(int a, int b);
main()
{
int a,b;
cout<<"Enter your position: ";
cin>>a;
cout<<"Enter your friend's position: ";
cin>>b;
possibleBonus (a,b);
}

void possibleBonus(int a, int b)
{
	if (a+6>=b)
	{
	cout<<"true";
	}
	if (a+6<b)

	{
	cout<<"false";

	}

}
#include<iostream>
using namespace std;

void time(float h, float m, float hsec, float msec);

main () 
{
	float h, m, hsec, msec;
	cout <<"Enter the number of hours: ";
	cin>> h;
	cout<<"Enter the number of minutes: ";
	cin>> m;
	time(h, m, hsec, msec );


}
void time(float h, float m, float hsec, float msec)
{
	hsec = h*60*60;
	msec = m*60;
	if ( hsec > msec )
	{
	cout<< h <<endl;
	}
	if ( msec > hsec )
	{
	cout << m << endl;
	}
}
	
#include<iostream>
using namespace std;

void flowershop(int redrose, int whiterose, int tulips);

main () 
{
	int redrose, whiterose, tulips;
	cout<<"Red Rose: ";
	cin>> redrose;
	cout<<"White Rose: ";
	cin>> whiterose;
	cout<<"Tulips: ";
	cin>> tulips;
	flowershop(redrose, whiterose, tulips);  


}
void flowershop(int redrose, int whiterose, int tulips)
{
	float redprice = 2.00;
	float whiteprice = 4.10;
	float tuliprice = 2.50;
	float totalprice = (redrose*redprice) + (whiterose*whiteprice) + (tulips*tuliprice);
	if ( totalprice > 200 )
	{
	cout << "Original Price: $" << totalprice << endl;
	cout << "Price after Discount: $" << (totalprice-totalprice*0.20) << endl;
	}
	else
	{
	cout << "Original Price: $" << totalprice << endl;
	cout<<"No discount applied." << endl;
	}
}
#include <iostream>
using namespace std;
void pet(int holidays);
main(){
    int holidays;
    cout<<"Holidays: ";
    cin>>holidays;
    pet(holidays);

}

void pet(int holidays)
{
    int workDays,gameTime,difference,diffinMinutes,diffinHours;
   

    workDays=365-holidays;
    gameTime=workDays*63+holidays*127;
    difference=30000-gameTime;
  


    if(gameTime<30000){
        diffinHours=difference/60;
        diffinMinutes=difference%60;
        cout<<"Tom sleeps well"<<endl;
        cout<<diffinHours<<" hours and "<<diffinMinutes<<" minutes less for play"<<endl;
    }
        
    if (gameTime>30000){
        diffinHours=-difference/60;
        diffinMinutes=-difference%60;
        cout<<"Tom will run away"<<endl;
        cout<< diffinHours<<" hours and " <<diffinMinutes<<" minutes for play"<<endl;
    }
}
#include <iostream>
using namespace std;

string tpChecker(int nOFpeople, int tp);

int main() {
    int nOFpeople, tp;
    cout << "Number of people in the household: ";
    cin >> nOFpeople;
    cout << "Number of rolls of TP: ";
    cin >> tp;

    tpChecker(nOFpeople, tp);
}

string tpChecker(int nOFpeople, int tp) {
    int sheetsPerRoll = 500;
    int sheetsPerDay = 57;
    int days = (tp * sheetsPerRoll) / (nOFpeople * sheetsPerDay);

        if (days < 14) 
	{
        cout<< "Your TP will only last " << days << " days, buy more!";
        }
	else
	{
        cout<< "Your TP will last " << days <<" days, no need to panic!";
        }
}

	PD-5
#include<iostream>
using namespace std;
int value1 = 10;
int value2 = 20;
int sum(){
    value1 = 40;
    return value1 + value2;

}
main(){
    int x = value1;
    value1 = 100;
    x = 20;
    value2 = sum();
    cout<<value1<<" "<<value2;

}
#include<iostream>
using namespace std;

main()
{
    float length, volume, height, width;
    string unt;
    cout<<"Enter the length of the pyramid (in meters): ";
    cin>>length;
    cout<<"Enter the width of the pyramid (in meters): ";
    cin>>width;
    cout<<"Enter the height of the pyramid (in meters):";
    cin>>height;
    cout<<"Enter the desired output unit (millimeters, centimeters, meters, kilometers): ";
    cin>>unt;
    volume = (length*width*height)/3.0;
    if (unt == "meters") 
   {
    cout<<"The volume of the pyramid is: " << volume << ".000000 cubic meters";
   }
   if (unt == "millimeters")
   {
    cout<<"The volume of the pyramid is: " << volume*1000000000 << ".000000 cubic millimeters";
   } 
   if (unt == "centimeters")
   {
    cout<<"The volume of the pyramid is: " << volume*1000000 << ".000000 cubic millimeters";
   } 
   if (unt == "kilometers")
   {
    cout<<"The volume of the pyramid is: " << volume/1000000000 << ".000000 cubic millimeters";
   } 
   
    
}
 #include<iostream>
 using namespace std;

void taxCalculator(char type, float price);

main()
{
    float price, taxrate;
    char type;
    cout<<"Enter the vehicle type code (M, E, S, V, T): ";
    cin>>type; 
    cout<<"Enter the price of the vehicle: $";
    cin>>price;
    taxCalculator(type, price);
    


}
void taxCalculator(char type, float price)
{
    float taxamount, finalprice;
    finalprice=price+taxamount; 
    

    if (type == 'E' )
    {
        taxamount=(price*8.0)/100;
        finalprice=price+taxamount;
        cout <<"The final price of a vehicle of type E after adding tax is "<< finalprice<<".";
    }
    if (type == 'S')
    {
        taxamount=(price*10.0)/100;
        finalprice=price+taxamount;
        cout<<"The final price of a vehicle of type E after adding tax is $"<< finalprice<<".";
    }
    if (type == 'M')
    {
        taxamount=(price*6.0)/100;
        finalprice=price+taxamount;
        cout<<"The final price of a vehicle of type E after adding tax is "<< finalprice<<".";
    }
    if (type == 'V')
    {
        taxamount=(price*12.0)/100;
        finalprice=price+taxamount;
        cout<<"The final price of a vehicle of type E after adding tax is "<< finalprice<<".";
    }
    if (type == 'T')
    {
        taxamount=(price*15.0)/100;
        finalprice=price+taxamount;
        cout<<"The final price of a vehicle of type E after adding tax is "<< finalprice<<".";
    }
}

#include<iostream>
using namespace std;
string projectTimeCalculation(int hours, int  days, int workers);
main()
{
    int hours, days, workers;
    cout<<"Enter the needed hours: ";
    cin>>hours;
    cout<<"Enter the days that the film has: ";
    cin>>days;
    cout<<"Enter the number of all workers: ";
    cin>>workers;
    projectTimeCalculation(hours, days, workers);

}
string projectTimeCalculation(int hours, int days, int workers)
{
    
    float traindays=days*0.10;
    float remainingdays=days-traindays;
    float workhours=remainingdays*10;
    int finalhours=(workers*workhours);

    if (finalhours > hours)
    {
        cout<<"Yes!"<<finalhours-hours<<" hours left."<<endl;
    }
    if (finalhours < hours)
    {
        cout<<"Not enough time! "<<hours-finalhours<<" hours needed."<<endl;
    }
}
#include<iostream>
#include<windows.h>
using namespace std;
void printbox();
void gotoxy(int x, int y);
void moveT(int x, int y);
void moveD(int x, int y);


main()
{
    int x = 8, y = 4; 
    system("color 09");
    system("cls");
    printbox();
    while (true)
    {
        moveT(x, y);
        x = x + 1;
	if( x== 45)
	{
	x = 8;
	}
    }
}
void printbox()
{
    cout<<"     _____________________________________________                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |                                           |                               "<<endl;
    cout<<"     |___________________________________________|                               "<<endl;
    cout<<"                                                                               "<<endl;

        
}
void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void moveT(int x, int y)
{
    gotoxy(x, y);
    cout<<"T";
    Sleep(200);
    gotoxy(x, y);
    cout<< "  ";
}
void moveD(int x, int y)
{
    gotoxy(x, y);
    cout<<"D";
    Sleep(200);
    gotoxy(x, y);
    cout<< "  ";
}
	PD-6
#include<iostream>
using namespace std;

string decideActivity(string temp, string humd){
    if (temp=="warm"&&humd=="dry"){
        return "Play tennis";
    }
    else if(temp=="warm"&&humd=="humid"){
        return "Swim";
    }
    else if(temp=="cold"&&humd=="dry"){
        return "Play basketball";
    }
    else if(temp=="cold"&&humd=="humid"){
        return "Watch TV";
    }
}
main(){
    string temp, humd;
    cout<<"Enter temperature (warm or cold): ";
    cin>>temp;
    cout<<"Enter humidity (dry or humid): ";
    cin>>humd;
    string decision = decideActivity(temp, humd);
    cout<<"Recommended activity: "<<decision;
}

Task2:
#include<iostream>
#include<windows.h>
using namespace std;
float calculateGrade(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology);
string calculateAverage(float percentage);
main()
{
    string name;
    float marksEnglish, marksMaths, marksSocialScience, marksChemistry, marksBiology, average;
    cout<<"Enter student name: ";
    cin>>name;
    cout<<"Enter marks for English: ";
    cin>>marksEnglish;
    cout<<"Enter marks for Maths: ";
    cin>>marksMaths;
    cout<<"Enter marks for Chemistry: ";
    cin>>marksChemistry;
    cout<<"Enter marks for Social Science: ";
    cin>>marksSocialScience;
    cout<<"Enter marks for Biology: ";
    cin>>marksBiology;
    cout<<"Student Name: "<<name<<endl;
    float percentage = calculateGrade(marksEnglish, marksMaths, marksChemistry, marksSocialScience, marksBiology);
    cout<<"Percentage: "<<percentage<<"%"<<endl;
    cout<<"Grade: "<<calculateAverage(percentage)<<endl;
}
float calculateGrade(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology)
{
    float percentage = ((marksMaths + marksChemistry + marksEnglish + marksMaths + marksSocialScience)*100)/500;
    return percentage;
}
string calculateAverage(float percentage){
     if(percentage>=90){
        return "A+";
    }
    else if(percentage>=90){
        return "A";
    }
    else if (percentage>=80){
        return "B+";
    }
    else if (percentage>=70){
        return "B";
    }
    else if(percentage>=60){ 
        return "C";
    }
    else if(percentage>=50){
        return "D";
    }
    else if (percentage<40){
        return "F";
    }   
}

Task3:
#include<iostream>
using namespace std;
string findZodiacSign(int day, string month);

main()
{
    int day;
    string month;
    cout<<"Enter the day of birth: ";
    cin>>day;
    cout<<"Enter the month of birth(e.g., January, February): ";
    cin>>month;
    cout<<"Zodiac Sign: "<<findZodiacSign(day,month);
}
string findZodiacSign(int day, string month){
    if((21<=day<=31&&month=="March")||((1<=day<=19)&&(month=="April"))){
        return "Aries";
    }
    else if ((20<=day<=31&&month=="April")||((1<=day<=20)&&(month=="May"))){
        return "Taurus";
    }
    else if ((21<=day<=31&&month=="May")||((1<=day<=20)&&(month=="June"))){
        return "Gemini";
    }
    else if ((21<=day<=31&&month=="June")||((1<=day<=22)&&(month=="July"))){
        return "Cancer";
    }
    else if ((23<=day<=31&&month=="July")||((1<=day<=22)&&(month=="August"))){
        return "Leo";
    }
    else if((23<=day<=31&&month=="August")||((1<=day<=22)&&(month=="September"))){
        return "Virgo";
    }
    else if((23<=day<=31&&month=="September")||((1<=day<=22)&&(month=="October"))){
        return "Libra";
    }
    else if ((23<=day<=31&&month=="October")||((1<=day<=21)&&(month=="November"))){
        return "Scorpio";
    }
    else if((22<=day<=31&&month=="November")||((1<=day<=21)&&(month=="December"))){
        return "Sagittarius";
    }
    else if ((22<=day<=31&&month=="December")||((1<=day<=19)&&(month=="January"))){
        return "Capricorn";
    }
    else if ((20<=day<=31&&month=="January")||((1<=day<=18)&&(month=="February"))){
        return "Aquarius";
    }
    else if((19<=day<=31&&month=="February")||((1<=day<=20)&&(month=="March"))){
        return "Pisces";
    }
    
} 

Task4:
#include<iostream>
using namespace std;

float calculate_amount(char service_code, char time_call,float num_mins, string service );
main(){
    char service_code, time_call;
    float num_mins;
    string service;
    cout<<"Enter the service code(R/r for regular, P/p for premium): ";
    cin>>service_code;
    if (service_code=='p'||service_code=='P'){
        cout<<"Enter the time of the call (D/d for day, N/n for night): ";
        cin>>time_call;
    }
    cout<<"Enter the number of minutes used: ";
    cin>>num_mins;
    if(service_code=='r'||service_code=='R'){
        cout<<"Service Type: Regular"<<endl;
    }
    else if(service_code=='p'||service_code=='P'){
        cout<<"Service Type: Premium"<<endl;
    }
    cout<<"Total Minutes Used: "<<num_mins<<" minutes"<<endl;
    float amount = calculate_amount(service_code,time_call, num_mins, service);
    cout<<"Amount Due: $"<<amount;
} 
float calculate_amount(char service_code, char time_call,float num_mins, string service ){
    if ((service_code=='P'||service_code=='p')&&(time_call=='n'||time_call=='N')&&(num_mins<=100)){
        return 25;
     }
    if ((service_code=='P'||service_code=='p')&&(time_call=='d'||time_call=='D')&&(num_mins>100)){
        return (num_mins*0.2)+25;
    }  
    
    else if (service_code=='R'||service_code=='r'){
        return (num_mins*0.2);
    }
}

Task5:
#include<iostream>
using namespace std;
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity);

main()
{
    string fruit, dayOfWeek;
    double quantity;
    cout<<"Enter the fruit name: ";
    cin>>fruit;
    cout<<"Enter the day of the week (e.g, Monday, Sunday): ";
    cin>>dayOfWeek;
    cout<<"Enter the quantity: ";
    cin>>quantity;
    float amount = calculateFruitPrice(fruit, dayOfWeek, quantity);
    cout<<amount<<endl;
    
}
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity)
{
    if (dayOfWeek=="Sunday"||dayOfWeek=="Saturday"){
        float banana = 2.70;
        float apple = 1.25;
        float orange = 0.90;
        float grapefruit = 1.60;
        float kiwi = 3.00;
        float pinapple = 5.60;
        float grapes = 4.20;
        if (fruit=="Banana"){
            return banana*quantity;
        }
        if (fruit=="Apple"){
            return apple*quantity;
        }
        if(fruit=="Orange"){
            return orange*quantity;
        }
        if(fruit=="Grapes"){
            return grapes*quantity;
        }
        if(fruit=="Kiwi"){
            return kiwi*quantity;
        }
        if(fruit=="Pineapple"){
            return pinapple*quantity;
        }
         if(fruit=="Grapefruit"){
            return grapefruit*quantity;
        }


    }
    else if (dayOfWeek=="Monday"||dayOfWeek=="Tuesday"||dayOfWeek=="Wednesday"||dayOfWeek=="Thursday"||dayOfWeek=="Friday"){
        float banana = 2.50;
        float apple = 1.20;
        float orange = 0.85;
        float grapefruit = 1.45;
        float kiwi = 2.70;
        float pinapple = 5.50;
        float grapes = 3.85;
         if (fruit=="Banana"){
            return banana*quantity;
        }
        if (fruit=="Apple"){
            return apple*quantity;
        }
        if(fruit=="Orange"){
            return orange*quantity;
        }
        if(fruit=="Grapes"){
            return grapes*quantity;
        }
        if(fruit=="Kiwi"){
            return kiwi*quantity;
        }
        if(fruit=="Pineapple"){
            return pinapple*quantity;
        }
         if(fruit=="Grapefruit"){
            return grapefruit*quantity;
        }
    }
}

Task6:
#include<iostream>
using namespace std;
string calculateHotelPrices(string month, int numberOfStays);
string apartment(int numberOfStays, string month);
main()
{
    string month;
    int numberOfStays;
    cout<<"Enter the month (May, June, July, August, September, October): ";
    cin>>month;
    cout<<"Enter the number of stays: ";
    cin>>numberOfStays;
    string aprtprice = apartment(numberOfStays, month);
    cout<<aprtprice<<endl;
    string studio = calculateHotelPrices(month,numberOfStays);
    cout<<studio;
    
}
string calculateHotelPrices(string month, int numberOfStays)
{
    if ((7<numberOfStays<=14)&&((month=="May")||(month=="October"))){
        float studio = (50*numberOfStays)-(50*numberOfStays)/5;
        return "Studio: "+ to_string(studio)+"$.";
    }
    if ((numberOfStays>14)&&((month=="May")||(month=="October"))){
        float studio = (50*numberOfStays)-(50*numberOfStays)/30;
        return "Studio: "+ to_string(studio)+"$.";
    }
    if ((numberOfStays>14)&&((month=="June")||(month=="September"))){
        float studio = (75.20*numberOfStays)-(75.20*numberOfStays)/20;
        return "Studio: "+ to_string(studio)+"$.";
    }
    if ((numberOfStays<=14)&&((month=="June")||(month=="September"))){
        float studio = (75.20*numberOfStays);
        return "Studio: "+ to_string(studio)+"$.";
    }
    if(month=="July"||month=="August"){
        float studio = (76*numberOfStays);
        return "Studio: "+ to_string(studio)+"$.";
    }
}

string apartment(int numberOfStays, string month){
    if(numberOfStays>14&&((month=="May")||(month=="October"))){
        float apartment = (65.0*numberOfStays)-(65.0*numberOfStays)/10;
        return "Apartment: "+to_string(apartment)+"$.";
    }
    if(numberOfStays>14&&((month=="June")||(month=="September"))){
        float apartment = (68.7*numberOfStays)-(68.7*numberOfStays)/10;
        return "Apartment: "+to_string(apartment)+"$.";
    }
        if(numberOfStays<=14&&((month=="June")||(month=="September"))){
        float apartment = (68.7*numberOfStays);
        return "Apartment: "+to_string(apartment)+"$.";
    }
    if(numberOfStays>14&&((month=="July")||(month=="August"))){
        float apartment = (77.0*numberOfStays)-(77.0*numberOfStays)/10;
        return "Apartment: "+to_string(apartment)+"$.";
    }


else if (numberOfStays<=14)
{
        float apartment = (65*numberOfStays)-(65*numberOfStays);
        return "Apartment: "+ to_string(apartment) +"$.";
}

}

Task7:

#include<iostream>
using namespace std;
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute);
main()
{
    int examHour,examMinute, studentHour, studentMinute;
    cout<<"Enter Exam Starting Time (hour): ";
    cin>>examHour;
    cout<<"Enter Exam Starting Time (minutes): ";
    cin>>examMinute;
    cout<<"Enter Student hour of arrival: ";
    cin>>studentHour;
    cout<<"Enter Student minutes of arrival: ";
    cin>>studentMinute;
    string result = checkStudentStatus(examHour,examMinute,studentHour,studentMinute);
    cout<<result;
}
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute)
{
    int examtime = (examHour*60) + examMinute;
    int st_time = (studentHour*60) + studentMinute;
    if (examtime==st_time){
        return "On time";
    }
    if (examtime>st_time){
        int remaining_time = examtime-st_time;
        int remaining_hours = remaining_time/60;
        if (remaining_time>=60){
            int rem_mins = remaining_time%60;
            return "Early\n""Test: "+to_string(remaining_time)+"\n"+to_string(remaining_hours)+":"+to_string(rem_mins)+" hours before the start";
        }
        else if (remaining_time<60){
            return "Early\n""Test: "+to_string(remaining_time)+"\n"+to_string(remaining_time)+" minutes before the start";
        }
    }
    if (examtime<st_time){
        int remaining_time = st_time-examtime;
        int remaining_hours = remaining_time/60;
        if (remaining_time>=60){
            int rem_mins = remaining_time%60;
            return "Late\n""Test: "+to_string(remaining_time)+"\n"+to_string(remaining_hours)+":"+to_string(rem_mins)+" hours after the start";
        }
        else if (remaining_time<60){
            return "Late\n""Test: "+to_string(remaining_time)+"\n"+to_string(remaining_time)+" minutes after the start";
        }
    }

}

Task8:

#include<iostream>
using namespace std;
int calculateVolleyballGames(string yearType, int holidays, int hometownWeekends);
main(){
    string yearType;
    int holidays, hometownWeekends;
    cout<<"Enter year type: ";
    cin>>yearType;
    cout<<"Enter number of holidays: ";
    cin>>holidays;
    cout<<"Enter number of weekends: ";
    cin>>hometownWeekends;
    int result = calculateVolleyballGames(yearType,holidays,hometownWeekends);
    cout<<result;
}
int calculateVolleyballGames(string yearType, int holidays, int hometownWeekends)
{

    float num_1= (hometownWeekends) - (hometownWeekends-1)*(3/4);
    float num_2 = holidays-(holidays*(2/3));
    int final_playtime = (num_1+num_2);
    if (yearType=="leap"){
        return final_playtime*0.15;
    }
    else {
        return final_playtime;
    }
}
Task9:
#include<iostream>
using namespace std;
string checkPointPosition(int h, int x, int y);
main(){
    int h,x,y;
    cout<<"Enter height: ";
    cin>>h;
    cout<<"Enter x coordinates: ";
    cin>>x;
    cout<<"Enter y coordinates: ";
    cin>>y;
    string result = checkPointPosition(h,x,y);
    cout<<result;
}
string checkPointPosition(int h, int x, int y)
{
        if ((x < 3*h)&&(y < h))
    {
        return "Inside";
    }
    else if (((x >h)&&(x < 2*h))&&((y < 4*h)))
    {
        return "Inside";
    }
    else if (((x > 0)||(x < h))&&(y > h))
    {
        return "Outside";
    }
     else if (((x > 2*h)||(x < 3*h)&&(y > h)))
    {
        return "Outside";
    }
    else if ((x > h)||(x < 2*h)&&(y > 4*h))
    {
        return "Outside";
    }
    else if ((x < 0)&&((y > 0)||(y < 0)))
    {
        return "Outside";
    }
    else if (((x < 0)||(x > 0))&&(y < 0))
    {
        return "Outside";
    }
    else if ((x > 3*h)&&(y == 0))
    {
        return "Outside";
    }
    else if ((x == 0)&&(y == 0))
    {
        return "Border";
    }
    else if ((x == 0)&&(y == h))
    {
        return "Border";
    }
     else if ((x == 3*h)&&(y == h))
    {
        return "Border";
    }
    else if ((x == h)&&(y == h))
    {
        return "Border";
    }
    else if ((x == 2*h)&&(y == h))
    {
        return "Border";
    }
    else if ((x == 3*h)&&(y == 0))
    {
        return "Border";
    }
    else if ((x == 2*h)&&(y == 0))
    {
        return "Border";
    }
     else if ((x == 2*h)&&(y == 2*h))
    {
        return "Border";
    }
    else if ((x == h)&&(y == 0))
    {
        return "Border";
    }
    else if ((x == h)&&(y == 2*h))
    {
        return "Border";
    }
    else if ((x == h)&&(y == 3*h))
    {
        return "Border";
    }
    else if ((x == h)&&(y == 4*h))
    {
        return "Border";
    }
    else if ((x == 2*h)&&(y == 3*h))
    {
        return "Border";
    }
    else if ((x == 2*h)&&(y == 4*h))
    {
        return "Border";
    }   
}

	PD-7
#include<iostream>
using namespace std;
void printstars(int numrows);
main()
{
    int numrows;
    cout<<"Enter desired number of rows: ";
    cin>>numrows;
    printstars(numrows);


}
void printstars(int numrows){
    for(int row=numrows;row>0;row--){
        for (int col=1;col<=row;col++){
        cout<<"*";
    }
    cout<<endl;
    }
}
#include<iostream>
using namespace std;
void printstars(int numrows);
main()
{
    int numrows;
    cout<<"Enter desired number of rows: ";
    cin>>numrows;
    printstars(numrows);


}
void printstars(int numrows){
    for (int row=1;row>=numrows;row++){
        for(int col=1;col<=row;col++){
                cout<<"*";
        }
    cout<<endl;    
    }
    }

#include <iostream>
using namespace std;
void printup(int numRows);
void printdown(int numRows);
int main()
{
    int numRows;
    cout << "Enter desired number of rows: ";
    cin >> numRows;
    printup(numRows);
    printdown(numRows);
}
void printup(int numRows)
{

    for (int i = 1; i <= numRows/2; i++)
    {
        for (int j = 1; j <= (numRows/2) - i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void printdown(int numRows)
{
    for(int i = numRows / 2; i >= 1; i--)
    {
        for(int j = 1; j <= (numRows / 2) - i; j++)
        {
            cout<<" ";
        }
        for(int k = 1; k <= i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
#include<iostream>
using namespace std;
void amplify(int number);
main(){
    int number;
    cout<<"Enter the number to Amplify: ";
    cin>>number;
     amplify(number);
}
void amplify(int number)
{
    for(int i=1;i<=number;i++){
            int x=i;
            
            if (i%4==0){
                x=i*10;
            }
          cout<<x<<", ";
    }
}

#include<iostream>
using namespace std;
void dots(int numtriangle);
main(){
    int numtriangle;
    cout<<"Enter number of Triangle: ";
    cin>>numtriangle;
    dots(numtriangle);
}
void dots(int numtriangle)
{
    int dot=0;
    for(int i=1;i<=numtriangle;i++){
        dot=dot+i;
    }
     cout<<dot;   

}

#include<iostream>
using namespace std;
bool prime(int num){
    int count=0;
    for(int x=2;x<=num;x++){
        if (num%x==0){
            count=count+1;
        }
    }
        if (count==1){
            return 1;
        }
        if (count!=1){
            return 0;
        }

}
main(){
    int num;
    cout<<"Enter Number: ";
    cin>> num;
    int result = prime(num);
    cout<<result;
}

#include<iostream>
using namespace std;
int primorial(int num);
main()
{
    int num;
    cout<<"Enter Number: ";
    cin>>num;
    int result = primorial(num);
    cout<<result;
}
int primorial(int num)
{
    int primeNumbers=0, NumberCount=0, primorial=1;
    while(NumberCount<=num){
        if((primeNumbers==2||primeNumbers==3)||(primeNumbers%2!=0||primeNumbers%3!=0)){
            NumberCount=NumberCount+1;
            primorial=primorial*primeNumbers;
        }
        primeNumbers++;
    }
    return primorial;
    } 
    
#include <iostream>
using namespace std;

int main(){
    int numOfdays;  
    cout << "Enter number of days you visited hospital: ";
    cin >> numOfdays;
    int treated = 0;
    int untreated=0;
    for (int x=1; x<= numOfdays; x++)
    {
        int patients;
        cout << "Enter the number of patients for day "<<x<<": ";
        cin >> patients;
        int docs=7;
        if (patients <= docs)
        {
            treated = treated+patients;
        }
        else
        {
            treated = treated+docs;
            untreated = untreated+patients-docs;
        }
        if (x%3 == 0&&untreated>treated)
        {
            docs++;
        }
    }
    cout<<"Treated patients: "<<treated<<"."<< endl;
    cout<<"Untreated patients: "<<untreated<<"."<< endl;
}



#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float countOfCargo;
    cout << "Enter the count of cargo for transportation: ";
    cin >> countOfCargo;
    float cargoForDay = 0, amountForBus = 0;
    float amountForTruck = 0, amountForTrain = 0, totalAmountBus = 0;
    float totalAmountTruck = 0, totalAmountTrain = 0, sumOfCargo = 0, totalCargoByBus = 0, totalCargoByTruck = 0,;
    float train_total_Cargo = 0;
    for (float cargoNumber = 1; cargoNumber <= countOfCargo; cargoNumber++)
    {
        cout << "Enter the tonnage for cargo " << cargoNumber << ": ";
        cin >> cargoForDay;
        sumOfCargo = sumOfCargo + cargoForDay;
        if (cargoForDay > 11)
        {
            train_total_Cargo = train_total_Cargo + cargoForDay;
            amountForTrain = cargoForDay*120;
            totalAmountTrain = totalAmountTrain + amountForTrain;
        }
        if (cargoForDay>3&&cargoForDay<= 11)
        {
            totalCargoByTruck = totalCargoByTruck+cargoForDay;
            amountForTruck = cargoForDay*175;
            totalAmountTruck = totalAmountTruck+amountForTruck;
        }
        if (cargoForDay<=3)
        {
            totalCargoByBus = totalCargoByBus+cargoForDay;
            amountForBus = cargoForDay * 200;
            totalAmountBus = totalAmountBus + amountForBus;
        }
        
        
    }
    float totalCargoByMiniBusPercent = (totalCargoByBus / sumOfCargo) * 100;
    float totalCargoByTruckPercent = (totalCargoByTruck / sumOfCargo) * 100;
    float train_total_CargoPercent = (train_total_Cargo / sumOfCargo) * 100;
    float totalAmount = totalAmountBus+totalAmountTruck+totalAmountTrain;
    float average = totalAmount/sumOfCargo;
    cout << fixed;
    cout << setprecision(2);
    cout <<average<<endl<<totalCargoByMiniBusPercent<<endl<<totalCargoByTruckPercent<<endl<<train_total_CargoPercent;
}

#include<iostream>
using namespace std;

bool isLengthEven(string);
main(){
    string word;
    cout << "Enter a String: ";
    cin  >> word;
    cout << isLengthEven(word);
}

bool isLengthEven(string word){
    int indx = 0;
    while(word[indx] != '\0'){
        indx++;
    }
    return (indx%2==0);
}

#include<iostream>
using namespace std;

string containsSeven(int[], int);
main(){
    int size;
    cout << "Enter the size of Array: ";
    cin  >> size;
    int numbers[size];
    for(int idx= 1;idx<=size;idx++){
        cout << "Enter Element " << idx << ": ";
        cin  >> numbers[idx-1];
    }
    cout << containsSeven(numbers,size);
}
string containsSeven(int numbers[],int size){
    for(int i=0;i<size;i++){
        if((numbers[i]==7) || (numbers[i]%10==7)||(numbers[i]/10==7)){
            return "Boom!";
        }
    }
    return "there is no 7 in the array";
}

#include<iostream>
using namespace std;

bool areAllElementsIdentical(string[], int);
main(){
    int size;
    cout << "Enter the size of Array: ";
    cin  >> size;
    string elements[size];
    for(int idx= 1;idx<=size;idx++){
        cout << "Enter Element " << idx << ": ";
        cin  >> elements[idx-1];
    }
    cout << areAllElementsIdentical(elements,size);
}
bool areAllElementsIdentical(string elements[], int size){
    string element = elements[0];
    for(int i=1;i<size;i++){
        if(element != elements[i])
            return false;
    }
    return true;
}

#include<iostream>
using namespace std;

void evenOddTransform(int[], int, int);
main(){
    int size,num;
    cout << "Enter the size of Array: ";
    cin  >> size;
    int elements[size];
    for(int idx= 1;idx<=size;idx++){
        cout << "Enter Element " << idx << ": ";
        cin  >> elements[idx-1];
    }
    cout << "Enter number of times even-odd transformation need to be done: ";
    cin  >> num;
    evenOddTransform(elements,size,num);
}

	PD-10
#include<iostream>
using namespace std;

int totaldays(int arrSat[], int num_Sat){
    int count=0,n=0;
    int day=arrSat[n];

    for(int i=0; i<=num_Sat; i++){
        if (arrSat[i]>day){
            count++;
            n++;
        }
    }
    return count;

}
main()
{
    int num_Sat;
    cout<<"Enter the number of Saturdays: ";
    cin>>num_Sat;
    int arrSat[num_Sat];
    for (int i=1; i<=num_Sat; i++){
        cout<<"Enter miles run for Saturday "<<i<<": ";
        cin>>arrSat[i-1];
    }
    cout<<"Total progress days: "<<totaldays(arrSat,num_Sat);


}

#include<iostream>
using namespace std;
int freq_let(string arrWord[] , char let, int num){
    string current;
    int n=0;
    int count=0;
    while(n<num){
        current = arrWord[n];
        for(int j=0; j<current.length(); j++){
            if(current[j] ==let){
                count++;
            }
        }
        n++;
    }
    return count;
}
main()
{
    int num;
    char let;
    cout<<"Enter how many words you want to enter: ";
    cin>>num;
    string arrWords[num];
    for (int i=1; i<=num; i++){
        cout<<"Enter word "<<i<<": ";
        cin>>arrWords[i-1];
    }
    cout<<"Enter the letter you want to count: ";
    cin>>let;
    cout<<let<<" shows up "<<freq_let(arrWords, let,num)<<" times in the data."<<endl;
    return 0;
}

#include<iostream>
using namespace std;

bool RepeatingCycle(int arrL[], int cycle, int length){
    bool result = false;
    for(int i=0; i<length-cycle; i=i+cycle){
        if(arrL[i]==arrL[i+cycle]){
            result = true;
        }
    }
    return result;
}
main()
{
    int length,cycle;
    cout<<"Enter the length of the array: ";
    cin>>length;
    int arrL[length];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<length; i++){
        cin>>arrL[i];
    }
    cout<<"Enter the length of the cycle: ";
    cin>>cycle;

    if(cycle>length){
         cout<<"Output: "<<true;
    }
    else{
    cout<<"Output: "<<RepeatingCycle(arrL, cycle, length);
    }
}    

#include<iostream>
using namespace std;
float sum(float arrDiminsions[],int numBox){
    float v=0,sum=0;
    for(int i=0; i<numBox*3; i=i+3){
        v=(arrDiminsions[i]*arrDiminsions[i+1])*arrDiminsions[i+2];
        sum=sum+v;
    }
    
    return sum;
}
main()
{
    int numBox;
    cout<<"Enter the number of boxes: ";
    cin>>numBox;
    float arrDiminsions[numBox*3];
    cout<<"Enter the dimensions of the boxes (length, width, height):"<<endl;
    for(int i=0; i<numBox*3;i=i+1){
        cin>>arrDiminsions[i];
    }
    
    cout<<"Total volume of all boxes: "<<sum(arrDiminsions,numBox);
}

#include<iostream>
using namespace std;
void sort(int arr[]){
    cout<<"[";
    int mini;
    int swapper, minIndex;
    for(int i=0; i<10; i++){
        mini = arr[i];
          for(int j=i; j<10; j++){
                if(arr[j]<mini){
                    mini=arr[j];
                    minIndex=j;
                }
          }
    swapper=arr[i];
    arr[i]=arr[minIndex];
    arr[minIndex]=swapper;
    if(i==9){
    cout<<mini;
    }
    else {
    cout<<mini<<", ";
    }
}
    cout<<"]";
}
main()
{
    int arr[10];
    cout<<"Enter the weights of the 10 packages: "<<endl;
    for(int i=0; i<10; i++){
        cin>>arr[i];
    }
    cout<<"Sorted array in ascending order: ";
    sort(arr);
    
}

#include<iostream>
using namespace std;
void reverseString(string inputstring);
main()
{
    string inputstring;
    cout<<"Enter a string: ";
    getline(cin, inputstring);
    cout<<"Reversed string: ";
    reverseString(inputstring);

}
void reverseString(string inputstring)
{
    string arr[20];
    int arr_idx=0;
    string current="";
    for(int i=0; i<inputstring.length();i++){
        if(inputstring[i]!=' '){
            current+=inputstring[i];
        }    
        else{
            arr[arr_idx]=current;
            arr_idx++;
            current="";
        }    
        
        arr[arr_idx]=current;
    }
    for(int i=arr_idx; i>=0; i--){
        cout<<arr[i]<<" ";
    }
}

#include<iostream>
using namespace std;

int smallest(int arr[], int length){
    int min=arr[0];
    for(int i=1;i<length; i++){
        if(arr[i]<min){
            min=arr[i];
        }
        }
        return min;
    }

bool isPresent(int arr[], int length, int num){
    bool result=false;
    for(int i=0; i<length; i++){
        if(num==arr[i]){
            result=true;
        }
    }
    return result;
}    

bool areConsecutive(int arr[], int length){
    int small = smallest(arr, length);
    for(int i = small; i<small+length; i++){
        if(!isPresent(arr, length, i)){
            return false;
        }
    }
    return true;
}
    

main()
{
    int length;
    cout<<"Enter the length of the array: ";
    cin>>length;
    int arr[length];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<length; i++){
        cin>>arr[i];
    }
    cout<<"Can be arranged: "<<areConsecutive(arr, length);
}


void evenOddTransform(int elements[], int size, int num){
    cout << "[";
    for(int i=0;i<size;i++){
        if(elements[i] %2 == 0){
            if( i==0)
                cout << elements[i]- 2*num;
            else
                cout << ", " << elements[i]- 2*num;
        }else{
            if( i==0)
                cout << elements[i]+ 2*num;
            else
                cout << ", " << elements[i] + 2*num;
        }
    }
    cout << "]";
}

#include<iostream>
using namespace std;
int checkSameLetters(string, string);
main(){
    string first,second;
    cout << "Enter the first string: ";
    cin  >> first;
    cout << "Enter the second string: ";
    cin  >> second;
    cout << checkSameLetters(first, second);
}
int checkSameLetters(string first,string second){
    int count=0,n=0;

    int l1=0,l2=0;
    while (first[l1] != '\0'){
        l1++;
    }
    while (second[l2] != '\0'){
        l2++;
    }
    for(int i=0;i<l1;i++){
        for(int j=n;j<l2;j++){
            if(first[i]==second[j]){
                count++;
                n++;
                break;
            }
        }
            
    }
    return count;
}   

#include<iostream>
using namespace std;
int coloringTime(string[], int);
main(){
    int size;
    cout << "Enter the size of Array: ";
    cin  >> size;
    string colors[size];
    for(int idx= 1;idx<=size;idx++){
        cout << "Enter Element " << idx << ": ";
        cin  >> colors[idx-1];
    }
    cout << "Time to color: " << coloringTime(colors,size)<< " seconds";
}
int coloringTime(string cols[], int size){
    int time = size*2; 
    string previous= cols[0];
    for(int i=1;i<size;i++){
        if(cols[i] != previous){
            time++;
            previous = cols[i];
        }
    }
    return time;
}

#include<iostream>
using namespace std;

void convertPINToDance(string);
main(){
    string pin;
    cout << "Enter your PIN (4 digits): ";
    cin  >> pin;
    convertPINToDance(pin);
}

void convertPINToDance(string pin){
    string moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado","Pop", "Lock", "Arabesque"};
    if(pin.length()!= 4){
        cout << "Invalid input.";
        return;
    }
    for(int i=0;i<pin.length();i++){
        if(!isdigit(pin[i])){
            cout << "Invalid input.";
            return;
        }
    }
    string index;
    int crIndex,netIndex;
    for(int i=1;i<=pin.length();i++){
        index = pin[i-1];
        crIndex = stoi(index);
        netIndex = ((crIndex+i)%10)-1;
        if(netIndex<0){
            netIndex += 10;
        }
        if(i==1){
            cout << moves[netIndex];
        }else{
            cout << ", " << moves[netIndex];
        }
    }
}

#include <iostream>
using namespace std;

string findBrokenKeys(string,string);
main()
{
    string correctPhrase,actualTyped;
    cout << "Enter the correct phrase: ";
    cin  >> correctPhrase;
    cout << "Enter what you actually typed: ";
    cin  >> actualTyped;

    cout << "Broken keys: " << findBrokenKeys(correctPhrase, actualTyped);
}

string findBrokenKeys(string correct,string actual){
    bool isBrokenKey;
    bool isALreadyPresent;
    string brokenKeys="";
    for(int i=0;i<correct.length();i++){
        isBrokenKey = true;
        isALreadyPresent = false;
        for(int n=0;n<actual.length();n++){
            if(correct[i] == actual[n]){
                isBrokenKey = false;
                break;
            }
        }
        for(int j=0;j<brokenKeys.length();j++){
            if(brokenKeys[j]== correct[i]){
                isALreadyPresent = true;
            }
        }
        if(isBrokenKey){
            if(!(isALreadyPresent)){
                brokenKeys += correct[i];
            }
        }
    }
    return brokenKeys;
}

#include<iostream>
using namespace std;

bool canDisplay(string);
string longest7SegmantWord(string[],int);
main(){
    int length;
    cout << "Enter the number of words: ";
    cin  >> length;
    string words[length];
    cout << "Enter the words, one by one:\n";
    for(int i=0;i<length;i++){
        cin >> words[i];
    }
    cout << "Longest 7-segment word: " << longest7SegmantWord(words,length);
}

string longest7SegmantWord(string words[],int length){
    string result = "";
    for (int i=0;i<length;i++){
        if(canDisplay(words[i])){
            if(result == ""){
                result = words[i];
            }else{
                if(words[i].length() > result.length()){
                    result = words[i];
                }
            }
        }
    }
    return result;
}

bool canDisplay(string word){
    int idx = 0;
    string negatedLetters = "kmvwx";
    while(negatedLetters[idx] != '\0'){
        for(int i=0;i<word.length();i++){
            if(word[i] == negatedLetters[idx]){
                return false;
            }
        }
        idx++;
    }
    return true;
}

#include<iostream>
using namespace std;
int rotation(string arr[], int length);
main()
{
    int length;
    cout<<"Enter the length of the array: ";
    cin>>length;
    string arr[length];
    cout<<"Enter the elements of the array (\"left\" or \"right\"): "<<endl;
    for(int i=0; i<length; i++){
        cin>>arr[i];
    }
    cout<<"Number of full rotations: "<<rotation(arr, length);
    return 0;
}
int rotation(string arr[], int length)
{
    int cLeft=0, cright=0;
    for(int i=0; i<length; i++)
    {
        if (arr[i]=="right"){
            cright++;
        }
        else if(arr[i]=="left"){
            cLeft++;
        }
    }
    int count = (cLeft/4) + (cright/4);
    return count; 
}

#include<iostream>
using namespace std;

int specialValue(int arr[], int length)
{
    int count = 0;
    for (int i = length; i >= 0; i--)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[j] >= i)
            {
                count++;
            }
            if (count == i)
                return i;
        }
    }
    return -1;
}

main()
{
    int length;
    cout<<"Enter the length of the array: ";
    cin>>length;
    int arr[length];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<length; i++){
        cin>>arr[i];
    }
    cout<<"Special value: "<<specialValue(arr,length);

    return 0;
}







	
	

	
	
	
   	