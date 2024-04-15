#include<iostream>
#include<fstream>
using namespace std;

int countLines(string fileName){
    fstream file;
    string lines;
    int count = 0, n = 0;
    file.open(fileName, ios::in);
    while (getline(file, lines)) {
        count += lines.length();
    }
    file.close();
    return count;
}

main()
{
    string fileName;
    int count = countLines("Task1.txt");
    cout << "Total number of characters: "<<count;
    return 0;
}