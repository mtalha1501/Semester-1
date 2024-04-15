#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

void review_rating(string review[],float ratings[],int &review_index){

    string comment; 
    float User_rating;
    cout << "Enter your Review: ";
    getline(cin,comment);
    cout << "Enter Rating out of 10: ";
    cin >> User_rating;

    if (User_rating > 10){
        cout << "\nRating out of Range... Review not Submitted\n\n";
        cout << "Press any key to go back";
        getch();

    }
    else{
         review[review_index]=comment;
         ratings[review_index]=User_rating;
         review_index++;
         cout << "\nThanks! Your Review has been submitted...\n";
         cout << "Press any key to go back..\n";
         getch();
    }

}

void show_reviews(string review[],float ratings[],int review_index){

    cout << setw(7)<<left<< "No."<<setw(12)<<left<< "Rating" <<setw(12)<<left<< "Review" <<endl;

    for(int i=0; i<review_index; i++){
        cout << setw(7) <<left << i+1 <<" "<<setw(12)<<left<<ratings[i]<<setw(12)<<left<<review[i]<<endl;
    }

}

main()
{
    string review[30];
    float ratings[30];
    int review_index=0;
    
    review_rating(review,ratings,review_index);
    show_reviews(review,ratings,review_index);

}


