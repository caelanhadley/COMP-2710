/*
*   Caelan Hadley (clh0089)   
*   project3_Hadley_clh0089.cpp
*
*   Reference(s):
*   (1) https://stackoverflow.com/questions/3473438/return-array-in-a-function
*   (2) https://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
*   
*   Compilation/Execution Instructions (Run in command line):
*   # g++ -o a project2_Hadley_clh0089.cpp
*   # ./a
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

vector<int> readfile(ifstream &inStream);
vector<int> sort(vector<int> iArray1, vector<int> iArray2);
int insert(int inputArray[], int index, int value);
void writefile(string filename, vector<int> contents);

void arrayContents(vector<int> ind);

int main()
{
    ifstream inStream1;
    ifstream inStream2;
    string filename_1 = "";
    string filename_2 = "";
    string filename_o = "";
    vector<int> iArray1;
    vector<int> iArray2;
    vector<int> output;

    cout << "*** Welcome to Caelan's sorting program ***\n";
    cout << "Enter the first input file name: ";
    cin >> filename_1;
    inStream1.open(filename_1);
    if (inStream1.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    cout << "probe" << endl;
    iArray1 = readfile(inStream1);

    inStream1.close();

    cout << "Enter the second input file name: ";
    cin >> filename_2;

    inStream2.open(filename_2);
    if (inStream2.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    iArray2 = readfile(inStream2);
    inStream2.close();

    output = sort(iArray1, iArray2);
    arrayContents(output);

    cout << "Enter the output file name: ";
    cin >> filename_o;
    writefile(filename_o, output);
    cout << "*** Please check the new file - " << filename_o << "***\n";
    cout << "*** Goodbye. ***\n";

    return 0;
}

vector<int> readfile(ifstream &inStream)
{
    int index = 0;
    int temp;
    vector<int> result;
    inStream >> temp;
    result.push_back(temp);
    while (!inStream.eof())
    {
        cout << result[index] << endl;
        index++;

        inStream >> temp;
        if (inStream.eof())
        {
            break;
        }
        result.push_back(temp);
    }
    return result;
}

void writefile(string filename, vector<int> contents)
{
    ofstream outStream;
    outStream.open((char *)filename.c_str());
    for (int i = 0; i < contents.size(); i++)
    {
        outStream << contents[i] << "\n";
    }
    outStream.close();
}

vector<int> sort(vector<int> iArray1, vector<int> iArray2)
{
    vector<int>
        result = iArray1;

    for (int i = 0; i < iArray2.size(); i++)
    {
        for (int j = 0; j < iArray1.size(); j++)
        {
            if (iArray2[i] <= result[j])
            {
                result.insert(result.begin() + j, iArray2[i]);
                break;
            }
        }
    }
    return result;
}

void arrayContents(vector<int> ind)
{
    cout << "The sorted list of " << ind.size() << " numbers is: ";
    for (int i = 0; i < ind.size(); i++)
    {
        cout << ind[i] << " ";
    }
    cout << "\n";
}