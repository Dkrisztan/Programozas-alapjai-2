// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include <cmath>
#include <limits>
#include "fuggvenyeim.h"

// Polinom kiszámolása
// 5-ös feladat
// 8-as feladat
double polinom(double f, int fok, double eho[]) {
  double x = 0;

  for(int i = fok; i >= 0; i--) {
    x *= f;
    x += eho[i];
  }

  return x;
}

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp = a;
   a =  b;
   b = tmp;
}

/// Segédfüggvény double pontosságú számok összehasonlításához
/// Nem bombabiztos, de nekünk most jó lesz
/// Elméleti hátér:
/// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.html
bool almostEQ(double a, double  b) {
    // eps: ha a relatív, vagy abszolút hiba ettől kisebb, akkor elfogadjuk
    double eps = 50 * std::numeric_limits<double>::epsilon(); // 50-szer a legkisebb absz. (!=0) érték: ~1e-14
    if (a == b) return true;
    if (fabs(a - b) < eps)
       return true;
    double aa = fabs(a);
    double ba = fabs(b);
    if (aa < ba) {
        aa = ba;
        ba = fabs(a);
    }
    return (aa - ba) < aa * eps;
}
