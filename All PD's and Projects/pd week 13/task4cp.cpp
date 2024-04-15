#include<iostream>
#include<fstream>
using namespace std;
void getStudentDetails(string[], int[], float[], float [], float [], int , int &);
void saveToFile(string[], int[], float[], float[], float[], int, string );
main()
{
    int size=20;
    string name[size], fileName;
    int age[size];
    float matricMarks[size], FscMarks[size], ecatMarks[size];
    int count=0;
    
    getStudentDetails(name, age, matricMarks, FscMarks, ecatMarks, size, count);
    saveToFile(name, age, matricMarks, FscMarks, ecatMarks, count, "Task4.txt");

}
void getStudentDetails(string names[], int ages[], float matricMarks[], float fscMarks[], float ecatMarks[], int size, int &count)
{
    string option;
    while(option != "No"){
        cout << "Enter student's name: ";
        cin >> names[count];
        cout << "Enter student's age: ";
        cin >> ages[count];
        cout << "Enter student's Matric marks: ";
        cin>>matricMarks[count];
        cout << "Enter student's Fsc marks: ";
        cin>>fscMarks[count];
        cout<<"Enter student's Ecat marks: ";
        cin>>ecatMarks[count];
        count++;
        cout<<"Enter No to Stop or Yes to continue Enter: ";
        cin>>option;
    }



}

void saveToFile(string names[], int ages[], float matricMarks[], float fscMarks[], float ecatMarks[], int count, string fileName)
{
    fstream file;
    file.open("studentData.txt", ios::out);
    for (int i = 0; i<count; i++){
        file << "Name: "<< names[i]<<endl;
        file << "Age: "<< ages[i]<<endl;
        file << "Fsc Marks: " << fscMarks[i]<<endl;
        file << "Matric Marks: " << matricMarks[i]<<endl;
        file << "Ecat Marks: "<< ecatMarks[i]<<endl;
        file << endl;
    }
    file.close();
    
}
