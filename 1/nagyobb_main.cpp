// Fájl: nagyobb_main.cpp
// Egyszerű demo program.
// Bekér két egész számot és kiírja a nagyobbat.

#include <iostream>
#include <iomanip>
#include "fuggvenyeim.h"

using namespace std;

/*

int main() {

     cout << "Kerek ket egesz szamot:";

     int i, j;
     cin >> i >> j;                    // i és j értékének beolvasása
     int k  = max(i,  j);
     cout << "A nagyobb: " << k  << endl; // nagyobb kiírása

    double an[] = { 3, 2, 1}; // együtthatók: a0=3, a1=2, a2=1      
    cout << "polinom(x=1)(x^2+2x+3):" << polinom(1.0, 2, an) << endl;

    return 0;
}

*/

// 9-ik, 10-ik, 11-ik, 12-ik feladat

int main() {
    double an[] = { 3, 2, 1 }; // együtthatók: a0=3, a1=2, a3=1      
    double res[] = { 3, 6, 11, 18, 27, 38, 51 };
    int hibak = 0;
    for (int i = 0; i < 7; i++) {
        const double Z = 3.141e2;
        double x = i / Z - 1;
        x++;
        x = x * Z;
        double fx = polinom(x, 2, an);
        if (!almostEQ(res[i], fx)) {    // Helyes ez így? Igen, mivel az almosEQ függvény leírása szerint a számoknak a relatív vagy abszolút hibája kisebb mint a viszonyítási pont a függvényben, ezért elfogadottnak tekintjük őket
           cout << "Hibas: " << setprecision(20) << res[i] << "!=" << fx << endl;
           hibak++;
        }
    }
    if (hibak == 0)
        cout << "Nem volt elteres" << endl;
}
