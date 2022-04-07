#include <iostream>
using std::cout;
using std::endl;

#define ELKESZULT 2

/**
 * Feladatok:
 * 1. ELKESZULT=1
 *    Val�s�tsa meg (defini�lja) a hi�nyz� tagf�ggv�nyeket! (kerulet(), terulet())
 *
 * 2. ELKESZULT=2
 *    Eg�sz�tse ki az oszt�lyt �gy, hogy t�mb is l�trehozhat� legyen bel�le
 *    (Tipp: t�mb csak olyan oszt�lyb�l p�ld�nyos�that�, aminek van param�ter
 *    n�lk�l h�vhat� konstruktora)
 *
 */

class Teglalap {
    double a, b;       
public:
    Teglalap(double, double);  
    void kiir() const;          
    double kerulet() const;
    double terulet() const;     
};

Teglalap::Teglalap(double a, double b) {
    this->a = a;
    this->b = b;
}

void Teglalap::kiir() const {
    cout << "a:" << a << " b:" << b << endl;
}

// ELKESZULT 1 - 2
// 1. feladat

double Teglalap::terulet() const {
  return a * b;
}

// Itt pedig a ker�let sz�m�t�st kell megval�s�tania

double Teglalap::kerulet() const {
  return (2 * a) + (2 * b);
}


int main() {
    Teglalap ta(1,4);
    cout << "ta: ";
    ta.kiir();
    Teglalap tb(3,8);
    cout << "tb: ";
    tb.kiir();
#if ELKESZULT >= 1
    cout << "ta ker�lete:" << ta.kerulet() << endl;
    cout << "tb ker�lete:" << tb.kerulet() << endl;
    cout << "ta ter�lete:" << ta.terulet() << endl;
    cout << "tb ter�lete:" << tb.terulet() << endl;
#endif

#if ELKESZULT >= 2
    const int N = 5;
    Teglalap teglak[N];
    for (int i = 0; i < N; i++) {
        cout << "teglak[" << i << "]: ";
        teglak[i].kiir();
    }
#endif
    return 0;
}
