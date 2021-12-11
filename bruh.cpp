#include <iostream>
using namespace std;

int main()
{
    double *p1;
    double *p2;
    double p3;

    p1 = &p3;
    p3 = 9.9;
    p2 = p1;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << &p3 << endl;

    return 0;
}
