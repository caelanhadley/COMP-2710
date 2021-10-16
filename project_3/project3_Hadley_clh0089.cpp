/*
*   Caelan Hadley (clh0089)   
*   project3_Hadley_clh0089.cpp
*
*   Reference(s):
*   (1) https://stackoverflow.com/questions/3473438/return-array-in-a-function
*   
*   Compilation/Execution Instructions (Run in command line):
*   # g++ -o a project2_Hadley_clh0089.cpp
*   # ./a
*/
#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream &inStream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
int *insert(int inputArray[], int index, int value, int output[]);

void arrayContents(int inputArray[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << i << ": " << inputArray[i] << "\n";
    }
}

void writefile(string filename); // Work in Progress

int main()
{
    ifstream inStream1;
    ifstream inStream2;
    string filename_1 = "";
    string filename_2 = "";
    int iArray1[MAX_SIZE] = {0};
    int iArray1_size;
    int iArray2[MAX_SIZE] = {0};
    int iArray2_size;
    int output[MAX_SIZE] = {0};

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

    cout << "ARRAY1\n";
    arrayContents(iArray1);
    int test[MAX_SIZE] = {0};
    insert(iArray1, 4, 5, test);
    cout << "ARRAY2\n";
    arrayContents(test);

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

void writefile(string filename)
{
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
{
    int itt = 0;

    if (inputArray1[0] < inputArray2[0])
    {
        outputArray[0] = inputArray1[0];
        itt++;
    }
    else
    {
        outputArray[0] = inputArray2[0];
        itt++;
    }

    for (int i = 0; i < inputArray1_size; i++)
    {
        for (int j = 0; j < inputArray2_size; j++)
        {
            if (inputArray1[i] >= inputArray2[j])
            {
                outputArray[itt] = inputArray1[i];
                itt++;
            }
            else if (inputArray1[i] < inputArray2[j])
            {
                outputArray[itt] = inputArray2[j];
            }
            cout << ":: " << outputArray[itt - 1] << "\n";
        }
    }
    return itt;
}

int *insert(int inputArray[], int index, int value, int output[])
{
    for (int i = 0; i < index - 1; i++)
    {
        inputArray[i] >> output[i];
    }
    value >> output[index];
    for (int i = index; i < MAX_SIZE - 1; i++)
    {
        inputArray[i] >> output[i + 1];
    }
    return output;
}