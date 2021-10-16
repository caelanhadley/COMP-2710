#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 3> test = {3, 1, 2};
    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << "\n";
    }
    return 0;
}