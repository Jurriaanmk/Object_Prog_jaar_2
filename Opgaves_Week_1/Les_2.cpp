#include <iostream>

using namespace std;

void Reference_Voorbeeld()
{
    int Test_i;
    int& Test_j = Test_i;

    Test_i = 3;

    cout << Test_j << endl;
}
6+
int main()
{
    int a = 3, b = 7, c = 5;

    (a += b) += c;
    cout << a << b << c << endl;
    Reference_Voorbeeld();
}