#include <iostream>

using namespace std;

void verwissel(int Waarde_1, int Waarde_2)
{
 int temp = Waarde_1;
 Waarde_1 = Waarde_2;

 Waarde_2 = Waarde_1;

 cout <<"Waarde 1: " << Waarde_1;
 cout <<"Waarde 2: " << Waarde_2;

}

void Verwissel_Correct( int *a, int *b){
    int tijdelijk = *a;
    *a = *b;
    *b = tijdelijk;
}

int main()
{
    int dit = {6};
    cout << "\r\n Hello world! " << dit;
    int *pdit = &dit;

    cout <<"\r\n pointer waarde "<< *pdit;

    int mA = 5;
    int mB = 10;

    Verwissel_Correct(&mA,&mB);

    cout <<"\r\n Waarde mA "<< mA;
    cout<<"\r\n Waarde mA" <<mB;

    int &rmA{mA}; // declaren met een & dat het een refrence
    cout << "\r\n Geef rmA: "<< rmA;
    cout << "\r\n Geef mA: "<< mA;

    rmA = rmA + 20;

    cout << "\r\n Geef mA: "<< mA;

    Breuk Naampie;
    cout << Naampie.ditzietiedereen;




    return 0;
}

class Breuk{
 public:
    int ditzietiedereen = 2;
 private:
     int ditzietNiemand = 69;
};


