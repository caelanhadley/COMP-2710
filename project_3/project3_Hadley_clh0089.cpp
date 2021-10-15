/*
*   Caelan Hadley (clh0089)   
*   project3_Hadley_clh0089.cpp
*
*   Reference(s):
*   (1)
*   
*   Compilation/Execution Instructions (Run in command line):
*   # g++ -o a project2_Hadley_clh0089.cpp
*   # ./a
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream &inStream);

void writefile(string filename); // Work in Progress

int main()
{
    ifstream inStream1;
    ifstream inStream2;
    string filename_1 = "";
    string filename_2 = "";
    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;

    cout << "*** Welcome to Caelan's sorting program ***\n";
    cout << "Enter the first input file name: ";
    cin >> filename_1;
    inStream1.open(filename_1);
    iArray1_size = readfile(iArray1, inStream1);
    inStream1.close();

    cout << "Enter the second input file name: ";
    cin >> filename_2;
    inStream2.open(filename_2);
    iArray2_size = readfile(iArray2, inStream2);
    inStream2.close();

    return 0;
}

int readfile(int inputArray[], ifstream &inStream)
{
    int index = 0;
    inStream >> inputArray[index];
    while (!inStream.eof())
    {
        cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
    }
    return index;
}
